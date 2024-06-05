#ifndef __geometrie_H__
#define __geometrie_H__

typedef struct {
    float x;
    float y;
}point2D;

typedef struct
{
    float dx;
    float dy;
}vecteur2D;

typedef struct{
    point2D centre;
    vecteur2D vect;
}circle;

point2D creerPoint(float ,float );
vecteur2D creerVecteur(point2D , point2D );
void Affiche(point2D);
circle creerCercle(point2D, vecteur2D);
float aire(circle);

#endif