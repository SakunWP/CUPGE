#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "equation.h"

struct s_complexe{
    float re;
    float im;
};

struct s_equation{
    float a;
    float b;
    float c;
};

EquationDeSecondDegre construitSecondDegre(float a, float b, float c){
    EquationDeSecondDegre e= (EquationDeSecondDegre) malloc(sizeof(struct s_equation));
    e->a=a;
    e->b=b;
    e->c=c;
    return e;
}

void afficheSecondDegre(EquationDeSecondDegre e){
    printf("%.2fz^2 + %.2fz + %.2f = 0", e->a, e->b, e->c);
}

void afficheComplexe(Complexe c){
    printf("%.2f + i%.2f",c->re,c->im);
}

Complexe * resolutionSecondDegre(EquationDeSecondDegre e){
    Complexe x1;
    Complexe x2;
    Complexe* solutions = (Complexe*) malloc(2 * sizeof(struct s_complexe));
    float delta;
    delta=(e->b)*(e->b)-4*(e->a)*(e->c);
    if(delta>0){
        x1->re=(-(e->b)+sqrt(delta))/(2*(e->a));
        x1->im=0;
        x2->re=(-(e->b)-sqrt(delta))/(2*(e->a));
        x1->im=0;
        solutions[0]=x1;
        solutions[1]=x2;
    }else if (delta==0)
    {
        x1->re=(-(e->b))/(2*(e->a));
        x1->im=0;
        solutions[0]=x1;
    }
    else{
        x1->re=(-(e->b))/(2*(e->a));
        x1->im=(sqrt(-delta))/(2*(e->a));
        x2->re=(-(e->b))/(2*(e->a));
        x2->im=(-sqrt(-delta))/(2*(e->a));
        solutions[0]=x1;
        solutions[1]=x2;
    }
    return solutions;
}




int main(){
    EquationDeSecondDegre e1;
    EquationDeSecondDegre e2;
    e1=construitSecondDegre(1,2,3);
    afficheSecondDegre(e1);
    return 1;
}



