
#pragma once
enum SOLUTIONS {NO_SOLUTIONS = 0, ONE = 1, TWO = 2, INFINITY_SOLUTIONS = 100};
enum RESULT {UNSUCCESS = 0, SUCCESS = 1};
const double eps = 1.0e-19;

int controller_function(double, double, double, double*, double*);
int input_coefficients(double*, double*, double*);
int solve_linear(double, double, double*);
int solve_quadratic(double, double, double, double*, double*);
void output_answer(SOLUTIONS, double, double);
void clear_input(void);
int comparison_with_eps(double);
