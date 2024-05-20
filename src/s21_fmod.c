#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (s21_isnan(x)) {
    result = x;
  } else if (s21_isnan(y)) {
    result = y;
  } else if (s21_isinf(x)) {
    result = -S21_NAN;
  } else if (s21_isinf(y)) {
    result = x;
  } else if (y == 0.0) {
    result = S21_NAN;
  } else if (x == 0.0) {
    result = x;
  } else {
    result = (x - s21_trunc(x / y) * y);
  }
  return result;
}
