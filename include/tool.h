#ifndef LIB_OP_CODE_TOOL_H
#define LIB_OP_CODE_TOOL_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "libopcode16.h"
#include "libopcodecontext.h"

#define OP_MAX_ARGV_COUNT 8

typedef struct {
  bool print;
  bool print_w;
} op_tool_config_t;

typedef struct {
  bool isValid;
  size_t argc;
  uint32_t argv[OP_MAX_ARGV_COUNT];
} op_command_argument_t;

op_error_t op_parse_command(op_command_argument_t *args);

#endif //LIB_OP_CODE_TOOL_H
