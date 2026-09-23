#ifndef LIB_OP_CODE_REPL_H
#define LIB_OP_CODE_REPL_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "libopcode16.h"
#include "libopcodecontext.h"
#include "tool.h"

#ifdef _WIN32
  #include <windef.h>
  #define PATH_LENGTH (MAX_PATH)
#else 
  #include <linux/limits.h>
  #define PATH_LENGTH (PATH_MAX)
#endif

op_error_t op_command_parser_handler(op_command_argument_t *args, const size_t minargs, const char *name, const char *help);

op_error_t op_command_goto(op_context_t *ctx);
op_error_t op_command_move(op_context_t *ctx);
op_error_t op_command_replace(op_context_t *ctx);
op_error_t op_command_add_watch_variable(op_context_t *ctx, op_tool_config_t *cfg);
op_error_t op_command_remove_watch_variable(op_context_t *ctx, op_tool_config_t *cfg);
op_error_t op_hex_print_stream(const uint8_t *mem, const size_t length, FILE *stream);
op_error_t op_command_hex_dump(op_context_t *ctx);
op_error_t op_command_execute_n(op_context_t *ctx);
op_error_t op_command_execute_until_return(op_context_t *ctx);
op_error_t op_command_save_program(op_context_t *ctx);
op_error_t op_command_save_memory(op_context_t *ctx);
op_error_t op_command_load_program(op_context_t *ctx);
op_error_t op_command_load_memory(op_context_t *ctx);
char op_to_upper(const char c);
op_error_t op_context_replace_instruction_memory(op_context_t *ctx, const uint16_t *data, const size_t length, const size_t address);

#endif //LIB_OP_CODE_REPL_H
