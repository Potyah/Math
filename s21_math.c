#include "s21_math.h"

long int s21_abs(int x) {
    if (x < 0) {
        x *= -1;
    }

    return (long int) x;
}

long double s21_fabs(double x) {
    if (x < 0 || x == S21_N_INF) {
        x = -x;
    }

    return x;
}

int number_order_bin(double x) {
    int num_order = 0;
    unsigned long int mask = 0x8000000000000000;
    unsigned long int ulx = *((unsigned long int *)&x);

    for (int i = 11; i >= 0; i--, mask /= 2) {
        if (mask & ulx) {
            double rez = 1;

            for (int j = 0; j < i; j++) {
            rez *= 2;
            }

            num_order = num_order + rez;
        }
    }

    num_order = num_order - 1023;

    return num_order;
}

double integer_part(double x) {
    double rez = 0;
    int num_order = number_order_bin(x);

    if (num_order >= 0) {
        double pow = 1;

        for (int i = 0; i < num_order; i++) {
            pow *= 2;
        }

        rez += pow;
        num_order--;
        unsigned long int mask = 0x8000000000000;
        unsigned long int ulx = *((unsigned long int *)&x);

        for (; num_order >= 0 && mask; num_order--, mask /= 2) {
            if (mask & ulx) {
                double pow2 = 1;

                for (int j = 0; j < num_order; j++) {
                    pow2 *= 2;
                }

            rez = rez + pow2;
            }
        }
    }

    return rez;
}

long double s21_ceil(double x) {
    int flag_minus = 1;
    long double rez;

    if (x != x) {
        rez = s21_NAN;
    } else if (x == S21_N_INF) {
        rez = S21_N_INF;
    } else if (x == S21_P_INF) {
        rez = S21_P_INF;
    } else {
        if (x < 0) {
            flag_minus = -1;
            x = s21_fabs(x);
        }
        rez = integer_part(x);

        if (rez < x && flag_minus > 0) {
            rez = rez + 1.0;
        }
    }

    return rez * flag_minus;
}

long double s21_floor(double x) {
    int flag_minus = 1;
    long double rez;

    if (x != x) {
        rez = s21_NAN;
    } else if (x == S21_N_INF) {
        rez = S21_N_INF;
    } else if (x == S21_P_INF) {
        rez = S21_P_INF;
    } else {
        if (x < 0) {
            flag_minus = -1;
            x = s21_fabs(x);
        }

        rez = integer_part(x);

        if (rez < x && flag_minus < 0) {
            rez = rez + 1.0;
        }
    }

    return rez * flag_minus;
}

long double s21_fmod(double x, double y) {
    double rez;

    if (x == S21_P_INF || x == S21_N_INF) {
        rez = s21_NAN;
    } else if (y == S21_P_INF || y == S21_N_INF) {
        rez = x;
    } else {
        int negativ = 1;

        if (x < 0) {
            x = x * -1;
            negativ = -1;
        }

        if (y < 0) {
            y = y * -1;
        }

        rez = x / y;
        double z = integer_part(rez);
        rez = x - (y * z);
        rez = rez * negativ;
    }

    return (long double)rez;
}

long double s21_cos(double x) {
    long double rez = 1;

    if (x != s21_NAN && x != S21_P_INF && x != S21_N_INF) {
        long double s = s21_fmod(x, 2.0L * S21_PI);
        long double step = 1.0L;

        for (int n = 1; n <= 1000000; n++) {
            step *= (-1.0L) * s * s / (2.0L * (double)n) / (2.0L * (double)n - 1.0L);
            rez += step;
        }
    } else {
        rez = s21_NAN;
    }

    return rez;
}

long double s21_sin(double x) {
    long double s = s21_fmod(x, 2.0L * S21_PI);
    long double rez = s;

    if (x != s21_NAN && x != S21_P_INF && x != S21_N_INF) {
        long double step = s;

        for (int n = 1; n <= 1000000; n++) {
            step *= (-1.0L) * s * s / (2.0L * (double)n) / (2.0L * (double)n + 1.0L);
            rez += step;
        }
    } else {
        rez = s21_NAN;
    }

    return rez;
}

long double s21_tan(double x) {
    long double rez = 0.0;
    double pn = - (S21_PI / 2.0);
    double pp = (S21_PI / 2.0);

    if (x == s21_NAN || x == S21_N_INF || x == S21_P_INF) {
        rez = s21_NAN;
    } else if (x == pn) {
        rez = S21_N_INF;
    } else if (x == pp) {
        rez = S21_P_INF;
    } else {
        rez = s21_sin(x) / s21_cos(x);
    }

    return rez;
}

long double s21_asin(double x) {
    long double rez = x;
    if (x > 1 || x < -1 || x != x) {
        rez = s21_NAN;
    } else if (x == 1) {
        rez = S21_PI / 2.0L;
    } else if (x == -1) {
        rez = -S21_PI / 2.0L;
    } else {
        long double step = x;

        for (long long int i = 1; step > S21_EPSILON; i++) {
            step *= ((x * x) * (2 * i - 1) * (2 * i - 1)) / ((2 * i) * (2 * i + 1));
            rez += step;
        }
    }

    return rez;
}

long double s21_acos(double x) {
    return (S21_PI / 2.0L - s21_asin(x));
}

long double s21_atan(double x) {
    long double rez = 0;
    if (x != x) {
        rez = s21_NAN;
    } else if (x == S21_N_INF) {
        rez = -S21_PI / 2;
    } else if (x == S21_P_INF) {
        rez = S21_PI / 2;
    } else if (x < 1.0 && x > -1.0) {
        long double step = s21_fmod(x, 2.0L * S21_PI);
        long long int n = 1l;

        while (s21_fabs(step) > S21_EPSILON) {
            n++;
            rez += step;
            step *= -x * x * (2 * n - 3) / (2 * n - 1.0L);
        }
    } else if ((x >= 1.0 || x <= -1.0) && x != S21_N_INF && x != S21_P_INF) {
        int flag_minus = 1;

        if (x < 0) {
            flag_minus = -1;
            x = s21_fabs(x);
        }

        rez = s21_asin(x / (s21_sqrt(1 + s21_pow(x, 2))));
        rez *= flag_minus;
    }

    return rez;
}

long double s21_log(double x) {
    long double log = 0;

    if (x == 0) {
        log = S21_N_INF;
    } else if (x < 0 || x == s21_NAN) {
        log = s21_NAN;
    } else if (x == S21_P_INF) {
        log = S21_P_INF;
    } else {
        long double log_2 = 0;

        while (x > 1) {
            x /= 2;
            log_2 += S21_LN2;
        }

        while (x * 2 < 1) {
            x *= 2;
            log_2 -= S21_LN2;
        }

        x -= 1;
        long double temp = 1, step = 1;

        for (int i = 1; temp > 1e-200; i++) {
            step *= x;
            temp = step / i * (s21_pow(-1, i - 1));
            log += temp;

            if (temp < 0) temp *= -1;
        }

        log += log_2;
    }

    return log;
}

long double s21_pow(double x, double y) {
    long double pow = 0.0L;

    if (x == 1.0L || y == 0.0L) {
        pow = 1.0L;
    } else if (y ==  s21_NAN || x == s21_NAN) {
        pow = s21_NAN;
    } else if (y == S21_P_INF ||y == S21_N_INF) {
        if (x == -1.0L) {
            pow = 1.0L;
        } else if (x == S21_N_INF) {
            pow = 0.0L;
        } else if (s21_fabs(x) < 1 && y == S21_N_INF) {
            pow = S21_P_INF;
        } else if (s21_fabs(x) > 1 && y == S21_N_INF) {
            pow = +0.0L;
        } else if (s21_fabs(x) < 1 && y == S21_P_INF) {
            pow = +0.0L;
        } else if (s21_fabs(x) > 1 && y == S21_P_INF) {
            pow = S21_P_INF;
        }
    } else if (x == S21_P_INF || x ==S21_N_INF) {
        pow = 0.0L;
    } else if (s21_ceil(y) == y && x < 0) {
        pow = s21_exp(y * s21_log(-x));

        if (1.7e-308 > pow) pow = 0.0L;

        if (s21_fabs(s21_fmod(y, 2)) == 1) pow = -pow;
    } else {
        pow = s21_exp(y * s21_log(x));

        if (1.7e-308 > pow) pow = 0.0L;
    }

    return pow;
}

long double s21_sqrt(double x) {
    long double sqrt = 0;

    if (x == S21_N_INF) {
        sqrt = s21_NAN;
    } else {
        sqrt = s21_pow(x, 0.5);
    }

    return sqrt;
}

long double s21_exp(double x) {
    long double result = 1, temp = 1;
    long double i = 1;
    int is_negative = 0;

    if (x < 0) is_negative = 1;

    x = s21_fabs(x);
 
    while (s21_fabs(result) > S21_EPSILON && temp <= 1.7e308) {
        result *= x / i++;
        temp += result;
    }

    if (is_negative == 1) temp = 1.0 / temp;

    return temp;
}
