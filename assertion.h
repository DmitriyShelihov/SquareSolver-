#ifndef ASSERTION_H
#define ASSERTION_H

#include "TXLib.h"
#include <stdio.h>
#include <assert.h>


/*!
\file
\brief Header file with assert define
*/

#define POSITION_IN_CODE __FILE__, __PRETTY_FUNCTION__, __LINE__  ///< a define that combines three position macros in the code

/*!
\brief a define that checks a variable for an error.
*/

#define CONDITIONAL_COMPILATION
#ifdef CONDITIONAL_COMPILATION

    #define cooler_assert(condition, error_code)                                                                              \
        if (condition)                                                                                                        \
            {                                                                                                                 \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);                                         \
            fprintf (stderr, "Assert %s in file %s in %s:%d failed\n", #condition, POSITION_IN_CODE);                         \
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);    \
            call_errors(error_code);                                                                                          \
            return error_code;                                                                                                \
            }
#else
    #define cooler_assert(condition, error_code) \
        ;                                        \
#endif
#endif




#endif
