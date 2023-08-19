#include <stdio.h>
#include <TXLib.h>
#include <assert.h>
#include "functions_declaration.h"
#include "input_solution_output_functions.cpp"

int main(){
    double a = 0.0, b = 0.0, c = 0.0;
    double x1 = 0.0, x2 = 0.0;
    enum SOLUTIONS solutions;
    if (Input_Coefficients(&a, &b, &c)){
        solutions = (SOLUTIONS)Controller_Function(a, b, c, &x1, &x2);
        Output_Answer(solutions, x1, x2);
    }
    return 0;
}

