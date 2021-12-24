#define _CRT_SECURE_NO_WARNINGS 

#define PI 3.1415926535897931

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

typedef struct Answer(*Type_Func) (double, double, double, int);
Type_Func func[4];

int main() {

    int proglive = 1;

    func[0] = Sin;
    func[1] = Cos;
    func[2] = Exp;
    func[3] = Log;

    do {
        printf("Enter program's mode 0/1: ");
        scanf_s("%d", &mode);

        switch (mode) {
            case 0: {
                printf("enter the function: 0 - sin, 1 - cos, 2 - exp, 3 - log: ");
                scanf_s("%d", &fun);

                switch (fun) {
                    case 0: {
                        funcScanDataMode0();
                        etalon = sin(x);
                        struct Answer res = func[fun](x, etalon, eps, N);
                        printf("True value: %.12lf\nf(x) = %.12lf\nError: %.12lf\nCount of elements: %d\n", etalon, res.f, res.error, res.count);
                        break;
                    }
                    case 1: {
                        funcScanDataMode0();
                        etalon = cos(x);
                        struct Answer res = func[fun](x, etalon, eps, N);
                        printf("True value: %.12lf\nf(x) = %.12lf\nError: %.12lf\nCount of elements: %d\n", etalon, res.f, res.error, res.count);
                        break;
                    }
                    case 2: {
                        funcScanDataMode0();
                        etalon = exp(x);
                        struct Answer res = func[fun](x, etalon, eps, N);
                        printf("True value: %.12lf\nf(x) = %.12lf\nError: %.12lf\nCount of elements: %d\n", etalon, res.f, res.error, res.count);
                        break;
                    }
                    case 3: {
                        funcScanDataMode0();
                        etalon = log(x);
                        struct Answer res = func[fun](x, etalon, eps, N);
                        printf("True value: %.12lf\nf(x) = %.12lf\nError: %.12lf\nCount of elements: %d\n", etalon, res.f, res.error, res.count);
                        break;
                    }
                    default: {
                        printf("Error, wrong input.");
                        break;
                    }
                }
                break;
            }
            case 1: {
                printf("enter the function: 0 - sin, 1 - cos, 2 - exp, 3 - log: ");
                scanf_s("%d", &fun);

                switch (fun) {
                    case 0: {
                        funcScanDataMode1();
                        for (int j = 1; j <= Nmax; j++) {
                            etalon = sin(x);
                            struct Answer res = func[fun](x, etalon, eps, j);
                            printf("Amount of elements: %d | True value: %.12lf | f(x) = %.12lf | Error: %.12lf\n", j, etalon, res.f, res.error);
                        }
                        break;
                    }
                    case 1: {
                        funcScanDataMode1();
                        for (int j = 1; j <= Nmax; j++) {
                            etalon = cos(x);
                            struct Answer res = func[fun](x, etalon, eps, j);
                            printf("Amount of elements: %d | True value: %.12lf | f(x) = %.12lf | Error: %.12lf\n", j, etalon, res.f, res.error);
                        }
                        break;
                    }
                    case 2: {
                        funcScanDataMode1();
                        for (int j = 1; j <= Nmax; j++) {
                            etalon = exp(x);
                            struct Answer res = func[fun](x, etalon, eps, j);
                            printf("Amount of elements: %d | True value: %.12lf | f(x) = %.12lf | Error: %.12lf\n", j, etalon, res.f, res.error);
                        }
                        break;
                    }
                    case 3: {
                        funcScanDataMode1();
                        for (int j = 1; j <= Nmax; j++) {
                            etalon = log(x);
                            struct Answer res = func[fun](x, etalon, eps, j);
                            printf("Amount of elements: %d | True value: %.12lf | f(x) = %.12lf | Error: %.12lf\n", j, etalon, res.f, res.error);
                        }
                        break;
                    }
                    default: {
                        printf("Error, wrong input.");
                        break;
                    }
                }
                break;
            }
        }
        printf("Would you like to continue? 0/1: ");
        scanf_s("%d", &proglive);
    } while (proglive == 1);

    return 0;
}