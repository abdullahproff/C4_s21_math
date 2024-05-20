#include <check.h>
#include <float.h>
#include <math.h>

#include "s21_math.h"

START_TEST(positive_zero) {
  double num = 0.0;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_zero) {
  double num = -0.0;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_049) {
  double num = 0.49;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_049) {
  double num = -0.49;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_05) {
  double num = 0.5;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_05) {
  double num = -0.5;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_dbl_max) {
  double num = +DBL_MAX;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_dbl_max) {
  double num = -DBL_MAX;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_dbl_min) {
  double num = +DBL_MIN;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_dbl_min) {
  double num = -DBL_MIN;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(positive_inf) {
  double num = +INFINITY;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

START_TEST(negative_inf) {
  double num = -INFINITY;
  long double ret;
  long double ret21;

  ret = ceil(num);
  ret21 = s21_ceil(num);
  ck_assert_ldouble_eq(ret, ret21);
}
END_TEST

static double nums[] = {-1.0,
                        +1.0,
                        -FLT_MAX,
                        FLT_MAX,
                        -FLT_MIN,
                        FLT_MIN,
                        -1.2,
                        1.2,
                        -99.99999999,
                        99.99999999,
                        -2,
                        2,
                        -100.0,
                        101.0,
                        -0.005,
                        0.005,
                        -3.00000001,
                        3.00000001,
                        107.8,
                        4.4,
                        -19764.034 - 16.73,
                        -18.24,
                        15.12,
                        -10.000000000008,
                        10.0000000008,
                        -217211262167.2712721721,
                        217211262167.2712721721,
                        -636236326262636236.12721721,
                        636236326262636236.12721721};

static size_t numlen = sizeof(nums) / sizeof(double);

START_TEST(test_nums) {
  long double ret;
  long double ret21;

  for (size_t i = 0; i < numlen; ++i) {
    ret = ceil(nums[i]);
    ret21 = s21_ceil(nums[i]);
    ck_assert_ldouble_eq(ret, ret21);
  }
}
END_TEST

Suite *suite_s21_ceil(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_ceil");
  tc = tcase_create("s21_ceil create");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, positive_zero);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, positive_049);
    tcase_add_test(tc, negative_049);
    tcase_add_test(tc, positive_05);
    tcase_add_test(tc, negative_05);
    tcase_add_test(tc, positive_dbl_max);
    tcase_add_test(tc, negative_dbl_max);
    tcase_add_test(tc, positive_dbl_min);
    tcase_add_test(tc, negative_dbl_min);
    tcase_add_test(tc, positive_inf);
    tcase_add_test(tc, negative_inf);
    tcase_add_test(tc, test_nums);
    suite_add_tcase(s, tc);
  }

  return (s);
}
