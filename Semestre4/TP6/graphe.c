#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphe.h"
#define MAX 10

struct s_sommet{
    char nom;
    int s;
};

struct s_arc{
    Sommet sommet1;
    Sommet sommet2;
    Arc suivant;
};

struct s_graphe{
    Sommet liste_sommets[MAX];
    Arc liste_arcs [MAX][MAX];
    int nbSommets;
};

void intitialiseGraphe(){
    Graphe gr;
    int nbSommets=0;
    for(int i=0; i<MAX; i++){
        for(int j=0; i<MAX; j++){
            gr->liste_arcs[i][j]=0;
        }
    }
}

void ajouteSommet(Sommet a, Graphe G){
    assert(G->nbSommets<=MAX);
    G->liste_sommets[G->nbSommets]=a;
    G->nbSommets++;
}

Arc creerArc(Sommet s1, Sommet s2) {
	Arc a = (Arc) malloc(sizeof(Arc));
    a->sommet1=s1;
    a->sommet2=s2;
    a->suivant=NULL;
    return a;
}
void ajouteArc(Arc a, Graphe g){
    assert(existeSommet(a->sommet1,g)&&(a->sommet2,g));
    g->liste_arcs[a->sommet1->s][a->sommet2->s]=1;
}

void supprimeArc(Arc a, Graphe G){
    assert(existeSommet(a->sommet1,G)&&(a->sommet2,G));
    G->liste_arcs[a->sommet1->s][a->sommet2->s]=0;
}

int existeSommet(Sommet a, Graphe G){
    int j=0;
    for(int i=0;i<MAX;i++){
        if(G->liste_sommets[i]==a->s){
            j=1;
        }
    }
    return j;
}

int existeArc(Arc a, Graphe G){
    if(G->liste_arcs[a->sommet1->s][a->sommet2->s]==0){
        return 0;
    }
    else{
        return 1;
    }
}
void afficheArc(Arc a) {
	printf("___Arc___\n");
    printf("(%d,%d)\n",a->sommet1->s,a->sommet2->s);
}

void afficheArcs(Graphe G) {	
	if (G->liste_arcs == NULL)
		printf("Pas d'arcs dans le graphe !\n");
	else {
		Arc a = G->liste_arcs;
		printf("Liste des arcs dans le graphe\n");
		while (a!= NULL)
		{
			printf("\tArc (%d,%d)\n",a->sommet1->s,a->sommet2->s);
			a = a->suivant;
		}
	}
	printf("------------------------\n");
}

int main() {
	Graphe G;
	Arc a;
	printf("== Gestion du Graphe ==\n");
	intitialiseGraphe();

	

	return(1);
}



