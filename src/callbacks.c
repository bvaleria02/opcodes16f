#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "../include/libopcode16.h"
#include "../include/libopcodecontext.h"
#include "../include/callback.h"

op_error_t op_context_fetch_bank(op_context_t *ctx, uint8_t *bank){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(bank);

  uint8_t i_bank = ctx->memory[0][OP_MEM_STATUS] & OP_STATUS_BANK_MASK;
  (*bank) = i_bank >> OP_STATUS_BANK_SHIFT;
  
  return OP_NO_ERROR;
}

op_error_t op_context_fetch_memory(op_context_t *ctx, const uint8_t bank, const uint8_t address, uint8_t *value){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(value);

  uint8_t bank_s    = (bank    >= OP_BANK_COUNT) ? (OP_BANK_COUNT - 1) : bank;
  uint8_t address_s = (address >= OP_BANK_SIZE)  ? (OP_BANK_SIZE  - 1) : address;

  if(address == OP_MEM_INDF){
    (*value) = ctx->memory[0][OP_MEM_INDF];
  } else if(address == OP_MEM_TMR0 && ((bank & 0x1) == 0)){
    (*value) = ctx->memory[0][OP_MEM_TMR0];
  } else if(address == OP_MEM_OPTION_REG && ((bank & 0x1) == 1)){
    (*value) = ctx->memory[1][OP_MEM_OPTION_REG];
  } else  if(address == OP_MEM_PCL){
    (*value) = ctx->memory[0][OP_MEM_PCL];
  } else  if(address == OP_MEM_STATUS){
    (*value) = ctx->memory[0][OP_MEM_STATUS];
  } else  if(address == OP_MEM_FSR){
    (*value) = ctx->memory[0][OP_MEM_FSR];
  } else if(address == OP_MEM_PORTB && ((bank & 0x1) == 0)){
    (*value) = ctx->memory[0][OP_MEM_PORTB];
  } else if(address == OP_MEM_TRISB && ((bank & 0x1) == 1)){
    (*value) = ctx->memory[1][OP_MEM_TRISB];
  } else  if(address == OP_MEM_PCLATH){
    (*value) = ctx->memory[0][OP_MEM_PCLATH];
  } else  if(address == OP_MEM_INTCON){
    (*value) = ctx->memory[0][OP_MEM_INTCON];
  } else {
    (*value) = ctx->memory[bank_s][address_s];
  }
    
  return OP_NO_ERROR;
}

op_error_t op_context_store_memory(op_context_t *ctx, const uint8_t bank, const uint8_t address, uint8_t value){
  OP_CHECK_NULLPTR(ctx);

  uint8_t bank_s    = (bank    >= OP_BANK_COUNT) ? (OP_BANK_COUNT - 1) : bank;
  uint8_t address_s = (address >= OP_BANK_SIZE)  ? (OP_BANK_SIZE  - 1) : address;

  if(address == OP_MEM_INDF){
    ctx->memory[0][OP_MEM_INDF] = value;
  } else if(address == OP_MEM_TMR0 && ((bank & 0x1) == 0)){
    ctx->memory[0][OP_MEM_TMR0] = value;
  } else if(address == OP_MEM_OPTION_REG && ((bank & 0x1) == 1)){
    ctx->memory[1][OP_MEM_OPTION_REG] = value;
  } else  if(address == OP_MEM_PCL){
    ctx->memory[0][OP_MEM_PCL] = value;
  } else  if(address == OP_MEM_STATUS){
    ctx->memory[0][OP_MEM_STATUS] = value;
  } else  if(address == OP_MEM_FSR){
    ctx->memory[0][OP_MEM_FSR] = value;
  } else if(address == OP_MEM_PORTB && ((bank & 0x1) == 0)){
    ctx->memory[0][OP_MEM_PORTB] = value;
  } else if(address == OP_MEM_TRISB && ((bank & 0x1) == 1)){
    ctx->memory[1][OP_MEM_TRISB] = value;
  } else  if(address == OP_MEM_PCLATH){
    ctx->memory[0][OP_MEM_PCLATH] = value;
  } else  if(address == OP_MEM_INTCON){
    ctx->memory[0][OP_MEM_INTCON] = value;
  } else {
    ctx->memory[bank_s][address_s] = value;
  }
    
  return OP_NO_ERROR;
}

op_error_t op_context_conditional_d_store(op_context_t *ctx, const bool d, uint8_t value, const uint8_t bank, const uint8_t address){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  if(d){
    code = op_context_store_memory(ctx, bank, address, value);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;
  } else {
    ctx->w = value;
  }

  return OP_NO_ERROR;
}


op_error_t op_callback_addwf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value + ctx->w;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}


op_error_t op_callback_andwf(op_context_t *ctx, op_enriched_instruction_t *res){ 
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = ctx->w & mem_value;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_clrf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = 0x0;

  // Store value
  code = op_context_store_memory(ctx, bank, res->regF.value, value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_clrw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  // Execute
  ctx->w = 0x0;

  // Store value
  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_comf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = ~(mem_value);

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_decf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value--;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_decfsz(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value--;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  if(value == 0){
    ctx->pc += 2;
    ctx->wait_cycles = 1;
    ctx->cycle_count += 1;
  } else {
    ctx->pc += 1;
    ctx->wait_cycles = 0;
    ctx->cycle_count += 1;
  }
  
  return OP_NO_ERROR;
}

op_error_t op_callback_incf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value++;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_incfsz(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value++;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  if(value == 0){
    ctx->pc += 2;
    ctx->wait_cycles = 1;
    ctx->cycle_count += 1;
  } else {
    ctx->pc += 1;
    ctx->wait_cycles = 0;
    ctx->cycle_count += 1;
  }
  
  return OP_NO_ERROR;
}

op_error_t op_callback_iorwf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = ctx->w | mem_value;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_movf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_movwf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = ctx->w;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_nop(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_rlf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t msb = mem_value & 0x80;
  msb = msb >> 0x7;
  uint8_t value = (mem_value >> 1) | msb;

  uint8_t status = 0;
  code = op_context_fetch_memory(ctx, 0, OP_MEM_STATUS, &status);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  status = status & ~(0xFE);
  status = status |  (msb);
  
  code = op_context_store_memory(ctx, 0, OP_MEM_STATUS, status);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_rrf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t lsb = mem_value & 0x1;
  uint8_t value = (mem_value >> 1) | (lsb << 7);

  uint8_t status = 0;
  code = op_context_fetch_memory(ctx, 0, OP_MEM_STATUS, &status);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  status = status & ~(0xFE);
  status = status |  (lsb);
  
  code = op_context_store_memory(ctx, 0, OP_MEM_STATUS, status);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_subwf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value - ctx->w;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_swapf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t nibble_H = (mem_value >> 0x4) & 0xF;
  uint8_t nibble_L = (mem_value)        & 0xF;
  uint8_t value = (nibble_L << 0x4) | nibble_H;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_xorwf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value ^ ctx->w;

  // Store value
  code = op_context_conditional_d_store(ctx, res->regD.value, value, bank, res->regF.value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_bcf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value & ~(0x1 << res->regB.value);

  // Store value
  code = op_context_store_memory(ctx, bank, res->regF.value, value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_bsf(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = mem_value | (0x1 << res->regB.value);

  // Store value
  code = op_context_store_memory(ctx, bank, res->regF.value, value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;
  
  return OP_NO_ERROR;
}

op_error_t op_callback_btfsc(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = (mem_value >> res->regB.value) & 0x1;

  // Store value
  if(value == 0){
    ctx->pc += 2;
    ctx->wait_cycles = 1;
    ctx->cycle_count += 1;
  } else {
    ctx->pc += 1;
    ctx->wait_cycles = 0;
    ctx->cycle_count += 1;
  }
  
  return OP_NO_ERROR;
}

op_error_t op_callback_btfss(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  // Fetch bank
  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Fetch value from memory
  uint8_t mem_value = 0;
  code = op_context_fetch_memory(ctx, bank, res->regF.value, &mem_value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // Execute
  uint8_t value = (mem_value >> res->regB.value) & 0x1;

  // Store value
  if(value == 1){
    ctx->pc += 2;
    ctx->wait_cycles = 1;
    ctx->cycle_count += 1;
  } else {
    ctx->pc += 1;
    ctx->wait_cycles = 0;
    ctx->cycle_count += 1;
  }
  
  return OP_NO_ERROR;
}

op_error_t op_callback_addlw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->w = ctx->w + res->regK.value;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_andlw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->w = ctx->w & res->regK.value;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_context_stack_push(op_context_t *ctx, const uint16_t value){
  OP_CHECK_NULLPTR(ctx);

//  printf("sp1: %i\n", ctx->sp);
  uint16_t sp_s = (ctx->sp >= OP_STACK_SIZE) ? 0 : ctx->sp;
  ctx->stack[sp_s] = value;
  ctx->sp += 1;
//  printf("sp2: %i\n", ctx->sp);
  return OP_NO_ERROR;
}

op_error_t op_context_stack_pop(op_context_t *ctx, uint16_t *value){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(value);

  uint16_t sp_s = (ctx->sp >= OP_STACK_SIZE) ? (OP_STACK_SIZE - 1) : ctx->sp;
  sp_s = (sp_s >= 1) ? (sp_s - 1) : (OP_STACK_SIZE - 1);
//  printf("sp1: %i\n", sp_s);
  (*value) = ctx->stack[sp_s];
  ctx->sp  = (ctx->sp == 0) ? (OP_STACK_SIZE - 1) : sp_s;
//  printf("sp2: %i\n", ctx->sp);
  return OP_NO_ERROR;
}

op_error_t op_callback_call(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  code = op_context_stack_push(ctx, ctx->pc + 1);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  code = op_context_store_memory(ctx, 0, OP_MEM_PCL, res->regK.value & 0xFF);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  code = op_context_store_memory(ctx, 0, OP_MEM_PCLATH, (res->regK.value >> 8) & 0x7);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  ctx->pc = res->regK.value;
  ctx->wait_cycles = 1;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
  
}

// NotImplemented (yet)
op_error_t op_callback_clrwdt(op_context_t *ctx, op_enriched_instruction_t *res){  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_goto(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->pc = res->regK.value;
  ctx->wait_cycles = 1;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}
  
op_error_t op_callback_iorlw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->w = ctx->w | res->regK.value;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_movlw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->w = res->regK.value;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_retfie(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  uint16_t value = 0;
  code = op_context_stack_pop(ctx, &value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  code = op_context_store_memory(ctx, 0, OP_MEM_PCL, value & 0xFF);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  code = op_context_store_memory(ctx, 0, OP_MEM_PCLATH, (value >> 8) & 0x7);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->memory[0][OP_MEM_INTCON] |= 0x80;
 
  ctx->pc += value;
  ctx->wait_cycles = 1;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_retlw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  uint16_t value = 0;
  code = op_context_stack_pop(ctx, &value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  code = op_context_store_memory(ctx, 0, OP_MEM_PCL, value & 0xFF);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  code = op_context_store_memory(ctx, 0, OP_MEM_PCLATH, (value >> 8) & 0x7);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->w = res->regK.value;
  ctx->pc += value;
  ctx->wait_cycles = 1;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_return(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  op_error_t code = OP_NO_ERROR;

  uint16_t value = 0;
  code = op_context_stack_pop(ctx, &value);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  code = op_context_store_memory(ctx, 0, OP_MEM_PCL, value & 0xFF);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  code = op_context_store_memory(ctx, 0, OP_MEM_PCLATH, (value >> 8) & 0x7);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  ctx->pc = value;
  ctx->wait_cycles = 1;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_sleep(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->pc += 1;
  ctx->wait_cycles = SIZE_MAX;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_sublw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->w = ctx->w - res->regK.value;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

op_error_t op_callback_xorlw(op_context_t *ctx, op_enriched_instruction_t *res){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(res);

  ctx->w = ctx->w ^ res->regK.value;

  ctx->pc += 1;
  ctx->wait_cycles = 0;
  ctx->cycle_count += 1;

  return OP_NO_ERROR;
}

