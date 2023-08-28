#ifndef CORE_FUNCTIONS_H
#define CORE_FUNCTIONS_H

/*!
\file
\brief Header file with function and enum description
*/

#define POSITION_IN_CODE __FILE__, __PRETTY_FUNCTION__, __LINE__  ///< a define that combines three position macros in the code

/*!
\brief a define that checks a variable for an error.
*/

#define cooler_assert(condition, error_code)                                                                                  \
        if (condition)                                                                                                        \
            {                                                                                                                 \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);                                         \
            printf ("Assert %s in file %s in %s:%d failed\n", #condition, POSITION_IN_CODE);                                  \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);    \
            call_errors(error_code);                                                                                          \
            return error_code;                                                                                                \
            }

/*!
\brief Enum needed to store code of the error
*/

enum ERRORS
    {
    NAN_ERROR = 0,          ///<if NAN or INFINITE variable was found
    NULL_ERROR = 1,         ///<if NULL pointer was found
    POINTER_MATCHING = 2,   ///<if two equal pointers was found
    FILE_NOT_FOUND = 3,     ///<if there is no file
    NOT_ERROR = 4           ///<if there is no error
    };

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
 \param solutions - pointer to the variable that contains the number of roots obtained from the equation solution function.
 \param a - coefficient near x^2 in square equation.
 \param b - coefficient near x in square equation.
 \param ñ - constant in square equation.
 \param x1 - pointer to the first root of the equation.
 \param x2 - pointer to the first root of the equation.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS solver_function(SOLUTIONS*, double, double, double, double*, double*);

/*!
 \brief a function that takes three coefficients of the equation
 and enters them again if the user makes a mistake.
 \param a - pointer to the coefficient near x^2 in square equation.
 \param b - pointer to the coefficient near x in square equation.
 \param ñ - pointer to the constant in square equation.
 \param result - pointer to the result about entering coefficients
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS input_coefficients(double*, double*, double*,  RESULT *);

/*!
 \brief a function solving a linear quadratic equation.
 \param solutions - variable that contains the number of roots obtained from the equation solution function.
 \param b - the coefficient near x in square equation.
 \param c - the constant in square equation.
 \param x1 - pointer to the first root of the equation.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS solve_linear(SOLUTIONS*, double, double, double*);

/*!
 \brief a function solving a quadratic equation.
 \param solutions - variable that contains the number of roots obtained from the equation solution function.
 \param a - coefficient near x^2 in square equation.
 \param b - coefficient near x in square equation.
 \param ñ - constant in square equation.
 \param x1 - pointer to the first root of the equation.
 \param x2 - pointer to the second root of the equation.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS solve_quadratic(SOLUTIONS*, double, double, double, double*, double*);

/*!
 \brief a function that prints the answer depending on the number of solutions.
 \param solutions - variable that contains the number of roots obtained from the equation solution function.
 \param x1 - the first root of the equation.
 \param x2 - the second root of the equation.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.
*/



ERRORS output_answer(SOLUTIONS, double, double);

/*!
 \brief a function to remove extra characters from the buffer
 if an error occurred while typing.

*/

void clear_input();

/*!
 \brief a function that compares a floating point number with epsilon.
 \param number - the number that is compared.
 \param result_of_compare - comparison result: equal with 0 (true) or not equal with 0(false)
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.
*/

ERRORS comparison_with_eps(double, bool *);

/*!
 \brief a function that compares two floating point numbers.
 \param number1 - the first compared number.
 \param number2 - the second compared number.
 \param result_of_compare - comparison result: number are equal (true) or different (false)
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.

*/

ERRORS comparison_two_doubles(double, double, bool *);

/*!
 \brief function that tests the SquareSolver program on data from a txt file and outputs the test results.

*/


void normal_mode();

/*!
 \brief function responsible for selecting the test mode: manual or from a file.

*/

void choosing_the_mode();


/*!
 \brief a function that outputs the text about the error(custom assert).
 \param errors - the variable that contains the error code.
 \return NOT_ERROR - if the function has shut down correctly,
         NAN_ERROR - if the value of the NAN variable was found,
         NULL_ERROR - if an empty pointer was found.
         POINTER_MATCHING - if two variables with the same address are found.
*/

ERRORS call_errors(ERRORS);

/*!
 \brief function that prints the main information about the test(author and version).

*/
void print_main_information();


#endif
