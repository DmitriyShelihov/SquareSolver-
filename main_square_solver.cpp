/*!
\file
\brief Main program
*/

#include "TXLib.h"
#include <stdio.h>
#include <assert.h>
#include "core_functions.h"
#include "testing_mode.h"

/*! The main function.
    Starts the mode selection function
    and displays information about the program */

int main()
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
    printf("# Square Solver!\n"
           "# Square equation solver\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    choosing_the_mode();
    return 0;
    }

