#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H

/*!
\file
\brief Header file with function and enum description
*/


/*!
\brief Enum needed to store number of roots
*/

enum SOLUTIONS
    {
    ONE_SOLUTION = 1,           ///< if the equation is linear or square with a discriminant equal to 0.
    NO_SOLUTIONS = 0,           ///< if there are no solutions.
    TWO_SOLUTIONS = 2,          ///< if the equation is square with two different roots.
    INFINITY_SOLUTIONS = 100,   ///< if there are infinitely many solutions.
    DEFAULT_VALUE = -2          ///< if something goes wrong and and the function did not assign any value to the solutions variable.
    };

/*!
\brief Enum needed to store result of the input function
*/

enum RESULT
    {
    UNSUCCESS = 0,  ///< if the user has not entered 3 coefficients.
    SUCCESS = 1     ///< if the user has successfully entered 3 coefficients.
    };

/*!
\brief constants needed compare numbers
*/

const double eps = 1.0e-5; ///< epsilon if a very small fractional number needed to compare floating point numbers

/*!
 \brief a function that compares a with epsilon and starts, depending on this, a function for solving linear
 and quadratic equations.
 \param a - coefficient near x^2 in square equation.
 \param b - coefficient near x in square equation.
 \param ñ - constant in square equation.
 \param *x1 - pointer to the first root of the equation.
 \param *x2 - pointer to the first root of the equation.
 \return solutions - number of equation solutions described in enum SOLUTIONS

*/

int controller_function(double, double, double, double*, double*);

/*!
 \brief a function that takes three coefficients of the equation
 and enters them again if the user makes a mistake.
 \param *a - pointer to the coefficient near x^2 in square equation.
 \param *b - pointer to the coefficient near x in square equation.
 \param *ñ - pointer to the constant in square equation.
 \return SUCCESS - if the input was successful, UNSUCCESS - if the input was unsuccessful.

*/

int input_coefficients(double*, double*, double*);

/*! 
 \brief a function solving a linear quadratic equation.
 \param b - the coefficient near x in square equation.
 \param c - the constant in square equation.
 \param *x1 - pointer to the first root of the equation.
 \return INFINITY_SOLUTIONS - if the equation has infinite solutions, NO_SOLUTIONS - if the equation has no solutions,
 ONE_SOLUTION - if the equation has one solution.

*/

int solve_linear(double, double, double*);

/*!
 \brief a function solving a quadratic equation.
 \param a - coefficient near x^2 in square equation.
 \param b - coefficient near x in square equation.
 \param ñ - constant in square equation.
 \param *x1 - pointer to the first root of the equation.
 \param *x2 - pointer to the second root of the equation.
 \return ONE_SOLUTION - if the equation has one solution, NO_SOLUTIONS - if the equation has no solutions,
 TWO_SOLUTIONS - if the equation has two solutions.

*/

int solve_quadratic(double, double, double, double*, double*);

/*!
 \brief a function that prints the answer depending on the number of solutions.
 \param SOLUTIONS - enum that contains the number of roots.
 \param x1 - the first root of the equation.
 \param x2 - the second root of the equation.

*/



void output_answer(SOLUTIONS, double, double);

/*!
 \brief a function to remove extra characters from the buffer
 if an error occurred while typing.

*/

void clear_input();

/*!
 \brief a function that compares a floating point number with epsilon.
 \param number - the number that is compared.
 \return true - if the number is epsilon, false - if the number in not epsilon;
*/

bool comparison_with_eps(double);

/*!
 \brief a function that compares two floating point numbers.
 \param number1 - the first compared number.
 \param number2 - the second compared number.
 \return true - if the numbers are equal, false - if the numbers are not equal;

*/

bool comparison_two_doubles(double, double);

/*!
 \brief an important function that tests the SquareSolver program on data from a txt file and outputs the test results.

*/


void normal_mode();

/*!
 \brief the function responsible for selecting the test mode: manual or from a file.

*/

void choosing_the_mode();

/*!
 \brief a function that outputs the text about the correct answer.

*/

void true_answer();

/*!
 \brief a function that outputs the text about the incorrect answer.

*/

void false_answer();


#endif
