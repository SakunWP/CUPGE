/*
 * Graphes.h
 */


typedef struct _sommet *Sommet;
typedef struct _arc *Arc;
typedef struct _graphe *Graphe;

Graphe initialiseGraphe(); // permet d'ajouter des sommets au graphe

Arc creerArc(int,int);
void afficheArc(Arc);
void afficheArcs(Graphe);
void ajouteArc(Arc, Graphe); // ajoute l'arc au graphe
void supprimeArc(Arc, Graphe); //supprime l'arc au graphe
int existeArc(Arc, Graphe); // retourne 1 si l'arc a existe dans le graphe


int existeSommet(Sommet, Graphe); // retourne 1 si le sommet s existe dans le graphe


