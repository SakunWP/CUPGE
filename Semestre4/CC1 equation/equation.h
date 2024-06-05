#ifndef __equation_H__
#define __equation_H__

typedef struct s_complexe * Complexe;
typedef struct s_equation * EquationDeSecondDegre;

EquationDeSecondDegre construitSecondDegre(float , float, float);
void afficheSecondDegre(EquationDeSecondDegre );
Complexe * resolutionSecondDegre(EquationDeSecondDegre );



#endif