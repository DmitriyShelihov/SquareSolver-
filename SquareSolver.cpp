#include <stdio.h>
#include <TXLib.h>
#include "other.h"
#include "other.cpp"

int main(){
    float a, b, c;
    float x1, x2;
    enum SOLUTIONS solutions;
    if (Input(&a, &b, &c))
    {
        if (fabs(a) < eps)
            solutions = (SOLUTIONS)Solvelinear(b, c, &x1);
        else
            solutions = (SOLUTIONS)Solvequadratic(a, b, c, &x1, &x2);
        Output(solutions, x1, x2);
    }
    return 0;
}

