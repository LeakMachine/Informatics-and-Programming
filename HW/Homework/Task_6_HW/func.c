#define _CRT_SECURE_NO_WARNINGS 

#define PI 3.1415926535897931

#include <math.h>
#include "func.h"
#include "main.h"

void funcScanDataMode0() {
    printf("Enter x: ");
    scanf_s("%lf", &x);
    
    do {
        printf("Enter N (from 1 to 1000): ");
        scanf_s("%d", &N);
        if (N < 1 || N > 1000)
            printf("Error. Incorrect value.\n");
    } while (N < 1 || N > 1000);

    do {
        printf("Enter eps (from 0.000001): ");
        scanf_s("%lf", &eps);
        if (eps > 0.000001)
            printf("Error. Incorrect value.\n");
    } while (eps > 0.000001);
}

void funcScanDataMode1() {
    printf("Enter x: ");
    scanf_s("%lf", &x);

    do {
        printf("Enter Nmax (from 1 to 25): ");
        scanf_s("%d", &Nmax);
        if (Nmax < 1 || Nmax > 25)
            printf("Error. Incorrect value.\n");
    } while (Nmax < 1 || Nmax > 25);

    do {
        printf("Enter eps (from 0.000001): ");
        scanf_s("%lf", &eps);
        if (eps > 0.000001)
            printf("Error. Incorrect value.\n");
    } while (eps > 0.000001);
}

long long Fact(int x) {
    if (x < 0) return 0;
    if (x == 1 || x == 0) return 1;
    return x * Fact(x - 1);
}
struct Answer Sin(double x, double etalon, double eps, int N) {
    int i = 0;
    struct Answer result;
    result.f = 0;
    for (i = 1; i < N; i++) {
        result.f += pow(-1, i + 1) * pow(x, 2 * i - 1) / (long double)Fact(2 * i - 1);
        if (fabs(etalon - result.f) < eps) break;
    }
    result.error = fabs(etalon - result.f);
    result.count = i;
    return result;
}
struct Answer Cos(double x, double etalon, double eps, int N) {
    int i = 0;
    struct Answer result;
    result.f = 0;
    for (i = 0; i < N; i++) {
        result.f += pow(-1, i) * pow(x, 2 * i) / (long double)Fact(2 * i);
        if (fabs(etalon - result.f) < eps) break;
    }
    result.error = fabs(etalon - result.f);
    result.count = i;
    return result;
}
struct Answer Exp(double x, double etalon, double eps, int N) {
    int i = 0;
    struct Answer result;
    result.f = 0;
    for (i = 0; i < N; i++) {
        result.f += pow(x, i) / (long double)Fact(i);
        if (fabs(etalon - result.f) < eps) break;
    }
    result.error = fabs(etalon - result.f);
    result.count = i;
    return result;
}
struct Answer Log(double x, double etalon, double eps, int N) {
    int i = 0;
    struct Answer result;
    int ded = 0, inside = 0;
    result.f = 0;
    for (i = 1; i < N; i++) {
        if (x <= 2) {
            result.f += -1 * (pow(-1, i) * pow(x - 1, i) / i);
            if (fabs(etalon - result.f) < eps) break;
        }
        if (x > 2) {
            result.f += -1 * (pow(-1, i) * pow(x - 1, -i) / i);
            if (fabs(etalon - result.f) < eps) break;
        }
    }
    if (x > 2) {
        result.f = log(x - 1) + result.f;
    }
    result.error = fabs(etalon - result.f);
    result.count = i;
    return result;
}
