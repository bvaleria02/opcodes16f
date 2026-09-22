#include <stdint.h>
#include <stdbool.h>
#include "../include/libopcode16.h"
#include "../include/callback.h"

const op_instruction_t op_instruction_set[OP_INSTRUCTION_SET_COUNT] = {
  {
    .name            = "ADDWF",
    .description     = "Add W and f",
    .cycles          = 1,
    .status_affected = OP_STATUS_C | OP_STATUS_DC | OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x7,
    .callback        = op_callback_addwf,
    .type            = OP_INSTRUCTION_ADDWF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    },
  },
  {
    .name            = "ANDWF",
    .description     = "AND W and f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x5,
    .callback        = op_callback_andwf,
    .type            = OP_INSTRUCTION_ANDWF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "CLRF",
    .description     = "Clear f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F80,
    .shift           = 7,
    .opcode          = 0x3,
    .callback        = op_callback_clrf,
    .type            = OP_INSTRUCTION_CLRF,
    .reg = {
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "CLRW",
    .description     = "Clear W",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F80,
    .shift           = 7,
    .opcode          = 0x2,
    .callback        = op_callback_clrw,
    .type            = OP_INSTRUCTION_CLRW,
    .reg = {
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "COMF",
    .description     = "Complement f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x9,
    .callback        = op_callback_comf,
    .type            = OP_INSTRUCTION_COMF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "DECF",
    .description     = "Decrement f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x3,
    .callback        = op_callback_decf,
    .type            = OP_INSTRUCTION_DECF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "DECFSZ",
    .description     = "Decrement f. Skip if 0",
    .cycles          = 2,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0xB,
    .callback        = op_callback_decfsz,
    .type            = OP_INSTRUCTION_DECFSZ,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "INCF",
    .description     = "Increment f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0xA,
    .callback        = op_callback_incf,
    .type            = OP_INSTRUCTION_INCF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "INCFSZ",
    .description     = "Increment f. Skip if 0",
    .cycles          = 2,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0xF,
    .callback        = op_callback_incfsz,
    .type            = OP_INSTRUCTION_INCFSZ,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "IORWF",
    .description     = "Inclusive OR W with f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x4,
    .callback        = op_callback_iorwf,
    .type            = OP_INSTRUCTION_IORWF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "MOVF",
    .description     = "Move f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x8,
    .callback        = op_callback_movf,
    .type            = OP_INSTRUCTION_MOVF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "MOVWF",
    .description     = "Move f",
    .cycles          = 1,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3F80,
    .shift           = 7,
    .opcode          = 0x1,
    .callback        = op_callback_movwf,
    .type            = OP_INSTRUCTION_MOVWF,
    .reg = {
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "NOP",
    .description     = "No Operation",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F9F,
    .shift           = 0,
    .opcode          = 0x0,
    .callback        = op_callback_nop,
    .type            = OP_INSTRUCTION_NOP,
    .reg = {
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "RLF",
    .description     = "Rotate Left f through Carry",
    .cycles          = 1,
    .status_affected = OP_STATUS_C,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0xD,
    .callback        = op_callback_rlf,
    .type            = OP_INSTRUCTION_RLF,
    .reg = {
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "RRF",
    .description     = "Rotate Right f through Carry",
    .cycles          = 1,
    .status_affected = OP_STATUS_C,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0xC,
    .callback        = op_callback_rrf,
    .type            = OP_INSTRUCTION_RRF,
    .reg = {
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
      {
        .active = false,
        .mask   = 0x00,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "SUBWF",
    .description     = "Subtract W from f",
    .cycles          = 1,
    .status_affected = OP_STATUS_C | OP_STATUS_DC | OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x2,
    .callback        = op_callback_subwf,
    .type            = OP_INSTRUCTION_SUBWF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "SWAPF",
    .description     = "Swap nibbles in f",
    .cycles          = 1,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0xE,
    .callback        = op_callback_swapf,
    .type            = OP_INSTRUCTION_SWAPF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "XORWF",
    .description     = "Exclusive OR W with f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x6,
    .callback        = op_callback_xorwf,
    .type            = OP_INSTRUCTION_XORWF,
    .reg = {
      {
        .active = true,
        .mask   = 0x80,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_D
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "BCF",
    .description     = "Bit Clear f",
    .cycles          = 1,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3C00,
    .shift           = 10,
    .opcode          = 0x4,
    .callback        = op_callback_bcf,
    .type            = OP_INSTRUCTION_BCF,
    .reg = {
      {
        .active = true,
        .mask   = 0x380,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_B
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "BSF",
    .description     = "Bit Set f",
    .cycles          = 1,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3C00,
    .shift           = 10,
    .opcode          = 0x5,
    .callback        = op_callback_bsf,
    .type            = OP_INSTRUCTION_BSF,
    .reg = {
      {
        .active = true,
        .mask   = 0x380,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_B
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "BTFSC",
    .description     = "Bit Test f. Skip if Clear",
    .cycles          = 2,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3C00,
    .shift           = 10,
    .opcode          = 0x6,
    .callback        = op_callback_btfsc,
    .type            = OP_INSTRUCTION_BTFSC,
    .reg = {
      {
        .active = true,
        .mask   = 0x380,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_B
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "BTFSS",
    .description     = "Bit Test f. Skip if Set",
    .cycles          = 2,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3C00,
    .shift           = 10,
    .opcode          = 0x7,
    .callback        = op_callback_btfss,
    .type            = OP_INSTRUCTION_BTFSS,
    .reg = {
      {
        .active = true,
        .mask   = 0x380,
        .shift  = 0x7,
        .display= OP_NUMERIC_DISPLAY_DEC8,
        .reg    = OP_REGISTER_B
      },
      {
        .active = true,
        .mask   = 0x7F,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_F
      },
    }
  },
  {
    .name            = "ADDLW",
    .description     = "Add literal and w",
    .cycles          = 1,
    .status_affected = OP_STATUS_C | OP_STATUS_DC | OP_STATUS_Z,
    .mask            = 0x3E00,
    .shift           = 9,
    .opcode          = 0x1F,
    .callback        = op_callback_addlw,
    .type            = OP_INSTRUCTION_ADDLW,
    .reg = {
      {
        .active = true,
        .mask   = 0xFF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "ANDLW",
    .description     = "AND literal and w",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x39,
    .callback        = op_callback_andlw,
    .type            = OP_INSTRUCTION_ANDLW,
    .reg = {
      {
        .active = true,
        .mask   = 0xFF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "CALL",
    .description     = "Call subroutine",
    .cycles          = 2,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F80,
    .shift           = 11,
    .opcode          = 0x4,
    .callback        = op_callback_call,
    .type            = OP_INSTRUCTION_CALL,
    .reg = {
      {
        .active = true,
        .mask   = 0x7FF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX16,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "CLRWDT",
    .description     = "Clear Watchdog Timer",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3FFF,
    .shift           = 0,
    .opcode          = 0x64,
    .callback        = op_callback_clrwdt,
    .type            = OP_INSTRUCTION_CLRWDT,
    .reg = {
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "GOTO",
    .description     = "Go to address",
    .cycles          = 2,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F80,
    .shift           = 11,
    .opcode          = 0x5,
    .callback        = op_callback_goto,
    .type            = OP_INSTRUCTION_GOTO,
    .reg = {
      {
        .active = true,
        .mask   = 0x7FF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX16,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "IORLW",
    .description     = "Inclusive OR literal with w",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x38,
    .callback        = op_callback_iorlw,
    .type            = OP_INSTRUCTION_IORLW,
    .reg = {
      {
        .active = true,
        .mask   = 0xFF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "MOVLW",
    .description     = "Move literal to w",
    .cycles          = 1,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3C00,
    .shift           = 10,
    .opcode          = 0xC,
    .callback        = op_callback_movlw,
    .type            = OP_INSTRUCTION_MOVLW,
    .reg = {
      {
        .active = true,
        .mask   = 0xFF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "RETFIE",
    .description     = "Return from interrupt",
    .cycles          = 2,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3FFF,
    .shift           = 0,
    .opcode          = 0x9,
    .callback        = op_callback_retfie,
    .type            = OP_INSTRUCTION_RETFIE,
    .reg = {
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "RETLW",
    .description     = "Return with literal in W",
    .cycles          = 2,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3C00,
    .shift           = 10,
    .opcode          = 0xD,
    .callback        = op_callback_retlw,
    .type            = OP_INSTRUCTION_RETLW,
    .reg = {
      {
        .active = true,
        .mask   = 0xFF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "RETURN",
    .description     = "Return from subroutine",
    .cycles          = 2,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3FFF,
    .shift           = 0,
    .opcode          = 0x8,
    .callback        = op_callback_return,
    .type            = OP_INSTRUCTION_RETURN,
    .reg = {
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "SLEEP",
    .description     = "Go to standby mode",
    .cycles          = 1,
    .status_affected = OP_STATUS_NONE,
    .mask            = 0x3FFF,
    .shift           = 0,
    .opcode          = 0x63,
    .callback        = op_callback_sleep,
    .type            = OP_INSTRUCTION_SLEEP,
    .reg = {
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "SUBLW",
    .description     = "Subtract W from literal",
    .cycles          = 1,
    .status_affected = OP_STATUS_C | OP_STATUS_DC | OP_STATUS_Z,
    .mask            = 0x3E00,
    .shift           = 9,
    .opcode          = 0x1E,
    .callback        = op_callback_sublw,
    .type            = OP_INSTRUCTION_SUBLW,
    .reg = {
      {
        .active = true,
        .mask   = 0xFF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
  {
    .name            = "XORLW",
    .description     = "Exclusive OR literal with W",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x3A,
    .callback        = op_callback_xorlw,
    .type            = OP_INSTRUCTION_XORLW,
    .reg = {
      {
        .active = true,
        .mask   = 0xFF,
        .shift  = 0x0,
        .display= OP_NUMERIC_DISPLAY_HEX8,
        .reg    = OP_REGISTER_K
      },
      {
        .active = false,
        .mask   = 0x0,
        .shift  = 0x0,
        .reg    = OP_REGISTER_NONE
      },
    }
  },
};

