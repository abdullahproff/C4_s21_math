#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

START_TEST(zero) {
  double x = 0.0;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_zero) {
  double x = +0.0;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_zero) {
  double x = -0.0;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_x) {
  double x = +1874.3718;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_x) {
  double x = -12828.18282;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_S21_MAX_DOUBLE) {
  double x = +S21_MAX_DOUBLE;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_S21_MAX_DOUBLE) {
  double x = -S21_MAX_DOUBLE;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_dbl_min) {
  double x = +DBL_MIN;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_dbl_min) {
  double x = -DBL_MIN;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_inf) {
  double x = +S21_INFINITY;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_inf) {
  double x = -S21_INFINITY;
  long double ret;
  long double ret21;

  ret = fabs(x);
  ret21 = s21_fabs(x);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

Suite *suite_s21_fabs(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_fabs");
  tc = tcase_create("s21_fabs tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, positive_zero);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, positive_x);
    tcase_add_test(tc, negative_x);
    tcase_add_test(tc, positive_S21_MAX_DOUBLE);
    tcase_add_test(tc, negative_S21_MAX_DOUBLE);
    tcase_add_test(tc, positive_dbl_min);
    tcase_add_test(tc, negative_dbl_min);
    tcase_add_test(tc, positive_inf);
    tcase_add_test(tc, negative_inf);
    suite_add_tcase(s, tc);
  }

  return (s);
}
