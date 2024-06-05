#ifndef __equation_H__
#define __equation_H__
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_complexe * Complexe;
typedef struct s_delta * Delta;
typedef struct s_equation * Equation;
typedef union s_valeurs *Valeurs;


Equation equation(float , float );
Delta determinant(Equation );
void print_determinant(Delta );
float solve(Equation e);



#endif