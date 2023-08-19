#include <stdio.h>
#include <TXLib.h>
#include "other.h"
enum {UNSUCCESS, SUCCESS};
const double eps = 1.0e-19;

int Input(float *a, float *b, float *c){
    printf("Введите коэффициенты уравнения: ");
    int coefficients;
    while((coefficients = scanf("%f %f %f", &(*a), &(*b), &(*c))) != 3){
        if (coefficients == EOF)
            return UNSUCCESS;
        else
            Clean();
            printf("ERROR! Проверьте значения и введите числа заново: ");
    }
    return SUCCESS;

}

void Clean(void){
    while (char c = getchar() != '\n' && c != EOF)
    ;
}

int Solvelinear(float b, float c, float *x1){
    if (fabs(b) < eps && fabs(c) < eps)
        return INFINITYSOLUTIONS;
    else if (fabs(b) < eps && not(fabs(c) < eps))
        return NOSOLUTIONS;
    else
        *x1 = (-1 * c)/b;
        return ONE;
}

int Solvequadratic(float a, float b, float c, float *x1, float *x2){
    float D = b * b - 4 * a * c;
    if (D < 0)
        return NOSOLUTIONS;
    else if (fabs(D) < eps){
        *x1 = (-1 * b)/(2 * a);
        return ONE;
    }
    else{
        double sqrtD = sqrt(D);
        *x1 = float((-1 * b - sqrtD)/(2 * a));
        *x2 = float((-1 * b + sqrtD)/(2 * a));
        return TWO;
    }
}

void Output(enum SOLUTIONS solutions,float x1, float x2){
    switch(solutions){
        case NOSOLUTIONS:
            printf("Решений нет\n");
            break;
        case INFINITYSOLUTIONS:
            printf("Бесконечно много решений\n");
            break;
        case ONE:
            printf("Единственное решение:  %f\n", x1);
            break;
        case TWO:
            printf("Два различных решения: %f  %f\n", x1, x2);
        default:
            break;
    }

}
