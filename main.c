#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
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
    .simulate = true,
    .print   = true,
    .print_w = true
  };


  uint16_t ext_memory[8192];
  for(size_t i = 0; i < 8192; i++){
    ext_memory[i] = i;
  }

  op_context_replace_instruction_memory(&ctx, ext_memory, 8192, 0xF00);
  
  op_context_set_external(&ctx, &cfg);

  char c = 0;
  printf("[Start simulation. Press H for help]\n>> ");
  
  do {
    if(c == '\n'){
        printf(">> ");
    }
    
    c = fgetc(stdin);
    c = op_to_upper(c);

    if(c == '!'){
        code = op_repl_mnemonic_handler(&ctx, &cfg);
        continue;        
    } else if (c == EOF){
        code = op_command_quit(&ctx, &cfg);        
    }

    bool found = false;
    bool executed = false;
    for(size_t i = 0; i < OP_REPL_MNEMONIC_COUNT; i++){
        if(c != op_repl_mnemonics[i].shortcmd) continue;

        found = true;
        if(op_repl_mnemonics[i].func != NULL){
            code = op_repl_mnemonics[i].func(&ctx, &cfg);
            executed = true;
        }
        
        if(op_repl_mnemonics[i].consumer){
            printf(">> ");
        }
        break;
    }

    if(!found && c != '\n'){
        printf("Unknown command. Press H for help\n");
    }

    if(found && (!executed)){
        printf("Matching key found, but no callback found\nThis is likely a bug.\n");
    }

    if(code != OP_NO_ERROR){
        printf("[Error executing last instruction (code: %u)]\n", code);
    }

  } while(cfg.simulate);
  
  (void) argc;
  (void) argv;
  (void) code;
  return 0;
}

