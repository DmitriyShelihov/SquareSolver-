#ifndef ASSERTION_H
#define ASSERTION_H

#include "TXLib.h"
#include <stdio.h>
#include <assert.h>

const short unsigned int FOREGROUND_GREY = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;

/*!
\file
\brief Header file with assert define
*/

#define POSITION_IN_CODE __FILE__, __PRETTY_FUNCTION__, __LINE__  ///< a define that combines three position macros in the code

/*!
\brief a define of variable assertion.
*/

#define CONDITIONAL_COMPILATION
#ifdef CONDITIONAL_COMPILATION

    #define cooler_assert(condition, error_code)                                                                              \
        if (condition)                                                                                                        \
            {                                                                                                                 \
            set_colour(FOREGROUND_RED);                                                                                       \
            fprintf (stderr, "Assert %s in file %s in %s:%d failed\n", #condition, POSITION_IN_CODE);                         \
            set_colour(FOREGROUND_GREY);                                                                                      \
            call_errors (error_code);                                                                                         \
            return error_code;                                                                                                \
            }
#else
    #define cooler_assert(condition, error_code)                                               \
        ;                                                                                      \
#endif
#endif




#endif
