#ifndef TESTING_MODE_H
#define TESTING_MODE_H

/*!
\file
\brief Header file with function and enum description
*/



/*!
 \brief an important function that tests the SquareSolver program on data from a txt file and outputs the test results.

*/

void testing_mode();

/*!
 \brief a function that outputs information about the test results if the number of solutions is infinite.

*/

void tests_output_case_inf_solutions(SOLUTIONS, int *);

/*!
 \brief a function that outputs information about the test results if the number of solutions is zero.

*/

void tests_output_case_no_solutions(SOLUTIONS, int *);


#endif

