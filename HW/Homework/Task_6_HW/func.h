#ifndef _FUNC_H
#define _FUNC_H

#define _CRT_SECURE_NO_WARNINGS 

#define PI 3.1415926535897931

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Answer
{
    double f;
    double error;
    int count;
};

long long Fact(int x);
void funcScanDataMode0();
void funcScanDataMode1();

struct Answer Sin(double x, double etalon, double eps, int N);
struct Answer Cos(double x, double etalon, double eps, int N);
struct Answer Exp(double x, double etalon, double eps, int N);
struct Answer Log(double x, double etalon, double eps, int N);

#endif