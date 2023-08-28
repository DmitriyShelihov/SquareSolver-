#ifndef TESTING_MODE_H
#define TESTING_MODE_H

#include <stdio.h>


/*!
\file
\brief Header file with testing_mode function descriptions.
*/

/*!
\brief Enum which is used to store the results of the functions.
*/

enum IS_TEST
    {
    TEST_FAILED = 0,        ///< if the function finished correctly
    TEST_PASSED = 1 ,       ///< if the function finished incorrectly.
    DEFAULT_VALUE_TEST = 2  ///< the value when the function has not yet finished working.
    };


/*!
 \brief an important function that tests the SquareSolver program on data from a txt file and outputs the test results.
 \return NOT_ERROR - if the function has shut down correctly,
         FILE_NOT_FOUND - if there is no file.
*/

ERRORS testing_mode();

/*!
 \brief a function that runs a single test.
 \param a - coefficient near x^2 in square equation.
 \param b - coefficient near x in square equation.
 \param ñ - constant in square equation.
 \param x1_ref - the first root from the test.
 \param x2_ref - the second root from the test.
 \param nsolutions_in_test - the correct number of solutions from the test.
 \param is_test_successful - a pointer that stores the test result.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.
         FILE_NOT_FOUND - if there is no file.


*/

ERRORS test_one(double, double, double, double, double, int, bool *);

/*!
 \brief a function that outputs information about completed tests as a percentage.
 \param nsuccessful_tests - number of successfully completed tests.
 \param ntests - number of tests.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
*/

ERRORS output_the_tests_result(int ,int );


/*!
 \brief a function that outputs the text about the correct answer.

*/

void true_answer();

/*!
 \brief a function that outputs the text about the incorrect answer.

*/

void false_answer();

/*!
 \brief a function that outputs information about the test result.
 \param x1 - the first root of the equation.
 \param x1_ref - the first correct root of the dough.
 \param x2 - the second root of the equation.
 \param x2_ref - the second correct root of the dough.
 \param nsolutions_in_test - the correct number of solutions from the test.
 \param solutions - number of solutions from the program.
 \param is_testing_successful - a pointer that stores the test result.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS output_test_answer(double, double , double, double , int, SOLUTIONS, bool*) ;

/*!
 \brief a function that reads the test file.
 \param ntests - number of tests.
 \param nsolutions_in_test - number of solutions in test.
 \param testing_file - pointer to the test file.
 \param x1 - pointer to the first root.
 \param x2 - pointer to the second root.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/
ERRORS read_test_data(int, SOLUTIONS , FILE* , double*, double*);

/*!
 \brief a function that gives a verdict on the correctness of the test
 \param solutions - the number of solutions received from the solver program.
 \param nsolutions_in_test - correct number of solutions in test.
 \param x1 - the first root.
 \param x2 - the second root.
 \param x1_ref - the first root from the test.
 \param x2_ref - the second root from the test.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS compare_test_answer(SOLUTIONS , int, double, double , double , double, IS_TEST * );

/*!
 \brief a function that prints information about the completion of the test
 \param is_test_passed - stores the test result.
 \param x1 - the first root.
 \param x2 - the second root.
 \param x1_ref - the first root from the test.
 \param x2_ref - the second root from the test.
 \param solutions - the number of solutions received from the solver program.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS output_solution(IS_TEST , double , double , double , double, SOLUTIONS);

#endif

