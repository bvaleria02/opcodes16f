#ifndef LIB_OP_CODE_16_H
#define LIB_OP_CODE_16_H

#include <stdio.h>
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
  OP_REGISTER_F = 2,
  OP_REGISTER_D = 3,
  OP_REGISTER_B = 4,
  OP_REGISTER_K = 5,
  OP_REGISTER_Z = 6
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

typedef struct {
  bool active;
  uint16_t value;
  const char *name;    // SSPCON2, PORTA, INTCOM, etc OR W, f
  op_numeric_display_t display;
} op_enriched_register_t;

typedef struct {
  bool showRegname;
  bool showValue;
  bool showName;
} op_enriched_register_config_t;

typedef struct {
  bool showAddress;
  bool showName;
  bool showValue;
  bool showFlagname;
  bool showDescription;
  op_enriched_register_config_t configF;
  op_enriched_register_config_t configW;
  op_enriched_register_config_t configK;
  op_enriched_register_config_t configB;
  op_enriched_register_config_t configD;
} op_enriched_instruction_config_t;

typedef struct {
  uint16_t address;
  uint16_t value;
  const char *name;
  const char *description;
  
  op_enriched_register_t regF;
  op_enriched_register_t regW;
  op_enriched_register_t regK;
  op_enriched_register_t regD;
  op_enriched_register_t regB;
  
  const char *flag_name; // ADIF, TM0RIF, INTF 
} op_enriched_instruction_t;


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
op_error_t op_enrich_register_clear(op_enriched_register_t *reg);
op_error_t op_enrich_clear(op_enriched_instruction_t *ins);
op_error_t op_enrich_decode_result(op_enriched_instruction_t *ins, const op_instruction_result_t *result, const uint16_t address, const uint8_t bank);
op_error_t op_enriched_print_register_stream(const op_enriched_register_t *reg, const op_enriched_register_config_t *config, FILE *stream, const op_register_t regtype);
op_error_t op_enriched_print_stream(const op_enriched_instruction_t *ins, const op_enriched_instruction_config_t *config, FILE *stream);
op_error_t op_enrich_decode_print_array(const uint16_t *instruction_array, const size_t length, const op_enriched_instruction_config_t *config, const uint16_t addressStart);

#endif //LIB_OP_CODE_16_H
