#include <stdio.h>
#include "equation.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "equation.h"

int main() {
    // Test de la fonction equation
    Equation e = equation(1.0, 1.0);
    printf("Equation : x^3 + %.2fx + %.2f\n", setC(e), setD(e));
    
    // Test de la fonction determinant
    Delta d = determinant(e);
    printf("Delta : ");
    print_determinant(d);
    printf("\n");
    
    // Test de la fonction solde
    //union u_valeur valeurs;            // problème
    //solde(e);
    //printf("Solution : %.2f\n", valeurs.solution);
    
    return 0;
}
