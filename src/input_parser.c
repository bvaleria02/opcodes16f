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
