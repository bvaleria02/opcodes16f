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
#define OP_MAX_VARIABLE_COUNT 16

typedef struct {
  bool active;
  uint8_t bank;
  uint8_t address;
} op_variable_supervisor_t;

typedef struct {
  bool print;
  bool print_w;
  op_variable_supervisor_t variables[OP_MAX_VARIABLE_COUNT];
} op_tool_config_t;

typedef struct {
  bool isValid;
  size_t argc;
  uint32_t argv[OP_MAX_ARGV_COUNT];
} op_command_argument_t;

op_error_t op_parse_command(op_command_argument_t *args);

op_error_t op_tool_insert_variable(op_tool_config_t *cfg, const uint8_t bank, const uint8_t address);
op_error_t op_tool_remove_variable(op_tool_config_t *cfg, const uint8_t bank, const uint8_t address);

#endif //LIB_OP_CODE_TOOL_H
