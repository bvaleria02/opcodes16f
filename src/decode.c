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
