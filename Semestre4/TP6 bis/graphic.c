
#include "graphic.h"
#include <stdlib.h>
#include <stdio.h>

struct _sommet {
	 int indice;
	 char nom;
	 Sommet suivant;
};

struct _arc {
	int Ix;
	int Iy;
	Arc suivant;
};

struct _graphe {
	 Sommet liste_sommets;
	 Arc liste_arcs;
};


Graphe initialiseGraphe() {
	Graphe G = (Graphe) malloc (sizeof(Graphe));
	G->liste_sommets = NULL;
	G->liste_arcs = NULL;
	return(G);
}



void ajouteArc(Arc a, Graphe G) {
	if (G->liste_arcs == NULL) {
		G->liste_arcs = a;
	}	
	else {  
		
		Arc ac;
		ac = G->liste_arcs;	
		while (ac->suivant != NULL) {
			ac = ac->suivant; 
		}
		
		ac->suivant = a;
	}
}

void supprimeArc(Arc a, Graphe G) {
	if (existeArc(a,G)) { 
		Arc ac;
		ac = G->liste_arcs;	
		

	}
}

int existeArc(Arc a, Graphe G) {
	int Egal = -1; 
	
	if (G->liste_arcs == NULL)
		return(-1);
	else {
		Arc b = G->liste_arcs;
		
		while ((b!= NULL) || (Egal == -1))
		{
			if ((a->Ix == b->Ix) && (a->Iy == b->Iy)) 
				Egal = 1;
			b = b->suivant;
		}
	}
	return(Egal);
}


Arc creerArc(int Ix, int Iy) {
	Arc a = (Arc) malloc(sizeof(Arc));
	a->Ix = Ix;
	a->Iy = Iy;
	a->suivant = NULL;
	return(a);
}

void afficheArc(Arc a) {
	printf("___Arc___\n");
	printf("(%d,%d)\n",a->Ix,a->Iy);
}


void afficheArcs(Graphe G) {	
	if (G->liste_arcs == NULL)
		printf("Pas d'arcs dans le graphe !\n");
	else {
		Arc a = G->liste_arcs;
		printf("Liste des arcs dans le graphe\n");
		while (a!= NULL)
		{
			printf("\tArc (%d,%d)\n",a->Ix,a->Iy);
			a = a->suivant;
		}
	}
	printf("------------------------\n");
}

int main() {
	Graphe G;
	Arc a;
	printf("== Gestion du Graphe ==\n");
	G = initialiseGraphe();

	a = creerArc(1,2);
	ajouteArc(a,G);

	a = creerArc(2,1);
	ajouteArc(a,G);
	
	a = creerArc(2,2);
	ajouteArc(a,G);	
	
	afficheArc(a);
	printf("on affiche la liste des arcs\n");
	afficheArcs(G);

	return(1);
}

