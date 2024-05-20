#include "s21_math.h"

long double s21_sin(double x) {
  long double result;
  long double k;
  long double a;
  long double eps = 1.0e-16;

  if (s21_isnan(x)) {
    result = x;
  } else if (s21_isinf(x)) {
    result = -S21_NAN;
  } else {
    x = s21_fmod(x, 2.0 * S21_PI);
    if (x > S21_PI) {
      x -= 2.0 * S21_PI;
    } else if (x < -S21_PI) {
      x += 2.0 * S21_PI;
    }
    a = x;
    k = 1.0;
    result = 0.0;
    while (s21_fabs(a) > eps) {
      result += a;
      a = ((-a) * x * x) / ((k + 1.0) * (k + 2.0));
      k += 2.0;
    }
  }

  return (result);
}

/*
#include <stdint.h>
long double s21_sin(double x) {
  long double result = 0;
  int sign = 0;
  if (x != x || x == S21_INFINITY || x == -S21_INFINITY) {
    result = S21_NAN;
  } else {
    union {
      double num;
      struct double_bits {
        uint64_t mantissa : S21_DBL_MANT_BITS_COUNT;
        uint64_t exp : S21_DBL_EXP_BITS_COUNT;
        uint64_t sign : 1;
      } bits;
    } un = {x};
    sign = un.bits.sign;
    x = s21_fabs(x);
    if (x > (2.0 * S21_PI)) {
      x = s21_fmod(x, (2 * S21_PI));
    }
    if (x == S21_PI || x == 0.0) {
      result = 0.0;
    } else if (x == S21_PI / 2.0) {
      result = 1;
    } else if (x == 3.0 * S21_PI / 2.0) {
      result = -1;
    } else if (x == S21_PI / 4) {
      result = 1.0 / s21_sqrt(2);
    } else if (x == S21_PI / 6) {
      result = 1.0 / 2.0;
    } else if (x > S21_PI) {
      result = -s21_sin(x - S21_PI);
      //  sin(Pi+a) = sin(Pi)cos(a) + cos(Pi)sin(a) = -sin(a)
    } else if (x > S21_PI / 2) {
      result = s21_cos(x - S21_PI / 2);
      // sin(Pi/2+a) = sin(Pi/2)cos(a) + cos(Pi/2)sin(a) = cos(a)
    } else if (x > S21_PI / 4) {
      result = s21_cos(S21_PI / 2 - x);
      // sin(Pi/2 - a) = sin(Pi/2)cos(a) - cos(Pi/2)sin(a) = cos(a)
    } else {
      int k = 0;
      long double add = x;
      while (s21_fabs(add) > S21_EPS) {
        result += add;
        k += 1;
        add *= ((-1) * x * x / ((2.0 * k + 1.0) * (2.0 * k)));
      }
    }
  }
  return (sign) ? -result : result;
}
*/
