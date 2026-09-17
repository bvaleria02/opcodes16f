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

