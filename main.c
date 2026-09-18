#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/libopcode16.h"
#include "include/libopcodecontext.h"
#include "include/tool.h"
#include "include/callback.h"

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

op_error_t callback_print(op_context_t *ctx, op_enriched_instruction_t *enins, const uint16_t address, void *data){
  op_tool_config_t *cfg =  (op_tool_config_t *)data;
  op_error_t code = OP_NO_ERROR;

  if(cfg->print){
    fprintf(stdout, "C:%zu ", ctx->cycle_count);
    code = op_enriched_print_stream(enins, &(ctx->enrichedConfig), stdout);
    if(cfg->print_w) fprintf(stdout, " | W: %02X", ctx->w);

    for(size_t i = 0; i < OP_MAX_VARIABLE_COUNT; i++){
      if(!cfg->variables[i].active) continue;

      uint8_t mem_value = 0;
      code = op_context_fetch_memory(ctx, cfg->variables[i].bank, cfg->variables[i].address, &mem_value);

      printf("\n\tMemory at bank %01X, address %02X: %02X", cfg->variables[i].bank, cfg->variables[i].address, mem_value);
    }
  }
  
  fprintf(stdout, "\n");
  (void) address;
  return code;
}

op_error_t op_command_parser_handler(op_command_argument_t *args, const size_t minargs, const char *name, const char *help){
  OP_CHECK_NULLPTR(args);

  op_error_t code = OP_NO_ERROR;
  
  code = op_parse_command(args);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto error;

  assert(args->isValid == true);
  if(!args->isValid) goto stdin_error;

  assert(args->argc >= minargs);
  if(args->argc < minargs) goto stdin_error;
  
  return OP_NO_ERROR;

stdin_error:
  code = OP_ERROR_STDIN;
  goto error;
error:
  printf("[Error parsing input commands for \"%s\" %s]\n", (name == NULL) ? "Unknwon" : name, (help == NULL) ? "(No help)" : help);
  return code;
}

op_error_t op_command_goto(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  op_command_argument_t args = {0};
  code = op_command_parser_handler(&args, 1, "GOTO", "(G aaaa)");
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  ctx->pc = args.argv[0] & 0xFFFF;
  printf("[PC set to 0x%04x]\n", ctx->pc);
  return OP_NO_ERROR;  
}

op_error_t op_command_move(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  op_command_argument_t args = {0};
  code = op_command_parser_handler(&args, 3, "MOVE", "(M b aa vv)");
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  uint8_t bank_value  = args.argv[0] % OP_BANK_COUNT;
  uint8_t mem_address = args.argv[1] % OP_BANK_SIZE;
  uint8_t  set_value  = args.argv[2] & 0xFF;
                  
  ctx->memory[bank_value][mem_address] = set_value;
  printf("[Set memory bank:%i address:0x%02X to 0x%02X]\n", bank_value, mem_address, ctx->memory[bank_value][mem_address]);                  
  return OP_NO_ERROR;  
}

op_error_t op_command_replace(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  op_command_argument_t args = {0};
  code = op_command_parser_handler(&args, 1, "REPLACE", "(Z iiii)");
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  uint16_t instruction = args.argv[0] & 0x3FFF;
  uint16_t pc = (ctx->pc >= OP_INSTRUCTION_MEMORY_SIZE) ? (OP_INSTRUCTION_MEMORY_SIZE - 1) : ctx->pc;

  op_instruction_result_t decoded_instruction = {0};
  code = op_decode_instruction(instruction, &decoded_instruction);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  op_enriched_instruction_t enriched = {0};
  op_enriched_instruction_config_t config = {
    .showAddress = false,
    .showDescription = false,
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

  uint8_t bank = 0;
  code = op_context_fetch_bank(ctx, &bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;

  code = op_enrich_decode_result(&enriched, &decoded_instruction, pc, bank);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  ctx->instruction_memory[pc] = instruction;
  
  printf("[Set instruction at address=0x%04X to 0x%04X] ", pc, instruction);
  code = op_enriched_print_stream(&enriched, &config, stdout);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  printf("\n");
                  
  return OP_NO_ERROR;  
}

op_error_t op_command_add_watch_variable(op_context_t *ctx, op_tool_config_t *cfg){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(cfg);

  op_error_t code = OP_NO_ERROR;
  
  op_command_argument_t args = {0};
  code = op_command_parser_handler(&args, 2, "ADD WATCH", "(I b aa)");
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  uint8_t bank_value  = args.argv[0] % OP_BANK_COUNT;
  uint8_t mem_address = args.argv[1] % OP_BANK_SIZE;
                  
  code = op_tool_insert_variable(cfg, bank_value, mem_address);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR){
    printf("[Error adding variable watcher (code: %u)]\n", code);
    return code; 
  }
  
  printf("[Enabled memory watcher for bank:%i address:0x%02X]\n", bank_value, mem_address);                  
  return OP_NO_ERROR;  
}

op_error_t op_command_remove_watch_variable(op_context_t *ctx, op_tool_config_t *cfg){
  OP_CHECK_NULLPTR(ctx);
  OP_CHECK_NULLPTR(cfg);

  op_error_t code = OP_NO_ERROR;
  
  op_command_argument_t args = {0};
  code = op_command_parser_handler(&args, 2, "ADD WATCH", "(I b aa)");
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  uint8_t bank_value  = args.argv[0] % OP_BANK_COUNT;
  uint8_t mem_address = args.argv[1] % OP_BANK_SIZE;
                  
  code = op_tool_remove_variable(cfg, bank_value, mem_address);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR){
    printf("[Error removing variable watcher (code: %u)]\n", code);
    return code; 
  }
  
  printf("[Disabled memory watcher for bank:%i address:0x%02X]\n", bank_value, mem_address);                  
  return OP_NO_ERROR;  
}

op_error_t op_hex_print_stream(const uint8_t *mem, const size_t length, FILE *stream ){
  OP_CHECK_NULLPTR(mem);
  OP_CHECK_NULLPTR(stream);

  fprintf(stream, "Address  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F |                 \n");
  fprintf(stream, "----------------------------------------------------------------------------\n");

  for(size_t i = 0; i < length; i++){
    if((i % 0x10) == 0) fprintf(stream, "%08lX |", i);
    fprintf(stream, " %02X", mem[i]);
    if((i % 0x10) == 0xF) fprintf(stream, " | \n");
  }
  fprintf(stream, "\n");
    
  return OP_NO_ERROR;
}

op_error_t op_command_hex_dump(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  printf("[Memory hex dump]\n");
  for(size_t i = 0; i < OP_BANK_COUNT; i++){
    printf("Bank %zu:\n", i);
    code = op_hex_print_stream(ctx->memory[i], OP_BANK_SIZE, stdout);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) goto error;
  }
  
  return OP_NO_ERROR;
error:
  printf("[Error printing hex view of memory (code: %u)]\n", code);
  return code;
}

int main(const int argc, const char **argv){
  op_error_t code = OP_NO_ERROR;
  
  uint16_t instructions[0x2000];
  for(size_t i = 0; i < (main_bin_len / 2); i++){
    instructions[0x7BA + i] = main_bin[2*i] | (((uint16_t)main_bin[2*i + 1]) << 8);
  } 

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

  instructions[0] = 0x27D5;

  op_context_t ctx = {0};
  op_context_init(&ctx, instructions, 0x1000, callback_print, &config);

  op_tool_config_t cfg = {
    .print   = true,
    .print_w = true
  };

  op_context_set_external(&ctx, &cfg);

  char c = 0;
  bool simulate = true;
  printf("[Start simulation. Press H for help]\n>> ");
  
  do {
    c = fgetc(stdin);

    switch(c & 0xDF){
      case 'L':  for(int i = 0; i < OP_INSTRUCTION_SET_COUNT; i++){
                     printf("\t%s, %s\n", op_instruction_set[i].name, op_instruction_set[i].description);
                  }
                  break;
      case 'S':   op_context_step(&ctx);
                  break;
      case 'P':   cfg.print = !(cfg.print);
                  printf("[Master print %s]\n", (cfg.print) ? "enabled" : "disabled" );
                  break;
      case 'K':   printf("\033[2J");
                  break;
      case 'W':   cfg.print_w = !(cfg.print_w);
                  printf("[Print register W %s]\n", (cfg.print_w) ? "enabled" : "disabled" );
                  break;
      case 'Q':   printf("[End simulation]\n");
                  simulate = false;
                  break;
      case 'R':   ctx.pc = 0;
                  printf("[PC reset (set to 0)]\n");
                  break;
      case 'C':   ctx.enrichedConfig.showAddress = !(ctx.enrichedConfig.showAddress);
                  printf("[Print PC %s]\n", (ctx.enrichedConfig.showAddress) ? "enabled" : "disabled" );
                  break;
      case 'V':   ctx.enrichedConfig.showValue = !(ctx.enrichedConfig.showValue);
                  printf("[Print instruction value %s]\n", (ctx.enrichedConfig.showValue) ? "enabled" : "disabled" );
                  break;
      case 'D':   ctx.enrichedConfig.showDescription = !(ctx.enrichedConfig.showDescription);
                  printf("[Print instruction description %s]\n", (ctx.enrichedConfig.showDescription) ? "enabled" : "disabled" );
                  break;
      case 'H':   printf("Help:\n\tL: Print instruction set\n\tK: Clear stdout\n\tS: Step\n\tP: toggle print\n\tW: toggle print W register\n\tC: toggle print PC\n\tV: toggle print instruction data\n\tD: toggle print description\n\tQ: quit\n\tR: reset\n\tH: print help\n\tG aaaa: goto (set pc to aaaa)\n\tM b aa vv: move (set memory bank b, address aa to vv)\n\tZ iiii: replace instruction at PC with iiii\n");
                  break;
      case 'G':   code = op_command_goto(&ctx);
                  printf(">> ");
                  break;     
      case 'M':   code = op_command_move(&ctx);
                  printf(">> ");
                  break;
      case 'Z':   code = op_command_replace(&ctx);
                  printf(">> ");
                  break;
      case 'I':   code = op_command_add_watch_variable(&ctx, &cfg);
                  printf(">> ");
                  break;
      case 'O':   code = op_command_remove_watch_variable(&ctx, &cfg);
                  printf(">> ");
                  break;
      case 'N':   code = op_command_hex_dump(&ctx);
                  printf(">> ");
                  break;
      case 'U':   for(size_t i = 0; i < OP_MAX_VARIABLE_COUNT; i++) cfg.variables[i].active = false;
                  printf("[All watch variables disabled]\n");
                  break;
      case '\n':  printf(">> ");
                  break;
//      case 'V':   code = op_command_view(&ctx, &cfg);
//                  break;                 
                  
    }
  } while(simulate);
  
//  ctx.memory[0][0xC] = 0x10;

  
  (void) argc;
  (void) argv;
  (void) code;
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
