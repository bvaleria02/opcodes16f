#ifndef LIB_OP_CODE_16_CONTEXT_H
#define LIB_OP_CODE_16_CONTEXT_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "libopcode16.h"

#define OP_INSTRUCTION_MEMORY_SIZE 4096
#define OP_STACK_SIZE 8
#define OP_STATUS_BANK_MASK 0x60
#define OP_STATUS_BANK_SHIFT 0x5

#ifndef op_context_t
  typedef struct _op_context_t op_context_t;
#endif

typedef op_error_t (*op_context_fn_step_t)(op_context_t *);
typedef op_error_t (*op_context_fn_reset_t)(op_context_t *);
typedef op_error_t (*op_context_fn_run_t)(op_context_t *);
typedef op_error_t (*op_context_fn_callback_t)(op_context_t *, op_enriched_instruction_t *ins, const uint16_t address, void *data);

typedef struct {
  const op_context_fn_step_t step;
  const op_context_fn_reset_t reset;
  const op_context_fn_step_t run;
} op_context_vtable_t;

struct _op_context_t {
  op_context_vtable_t *vtable;

  uint8_t memory[OP_BANK_COUNT][OP_BANK_SIZE];
  uint16_t instruction_memory[OP_INSTRUCTION_MEMORY_SIZE];
  uint16_t pc;
  size_t cycle_count;
  uint16_t stack[OP_STACK_SIZE];
  uint16_t sp;
  uint16_t w;
  uint16_t f;
  size_t wait_cycles;

  op_enriched_instruction_config_t enrichedConfig;
  op_enriched_instruction_t lastInstruction;
  op_context_fn_callback_t callback;
  void *external_data;
};

extern op_context_vtable_t op_context_vtable_default;

op_error_t op_context_init(op_context_t *ctx, uint16_t *instructions, size_t length, op_context_fn_callback_t callback, const op_enriched_instruction_config_t *encfg);
op_error_t op_context_run(op_context_t *ctx);
op_error_t op_context_step(op_context_t *ctx);
op_error_t op_context_reset(op_context_t *ctx);
op_error_t op_context_set_external(op_context_t *ctx, void *data);


#endif //LIB_OP_CODE_16_CONTEXT_H
