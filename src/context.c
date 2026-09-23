#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "../include/libopcode16.h"
#include "../include/libopcodecontext.h"
#include "../include/checked_math.h"

op_context_vtable_t op_context_vtable_default = {
  .step  = (const op_context_fn_step_t)  op_context_step,
  .run   = (const op_context_fn_run_t)   op_context_run,
  .reset = (const op_context_fn_reset_t) op_context_reset,
};

op_error_t op_context_init(op_context_t *ctx, uint16_t *instructions, size_t length, op_context_fn_callback_t callback, const op_enriched_instruction_config_t *encfg){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(instructions);

  op_error_t code = OP_NO_ERROR;

  assert(length != 0);
  if(length == 0){
    return OP_ERROR_ZERO_LENGTH;
  }

  code = op_context_reset(ctx);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  size_t word_count = (length >= OP_INSTRUCTION_MEMORY_SIZE) ? OP_INSTRUCTION_MEMORY_SIZE - 1 : length;
  size_t copy_block_size = 0;
  code = op_checked_size_mul(word_count, sizeof(uint16_t), &copy_block_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  memcpy(ctx->instruction_memory, instructions, copy_block_size);

  if(callback != NULL){
    ctx->callback = callback;
  }
  
  if(encfg != NULL){
    memcpy(&(ctx->enrichedConfig), encfg, sizeof(op_enriched_instruction_config_t));
  }

  ctx->vtable = &(op_context_vtable_default);
  
  return OP_NO_ERROR;
}

op_error_t op_context_init_blank(op_context_t *ctx, const op_enriched_instruction_config_t *encfg){
  OP_CHECK_NULLPTR(ctx);

  uint16_t ins[OP_INSTRUCTION_MEMORY_SIZE];

  for(size_t i = 0; i < OP_INSTRUCTION_MEMORY_SIZE; i++){
    ins[i] = 0x00;
  }
  
  op_error_t code = op_context_init(ctx, ins, OP_INSTRUCTION_REGISTER_COUNT, NULL, encfg);
  
  return code;
}
  
op_error_t op_context_run(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);
  
  return OP_NO_ERROR;
}

op_error_t op_context_step(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  if(ctx->wait_cycles > 0){
    ctx->wait_cycles -= 1;
    ctx->cycle_count += 1;
    return OP_NO_ERROR;
  }
  
  op_error_t code = OP_NO_ERROR;

  assert(ctx->pc < OP_INSTRUCTION_MEMORY_SIZE);
  if(ctx->pc >= OP_INSTRUCTION_MEMORY_SIZE){
    return OP_ERROR_OUT_OF_BOUND;
  }

  // fetch
  uint16_t original_pc = ctx->pc;
  uint16_t instruction = ctx->instruction_memory[ctx->pc];

  uint8_t bank = ctx->memory[0][OP_MEM_STATUS] & OP_STATUS_BANK_MASK;
  bank = bank >> OP_STATUS_BANK_SHIFT;
  bank = bank & 0x3;

  // decode
  op_instruction_result_t decoded_instruction = {0};
  code = op_decode_instruction(instruction, &(decoded_instruction));
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  code = op_enrich_clear(&(ctx->lastInstruction));
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  code = op_enrich_decode_result(&(ctx->lastInstruction), &decoded_instruction, ctx->pc, bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  // execute
  if(!(decoded_instruction.unknown)){
    code = decoded_instruction.instruction->callback(ctx, &(ctx->lastInstruction));
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;
  } else {
    ctx->pc += 1;
    ctx->cycle_count += 1;
    ctx->wait_cycles = 0;
  }
  
  // callback
  if(ctx->callback != NULL){
    code = ctx->callback(ctx, &(ctx->lastInstruction), original_pc, ctx->external_data);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;
  }
  
  return OP_NO_ERROR;
}

op_error_t op_context_reset(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  ctx->pc = 0x0;
  ctx->cycle_count = 0x0;
  ctx->callback = NULL;
  ctx->w = 0x0;
  ctx->f = 0x0;
  ctx->wait_cycles = 0;

  size_t memory_size = 0;
  code = op_checked_size_mul(OP_BANK_COUNT, OP_BANK_SIZE, &memory_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  memset(ctx->memory, 0l, memory_size);

  size_t instruction_memory_size = 0;
  code = op_checked_size_mul(OP_INSTRUCTION_MEMORY_SIZE, sizeof(uint16_t), &instruction_memory_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  memset(ctx->instruction_memory, 0xFFl, instruction_memory_size);

  size_t stack_size = 0;
  code = op_checked_size_mul(OP_STACK_SIZE, sizeof(uint16_t), &stack_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  memset(ctx->stack, 0x0l, stack_size);
  ctx->sp = 0x0;

  code = op_enrich_clear(&(ctx->lastInstruction));
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  return OP_NO_ERROR;
}

op_error_t op_context_set_external(op_context_t *ctx, void *data){
  OP_CHECK_NULLPTR(ctx);

  ctx->external_data = data;
  
  return OP_NO_ERROR;
}
