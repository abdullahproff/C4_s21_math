#include <stdint.h>

#include "s21_math.h"

long double s21_ceil(double x) {
  long double result;
  union {
    double num;
    struct double_bits {
      uint64_t mantissa : S21_DBL_MANT_BITS_COUNT;
      uint64_t exp : S21_DBL_EXP_BITS_COUNT;
      uint64_t sign : 1;
    } bits;
  } un = {x};
  int sign = un.bits.sign;
  int exp = un.bits.exp - S21_DBL_EXP_OFFSET;

  if (exp > S21_DBL_MANT_BITS_COUNT || x == 0.0) {
    result = x;
  } else if (exp < 0) {
    result = sign ? -0.0 : 1.0;
  } else {
    double fractpart = x - (int64_t)x;
    if (fractpart > 0.0) {
      result = x - fractpart + 1;
    } else {
      result = x - fractpart;
    }
  }

  return (result);
}
