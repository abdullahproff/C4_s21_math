#include <stdint.h>

#include "s21_math.h"

long double s21_fabs(double x) {
  union {
    double num;
    struct double_bits {
      uint64_t other : 63;
      uint64_t sign : 1;
    } bits;
  } un = {x};

  un.bits.sign = 0;

  return (un.num);
}
