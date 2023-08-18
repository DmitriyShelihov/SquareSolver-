#include <stdio.h>
#include <TXLib.h>
enum {SUCCESS = 1, UNSUCCESS = 0};
const double eps = 1.0e-19;

int Input(float*, float*, float*);
int Solvelinear(float, float, float*);
int Solvequadratic(float, float, float, float*, float*);
void Output(int, int, float, float);

int main(){
    float a, b, c;
    float x1, x2;
    int data = Input(&a, &b, &c);
    int solutions = (fabs(a) < eps)?Solvelinear(b, c, &x1):Solvequadratic(a, b, c, &x1, &x2);
    Output(data, solutions, x1, x2);
    return 0;
}

int Input(float *pa, float *pb, float *pc){
    return (scanf("%f%f%f", &(*pa), &(*pb), &(*pc)) == 3)?SUCCESS:UNSUCCESS;
}
int Solvelinear(float b, float c, float *px1){
    if (fabs(b) < eps && fabs(c) < eps)
        return 100;
    else if (fabs(b) < eps && not(fabs(c) < eps))
        return 0;
    else
        (*px1) = (-1 * c)/b;
        return 1;
}

int Solvequadratic(float a, float b, float c, float *px1, float *px2){
    int solutions;
    float D = b * b - 4 * a * c;
    if (D < 0)
        solutions = 0;
    else if (fabs(D) < eps){
        (*px1) = (-1 * b)/(2 * a);
        solutions = 1;
    }
    else{
        solutions = 2;
        (*px1) = float((-1 * b - sqrt(D))/(2 * a));
        (*px2) = float((-1 * b + sqrt(D))/(2 * a));
    }
    return solutions;
}

void Output(int key1, int solutions, float x1, float x2){
    if (key1 == UNSUCCESS)
        printf("Неверный ввод!\n");
    else{
        switch(solutions){
            case 0: printf("Решений нет\n");break;
            case 100: printf("Бесконечно много решений\n");break;
            case 1: printf("Единственное решение:  %f\n", x1);break;
            default: printf("Два различных решения: %f  %f\n", x1, x2);
        }
    }
}
