#include "s21_math.h"

long double s21_cos(double x) {
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
    a = 1.0;
    k = 1.0;
    result = 0.0;
    while (s21_fabs(a) > eps) {
      result += a;
      a = ((-a) * x * x) / ((k) * (k + 1.0));
      k += 2.0;
    }
  }

  return (result);
}

/*
#include <stdint.h>
long double s21_cos(double x) {
  long double result = 0;
  if (x != x || x == S21_INFINITY || x == -S21_INFINITY) {
    result = S21_NAN;
  } else {
    x = s21_fabs(x);
    if (x > (2.0 * S21_PI)) {
      x = s21_fmod(x, (2.0 * S21_PI));
    }
    if (x == S21_PI) {
      result = -1;
    } else if (x == 0.0) {
      result = 1;
    } else if (x == S21_PI / 2.0 || x == 3.0 * S21_PI / 2.0) {
      result = 0;
    } else if (x == S21_PI / 4.0) {
      result = 1 / s21_sqrt(2);
    } else if (x == S21_PI / 3.0) {
      result = 1.0 / 2.0;
    } else if (x > S21_PI) {
      result = -s21_cos(x - S21_PI);
      //  cos(Pi+a) = cos(Pi)cos(a) - sin(Pi)sin(a) = -cos(a)
    } else if (x > S21_PI / 2.0) {
      result = -s21_sin(x - S21_PI / 2);
      // cos(Pi/2+a) = cos(Pi/2)cos(a) - sin(Pi/2)sin(a) = - sin(a)
    } else if (x > S21_PI / 4) {
      result = s21_sin(S21_PI / 2.0 - x);
      // cos(Pi/2-a) = cos(Pi/2)cos(a) + sin(Pi/2)sin(a) = sin(a)
    } else {
      int k = 0;
      double n = 1.0;
      while (s21_fabs(n) > S21_EPS) {
        result += n;
        k += 1;
        n *= ((-1) * (x * x) / ((2.0 * k) * (2.0 * k - 1.0)));
      }
    }
  }
  return result;
}
*/
