#include "s21_math.h"
#include <math.h>
#include <check.h>
#include <stdlib.h>

START_TEST(test_s21_math_abs) {
  for (int i = -100.0234562346526; i < 100; i++) {
    ck_assert_uint_eq(abs(i), s21_abs(i));
  }

  ck_assert_uint_eq(abs(s21_NAN), s21_abs(s21_NAN));
  ck_assert_uint_eq(abs(S21_P_INF), s21_abs(S21_P_INF));
  ck_assert_uint_eq(abs(S21_N_INF), s21_abs(S21_N_INF));
  ck_assert_uint_eq(abs(0), s21_abs(0));
}
END_TEST

START_TEST(test_math_ceil) {
  double a = -5.34654675464;
  double b = 5.34654675464;
  double c = 0;
  double d = 2.346435;
  double e = -1e-10;

  ck_assert_uint_eq(ceil(a), s21_ceil(a));
  ck_assert_uint_eq(ceil(b), s21_ceil(b));
  ck_assert_uint_eq(ceil(c), s21_ceil(c));
  ck_assert_uint_eq(ceil(d), s21_ceil(d));
  ck_assert_uint_eq(ceil(e), s21_ceil(e));

  ck_assert_uint_eq(ceil(s21_NAN), s21_ceil(s21_NAN));
  ck_assert_uint_eq(ceil(S21_P_INF), s21_ceil(S21_P_INF));
  ck_assert_uint_eq(ceil(S21_N_INF), s21_ceil(S21_N_INF));
  }
END_TEST

START_TEST(test_math_exp) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 1e-10;
  double e = -1e-10;

  ck_assert_uint_eq(exp(a), s21_exp(a));
  ck_assert_uint_eq(exp(b), s21_exp(b));
  ck_assert_uint_eq(exp(c), s21_exp(c));
  ck_assert_uint_eq(exp(d), s21_exp(d));
  ck_assert_uint_eq(exp(e), s21_exp(e));

  ck_assert_uint_eq(exp(s21_NAN), s21_exp(s21_NAN));
  ck_assert_uint_eq(exp(S21_P_INF), s21_exp(S21_P_INF));
  ck_assert_uint_eq(exp(S21_N_INF), s21_exp(S21_N_INF));
  }
END_TEST

START_TEST(test_math_fabs) {
    for (int i = -100.0234562346526; i < 100; i++) {
      ck_assert_uint_eq(fabs(i), s21_fabs(i));
  }

  ck_assert_uint_eq(fabs(s21_NAN), s21_fabs(s21_NAN));
  ck_assert_uint_eq(fabs(S21_P_INF), s21_fabs(S21_P_INF));
  ck_assert_uint_eq(fabs(S21_N_INF), s21_fabs(S21_N_INF));
  ck_assert_uint_eq(fabs(0), s21_fabs(0));
}
END_TEST

START_TEST(test_math_floor) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = -1e-10;

  ck_assert_uint_eq(floor(a), s21_floor(a));
  ck_assert_uint_eq(floor(b), s21_floor(b));
  ck_assert_uint_eq(floor(c), s21_floor(c));
  ck_assert_uint_eq(floor(d), s21_floor(d));
  ck_assert_uint_eq(floor(e), s21_floor(e));

  ck_assert_uint_eq(floor(s21_NAN), s21_floor(s21_NAN));
  ck_assert_uint_eq(floor(S21_P_INF), s21_floor(S21_P_INF));
  ck_assert_uint_eq(floor(S21_N_INF), s21_floor(S21_N_INF));
  }
END_TEST

START_TEST(test_math_fmod) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = -1e-10;

  ck_assert_uint_eq(fmod(a, b), s21_fmod(a , b));
  ck_assert_uint_eq(fmod(b, c), s21_fmod(b , c));
  ck_assert_uint_eq(fmod(a, c), s21_fmod(a , c));
  ck_assert_uint_eq(fmod(c, d), s21_fmod(c , d));
  ck_assert_uint_eq(fmod(d, e), s21_fmod(d , e));
  ck_assert_uint_eq(fmod(e, d), s21_fmod(e , d));

  ck_assert_uint_eq(fmod(s21_NAN, d), s21_fmod(s21_NAN , d));
//  ck_assert_uint_eq(fmod(e, s21_NAN), s21_fmod(e , s21_NAN));
//  ck_assert_uint_eq(fmod(s21_NAN, s21_NAN), s21_fmod(s21_NAN, s21_NAN));

  ck_assert_uint_eq(fmod(S21_P_INF, d), s21_fmod(S21_P_INF , d));
  ck_assert_uint_eq(fmod(e, S21_P_INF), s21_fmod(e , S21_P_INF));

  ck_assert_uint_eq(fmod(S21_N_INF, d), s21_fmod(S21_N_INF , d));
  ck_assert_uint_eq(fmod(e, S21_N_INF), s21_fmod(e , S21_N_INF));
  }
END_TEST

START_TEST(test_math_log) {
  double a = 1.45;
  double b = 0.346645;
  double f = 0.12345678912;

  ck_assert_uint_eq(log(a), s21_log(a));
  ck_assert_uint_eq(log(b), s21_log(b));
  ck_assert_uint_eq(log(f), s21_log(f));

  ck_assert_uint_eq(log(s21_NAN), s21_log(s21_NAN));
  ck_assert_uint_eq(log(S21_N_INF), s21_log(S21_N_INF));
  ck_assert_uint_eq(log(S21_P_INF), s21_log(S21_P_INF));
  }
END_TEST

START_TEST(test_math_pow) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = -1e-10;

  ck_assert_uint_eq(pow(a, b), s21_pow(a , b));
  ck_assert_uint_eq(pow(b, c), s21_pow(b , c));
  ck_assert_uint_eq(pow(a, c), s21_pow(a , c));
  ck_assert_uint_eq(pow(c, d), s21_pow(c , d));
  ck_assert_uint_eq(pow(d, e), s21_pow(d , e));
  ck_assert_uint_eq(pow(e, d), s21_pow(e , d));

  ck_assert_uint_eq(pow(s21_NAN, d), s21_pow(s21_NAN , d));
  ck_assert_uint_eq(pow(e, s21_NAN), s21_pow(e , s21_NAN));
  ck_assert_uint_eq(pow(s21_NAN, s21_NAN), s21_pow(s21_NAN, s21_NAN));

  ck_assert_uint_eq(pow(S21_P_INF, d), s21_pow(S21_P_INF , d));
  ck_assert_uint_eq(pow(e, S21_P_INF), s21_pow(e , S21_P_INF));

  ck_assert_uint_eq(pow(S21_N_INF, d), s21_pow(S21_N_INF , d));
  ck_assert_uint_eq(pow(e, S21_N_INF), s21_pow(e , S21_N_INF));
  }
END_TEST

START_TEST(test_math_sqrt) {
  double a = 7.346;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = 1e-3;
  double f = 0.123456789;

  ck_assert_uint_eq(sqrt(a), s21_sqrt(a));
  ck_assert_uint_eq(sqrt(b), s21_sqrt(b));
  ck_assert_uint_eq(sqrt(c), s21_sqrt(c));
  ck_assert_uint_eq(sqrt(d), s21_sqrt(d));
  ck_assert_uint_eq(sqrt(e), s21_sqrt(e));
  ck_assert_uint_eq(sqrt(f), s21_sqrt(f));
  ck_assert_uint_eq(sqrt(s21_NAN), s21_sqrt(s21_NAN));
  ck_assert_uint_eq(sqrt(S21_N_INF), s21_sqrt(S21_N_INF));
  ck_assert_uint_eq(sqrt(S21_P_INF), s21_sqrt(S21_P_INF));
  }
END_TEST

START_TEST(test_math_acos) {
  double a = -0.346546754645;
  double b = 0.346546754645;
  double c = 0;
  double d = 0.346435;
  double e = -1e-10;
  double f = 0.123456789;

  ck_assert_uint_eq(acos(a), s21_acos(a));
  ck_assert_uint_eq(acos(b), s21_acos(b));
  ck_assert_uint_eq(acos(c), s21_acos(c));
  ck_assert_uint_eq(acos(d), s21_acos(d));
  ck_assert_uint_eq(acos(e), s21_acos(e));
  ck_assert_uint_eq(acos(f), s21_acos(f));
  ck_assert_uint_eq(acos(s21_NAN), s21_acos(s21_NAN));
  ck_assert_uint_eq(acos(S21_N_INF), s21_acos(S21_N_INF));
  ck_assert_uint_eq(acos(S21_P_INF), s21_acos(S21_P_INF));
  }
END_TEST

START_TEST(test_math_asin) {
  double a = -0.346546754;
  double b = 0.346546754;
  double c = 0;
  double d = 0.346435;
  double e = -1;
  double f = 1;

  ck_assert_uint_eq(asin(a), s21_asin(a));
  ck_assert_uint_eq(asin(b), s21_asin(b));
  ck_assert_uint_eq(asin(c), s21_asin(c));
  ck_assert_uint_eq(asin(d), s21_asin(d));
  ck_assert_uint_eq(asin(e), s21_asin(e));
  ck_assert_uint_eq(asin(f), s21_asin(f));
  ck_assert_uint_eq(asin(s21_NAN), s21_asin(s21_NAN));
  ck_assert_uint_eq(asin(S21_N_INF), s21_asin(S21_N_INF));
  ck_assert_uint_eq(asin(S21_P_INF), s21_asin(S21_P_INF));
  }
END_TEST

START_TEST(test_math_atan) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = -1e-10;
  double f = 0.123456789;

  ck_assert_uint_eq(atan(a), s21_atan(a));
  ck_assert_uint_eq(atan(b), s21_atan(b));
  ck_assert_uint_eq(atan(c), s21_atan(c));
  ck_assert_uint_eq(atan(d), s21_atan(d));
  ck_assert_uint_eq(atan(e), s21_atan(e));
  ck_assert_uint_eq(atan(f), s21_atan(f));
  ck_assert_uint_eq(atan(s21_NAN), s21_atan(s21_NAN));
  ck_assert_uint_eq(atan(S21_N_INF), s21_atan(S21_N_INF));
  ck_assert_uint_eq(atan(S21_P_INF), s21_atan(S21_P_INF));
  }
END_TEST

START_TEST(test_math_cos) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = -1e-10;
  double f = 0.123456789;

  ck_assert_uint_eq(cos(a), s21_cos(a));
  ck_assert_uint_eq(cos(b), s21_cos(b));
  ck_assert_uint_eq(cos(c), s21_cos(c));
  ck_assert_uint_eq(cos(d), s21_cos(d));
  ck_assert_uint_eq(cos(e), s21_cos(e));
  ck_assert_uint_eq(cos(f), s21_cos(f));
  ck_assert_uint_eq(cos(s21_NAN), s21_cos(s21_NAN));
  ck_assert_uint_eq(cos(S21_N_INF), s21_cos(S21_N_INF));
  ck_assert_uint_eq(cos(S21_P_INF), s21_cos(S21_P_INF));
  }
END_TEST

START_TEST(test_math_sin) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = -1;
  double f = 1;

  ck_assert_uint_eq(sin(a), s21_sin(a));
  ck_assert_uint_eq(sin(b), s21_sin(b));
  ck_assert_uint_eq(sin(c), s21_sin(c));
  ck_assert_uint_eq(sin(d), s21_sin(d));
  ck_assert_uint_eq(sin(e), s21_sin(e));
  ck_assert_uint_eq(sin(f), s21_sin(f));
  ck_assert_uint_eq(sin(s21_NAN), s21_sin(s21_NAN));
  ck_assert_uint_eq(sin(S21_N_INF), s21_sin(S21_N_INF));
  ck_assert_uint_eq(sin(S21_P_INF), s21_sin(S21_P_INF));
  }
END_TEST

START_TEST(test_math_tan) {
  double a = -5.346546754645;
  double b = 5.346546754645;
  double c = 0;
  double d = 2.346435;
  double e = -1e-10;
  double f = 0.123456789;

  ck_assert_uint_eq(tan(a), s21_tan(a));
  ck_assert_uint_eq(tan(b), s21_tan(b));
  ck_assert_uint_eq(tan(c), s21_tan(c));
  ck_assert_uint_eq(tan(d), s21_tan(d));
  ck_assert_uint_eq(tan(e), s21_tan(e));
  ck_assert_uint_eq(tan(f), s21_tan(f));
  ck_assert_uint_eq(tan(s21_NAN), s21_tan(s21_NAN));
  ck_assert_uint_eq(tan(S21_N_INF), s21_tan(S21_N_INF));
  ck_assert_uint_eq(tan(S21_P_INF), s21_tan(S21_P_INF));
  }
END_TEST

Suite * s21_math_suite(void) {
  Suite *s;
  TCase *tc_s21_math_abs;
  s = suite_create("s21_math_abs");
  tc_s21_math_abs = tcase_create("math_abs");
  tcase_add_test(tc_s21_math_abs, test_s21_math_abs);
  suite_add_tcase(s, tc_s21_math_abs);

  TCase *tc_math_ceil;
  tc_math_ceil = tcase_create("math_ceil");
  tcase_add_test(tc_math_ceil, test_math_ceil);
  suite_add_tcase(s, tc_math_ceil);

  TCase *tc_math_exp;
  tc_math_exp = tcase_create("math_exp");
  tcase_add_test(tc_math_exp, test_math_exp);
  suite_add_tcase(s, tc_math_exp);

  TCase *tc_math_fabs;
  tc_math_fabs = tcase_create("math_fabs");
  tcase_add_test(tc_math_fabs, test_math_fabs);
  suite_add_tcase(s, tc_math_fabs);

  TCase *tc_math_floor;
  tc_math_floor = tcase_create("math_floor");
  tcase_add_test(tc_math_floor, test_math_floor);
  suite_add_tcase(s, tc_math_floor);

  TCase *tc_math_fmod;
  tc_math_fmod = tcase_create("math_fmod");
  tcase_add_test(tc_math_fmod, test_math_fmod);
  suite_add_tcase(s, tc_math_fmod);

  TCase *tc_math_log;
  tc_math_log = tcase_create("math_log");
  tcase_add_test(tc_math_log, test_math_log);
  suite_add_tcase(s, tc_math_log);

  TCase *tc_math_pow;
  tc_math_pow = tcase_create("math_pow");
  tcase_add_test(tc_math_pow, test_math_pow);
  suite_add_tcase(s, tc_math_pow);

  TCase *tc_math_sqrt;
  tc_math_sqrt = tcase_create("math_sqrt");
  tcase_add_test(tc_math_sqrt, test_math_sqrt);
  suite_add_tcase(s, tc_math_sqrt);

  TCase *tc_math_acos;
  tc_math_acos = tcase_create("math_acos");
  tcase_add_test(tc_math_acos, test_math_acos);
  suite_add_tcase(s, tc_math_acos);

  TCase *tc_math_asin;
  tc_math_asin = tcase_create("math_asin");
  tcase_add_test(tc_math_asin, test_math_asin);
  suite_add_tcase(s, tc_math_asin);

  TCase *tc_math_atan;
  tc_math_atan = tcase_create("math_atan");
  tcase_add_test(tc_math_atan, test_math_atan);
  suite_add_tcase(s, tc_math_atan);

  TCase *tc_math_cos;
  tc_math_cos = tcase_create("math_cos");
  tcase_add_test(tc_math_cos, test_math_cos);
  suite_add_tcase(s, tc_math_cos);

  TCase *tc_math_sin;
  tc_math_sin = tcase_create("math_sin");
  tcase_add_test(tc_math_sin, test_math_sin);
  suite_add_tcase(s, tc_math_sin);

  TCase *tc_math_tan;
  tc_math_tan = tcase_create("math_tan");
  tcase_add_test(tc_math_tan, test_math_tan);
  suite_add_tcase(s, tc_math_tan);

  return s;
}

int main(void) {
//  int number_failed;
  Suite *s;
  SRunner *sr;
  s = s21_math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
//  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return 0;
}
