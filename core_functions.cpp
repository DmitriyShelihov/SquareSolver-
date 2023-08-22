/*!
\file
\brief File with functions definition
*/

#include "TXLib.h"
#include <stdio.h>
#include <assert.h>
#include "functions_declaration.h"

void choosing_the_mode()
    {

    #define TEST

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

void testing_mode()  // TODO use different *.cpp file for this function

    {                    // max for function is 80 lines
    FILE* testing_file;
    testing_file = fopen("Tests.txt", "r");

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    double right_answer1 = NAN, right_answer2 = NAN;

    char str[50];

    int number_of_solutions_in_test = NAN;
    int number_of_tests = 0;
    int number_of_error_tests = 0;
    int number_of_successful_tests = 0;
    int number_of_coefficients = NAN;

    enum SOLUTIONS solutions = NO_SOLUTIONS;


    while ((number_of_coefficients = fscanf(testing_file, "%lf %lf %lf", &a, &b, &c)) != EOF)
        {
        fscanf(testing_file, "%d", &number_of_solutions_in_test);
        ++number_of_tests;
        printf("Test number %d\n", number_of_tests);
        if (number_of_coefficients != 3)
            {
            ++number_of_error_tests;
            printf("Введены недопустимые данные!\n\n");
            fgets(str, sizeof(str), testing_file);
            }
        else
            {
            solutions = (SOLUTIONS)controller_function(a, b, c, &x1, &x2);
            printf("Введенные данные: %lf %lf %lf\n", a, b, c);

            if (number_of_solutions_in_test == INFINITY_SOLUTIONS)
                {
                printf("Ответ программы square_solver: ");
                if (solutions == INFINITY_SOLUTIONS)
                    {
                    printf("Бесконечно много решений\n");
                    printf("Правильный ответ: Бесконечно много решений\n");
                    true_answer();
                    ++number_of_successful_tests;
                    }
                else
                    {
                    printf("0-2 решений\n");
                    printf("Правильный ответ: Бесконечно много решений\n");
                    false_answer();
                    }
                }


            else if (solutions == NO_SOLUTIONS)
                {
                printf("Ответ программы square_solver: ");
                if (number_of_solutions_in_test == NO_SOLUTIONS)
                    {
                    printf("Решений нет\n");
                    printf("Правильный ответ: Решений нет\n");
                    true_answer();
                    ++number_of_successful_tests;
                    }

                else if (solutions != NO_SOLUTIONS && number_of_solutions_in_test == NO_SOLUTIONS)
                    {
                    printf(">=1 решения\n");
                    printf("Правильный ответ: Решений нет\n");
                    false_answer();
                    }
                }

            else if (solutions == ONE_SOLUTION && number_of_solutions_in_test == ONE_SOLUTION)
                {

                fscanf(testing_file, "%lf", &right_answer1);
                printf("Ответ программы square_solver: %lf\n", x1);
                printf("Правильный ответ: %lf\n", right_answer1);
                if (comparison_two_doubles(x1, right_answer1))
                    {
                    true_answer();
                    ++number_of_successful_tests;
                    }

                else
                    false_answer();
                }
            else
                {
                fscanf(testing_file, "%lf %lf", &right_answer1, &right_answer2);
                printf("Ответ программы square_solver: %lf %lf\n", x1, x2);
                printf("Правильный ответ: %lf %lf\n", right_answer1, right_answer2);
                if (comparison_two_doubles(x1, right_answer1) && comparison_two_doubles(x2, right_answer2))
                    {
                    true_answer();
                    ++number_of_successful_tests;
                    }
                else
                    false_answer();
                }

            }
        fgets(str, sizeof(str), testing_file);

    }
    fclose(testing_file);
    printf("Выполнено %d%% тестов\n",int((number_of_successful_tests/double(number_of_tests)) * 100));
    printf("Тестов с недопустимыми данными %d%%\n",int((number_of_error_tests/double(number_of_tests)) * 100));
    }


int controller_function(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

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
    return (fabs(number1 - number2) < eps);
    }

bool comparison_with_eps(double number)
    {
    assert(isfinite(number));
    return (fabs(number) < eps);
    }

void clear_input()
    {
    int c = getchar();
    while (c = getchar() != '\n' && c != EOF)
        ;
    }
