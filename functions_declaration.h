
#pragma once
enum SOLUTIONS {NO_SOLUTIONS = 0, ONE = 1, TWO = 2, INFINITY_SOLUTIONS = 100};
enum RESULT {UNSUCCESS = 0, SUCCESS = 1};
const double eps = 1.0e-19;

int Controller_Function(double, double, double, double*, double*);
int Input_Coefficients(double*, double*, double*);
int Solve_Linear(double, double, double*);
int Solve_Quadratic(double, double, double, double*, double*);
void Output_Answer(SOLUTIONS, double, double);
void Clear_Input(void);
int Comparison_With_Eps(double);
