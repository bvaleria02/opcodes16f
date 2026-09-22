#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <linux/limits.h>
#include "include/libopcode16.h"
#include "include/libopcodecontext.h"
#include "include/tool.h"
#include "include/callback.h"
#include "include/checked_math.h"
#include "include/repl.h"


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

//  instructions[0] = 0x27D5;

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

    switch(op_to_upper(c)){
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
      case 'H':   printf("Help:\n\tL: Print instruction set\n\tK: Clear stdout\n\tS: Step\n\tE nnnn: Step n times\n\tP: toggle print\n\tW: toggle print W register\n\tC: toggle print PC\n\tV: toggle print instruction data\n\tD: toggle print description\n\tQ: quit\n\tR: reset\n\tH: print help\n\tG aaaa: goto (set pc to aaaa)\n\tM b aa vv: move (set memory bank b, address aa to vv)\n\tZ iiii: replace instruction at PC with iiii\n\tI b aa: Add watchpoint for bank b, address aa\n\tO b aa: Remove watchpoint from bank b, address aa\n\tN: Hex print memory\n");
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
                  break;
      case 'E':   code = op_command_execute_n(&ctx);
                  printf(">> ");
                  break;
      case 'Y':   code = op_command_execute_until_return(&ctx);
                  break;
      case '1':   code = op_command_save_program(&ctx);
                  printf(">> ");
                  break;
      case '2':   code = op_command_save_memory(&ctx);
                  printf(">> ");
                  break;
      case '3':   code = op_command_load_program(&ctx);
                  break;
//      case '4':   code = op_command_load_memory(&ctx);
//                  break;
      case 'U':   for(size_t i = 0; i < OP_MAX_VARIABLE_COUNT; i++) cfg.variables[i].active = false;
                  printf("[All watch variables disabled]\n");
                  break;
      case '\n':  printf(">> ");
                  break;                  
    }
  } while(simulate);
  
  (void) argc;
  (void) argv;
  (void) code;
  return 0;
}

