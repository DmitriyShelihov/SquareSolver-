
/*!
\file
\brief File with core functions definition
*/
#include "TXLib.h"
#include <stdio.h>
#include <assert.h>
#include "core_functions.h"
#include "testing_mode.h"


void choosing_the_mode()
    {

    #

    #ifndef TEST
        normal_mode();
    #else
        testing_mode();
    #endif
    }

void normal_mode()
    {
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    enum SOLUTIONS solutions = DEFAULT_VALUE;

    if (input_coefficients(&a, &b, &c))
        {
        solutions = (SOLUTIONS)controller_function(a, b, c, &x1, &x2);
        output_answer(solutions, x1, x2);
        }
    }

void true_answer()
    {
    printf("Программа дала верный ответ!\n\n");
    }

void false_answer()
    {
    printf("Программа дала неверный ответ!\n\n");
    }



int controller_function(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a)) ;
    assert(isfinite(b)) ;
    assert(isfinite(c)) ;

    assert(x1 != NULL) ;
    assert(x2 != NULL) ;
    assert(x1 != x2);
    if (!isfinite(a))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (!isfinite(b))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (!isfinite(c))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (x1 == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (x2 == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (x1 == x2)
        call_errors(__LINE__, POINTER_MATCHING, __PRETTY_FUNCTION__, __FILE__);

    enum SOLUTIONS solutions = DEFAULT_VALUE;
    if (comparison_with_eps(a))
        solutions = (SOLUTIONS)solve_linear(b, c, x1);
    else
        solutions = (SOLUTIONS)solve_quadratic(a, b, c, x1, x2);
    return solutions;
}



int input_coefficients(double *a, double *b, double *c)
    {
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    if (a == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (b == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (c == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (a == b)
        call_errors(__LINE__, POINTER_MATCHING, __PRETTY_FUNCTION__, __FILE__);
    if (b == c)
        call_errors(__LINE__, POINTER_MATCHING, __PRETTY_FUNCTION__, __FILE__);
    if (a == c)
        call_errors(__LINE__, POINTER_MATCHING, __PRETTY_FUNCTION__, __FILE__);


    int coefficients = -1;
    printf("Введите коэффициенты уравнения a, b, c: ");

    while((coefficients = scanf("%lf %lf %lf", a, b, c)) != 3)
        {
        if (coefficients == EOF)
            {
            printf("Конец файла! Ввод закончен\n");
            return UNSUCCESS;
            }

        else
            {
            clear_input();
            printf("ERROR! Проверьте значения и введите числа заново: ");
            }

        }
    return SUCCESS;

    }


int solve_linear(double b, double c, double *x1)
    {
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);

    if (!isfinite(b))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (!isfinite(c))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (x1 == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);

    int compare_b_with_eps = comparison_with_eps(b);
    int compare_c_with_eps = comparison_with_eps(c);

    if (compare_b_with_eps)
        {

        if (compare_c_with_eps)
            return INFINITY_SOLUTIONS;
        else
            return NO_SOLUTIONS;
        }

    else

        *x1 = -c/b;
        return ONE_SOLUTION;
    }

int solve_quadratic(double a, double b, double c, double *x1, double *x2)
    {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (!isfinite(a))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (!isfinite(b))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (!isfinite(c))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);

    if (x1 == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (x2 == NULL)
        call_errors(__LINE__, NULL_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (x1 == x2)
        call_errors(__LINE__, POINTER_MATCHING, __PRETTY_FUNCTION__, __FILE__);

    double D = b * b - 4 * a * c;

    if (D < 0)
        return NO_SOLUTIONS;
    else if (comparison_with_eps(D))
        {
        *x1 = -b/(2*a);
        return ONE_SOLUTION;
        }
    else
        {
        double sqrtD = sqrt(D);

        *x1 = double((-1 * b - sqrtD)/(2*a));
        *x2 = double((-1 * b + sqrtD)/(2*a));

        return TWO_SOLUTIONS;
        }
}

void output_answer(enum SOLUTIONS solutions, double x1, double x2)
    {
    assert(x1 != NAN);
    assert(x2 != NAN);
    if (!isfinite(x1))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (!isfinite(x2))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    switch(solutions)
        {
        case NO_SOLUTIONS:
            printf("Решений нет\n");
            break;

        case INFINITY_SOLUTIONS:
            printf("Бесконечно много решений\n");
            break;

        case ONE_SOLUTION:
            printf("Единственное решение:  %lf\n", x1);
            break;

        case TWO_SOLUTIONS:
            printf("Два различных решения: %lf  %lf\n", x1, x2);
            break;
        case DEFAULT_VALUE:
            break;

        default:
            break;
        }

    }


bool comparison_two_doubles(double number1, double number2)
    {

    assert(isfinite(number1));
    assert(isfinite(number2));

    if (!isfinite(number1))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    if (!isfinite(number2))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);

    return (fabs(number1 - number2) < eps);
    }

bool comparison_with_eps(double number)
    {
    assert(isfinite(number));
    if (!isfinite(number))
        call_errors(__LINE__, NAN_ERROR, __PRETTY_FUNCTION__, __FILE__);
    return (fabs(number) < eps);
    }

void clear_input()
    {
    int c = getchar();
    while (c = getchar() != '\n' && c != EOF)
        ;
    }

void call_errors(const int line, enum ERRORS errors, const char* function_name, const char*file_name)
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    printf("ошибка в файле %s в функции %s в %d строке: ", file_name, function_name, line);
    switch (errors)
        {
        case NAN_ERROR:
            printf("не определено значение переменной! (NAN variable)\n");
            break;
        case NULL_ERROR:
            printf("не определен указатель! (NULL pointer)\n");
            break;
        case POINTER_MATCHING:
            printf("совпадение адресов! (pointer = pointer)\n");
            break;
        case FILE_NOT_FOUND:
            printf("не найден файл! (NULL file pointer)\n");
            break;
        default:
            break;
        }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    }


