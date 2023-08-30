
/*!
\file
\brief File with core functions definition
*/

#include "TXLib.h"
#include <stdio.h>
#include <assert.h>
#include "core_functions.h"
#include "testing_mode.h"
#include "assertion.h"



void normal_mode()
    {
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    enum SOLUTIONS solutions = DEFAULT_VALUE;
    enum RESULT result = UNSUCCESS;
    if (input_coefficients(&a, &b, &c, &result)== NOT_ERROR)
        {
        if (solver_function(&solutions, a, b, c, &x1, &x2) == NOT_ERROR)
            output_answer(solutions, x1, x2);

        }
    }



ERRORS solver_function(enum SOLUTIONS *solutions, double a, double b, double c, double *x1, double *x2)
    {
    cooler_assert(!isfinite(a), NAN_ERROR);
    cooler_assert(!isfinite(b), NAN_ERROR);
    cooler_assert(!isfinite(c), NAN_ERROR);

    cooler_assert(x1 == NULL, NULL_ERROR);
    cooler_assert(x2 == NULL, NULL_ERROR);
    cooler_assert(solutions == NULL, NULL_ERROR);

    cooler_assert(x1 == x2, POINTER_MATCHING);
    cooler_assert((SOLUTIONS*)x1 == solutions, POINTER_MATCHING);
    cooler_assert((SOLUTIONS*)x2 == solutions, POINTER_MATCHING);

    bool result_of_compare = NAN;

    if (comparison_with_eps(a, &result_of_compare) == NOT_ERROR)
        {
        if (result_of_compare)
            solve_linear(solutions, b, c, x1);
        else
            solve_quadratic(solutions, a, b, c, x1, x2);
        }
    return NOT_ERROR;
    }

ERRORS input_coefficients(double *a, double *b, double *c, enum RESULT *result)
    {

    cooler_assert(a == NULL, NULL_ERROR);
    cooler_assert(b == NULL, NULL_ERROR);
    cooler_assert(c == NULL, NULL_ERROR);
    cooler_assert(result == NULL, NULL_ERROR);

    cooler_assert(a == b, POINTER_MATCHING);
    cooler_assert(a == c, POINTER_MATCHING);
    cooler_assert(b == c, POINTER_MATCHING);

    cooler_assert((RESULT*)a == result, POINTER_MATCHING);
    cooler_assert((RESULT*)b == result, POINTER_MATCHING);
    cooler_assert((RESULT*)c == result, POINTER_MATCHING);

    printf("Enter the coefficients of the equation a, b, c: ");
    int coefficients = -1;
    while ((coefficients = scanf("%lf %lf %lf", a, b, c)) != 3)
        {
        if (coefficients == EOF)
            {
            printf("End of file! Input is finished\n");
            *result = UNSUCCESS;
            return NOT_ERROR;
            }

        else
            {
            clear_input();
            printf("ERROR! Check the values and enter the numbers again: ");
            }

        }
    *result = SUCCESS;
    return NOT_ERROR;

    }


ERRORS solve_linear(enum SOLUTIONS *solutions, double b, double c, double *x1)
    {

    cooler_assert(!isfinite(b), NAN_ERROR);
    cooler_assert(!isfinite(c), NAN_ERROR);

    cooler_assert(x1 == NULL, NULL_ERROR);
    cooler_assert(solutions == NULL, NULL_ERROR);
    cooler_assert((SOLUTIONS*)x1 == solutions, POINTER_MATCHING);

    bool compare_b_with_eps = NAN;
    bool compare_c_with_eps = NAN;
    if (comparison_with_eps(b, &compare_b_with_eps) == NOT_ERROR && comparison_with_eps(b, &compare_b_with_eps) == NOT_ERROR)
        {

        if (compare_b_with_eps)
            {
            if (compare_c_with_eps)
                *solutions = INFINITY_SOLUTIONS;
            else
                *solutions = NO_SOLUTIONS;
            }
        else
            {
            *x1 = -c/b;
            *solutions = ONE_SOLUTION;
            }
        }
    return NOT_ERROR;
    }

ERRORS solve_quadratic(enum SOLUTIONS *solutions, double a, double b, double c, double *x1, double *x2)
    {

    cooler_assert(!isfinite(a), NAN_ERROR);
    cooler_assert(!isfinite(b), NAN_ERROR);
    cooler_assert(!isfinite(c), NAN_ERROR);

    cooler_assert(x1 == NULL, NULL_ERROR);
    cooler_assert(x1 == NULL, NULL_ERROR);
    cooler_assert(x1 == x2, POINTER_MATCHING);

    double D = b * b - 4 * a * c;
    bool compare_D_with_eps = NAN;
    if (comparison_with_eps(D, &compare_D_with_eps) == NOT_ERROR)
        {
        if (D < 0)
            *solutions = NO_SOLUTIONS;
        else if (compare_D_with_eps)
            {
            *x1 = -b/(2*a);
            *solutions = ONE_SOLUTION;
            }
        else
            {
            double sqrtD = sqrt(D);
            *x1 = double((-1 * b - sqrtD)/(2*a));
            *x2 = double((-1 * b + sqrtD)/(2*a));
            *solutions = TWO_SOLUTIONS;
            }
        }

    return NOT_ERROR;
}

ERRORS output_answer(enum SOLUTIONS solutions, double x1, double x2)
    {
    if (solutions == ONE_SOLUTION)
        {
        cooler_assert(!isfinite(x1), NAN_ERROR);
        }
    else if (solutions == TWO_SOLUTIONS)
        {
        cooler_assert(!isfinite(x1), NAN_ERROR);
        cooler_assert(!isfinite(x2), NAN_ERROR);
        }
    else
        {
        }
    cooler_assert(!isfinite(solutions), NAN_ERROR);

    switch(solutions)
        {
        case NO_SOLUTIONS:
            printf("There are no solutions\n");
            break;

        case INFINITY_SOLUTIONS:
            printf("Infinite solutions\n");
            break;

        case ONE_SOLUTION:
            printf("The only solution:  %lf\n", x1);
            break;

        case TWO_SOLUTIONS:
            printf("Two different solutions: %lf  %lf\n", x1, x2);
            break;
        case DEFAULT_VALUE:
            break;

        default:
            break;
        }
    return NOT_ERROR;
    }


ERRORS comparison_two_doubles(double number1, double number2, bool *result_of_compare)
    {
    cooler_assert(!isfinite(number1), NAN_ERROR);
    cooler_assert(!isfinite(number2), NAN_ERROR);

    *result_of_compare =  (fabs(number1 - number2) < eps);
    return NOT_ERROR;
    }


ERRORS comparison_with_eps(double number, bool *result_of_compare)
    {
    cooler_assert(!isfinite(number), NAN_ERROR);

    *result_of_compare = (fabs(number) < eps);
    return NOT_ERROR;
    }


void clear_input()
    {
    int c = getchar();
    while (c = getchar() != '\n' && c != EOF)
        ;
    }


void print_main_information()
    {
    set_colour(FOREGROUND_BLUE);
    printf("# Square equation solver\n"
           "# Version 1.4 (c) SHD, 2023\n\n");
    set_colour(FOREGROUND_GREY);
    }


void set_colour(short unsigned int wished_colour)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wished_colour);
    }


