#ifndef OP_CHECKED_MATH_H
#define OP_CHECKED_MATH_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include "libopcode16.h"

op_error_t op_checked_size_add(const size_t a, const size_t b, size_t *c);
op_error_t op_checked_size_sub(const size_t a, const size_t b, size_t *c);
op_error_t op_checked_size_mul(const size_t a, const size_t b, size_t *c);

#endif //OP_CHECKED_MATH_H
