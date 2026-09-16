#include <stdint.h>
#include <stdbool.h>
#include "../include/libopcode16.h"

const op_instruction_t op_instruction_set[OP_INSTRUCTION_SET_COUNT] = {
  {
    .name            = "ADDWF",
    .description     = "Add W and f",
    .cycles          = 1,
    .status_affected = OP_STATUS_C | OP_STATUS_DC | OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x7,
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
    .name            = "ANDWF",
    .description     = "AND W and f",
    .cycles          = 1,
    .status_affected = OP_STATUS_Z,
    .mask            = 0x3F00,
    .shift           = 8,
    .opcode          = 0x5,
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
    .mask            = 0x3F60,
    .shift           = 0,
    .opcode          = 0x0,
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

