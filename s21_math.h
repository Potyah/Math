#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_PI 3.141592653589793238462643383279502884
#define S21_EXP 2.718281828459045235360287471352662497
#define S21_EPSILON 1e-7
#define S21_LN2 0.693147180559945309417
#define s21_NAN 0.0 / 0.0
#define S21_P_INF 1 / 0.0
#define S21_N_INF 1 / -0.0

long int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
