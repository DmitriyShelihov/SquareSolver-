
#include "core_functions.h"
#include "testing_mode.h"
#include "TXLib.h"
#include <stdio.h>
#include <assert.h>

/*!
\file
\brief File with testing functions definition
*/

void testing_mode()

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
            printf("������� ������������ ������!\n\n");
            fgets(str, sizeof(str), testing_file);
            }
        else
            {
            solutions = (SOLUTIONS)controller_function(a, b, c, &x1, &x2);
            printf("��������� ������: %lf %lf %lf\n", a, b, c);

            if (number_of_solutions_in_test == INFINITY_SOLUTIONS)
                tests_output_case_inf_solutions(solutions, &number_of_successful_tests);

            else if (number_of_solutions_in_test == NO_SOLUTIONS)
                tests_output_case_no_solutions(solutions, &number_of_successful_tests);

            else if (solutions == ONE_SOLUTION && number_of_solutions_in_test == ONE_SOLUTION)
                {
                fscanf(testing_file, "%lf", &right_answer1);
                printf("����� ��������� square_solver: %lf\n", x1);
                printf("���������� �����: %lf\n", right_answer1);
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
                printf("����� ��������� square_solver: %lf %lf\n", x1, x2);
                printf("���������� �����: %lf %lf\n", right_answer1, right_answer2);
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
    printf("��������� %d%% ������\n",int((number_of_successful_tests/double(number_of_tests)) * 100));
    printf("������ � ������������� ������� %d%%\n",int((number_of_error_tests/double(number_of_tests)) * 100));
    }

void tests_output_case_inf_solutions(enum SOLUTIONS solutions,int *number_of_successful_tests)
    {
    printf("����� ��������� square_solver: ");
    if (solutions == INFINITY_SOLUTIONS)
        {
        printf("���������� ����� �������\n");
        printf("���������� �����: ���������� ����� �������\n");
        true_answer();
        ++(*number_of_successful_tests);
        }
    else
        {
        printf("0-2 �������\n");
        printf("���������� �����: ���������� ����� �������\n");
        false_answer();
        }
    }

void tests_output_case_no_solutions(enum SOLUTIONS solutions, int *number_of_successful_tests)
    {
    printf("����� ��������� square_solver: ");
    if (solutions == NO_SOLUTIONS)
        {
        printf("������� ���\n");
        printf("���������� �����: ������� ���\n");
        true_answer();
        ++(*number_of_successful_tests);
        }
    else
        {
        printf("�� 1 �� ������������� �������\n");
        printf("���������� �����: ������� ���\n");
        false_answer();
        }
    }








