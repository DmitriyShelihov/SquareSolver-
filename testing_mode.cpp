
#include "core_functions.h"
#include "testing_mode.h"
#include "assertion.h"
#include "TXLib.h"
#include <stdio.h>
#include <assert.h>


/*!
\file
\brief File with testing functions definition
*/

ERRORS testing_mode()
    {
    int nsuccessful_tests = 0;
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    int nsolutions_in_test = NAN;
    int ntests = NAN;
    FILE* testing_file = fopen("Tests.txt", "r");

    cooler_assert(testing_file == NULL, FILE_NOT_FOUND);

    for (ntests = 1; ((fscanf(testing_file, " %lf %lf %lf %d ", &a, &b, &c, &nsolutions_in_test)) != EOF);++ntests)
        {

        if (read_test_data(ntests, (SOLUTIONS)nsolutions_in_test, testing_file, &x1, &x2) == NOT_ERROR)
            {
            bool is_test_successful = NAN;

            if (test_one(a, b, c, x1, x2, nsolutions_in_test, &is_test_successful) == NOT_ERROR)
                {
                nsuccessful_tests += is_test_successful;
                }

            }

        }
    fclose(testing_file);

    if (output_the_tests_result(nsuccessful_tests, ntests) == NOT_ERROR)
        {
        }

    return NOT_ERROR;

    }



ERRORS output_the_tests_result(int nsuccessful_tests,int ntests)
    {
    cooler_assert(!isfinite(nsuccessful_tests), NAN_ERROR);
    cooler_assert(!isfinite(ntests), NAN_ERROR);

    printf("%d%% of tests completed\n",int((ntests/double(ntests)) * 100));

    return NOT_ERROR;
    }



ERRORS test_one(double a, double b, double c, double x1_ref, double x2_ref, int nsolutions_in_test, bool *is_test_successful )
    {
    cooler_assert(!isfinite(a), NAN_ERROR);
    cooler_assert(!isfinite(b), NAN_ERROR);
    cooler_assert(!isfinite(c), NAN_ERROR);
    cooler_assert(!isfinite(x1_ref), NAN_ERROR);
    cooler_assert(!isfinite(x2_ref), NAN_ERROR);
    cooler_assert(!isfinite(nsolutions_in_test), NAN_ERROR);
    cooler_assert(is_test_successful == NULL, NULL_ERROR);

    double x1 = NAN, x2 = NAN;
    enum SOLUTIONS solutions = DEFAULT_VALUE;
    solver_function(&solutions, a, b, c, &x1, &x2);
    bool is_testing_successful = NAN;
    if (output_test_answer(x1, x1_ref, x2, x2_ref, nsolutions_in_test, solutions, &is_testing_successful) == NOT_ERROR)
        {
        if (is_testing_successful)
            *is_test_successful = TEST_PASSED;
        else
            *is_test_successful = TEST_FAILED;
        }

    return NOT_ERROR;
    }


ERRORS compare_test_answer(enum SOLUTIONS solutions, int nsolutions_in_test, double x1, double x1_ref, double x2, double x2_ref, IS_TEST *is_test_passed)
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
        ;
    cooler_assert(!isfinite(solutions), NAN_ERROR);
    cooler_assert(!isfinite(nsolutions_in_test), NAN_ERROR);
    cooler_assert(!isfinite(x1_ref), NAN_ERROR);
    cooler_assert(!isfinite(x2_ref), NAN_ERROR);
    cooler_assert(is_test_passed == NULL, NULL_ERROR);

    if (solutions == (SOLUTIONS)nsolutions_in_test)
        {
        bool compare_x1_with_x1_ref = -1;
        bool compare_x2_with_x2_ref = -1;
        if (solutions == ONE_SOLUTION)
            {
            compare_x1_with_x1_ref = comparison_two_doubles(x1, x1_ref, &compare_x1_with_x1_ref);
            if (compare_x1_with_x1_ref)
                *is_test_passed = TEST_PASSED;
            }

        if (solutions == TWO_SOLUTIONS)
            {
            compare_x1_with_x1_ref = comparison_two_doubles(x1, x1_ref, &compare_x1_with_x1_ref);
            compare_x2_with_x2_ref = comparison_two_doubles(x2, x2_ref, &compare_x2_with_x2_ref);
            if (compare_x1_with_x1_ref && compare_x2_with_x2_ref)
                *is_test_passed = TEST_PASSED;
            }

        if (solutions == NO_SOLUTIONS || solutions == INFINITY_SOLUTIONS)
            *is_test_passed = TEST_PASSED;

        }
    if (*is_test_passed != TEST_PASSED)
        *is_test_passed = TEST_FAILED;

    return NOT_ERROR;
    }

ERRORS output_test_answer(double x1, double x1_ref, double x2, double x2_ref, int nsolutions_in_test, enum SOLUTIONS solutions, bool *is_testing_successful)
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
        ;
    cooler_assert(!isfinite(x1_ref), NAN_ERROR);

    cooler_assert(!isfinite(x2_ref), NAN_ERROR);
    cooler_assert(!isfinite(nsolutions_in_test), NAN_ERROR);
    cooler_assert(!isfinite(solutions), NAN_ERROR);
    cooler_assert(is_testing_successful == NULL, NULL_ERROR);

    enum IS_TEST is_test_passed = DEFAULT_VALUE_TEST;
    if (compare_test_answer(solutions, nsolutions_in_test, x1, x1_ref, x2, x2_ref, &is_test_passed) == NOT_ERROR)
        {
        if (is_test_passed == TEST_PASSED)
            *is_testing_successful = true;
        else
            *is_testing_successful = false;

        if (output_solution(is_test_passed, x1, x2, x1_ref, x2_ref, solutions) == NOT_ERROR)
            ;

        }

    return NOT_ERROR;
    }

ERRORS output_solution(enum IS_TEST is_test_passed, double x1, double x2, double x1_ref, double x2_ref, enum SOLUTIONS solutions)
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
    cooler_assert(!isfinite(is_test_passed), NAN_ERROR);
    cooler_assert(!isfinite(x1_ref), NAN_ERROR);
    cooler_assert(!isfinite(x2_ref), NAN_ERROR);

    if (is_test_passed == TEST_PASSED)
        true_answer();
    else if (is_test_passed == TEST_FAILED)
        {
        false_answer();
        printf ("Root values were expected: %lf %lf\nGot the values of the roots: %lf %lf\n\n", x1_ref, x2_ref, x1, x2);
        }
    else
        ;
    return NOT_ERROR;
    }

void true_answer()
    {
    printf("Test passed!\n\n");
    }

void false_answer()
    {
    printf("Test failed!\n");
    }

ERRORS read_test_data(int ntests, enum SOLUTIONS nsolutions_in_test, FILE* testing_file, double *x1, double *x2)
    {
    cooler_assert(!isfinite(ntests), NAN_ERROR);
    cooler_assert(!isfinite(nsolutions_in_test), NAN_ERROR);
    cooler_assert(testing_file == NULL, NULL_ERROR);
    cooler_assert(x1 == NULL, NULL_ERROR);
    cooler_assert(x2 == NULL, NULL_ERROR);
    cooler_assert(x1 == x2, POINTER_MATCHING);

    printf("Test number %d\n", ntests);
    if (nsolutions_in_test == ONE_SOLUTION)
        fscanf(testing_file, "%lf", x1);
    else if(nsolutions_in_test == TWO_SOLUTIONS)
        fscanf(testing_file, "%lf %lf", x1, x2);
    else
        ;
    return NOT_ERROR;
    }










