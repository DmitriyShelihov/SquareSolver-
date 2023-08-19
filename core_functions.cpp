#include <stdio.h>
#include <TXLib.h>
#include <assert.h>
#include "functions_declaration.h"

int controller_function(double a, double b, double c, double *x1, double *x2)
{
    assert(a != NAN );
    assert(b != NAN );
    assert(c != NAN );
    assert(x1 != NULL && x1 != 0 && x1 != x2);
    assert(x2 != NULL && x2 != 0 && x1 != x2);
    enum SOLUTIONS solutions = NO_SOLUTIONS;
    if (comparison_with_eps(a))
        solutions = (SOLUTIONS)solve_linear(b, c, x1);
    else
        solutions = (SOLUTIONS)solve_quadratic(a, b, c, x1, x2);
    return solutions;
}


int input_coefficients(double *a, double *b, double *c){
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    int coefficients = -1;
    printf("Введите коэффициенты уравнения: ");
    while((coefficients = scanf("%lf %lf %lf", a, b, c)) != 3){
        if (coefficients == EOF){
            printf("Конец файла! Ввод закончен\n");
            return UNSUCCESS;
        }
        else{
            clear_input();
            printf("ERROR! Проверьте значения и введите числа заново: ");
        }
    }
    return SUCCESS;

}

int comparison_with_eps(double number)
{
    assert(number != NAN);
    return (fabs(number) < eps);
}

void clear_input(void){
    char c = '0';
    while (c = getchar() != '\n' && c != EOF)
        ;
}

int solve_linear(double b, double c, double *x1){
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 != NULL && x1 != 0);
    int compare_b_with_eps = comparison_with_eps(b);
    int compare_c_with_eps = comparison_with_eps(c);

    if (compare_b_with_eps && compare_c_with_eps)
        return INFINITY_SOLUTIONS;
    else if (compare_b_with_eps && !(compare_c_with_eps))
        return NO_SOLUTIONS;
    else
        *x1 = (-1 * c)/b;
        return ONE;
}

int solve_quadratic(double a, double b, double c, double *x1, double *x2){
    assert(a != NAN);
    assert(b != NAN);
    assert(c != NAN);
    assert(x1 != NULL && x1 != 0 && x1 != x2);
    assert(x2 != NULL && x2 != 0 && x1 != x2);
    double D = b * b - 4 * a * c;
    if (D < 0)
        return NO_SOLUTIONS;
    else if (comparison_with_eps(D)){
        *x1 = (-1 * b)/(2 * a);
        return ONE;
    }
    else{
        double sqrtD = -1.0;
        sqrtD = sqrt(D);
        *x1 = double((-1 * b - sqrtD)/(2 * a));
        *x2 = double((-1 * b + sqrtD)/(2 * a));
        return TWO;
    }
}

void output_answer(enum SOLUTIONS solutions, double x1, double x2){
    assert(x1 != NAN);
    assert(x2 != NAN);
    switch(solutions){
        case NO_SOLUTIONS:
            printf("Решений нет\n");
            break;
        case INFINITY_SOLUTIONS:
            printf("Бесконечно много решений\n");
            break;
        case ONE:
            printf("Единственное решение:  %lf\n", x1);
            break;
        case TWO:
            printf("Два различных решения: %lf  %lf\n", x1, x2);
        default:
            break;
    }

}

