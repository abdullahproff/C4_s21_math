#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(zero) {
  int x = 0;
  int ret;
  int ret21;

  ret = abs(x);
  ret21 = s21_abs(x);
  ck_assert_int_eq(ret, ret21);
}
END_TEST

START_TEST(positive) {
  int x = 123456;
  int ret;
  int ret21;

  ret = abs(x);
  ret21 = s21_abs(x);
  ck_assert_int_eq(ret, ret21);
}
END_TEST

START_TEST(negative) {
  int x = -123456;
  int ret;
  int ret21;

  ret = abs(x);
  ret21 = s21_abs(x);
  ck_assert_int_eq(ret, ret21);
}
END_TEST

START_TEST(int_max) {
  int x = INT_MAX;
  int ret;
  int ret21;

  ret = abs(x);
  ret21 = s21_abs(x);
  ck_assert_int_eq(ret, ret21);
}
END_TEST

START_TEST(int_min) {
  int x = INT_MIN;
  int ret;
  int ret21;

  ret = abs(x);
  ret21 = s21_abs(x);
  ck_assert_int_eq(ret, ret21);
}
END_TEST

Suite *suite_s21_abs(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_abs");
  tc = tcase_create("s21_abs tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, positive);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, int_max);
    tcase_add_test(tc, int_min);
    suite_add_tcase(s, tc);
  }

  return (s);
}
