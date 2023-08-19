w#include <stdio.h>
#include <TXLib.h>
#include <assert.h>
#include "functions_declaration.h"
#include "core_functions.cpp"

int main(){
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    enum SOLUTIONS solutions = NO_SOLUTIONS;
    if (input_coefficients(&a, &b, &c)){
        solutions = (SOLUTIONS)controller_function(a, b, c, &x1, &x2);
        output_answer(solutions, x1, x2);
    }
    return 0;
}

