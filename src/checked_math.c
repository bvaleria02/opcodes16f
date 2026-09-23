#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../include/libopcode16.h"
#include "../include/checked_math.h"

op_error_t op_checked_size_add(const size_t a, const size_t b, size_t *c){
  OP_CHECK_NULLPTR(c);

  if(a > (SIZE_MAX - b)){
    return OP_ERROR_OVERFLOW;
  }

  (*c) = a + b;

  return OP_NO_ERROR;
}

op_error_t op_checked_size_sub(const size_t a, const size_t b, size_t *c){
  OP_CHECK_NULLPTR(c);

  if(a < b){
    return OP_ERROR_UNDERFLOW;
  }

  (*c) = a - b;

  return OP_NO_ERROR;
}

op_error_t op_checked_size_mul(const size_t a, const size_t b, size_t *c){
  OP_CHECK_NULLPTR(c);

  // Handle zero case to avoid zero div
  if((a == 0) || (b == 0)){
    (*c) = 0;
    return OP_NO_ERROR;
  }

  if(a > (SIZE_MAX / b)){
    return OP_ERROR_OVERFLOW;
  }

  (*c) = a * b;

  return OP_NO_ERROR;
}
