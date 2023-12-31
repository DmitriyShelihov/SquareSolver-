# SquareSolver programm. Version 1.1 23/08/2023

## GENERAL USAGE NOTES

+ <u>Language writing is C (g++ compiler).</u>

+ To compile program in test mode, use

  `g++ core_functions.cpp main_square_solver.cpp testing_mode.cpp assertion.cpp -Wall -Wextra -o SquareSolver.exe`

+ The program solves a quadratic equation for the entered coefficients. 

+ If there are no solutions or some error has occurred, the program will report it. 

+ The program can be run in two modes: normal_mode and testing_mode. (read more below)

+ To generate documentation, use doxygen doxygen.config

## NORMAL_MODE

+ In this mode, the user receives a message from the program and enters 3 coefficients of the equation - a, b, c. 

+ The program will present the number of solutions as well as their decimal representation.

## TESTING_MODE

+ This mode provides pre-entered values in the file Tests.txt according to which the program will work. 

+ After execution, the user will receive detailed information about each test and the percentage distribution of successful and unsuccessful tests.

## ABOUT FILLING OUT THE TEST FILE

+ Look at the ready-made file (Tests.txt) supplied with the program as an example.

+ For each test, write down 3 coefficients separated by a space, the number of solutions in the row below and the roots in ascending order in the third row.

+ After each test, you need to skip one line.

+ <u>Save the file in txt format.</u>
 

**If you have any questions, please contact <shelikhov.ds@phystech.edu>
SHD, 2023**

