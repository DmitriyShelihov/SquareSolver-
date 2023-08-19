
#pragma once
enum SOLUTIONS {NOSOLUTIONS,ONE,TWO,INFINITYSOLUTIONS = 100};

int Input(float*, float*, float*);
int Solvelinear(float, float, float*);
int Solvequadratic(float, float, float, float*, float*);
void Output(SOLUTIONS, float, float);
void Clean(void);
