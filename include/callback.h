#ifndef LIB_OP_CODE_CALLBACK_H
#define LIB_OP_CODE_CALLBACK_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "libopcode16.h"
#include "libopcodecontext.h"

op_error_t op_callback_addwf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_andwf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_clrf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_clrw(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_comf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_decf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_decfsz(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_incf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_incfsz(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_iorwf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_movf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_movwf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_nop(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_rlf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_rrf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_subwf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_swapf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_xorwf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_bcf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_bsf(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_btfsc(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_btfss(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_addlw(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_andlw(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_call(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_clrwdt(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_goto(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_iorlw(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_movlw(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_retfie(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_retlw(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_return(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_sleep(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_sublw(op_context_t *ctx, op_enriched_instruction_t *res);
op_error_t op_callback_xorlw(op_context_t *ctx, op_enriched_instruction_t *res);

op_error_t op_context_fetch_bank(op_context_t *ctx, uint8_t *bank);
op_error_t op_context_fetch_memory(op_context_t *ctx, const uint8_t bank, const uint8_t address, uint8_t *value);
op_error_t op_context_store_memory(op_context_t *ctx, const uint8_t bank, const uint8_t address, uint8_t value);
op_error_t op_context_conditional_d_store(op_context_t *ctx, const bool d, uint8_t value, const uint8_t bank, const uint8_t address);

#endif //LIB_OP_CODE_CALLBACK_H
