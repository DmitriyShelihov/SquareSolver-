/*!
\file
\brief Main program
*/

#include "TXLib.h"
#include <stdio.h>
#include <assert.h>
#include "core_functions.h"
#include "testing_mode.h"
#include "assertion.h"

/*! The main function.
    Starts the mode selection function
    and displays information about the program */

int main()
    {
    print_main_information();
    choosing_the_mode();

    return 0;
    }

