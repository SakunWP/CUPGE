#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quaternion.h"

struct s_complexe{
    float re;
    float im;
};

struct s_imaginaire{
    float b;
    float c;
    float d;
};

struct s_quaternion{
    float pr;
    Imaginaire pi;
};

Quaternion quaternion(float a, float b, float c, float d){
    Quaternion q=(Quaternion) malloc(sizeof(struct s_quaternion));
    Imaginaire pi=(Imaginaire) malloc(sizeof(struct s_imaginaire));
    q->pi=pi;
    q->pr=a;
    q->pi->b=b;
    q->pi->c=c;
    q->pi->d=d;
    return q;
}

Imaginaire Im(Quaternion q){
    return q->pi;
}

float Re(Quaternion q){
    return q->pr;
}

float norme(Quaternion q){
    return sqrt(q->pr*q->pr+q->pi->b*q->pi->b+q->pi->c*q->pi->c+q->pi->d*q->pi->d);
}

Quaternion conjugue(Quaternion q){
    q->pi->b=-q->pi->b;
    q->pi->c=-q->pi->c;
    q->pi->d=-q->pi->d;
    return q;
}

Quaternion inverse(Quaternion q){
    float normeauc=norme(q)*norme(q);
    q->pr=q->pr/normeauc;
    q->pi->b=(-q->pi->b)/normeauc;
    q->pi->c=(-q->pi->c)/normeauc;
    q->pi->d=(-q->pi->d)/normeauc;
    return q;
}

void affiche(Quaternion q){
    printf("%.2f + (%.2f)i + (%.2f)j + (%.2f)k\n", q->pr, q->pi->b, q->pi->c, q->pi->d);
}

void affiche_im(Imaginaire i){
    printf("(%.2f)i + (%.2f)j + (%.2f)k\n",i->b, i->c, i->d);
}

void affiche_float(float a){
    printf("%.2f\n",a);
}


int main(){
    Quaternion q1;
    Quaternion q2;
    q1=quaternion(1,2,3,4);
    affiche(q1);
    affiche_im(Im(q1));
    affiche_float(Re(q1));
    affiche_float(norme(q1));
    q2=conjugue(q1);
    affiche(q2);
    Quaternion q3=inverse(q1);
    affiche(q3);
    return 1;

}


