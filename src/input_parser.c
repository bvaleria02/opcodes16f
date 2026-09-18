#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include <errno.h>
#include "../include/libopcode16.h"
#include "../include/libopcodecontext.h"
#include "../include/tool.h"

#define _C_BUFFER_SIZE 128

op_error_t op_parse_command(op_command_argument_t *args){
  OP_CHECK_NULLPTR(args);

  // clear
  args->argc = 0;
  args->isValid = false;
  for(size_t i = 0; i < OP_MAX_ARGV_COUNT; i++) args->argv[i] = 0;
  
  char buffer[_C_BUFFER_SIZE];

  char *res = fgets(buffer, _C_BUFFER_SIZE, stdin);
  assert(res != NULL);
  if(res == NULL) return OP_ERROR_STDIN;

  char *startptr = buffer;
  char *endptr   = NULL;

  for(size_t i = 0; i < OP_MAX_ARGV_COUNT; i++){

    errno = 0;
    uint32_t value = strtoul(startptr, &endptr, 16);
    if(errno != 0 || endptr == startptr){
      break;
    }

    args->argv[i] = value;
    args->argc = i + 1;
    startptr = endptr;
  }
  
  args->isValid = true;
  return OP_NO_ERROR;
}

op_error_t op_tool_find_variable(op_tool_config_t *cfg, const uint8_t bank, const uint8_t address, bool *found, size_t *index){
  OP_CHECK_NULLPTR(cfg);
  OP_CHECK_NULLPTR(found);
  OP_CHECK_NULLPTR(index);

  (*found) = false;

  for(size_t i = 0; i < OP_MAX_VARIABLE_COUNT; i++){
    if(!(cfg->variables[i].active)) continue;

    if(cfg->variables[i].address != address) continue;
    if(cfg->variables[i].bank    != bank)    continue;

    (*index) = i;
    (*found) = true;
    break;
  }

  return OP_NO_ERROR;
}

op_error_t op_tool_insert_variable(op_tool_config_t *cfg, const uint8_t bank, const uint8_t address){
  OP_CHECK_NULLPTR(cfg);

  op_error_t code = OP_NO_ERROR;

  bool found = false;
  size_t index = 0;
  code = op_tool_find_variable(cfg, bank, address, &found, &index);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  if(found) return OP_NO_ERROR;

  for(size_t i = 0; i < OP_MAX_VARIABLE_COUNT; i++){
    if(cfg->variables[i].active) continue;

    cfg->variables[i].address = address;
    cfg->variables[i].bank    = bank;
    cfg->variables[i].active  = true;

    break;
  }
  
  return OP_NO_ERROR;
}

op_error_t op_tool_remove_variable(op_tool_config_t *cfg, const uint8_t bank, const uint8_t address){
  OP_CHECK_NULLPTR(cfg);
  
  op_error_t code = OP_NO_ERROR;
  
  bool found = false;
  size_t index = 0;
  code = op_tool_find_variable(cfg, bank, address, &found, &index);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  if(!found) return OP_NO_ERROR;

  cfg->variables[index].address = 0;
  cfg->variables[index].bank    = 0;
  cfg->variables[index].active  = false;
  
  return OP_NO_ERROR;
}
