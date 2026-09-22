#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <linux/limits.h>
#include "../include/libopcode16.h"
#include "../include/libopcodecontext.h"
#include "../include/tool.h"
#include "../include/callback.h"
#include "../include/checked_math.h"
#include "../include/repl.h"

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

op_error_t op_hex_print_stream(const uint8_t *mem, const size_t length, FILE *stream){
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
  uint8_t buffer[OP_BANK_SIZE];
  
  printf("[Memory hex dump]\n");
  for(size_t i = 0; i < OP_BANK_COUNT; i++){
    for(size_t j = 0; j < OP_BANK_SIZE; j++){
      code = op_context_fetch_memory(ctx, i, j, &(buffer[j]));
      assert(code == OP_NO_ERROR);
      if(code != OP_NO_ERROR) goto error;
    }
    
    printf("Bank %zu:\n", i);
    code = op_hex_print_stream(buffer, OP_BANK_SIZE, stdout);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) goto error;
  }
  
  return OP_NO_ERROR;
error:
  printf("[Error printing hex view of memory (code: %u)]\n", code);
  return code;
}

op_error_t op_command_execute_n(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  op_command_argument_t args = {0};
  code = op_command_parser_handler(&args, 1, "EXECUTE", "(E nnnn)");
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) return code;
  
  uint32_t steps = args.argv[0];
  
  printf("[Executing %u steps]\n", steps);

  for(size_t i = 0; i < steps; i++){
    code = op_context_step(ctx);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;
  }
  
  return OP_NO_ERROR;  
}

op_error_t op_command_execute_until_return(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  
  printf("[Executing until CALL, GOTO, RETURN, RETLW or RETFIE]\n");

  while(1){
    uint16_t instruction = ctx->instruction_memory[ctx->pc];
    op_instruction_result_t decoded_instruction = {0};
  
    code = op_decode_instruction(instruction, &decoded_instruction);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;

    code = op_context_step(ctx);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;
    
    if(decoded_instruction.instruction->type == OP_INSTRUCTION_CALL)   break;
    if(decoded_instruction.instruction->type == OP_INSTRUCTION_GOTO)   break;
    if(decoded_instruction.instruction->type == OP_INSTRUCTION_RETURN) break;
    if(decoded_instruction.instruction->type == OP_INSTRUCTION_RETLW)  break;
    if(decoded_instruction.instruction->type == OP_INSTRUCTION_RETFIE) break;
  }
  
  return OP_NO_ERROR;  
}


op_error_t op_save_buffer_to_file_from_fp(const uint8_t *buffer, const size_t length, FILE *fp){
  OP_CHECK_NULLPTR(buffer);
  OP_CHECK_NULLPTR(fp);

  op_error_t code = OP_NO_ERROR;
  assert(length != 0);
  if(length == 0) return OP_ERROR_ZERO_LENGTH;
  
  size_t bytes_written = fwrite(buffer, sizeof(uint8_t), length, fp);
  if(bytes_written != length) goto fwrite_error;
  
  goto cleanup;  

fwrite_error:  
  code = OP_ERROR_FWRITE;
  goto cleanup;
cleanup:
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}

op_error_t op_save_buffer_to_file_from_path(const uint8_t *buffer, const size_t length, const char *path){
  OP_CHECK_NULLPTR(buffer);
  OP_CHECK_NULLPTR(path);

  op_error_t code = OP_NO_ERROR;
  assert(length != 0);
  if(length == 0) return OP_ERROR_ZERO_LENGTH;
  
  FILE *fp = fp = fopen(path, "wb+");
  assert(fp != NULL);
  if(fp == NULL) goto fopen_error;

  code = op_save_buffer_to_file_from_fp(buffer, length, fp);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  
  goto cleanup;  

fopen_error:  
  code = OP_ERROR_FOPEN;
  goto cleanup;
cleanup:
  if(fp != NULL) fclose(fp);
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}

op_error_t op_clear_stream(FILE *stream){
  OP_CHECK_NULLPTR(stream);
  
  do{
    char ch = fgetc(stream);
    if(ch == '\n' || ch == EOF) break;
  } while(1);

  return OP_NO_ERROR;
}

op_error_t op_clear_linebreaks_from_string(char *buffer){
  OP_CHECK_NULLPTR(buffer);
  
  for(size_t i = 0; buffer[i] != '\0'; i++){
    if(buffer[i] == '\n') buffer[i] = '\0';
  }
  
  return OP_NO_ERROR;
}

op_error_t op_get_path_from_stream(const char *hint, FILE *stream, char *path, const size_t length){
  OP_CHECK_NULLPTR(stream);
  OP_CHECK_NULLPTR(path);

  op_error_t code = OP_NO_ERROR;
  assert(length != 0);
  if(length == 0) return OP_ERROR_ZERO_LENGTH;
  
  if(hint != NULL) printf("%s: ", hint);
  
  code = op_clear_stream(stream);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  char *res = fgets(path, length, stream);
  assert(res != NULL);
  if(res == NULL) goto fgets_error;
  path[length - 1] = '\0';

  code = op_clear_linebreaks_from_string(path);;
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  
  goto cleanup;  

fgets_error:  
  code = OP_ERROR_FGETS;
  goto cleanup;
cleanup:
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}

op_error_t op_checked_malloc(void **buffer, const size_t length){
  OP_CHECK_NULLPTR(buffer);

  assert(length != 0);
  if(length == 0) return OP_ERROR_ZERO_LENGTH;
  
  (*buffer) = NULL;
  (*buffer) = (void *)malloc(length);
  assert((*buffer) != NULL);
  if((*buffer) == NULL) return OP_ERROR_MALLOC;

  return OP_NO_ERROR;
}

op_error_t op_uint16_to_bytes(const uint16_t *src, const size_t src_length, uint8_t *dest, const size_t dest_length, size_t *words_copied){
  OP_CHECK_NULLPTR(src);
  OP_CHECK_NULLPTR(dest);

  op_error_t code = OP_NO_ERROR;
  assert(src_length != 0);
  if(src_length == 0) return OP_ERROR_ZERO_LENGTH;
  assert(dest_length != 0);
  if(dest_length == 0) return OP_ERROR_ZERO_LENGTH;

  // Best effort, copy as many words (uint16_t) it can from src to dest
  size_t count = 0;
  for(size_t i = 0; i < src_length; i++){
    uint16_t value = src[i];

    size_t index_dest = 0;
    code = op_checked_size_mul(i, 2, &index_dest);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;

    assert(index_dest < dest_length);
    if(index_dest >= dest_length) break;
    dest[index_dest] = value & 0xFF;
  
    size_t index_dest_2 = 0;
    code = op_checked_size_add(index_dest, 1, &index_dest_2);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;

    assert(index_dest_2 < dest_length);
    if(index_dest_2 >= dest_length) break;
    dest[index_dest_2] = (value >> 8) & 0xFF;

    code = op_checked_size_add(count, 1, &count);
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) return code;
  }

  if(words_copied != NULL){
    (*words_copied) = count;
  }
    
  return OP_NO_ERROR;
}

op_error_t op_command_save_program(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  uint8_t *buffer = NULL;
  printf("[Save instruction memory (FLASH) to file]\n");
  
  size_t total_size = 0;
  code = op_checked_size_mul(OP_INSTRUCTION_MEMORY_SIZE, sizeof(uint16_t), &total_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  code = op_checked_malloc((void **)(&buffer), total_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  size_t words_copied = 0;
  code = op_uint16_to_bytes(ctx->instruction_memory, OP_INSTRUCTION_MEMORY_SIZE, buffer, total_size, &words_copied);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  assert(words_copied == OP_INSTRUCTION_MEMORY_SIZE);
  if(words_copied != OP_INSTRUCTION_MEMORY_SIZE) goto copy_error;
   
  char path[PATH_MAX];
  code = op_get_path_from_stream("Enter file name: ", stdin, path, PATH_MAX);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  code = op_save_buffer_to_file_from_path(buffer, total_size, path);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  
  printf("[Write succeed! %zu bytes writen to %s]\n", total_size, path);

  goto cleanup;  
  
copy_error:
  code = OP_ERROR_COPY;
  goto cleanup;
cleanup:
  if(buffer != NULL) free(buffer);
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}

char op_to_upper(const char c){
  return (c >= 'a' && c <= 'z') ? c & 0xDF : c;
}

op_error_t op_command_save_memory(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  uint8_t *buffer = NULL;
  printf("[Save memory (RAM) to file]\n");
  
  size_t total_size = 0;
  code = op_checked_size_mul(OP_BANK_COUNT, OP_BANK_SIZE, &total_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  code = op_checked_malloc((void **)(&buffer), total_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  for(size_t i = 0; i < total_size; i++){
    size_t bank    = i / OP_BANK_SIZE;
    size_t address = i % OP_BANK_SIZE;

    // Some SFR aren't memory, they are MMIO.
    code = op_context_fetch_memory(ctx, bank, address, &(buffer[i]));
    assert(code == OP_NO_ERROR);
    if(code != OP_NO_ERROR) goto cleanup;
  }
   
  char path[PATH_MAX];
  code = op_get_path_from_stream("Enter file name: ", stdin, path, PATH_MAX);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  code = op_save_buffer_to_file_from_path(buffer, total_size, path);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  
  printf("[Write succeed! %zu bytes writen to %s]\n", total_size, path);

  goto cleanup;  
  
cleanup:
  if(buffer != NULL) free(buffer);
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}

op_error_t op_load_buffer_to_file_from_fp(uint8_t *buffer, const size_t length, FILE *fp, size_t *file_size){
  OP_CHECK_NULLPTR(buffer);
  OP_CHECK_NULLPTR(fp);

  op_error_t code = OP_NO_ERROR;
  assert(length != 0);
  if(length == 0) return OP_ERROR_ZERO_LENGTH;

  size_t size = 0;
  int res = 0;
  
  res = fseek(fp, 0l, SEEK_END);
  assert(res == 0);
  if(res != 0) goto fseek_error;
  
  size = ftell(fp);
  
  res = fseek(fp, 0l, SEEK_SET);
  assert(res == 0);
  if(res != 0) goto fseek_error;

  size = (size >= length) ? length : size;
  assert(size != 0);
  if(size == 0) return OP_ERROR_ZERO_LENGTH;

  if(file_size != NULL) (*file_size) = size;
  
  size_t bytes_written = fread(buffer, sizeof(uint8_t), size, fp);
  if(bytes_written != size) goto fwrite_error;
  
  goto cleanup;  

fseek_error:
  code = OP_ERROR_FSEEK;
  goto cleanup;
fwrite_error:  
  code = OP_ERROR_FWRITE;
  goto cleanup;
cleanup:
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}

op_error_t op_load_buffer_to_file_from_path(uint8_t *buffer, const size_t length, const char *path, size_t *file_size){
  OP_CHECK_NULLPTR(buffer);
  OP_CHECK_NULLPTR(path);

  op_error_t code = OP_NO_ERROR;
  assert(length != 0);
  if(length == 0) return OP_ERROR_ZERO_LENGTH;
  
  FILE *fp = fp = fopen(path, "rb");
  assert(fp != NULL);
  if(fp == NULL) goto fopen_error;

  code = op_load_buffer_to_file_from_fp(buffer, length, fp, file_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  
  goto cleanup;  

fopen_error:  
  code = OP_ERROR_FOPEN;
  goto cleanup;
cleanup:
  if(fp != NULL) fclose(fp);
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}

op_error_t op_bytes_to_uint16(const uint8_t *src, const size_t src_length, uint16_t *dest, const size_t dest_length, size_t *bytes_copied){
  OP_CHECK_NULLPTR(src);
  OP_CHECK_NULLPTR(dest);

  op_error_t code = OP_NO_ERROR;
  assert(src_length != 0);
  if(src_length == 0) return OP_ERROR_ZERO_LENGTH;
  assert(dest_length != 0);
  if(dest_length == 0) return OP_ERROR_ZERO_LENGTH;

  // Best effort, copy as many words (uint16_t) it can from src to dest
  size_t count = 0;
  uint16_t value = 0;
  for(size_t i = 0; i < src_length; i++){
    if((i & 0x1) == 0){
      value = src[i];
    } else {
      value |= ((uint16_t) src[i]) << 8;
      size_t index = i / 2;
      assert(index < dest_length);
      if(index >= dest_length) break;
      dest[index] = value;

      code = op_checked_size_add(count, 2, &count);
      assert(code == OP_NO_ERROR);
      if(code != OP_NO_ERROR) return code;
    }
  }

  if(bytes_copied != NULL){
    (*bytes_copied) = count;
  }
    
  return OP_NO_ERROR;
}

op_error_t op_command_load_program(op_context_t *ctx){
  OP_CHECK_NULLPTR(ctx);

  op_error_t code = OP_NO_ERROR;
  uint8_t *buffer = NULL;
  printf("[Load instruction memory (FLASH) from file]\n");
  
  size_t total_size = 0;
  code = op_checked_size_mul(OP_INSTRUCTION_MEMORY_SIZE, sizeof(uint16_t), &total_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  code = op_checked_malloc((void **)(&buffer), total_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
   
  char path[PATH_MAX];
  code = op_get_path_from_stream("Enter file name: ", stdin, path, PATH_MAX);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;

  size_t file_size = 0;
  code = op_load_buffer_to_file_from_path(buffer, total_size, path, &file_size);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  
  size_t bytes_copied = 0;
  code = op_bytes_to_uint16(buffer, file_size, ctx->instruction_memory, OP_INSTRUCTION_MEMORY_SIZE, &bytes_copied);
  assert(code == OP_NO_ERROR);
  if(code != OP_NO_ERROR) goto cleanup;
  assert(bytes_copied == file_size);
  if(bytes_copied != file_size) goto copy_error;
  
  printf("[Load succeed! %zu bytes loaded from %s]\n", file_size, path);

  goto cleanup;  
  
copy_error:
  code = OP_ERROR_COPY;
  goto cleanup;
cleanup:
  if(buffer != NULL) free(buffer);
  if(code != OP_NO_ERROR) printf("[Error ocurred (code: %u)]\n", code);
  return code;
}
