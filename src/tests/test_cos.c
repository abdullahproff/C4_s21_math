#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

static long double eps = 1.0e-6;

START_TEST(zero) {
  double x = 0.0;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(ret_nan1) {
  double x = S21_NAN;
  long double res;

  res = s21_cos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(ret_nan2) {
  double x = S21_INFINITY;
  long double res;

  res = s21_cos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(positive_zero) {
  double x = +0.0;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_zero) {
  double x = -0.0;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

static double nums[] = {-1.0,
                        -1.1,
                        -11.9888,
                        -25.3570,
                        -13.0675,
                        -44.5435,
                        -5.4645,
                        -309457389.324234,
                        -24658936.2347239847,
                        S21_PI,
                        -S21_PI,
                        S21_PI / 2,
                        -S21_PI / 2,
                        3 * S21_PI / 2,
                        -3 * S21_PI / 2,
                        S21_PI / 4,
                        -S21_PI / 4,
                        3 * S21_PI / 4,
                        -3 * S21_PI / 4,
                        S21_PI / 6,
                        -S21_PI / 6,
                        S21_PI / 3,
                        -S21_PI / 3};

static int len_nums = sizeof(nums) / sizeof(double);

START_TEST(nums_set) {
  double x;
  long double ret;
  long double ret21;
  for (int j = 0; j < len_nums; j++) {
    x = nums[j];
    ret = cos(x);
    ret21 = s21_cos(x);
    ck_assert_ldouble_eq_tol(ret, ret21, eps);
  }
}
END_TEST

START_TEST(positive_PI) {
  double x = +S21_PI;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_1_2) {
  double x = +S21_PI / 2;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_2_PI) {
  double x = +S21_PI * 2;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_2_PI_3) {
  double x = +S21_PI * 2 / 3;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_1_4) {
  double x = +S21_PI / 4;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_PI_3_4) {
  double x = +S21_PI * 3 / 4;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_x) {
  double x = -12828.18282;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI) {
  double x = -S21_PI;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_1_2) {
  double x = -S21_PI / 2;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_2_PI) {
  double x = -S21_PI * 2;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_2_PI_3) {
  double x = -S21_PI * 2 / 3;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_1_4) {
  double x = -S21_PI * 4;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_PI_3_4) {
  double x = -S21_PI * 3 / 4;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(positive_dbl_min) {
  double x = +DBL_MIN;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

START_TEST(negative_dbl_min) {
  double x = -DBL_MIN;
  long double ret;
  long double ret21;

  ret = cos(x);
  ret21 = s21_cos(x);
  ck_assert_ldouble_eq_tol(ret, ret21, eps);
}
END_TEST

Suite *suite_s21_cos(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_cos");
  tc = tcase_create("s21_cos tcase");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, ret_nan1);
    tcase_add_test(tc, ret_nan2);
    tcase_add_test(tc, zero);
    tcase_add_test(tc, positive_zero);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, nums_set);
    tcase_add_test(tc, positive_PI);
    tcase_add_test(tc, positive_PI_1_2);
    tcase_add_test(tc, positive_2_PI);
    tcase_add_test(tc, positive_2_PI_3);
    tcase_add_test(tc, positive_PI_1_4);
    tcase_add_test(tc, positive_PI_3_4);
    tcase_add_test(tc, negative_x);
    tcase_add_test(tc, negative_PI);
    tcase_add_test(tc, negative_PI_1_2);
    tcase_add_test(tc, negative_2_PI);
    tcase_add_test(tc, negative_2_PI_3);
    tcase_add_test(tc, negative_PI_1_4);
    tcase_add_test(tc, negative_PI_3_4);
    tcase_add_test(tc, positive_dbl_min);
    tcase_add_test(tc, negative_dbl_min);
    suite_add_tcase(s, tc);
  }

  return (s);
}
