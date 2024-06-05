#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "equation.h"

enum Type {reel,comp};

struct s_complexe{
    float re;
    float im
};

struct s_equation{
    float c;
    float d;
};

struct s_delta{
    enum Type type;
    union{
        Complexe RacineDeltaComp;
        float RacineDeltaReel;
    };
};

union u_valeurs{
    float solution;
    Delta delta;
};

Equation equation(float c, float d){
    Equation e=(Equation) malloc(sizeof(struct s_equation));
    e->c=c;
    e->d=d;
    return e;
}

Delta determinant(Equation e){
    Delta d=(Delta) malloc(sizeof(struct s_delta));
    float delta=(e->d)*(e->d)+(4*(e->c)*(e->c)*(e->c))/27;
    if(delta<0){
        d->type=comp;
        d->RacineDeltaComp->re=0;
        d->RacineDeltaComp->im=-sqrt(delta);
    }
    else{
        d->type=reel;
        d->RacineDeltaReel=sqrt(delta);
    }
    return d;
    
}

void print_determinant(Delta d){
    if(d->type==comp){
        printf("le determinant est: %.2f + i%.2f",d->RacineDeltaComp->re,d->RacineDeltaComp->im);
    }
    else{
        printf("le determinant est: %.2f",d->RacineDeltaReel);
    }
    
}

float setC(Equation e){
    return (e->c);
}

float setD(Equation e){
    return (e->d);
}

float solve(Equation e){
    float c = setC(e);
    float d = setD(e);
    float a = 0;
    float b = c/3.0;
    float p = (3*b*b-c)/3.0;
    float q = (2*b*b*b-c*b+d)/27.0;
    float delta = q*q/4.0 + p*p*p/27.0;
    float solution;
    
    if (delta >= 0) {
        float u = cbrt(-q/2.0 + sqrt(delta));
        float v = cbrt(-q/2.0 - sqrt(delta));
        solution = u + v - b;
    }
    else {
        float r = sqrt(-p*p*p/27.0);
        float theta = acos(-q/(2*r));
        float u = 2*cbrt(r)*cos(theta/3.0);
        float v = 2*cbrt(r)*cos((theta+2*M_PI)/3.0);
        float w = 2*cbrt(r)*cos((theta-2*M_PI)/3.0);
        solution = u + v + w - b;
    }
    return solution;
}


