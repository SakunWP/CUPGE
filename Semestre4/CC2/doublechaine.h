#ifndef __doublechaine_H__
#define __doublechaine_H__
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_cellule * Cellule;
typedef struct s_liste * Liste;

Liste dc();
Liste ajouter(int x, Liste l);
bool trouver(int x, Liste l);
Liste supprimer(int x, Liste l);
Liste alenvers(Liste l);

#endif