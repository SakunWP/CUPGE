#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometrie.h"
#define pi 3.14

point2D creerPoint(float x,float y){
    point2D p;
    p.x=x;
    p.y=y;
    return p;
}

vecteur2D creerVecteur(point2D a, point2D b){
    vecteur2D v;
    v.dx=b.x-a.x;
    v.dy=b.y-a.y;
    return v;
}

void Affiche(point2D point){
    printf("Point (%.2f,%.2f)\n", point.x, point.y);
}

circle creerCercle(point2D p, vecteur2D v){
    circle c;
    c.centre=p;
    c.vect=v;
    return c;
}

float aire(circle c){
    float r;
    float a;
    r=sqrt((c.vect.dx)*(c.vect.dx)+(c.vect.dy)*(c.vect.dy));
    a=2*pi*r*r;
    return a;
}

int main(int argc, char* argv[]) {

	if (argc!=5) {
		printf("Wrong usage, 4 parameters expected: ./a x y vx vy\n");
		return(EXIT_FAILURE); // ERROR
	}
	// vérification des arguments
	int i=1;
	float origin;
	while (i<argc) {
	// normalement, il faudrait vérifier que les données sont ok
		if (sscanf(argv[i], "%f", &origin) != 1) {
			printf("Error, %s is not a float\n", argv[i]);
			return(EXIT_FAILURE);
		}
		i++;
	}
	float x = atof(argv[1]);
	float y = atof(argv[2]);
	float vx = atof(argv[3]);
	float vy = atof(argv[4]);

	// affectation des arguments
	
	point2D P= creerPoint(x,y);

	vecteur2D V;
	V.dx=vx;
	V.dy=vy;
	Affiche(P);
	Affiche(P); // once again, not useful ...
 
	circle c = creerCercle(P,V);
	float a = aire(c);
	printf("l'aire est de %.2f\n",a);
	return(0);
}