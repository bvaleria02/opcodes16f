#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../include/libopcode16.h"

op_error_t op_decode_instruction(const uint16_t instruction, op_instruction_result_t *result){
  OP_CHECK_NULLPTR(result);

  op_error_t code = op_clear_instruction_result(result);
  assert(code == OP_NO_ERROR);
  
  result->value = instruction;
  
  size_t index = 0;
  bool found = false;
  uint16_t opcode = 0;
  
  for(size_t i = 0; i < OP_INSTRUCTION_SET_COUNT; i++){
      opcode = instruction & op_instruction_set[i].mask;
      opcode = opcode >> op_instruction_set[i].shift;

      if(opcode != op_instruction_set[i].opcode) continue;

      found = true;
      index = i;
      break;
  }

  if(!found) goto unknown;

  result->instruction = &(op_instruction_set[index]);
  result->unknown = false;

  uint16_t operand = 0;
  for(size_t i = 0; i < OP_INSTRUCTION_REGISTER_COUNT; i++){
    if(!(op_instruction_set[index].reg[i].active)) continue;
    
    operand = instruction & op_instruction_set[index].reg[i].mask;
    operand = operand >> op_instruction_set[index].reg[i].shift;
    result->registers[i].value  = operand;
    result->registers[i].reg    = op_instruction_set[index].reg[i].reg;
    result->registers[i].active = true;
  }

  return OP_NO_ERROR;

unknown:
  result->instruction = NULL;
  result->unknown = true;
  for(size_t i = 0; i < OP_INSTRUCTION_REGISTER_COUNT; i++) {
    result->registers[i].active = false;
  }
  return OP_NO_ERROR;
}


op_error_t op_print_register_result(const op_register_result_t *reg, const op_instruction_register_t *reginst, const uint8_t bank){
  OP_CHECK_NULLPTR(reg);

  const uint8_t bank_s = (bank >= OP_BANK_COUNT) ? (OP_BANK_COUNT - 1) : bank;

  switch(reg->reg){
    case OP_REGISTER_NONE:  printf("NONE");
                            break;
    case OP_REGISTER_W:     printf("W");
                            break;
    case OP_REGISTER_Z:     printf("Z");
                            break;
    case OP_REGISTER_F:     printf("F");
                            break;
    case OP_REGISTER_D:     printf("D");
                            break;
    case OP_REGISTER_B:     printf("B");
                            break;
    case OP_REGISTER_K:     printf("K");
                            break;
    default:                printf("OTHER");
  }
  
  printf(":");

  switch(reginst->display){
    case OP_NUMERIC_DISPLAY_HEX8:  printf("#0x%02X", reg->value);
                                   break;
    case OP_NUMERIC_DISPLAY_HEX16: printf("#0x%04X", reg->value);
                                   break;
    case OP_NUMERIC_DISPLAY_DEC8:  printf("%u", reg->value);
                                   break;
    case OP_NUMERIC_DISPLAY_DEC16: printf("%u", reg->value);
                                   break;
  }
  
  if(reg->reg == OP_REGISTER_F && op_registers_file_map[bank_s][reg->value].reserved){
    printf(" [%s]", op_registers_file_map[bank_s][reg->value].name);
  } else if(reg->reg == OP_REGISTER_D) {
    printf(" [%c]", (reg->value & 0x1) ? 'f' : 'W');
  }
  
  
  return OP_NO_ERROR;
}

op_error_t op_print_instruction_result(const op_instruction_result_t *result, uint8_t bank){
  OP_CHECK_NULLPTR(result);

  printf("0x%04X:\t", result->value);
  
  if(result->unknown){
    printf("Unknown instruction 0x%04X\n", result->value);
    return OP_NO_ERROR;
  }

  bool hasBRegister = false;
  uint16_t bValue = 0;
  bool hasFRegister = false;
  uint16_t fValue = 0;
  
  printf("%s ", result->instruction->name);
  for(size_t i = 0; i < OP_INSTRUCTION_REGISTER_COUNT; i++) {
    if(result->registers[i].active) {
      if(result->registers[i].reg == OP_REGISTER_B){
        hasBRegister = true;
        bValue = result->registers[i].value;
      }
      else if(result->registers[i].reg == OP_REGISTER_F){
        hasFRegister = true;
        fValue = result->registers[i].value;
      }
      
      if(i != 0) printf(", ");
      op_print_register_result(&(result->registers[i]), &(result->instruction->reg[i]), bank);
    }
  }

  if(hasBRegister && hasFRegister){
    fValue = (fValue >= OP_BANK_SIZE) ? (OP_BANK_SIZE - 1) : fValue;
    bValue = (bValue >= 8) ? 7  : bValue;
    if(op_registers_file_map[bank][fValue].reserved){
      if(op_registers_file_map[bank][fValue].bits[bValue].active){
        printf(" (%s)", op_registers_file_map[bank][fValue].bits[bValue].name);
      }
    }
  }
  
  printf("\t; %s\n", result->instruction->description);

  return OP_NO_ERROR;
}

op_error_t op_clear_instruction_result(op_instruction_result_t *result){
  OP_CHECK_NULLPTR(result);

  result->instruction = NULL;
  result->unknown = false;
  result->value = 0x0;
  
  for(size_t i = 0; i < OP_INSTRUCTION_REGISTER_COUNT; i++) {
    result->registers[i].active = false;
    result->registers[i].reg    = OP_REGISTER_NONE;
    result->registers[i].value  = 0x0;
  }

  return OP_NO_ERROR;
}

op_error_t op_decode_print_array(const uint16_t *instruction_array, const size_t length){
  OP_CHECK_NULLPTR(instruction_array);

  op_error_t code = OP_NO_ERROR;
  op_instruction_result_t result = {0};
  
  for(size_t i = 0; i < length; i++){
    code = op_decode_instruction(instruction_array[i], &result);
//    assert(code != OP_NO_ERROR);
    code = op_print_instruction_result(&result, 0);
//    assert(code != OP_NO_ERROR);
  }

  (void) code;
  return OP_NO_ERROR;
}

op_error_t op_enrich_register_clear(op_enriched_register_t *reg){
  OP_CHECK_NULLPTR(reg);
  
  reg->active = false;
  reg->value  = 0x0;
  reg->name   = NULL;
  reg->display= OP_NUMERIC_DISPLAY_HEX16;

  
  return OP_NO_ERROR;
}

op_error_t op_enrich_clear(op_enriched_instruction_t *ins){
  OP_CHECK_NULLPTR(ins);

  op_error_t code = OP_NO_ERROR;
  
  ins->address = 0x0;
  ins->value   = 0x0;
  ins->name    = NULL;
  
  code = op_enrich_register_clear(&(ins->regB));
  assert(code == OP_NO_ERROR);
  code = op_enrich_register_clear(&(ins->regF));
  assert(code == OP_NO_ERROR);
  code = op_enrich_register_clear(&(ins->regW));
  assert(code == OP_NO_ERROR);
  code = op_enrich_register_clear(&(ins->regK));
  assert(code == OP_NO_ERROR);
  code = op_enrich_register_clear(&(ins->regD));
  assert(code == OP_NO_ERROR);
  
  ins->flag_name = NULL;
  
  return OP_NO_ERROR;
}

op_error_t op_enrich_decode_result(op_enriched_instruction_t *ins, const op_instruction_result_t *result, const uint16_t address, const uint8_t bank){
  OP_CHECK_NULLPTR(result);
  OP_CHECK_NULLPTR(ins);

  op_error_t code = OP_NO_ERROR;
  code = op_enrich_clear(ins);
  assert(code == OP_NO_ERROR);

  ins->address = address;
  ins->value   = result->value;

  if(result->unknown){
    ins->name        = "UNKNOWN";
    ins->description = "Unknown instruction";
  } else {
    ins->name        = result->instruction->name;  
    ins->description = result->instruction->description;  
  }

  uint8_t bank_s  = (bank >= OP_BANK_COUNT) ? (OP_BANK_COUNT - 1) : bank;

  for(size_t i = 0; i < OP_INSTRUCTION_REGISTER_COUNT; i++){
    if(!(result->registers[i].active)) continue;
      
    switch(result->registers[i].reg){
      case OP_REGISTER_F: ins->regF.active  = true;
                          ins->regF.value   = result->registers[i].value;
                          ins->regF.display = result->instruction->reg[i].display;
                          uint8_t f_safe = (ins->regF.value >= OP_BANK_SIZE) ? (OP_BANK_SIZE - 1) : ins->regF.value;
                          ins->regF.name    = (op_registers_file_map[bank_s][f_safe].reserved) ? op_registers_file_map[bank_s][f_safe].name : NULL;
                          break;
      case OP_REGISTER_B: ins->regB.active  = true;
                          ins->regB.value   = result->registers[i].value;
                          ins->regB.display = result->instruction->reg[i].display;
                          ins->regB.name    = NULL;
                          break;
      case OP_REGISTER_K: ins->regK.active  = true;
                          ins->regK.value   = result->registers[i].value;
                          ins->regK.display = result->instruction->reg[i].display;
                          ins->regK.name    = NULL;
                          break;
      case OP_REGISTER_D: ins->regD.active  = true;
                          ins->regD.value   = result->registers[i].value;
                          ins->regD.display = result->instruction->reg[i].display;
                          ins->regD.name    = (ins->regD.value & 0x1) ? "f" : "W";
                          break;
      case OP_REGISTER_W: ins->regW.active  = true;
                          ins->regW.value   = result->registers[i].value;
                          ins->regW.display = result->instruction->reg[i].display;
                          ins->regW.name    = NULL;
                          break;    
      case OP_REGISTER_NONE: break;
      case OP_REGISTER_Z: break;                      
    }
  }

  if(ins->regB.active && ins->regF.active){
    uint8_t f_safe = (ins->regF.value >= OP_BANK_SIZE) ? (OP_BANK_SIZE - 1) : ins->regF.value;
    uint8_t b_safe = (ins->regB.value >= 8) ? 7 : ins->regB.value;

    if(op_registers_file_map[bank_s][f_safe].reserved && op_registers_file_map[bank_s][f_safe].bits[b_safe].active){
      ins->flag_name = op_registers_file_map[bank_s][f_safe].bits[b_safe].name;
    }
  }
  
  return OP_NO_ERROR;
}

op_error_t op_enriched_print_register_stream(const op_enriched_register_t *reg, const op_enriched_register_config_t *config, FILE *stream, const op_register_t regtype){
  OP_CHECK_NULLPTR(reg);
  OP_CHECK_NULLPTR(config);
  OP_CHECK_NULLPTR(stream);

  op_error_t code = OP_NO_ERROR;

  if(config->showRegname){
    switch(regtype){
      case OP_REGISTER_NONE:  fprintf(stream, "NONE:");
                              break;
      case OP_REGISTER_W:     fprintf(stream, "W:");
                              break;
      case OP_REGISTER_Z:     fprintf(stream, "Z:");
                              break;
      case OP_REGISTER_F:     fprintf(stream, "F:");
                              break;
      case OP_REGISTER_D:     fprintf(stream, "D:");
                              break;
      case OP_REGISTER_B:     fprintf(stream, "B:");
                              break;
      case OP_REGISTER_K:     fprintf(stream, "K:");
                              break;
      default:                fprintf(stream, "OTHER:");
    }
  }

  if(config->showValue){
    switch(reg->display){
      case OP_NUMERIC_DISPLAY_HEX8:  fprintf(stream, "#0x%02X", reg->value);
                                     break;
      case OP_NUMERIC_DISPLAY_HEX16: fprintf(stream, "#0x%04X", reg->value);
                                     break;
      case OP_NUMERIC_DISPLAY_DEC8:  fprintf(stream, "%u", reg->value);
                                     break;
      case OP_NUMERIC_DISPLAY_DEC16: fprintf(stream, "%u", reg->value);
                                     break;
    }
  }

  if(config->showName && (reg->name != NULL) && ((regtype == OP_REGISTER_B) | (regtype == OP_REGISTER_F))){
    fprintf(stream, " [%s]", reg->name);
  }
  
  (void) code;
  return OP_NO_ERROR; 
}

op_error_t op_enriched_print_stream(const op_enriched_instruction_t *ins, const op_enriched_instruction_config_t *config, FILE *stream){
  OP_CHECK_NULLPTR(ins);
  OP_CHECK_NULLPTR(config);
  OP_CHECK_NULLPTR(stream);

  op_error_t code = OP_NO_ERROR;

  if(config->showAddress){
    fprintf(stream, "0x%04X ", ins->address);
  }
  
  if(config->showValue){
    fprintf(stream, "0x%04X ", ins->value);
  }
  
  if(config->showName && (ins->name != NULL)){
    fprintf(stream, "%s ", ins->name);
  }

  if(ins->regB.active){
    code = op_enriched_print_register_stream(&(ins->regB), &(config->configB), stream, OP_REGISTER_B);
    assert(code == OP_NO_ERROR);
    fprintf(stream, ", ");
  }
  
  if(ins->regD.active){
    code = op_enriched_print_register_stream(&(ins->regD), &(config->configD), stream, OP_REGISTER_D);
    assert(code == OP_NO_ERROR);
    fprintf(stream, ", ");
  }
  
  if(ins->regW.active){
    code = op_enriched_print_register_stream(&(ins->regW), &(config->configW), stream, OP_REGISTER_W);
    assert(code == OP_NO_ERROR);
  }
  
  if(ins->regF.active){
    code = op_enriched_print_register_stream(&(ins->regF), &(config->configF), stream, OP_REGISTER_F);
    assert(code == OP_NO_ERROR);
  }

  if(ins->regK.active){
    code = op_enriched_print_register_stream(&(ins->regK), &(config->configK), stream, OP_REGISTER_K);
    assert(code == OP_NO_ERROR);
  }

  if((ins->regB.active && ins->regF.active) && config->showFlagname && (ins->flag_name != NULL)){
    fprintf(stream, "(bit:%s) ", ins->flag_name);
  }

  return OP_NO_ERROR; 
}

op_error_t op_enrich_decode_print_array(const uint16_t *instruction_array, const size_t length, const op_enriched_instruction_config_t *config, const uint16_t addressStart){
  OP_CHECK_NULLPTR(instruction_array);
  OP_CHECK_NULLPTR(config);

  op_error_t code = OP_NO_ERROR;
  op_instruction_result_t result = {0};
  op_enriched_instruction_t enins = {0};
  uint16_t address = addressStart;
  
  for(size_t i = 0; i < length; i++){
    address = addressStart + i;
    code = op_decode_instruction(instruction_array[i], &result);
    assert(code == OP_NO_ERROR);
    code = op_enrich_decode_result(&enins, &result, address, 0);
    assert(code == OP_NO_ERROR);
    code = op_enriched_print_stream(&enins, config, stdout);
    assert(code == OP_NO_ERROR);
    fprintf(stdout, "\n");
  }

  (void) code;
  return OP_NO_ERROR;
}
