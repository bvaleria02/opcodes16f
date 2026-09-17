#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "include/libopcode16.h"
#include "include/libopcodecontext.h"

const unsigned char main_bin[] = {
  0xff, 0xff, 0x83, 0x12, 0x03, 0x13, 0xa0, 0x00, 0x0c, 0x1e, 0xc1, 0x2f,
  0xc2, 0x2f, 0xbe, 0x2f, 0x20, 0x08, 0x99, 0x00, 0x08, 0x00, 0x83, 0x16,
  0x03, 0x13, 0x07, 0x17, 0xdf, 0x30, 0x87, 0x05, 0x20, 0x30, 0x98, 0x00,
  0x90, 0x30, 0x83, 0x12, 0x03, 0x13, 0x98, 0x00, 0x1f, 0x30, 0x83, 0x16,
  0x03, 0x13, 0x99, 0x00, 0x08, 0x00, 0x8a, 0x11, 0xc5, 0x27, 0x8a, 0x11,
  0x43, 0x30, 0x8a, 0x11, 0xbb, 0x27, 0x8a, 0x11, 0x68, 0x30, 0x8a, 0x11,
  0xbb, 0x27, 0x8a, 0x11, 0x6f, 0x30, 0x8a, 0x11, 0xbb, 0x27, 0x8a, 0x11,
  0x63, 0x30, 0x8a, 0x11, 0xbb, 0x27, 0x8a, 0x11, 0x6f, 0x30, 0x8a, 0x11,
  0xbb, 0x27, 0x8a, 0x11, 0x62, 0x30, 0x8a, 0x11, 0xbb, 0x27, 0x8a, 0x11,
  0x6f, 0x30, 0x8a, 0x11, 0xbb, 0x27, 0x8a, 0x11, 0x83, 0x16, 0x03, 0x13,
  0x86, 0x01, 0x02, 0x30, 0x83, 0x12, 0x03, 0x13, 0x86, 0x00, 0x8a, 0x11,
  0x04, 0x28, 0x83, 0x01, 0x8a, 0x11, 0xd5, 0x2f, 0xff, 0xff, 0xff, 0xff,
};

const unsigned int main_bin_len = 144;

op_error_t callback_print(op_context_t *ctx, op_enriched_instruction_t *enins, const uint16_t address){
  fprintf(stdout, "\rC:%zu ", ctx->cycle_count);
  op_error_t code = op_enriched_print_stream(enins, &(ctx->enrichedConfig), stdout);
  fprintf(stdout, " | W: %02X", ctx->w);
  (void)fgetc(stdin);
  (void) address;
  return code;
}


int main(const int argc, const char **argv){
  printf("Hola mundo\n");

  for(int i = 0; i < OP_INSTRUCTION_SET_COUNT; i++){
    printf("\t%s, %s\n", op_instruction_set[i].name, op_instruction_set[i].description);
  }

  uint16_t instructions[0x2000];
//  uint16_t instructions[main_bin_len / 2];
  for(size_t i = 0; i < (main_bin_len / 2); i++){
    instructions[0x7BA + i] = main_bin[2*i] | (((uint16_t)main_bin[2*i + 1]) << 8);
  }
  
/*  
  op_instruction_result_t result = {0};

  op_error_t code = op_decode_instruction(instruction, &result);
  printf("Code: %u\n", code);
  
  code = op_print_instruction_result(&result);
  printf("Code: %u\n", code);
    */

  op_enriched_instruction_config_t config = {
    .showAddress = true,
    .showDescription = true,
    .showName = true,
    .showFlagname = true,
    .showValue = true,
    .configB = {
      .showName = true,
      .showValue = true,
      .showRegname = true,
    },
    .configD = {
      .showName = true,
      .showValue = true,
      .showRegname = true,
    },
    .configW = {
      .showName = true,
      .showValue = true,
      .showRegname = true,
    },
    .configK = {
      .showName = true,
      .showValue = true,
      .showRegname = true,
    },
    .configF = {
      .showName = true,
      .showValue = true,
      .showRegname = true,
    },
  };

  printf("aaaa\n");
  instructions[0] = 0x27D5;
  
//  op_enrich_decode_print_array(instructions, 0x1000, &config, 0x0);


  op_context_t ctx = {0};
  op_context_init(&ctx, instructions, 0x1000, callback_print, &config);

  ctx.memory[0][0xC] = 0x10;

  for(size_t i = 0; i < 0x1000; i++){
    op_context_step(&ctx);
  }
  
  (void) argc;
  (void) argv;
  return 0;
}

/*
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#include "include/libopcode16.h"

int main(const int argc, const char **argv) {
    printf("Hola mundo\n");

    for (int i = 0; i < OP_INSTRUCTION_SET_COUNT; i++) {
        printf("\t%s, %s\n",
               op_instruction_set[i].name,
               op_instruction_set[i].description);
    }

    char input[32];

    while (true) {
        printf("\nIngrese una instrucción hexadecimal (q para salir): ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        char *endptr;
        errno = 0;

        unsigned long value = strtoul(input, &endptr, 16);

        if (errno != 0 || endptr == input || value > UINT16_MAX) {
            printf("Código hexadecimal inválido. Debe ser un valor entre 0x0000 y 0xFFFF.\n");
            continue;
        }

        uint16_t instruction = (uint16_t)value;

        op_instruction_result_t result = {0};

        op_error_t code = op_decode_instruction(instruction, &result);

        printf("Code: %u\n", code);

        code = op_print_instruction_result(&result);

        printf("Code: %u\n", code);
    }

    (void) argc;
    (void) argv;

    return 0;
}
*/
