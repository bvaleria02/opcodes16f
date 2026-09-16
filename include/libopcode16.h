#ifndef LIB_OP_CODE_16_H
#define LIB_OP_CODE_16_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

#define OP_INSTRUCTION_REGISTER_COUNT 2

typedef enum {
  OP_NO_ERROR = 0,
  OP_ERROR_NULLPTR = 1,
} op_error_t;

typedef enum {
  OP_STATUS_NONE,
  OP_STATUS_C,
  OP_STATUS_DC,
  OP_STATUS_Z,
} op_status_t;

typedef enum {
  OP_REGISTER_NONE = 0,
  OP_REGISTER_W = 1,
  OP_REGISTER_Z = 2,
  OP_REGISTER_F = 3,
  OP_REGISTER_D = 4,
  OP_REGISTER_B = 5,
  OP_REGISTER_K = 6
} op_register_t;

typedef enum {
  OP_NUMERIC_DISPLAY_HEX16 = 0,
  OP_NUMERIC_DISPLAY_HEX8  = 1,
  OP_NUMERIC_DISPLAY_DEC16 = 2,
  OP_NUMERIC_DISPLAY_DEC8  = 3
} op_numeric_display_t;

typedef struct {
  bool active;
  uint16_t mask;
  uint8_t shift;
  op_register_t reg;
  op_numeric_display_t display;
} op_instruction_register_t;

typedef struct {
  const char *name;
  const char *description;
  uint8_t cycles;
  uint16_t status_affected;
  uint16_t mask;
  uint8_t shift;
  uint16_t opcode;
  op_instruction_register_t reg[OP_INSTRUCTION_REGISTER_COUNT];
} op_instruction_t;

#define OP_INSTRUCTION_SET_COUNT 35
extern const op_instruction_t op_instruction_set[OP_INSTRUCTION_SET_COUNT];

typedef struct {
  op_register_t reg;
  uint16_t value;
  bool active;
} op_register_result_t;

typedef struct {
  uint16_t value;
  const op_instruction_t *instruction;
  bool unknown;
  op_register_result_t registers[OP_INSTRUCTION_REGISTER_COUNT];
} op_instruction_result_t;

typedef struct {
  bool active;
  const char *name;
} op_register_bit_t;

typedef struct {
  bool reserved;
  const char *name;
  op_register_bit_t bits[8];
} op_register_file_map_t;


#define OP_BANK_COUNT 4
#define OP_BANK_SIZE 128
extern const op_register_file_map_t op_registers_file_map[OP_BANK_COUNT][OP_BANK_SIZE];

#define OP_CHECK_NULLPTR(__ptr) do{ \
  assert((__ptr) != NULL);          \
    if((__ptr) == NULL){            \
    return OP_ERROR_NULLPTR;        \
  }                                 \
} while(0)

op_error_t op_decode_instruction(const uint16_t instruction, op_instruction_result_t *result);
op_error_t op_print_register_result(const op_register_result_t *reg, const op_instruction_register_t *reginst, const uint8_t bank);
op_error_t op_print_instruction_result(const op_instruction_result_t *result, const uint8_t bank);
op_error_t op_clear_instruction_result(op_instruction_result_t *result);
op_error_t op_decode_print_array(const uint16_t *instruction_array, const size_t length);

#endif //LIB_OP_CODE_16_H
