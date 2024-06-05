#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp3.h"
#define FERME 0
#define OUVERT 1
#define LIGNES 5
#define COLONNES 6

int creation_laby(int* laby){
    for (int i=0; i<LIGNES; i++){
        for (int j=0; j<COLONNES; j++){
             // fermer les contours du labyrinthe
             if((i==0 && j!=1) || (j==0) || (j==COLONNES-1)|| i==LIGNES-1){
                *(laby +(i*LIGNES)+j) = FERME;
             } 
             else{
                 int proba= rand() % 100;
                 if(proba>40){
                    *(laby +(i*LIGNES)+j) = OUVERT;
                 }
                 else{
                    *(laby +(i*LIGNES)+j) = FERME;
                 }
             } 
      
        }

    } 
    *(laby +(0*LIGNES)+1) = OUVERT;
    *(laby +((LIGNES-1)*LIGNES)+(COLONNES-2)) = OUVERT;
    return 1;  
}

void afficher(int *laby){
    for (int i=0; i<LIGNES; i++){
        for (int j=0; j<COLONNES; j++){
            if(*(laby +(i*LIGNES)+j) == FERME){
                printf("x");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
   }
}

typedef struct {
    int x;
    int y;
    int z;
    int t;
} PAS;

typedef struct{
    PAS pas;
    PAS* tab;
}num;

// Define internal structure
struct s_step {
	int x_ori;
	int y_ori;
	int x_fin;
	int y_fin;
};

typedef struct s_element {
	Step value;
	struct s_element *next;
} *Element;

struct s_stack {
	Element top;
};

/** Step Constructor */
/** Create a new Step */
Step step(int x_ori,int y_ori,int x_fin,int y_fin){
	Step s = (Step) malloc(sizeof(struct s_step));
	s->x_ori = x_ori;
	s->y_ori = y_ori;
	s->x_fin = x_fin;
	s->y_fin = y_fin;
	return(s);
};

int getX_ori(Step s){
	return(s->x_ori);
}
int getY_ori(Step s){
	return(s->y_ori);
}
int getX_fin(Step s){
	return(s->x_fin);
}
int getY_fin(Step s){
	return(s->y_fin);
}

/** Constructor */
Stack stack(void) {
	Stack s = (Stack) malloc(sizeof(struct s_stack));
	s->top = NULL;
	return(s);
}

/** Push */
Stack push(Stack s, Step e) {
	Element new = (Element) malloc (sizeof(struct s_element));
	new->value=e;
	new->next = s->top;
	s->top = new;
	return(s);
}

/** Pop */
Stack pop(Stack s){
	if (!isEmpty(s)) { // normally assert !
		Element e = s->top;
		s->top = e->next;
		free(e);
	}
	return(s);
}

/** isEmpty */
int isEmpty(Stack s) {
	return(s->top == NULL);
}

/* Top */
Step top(Stack s) {
	if (!isEmpty(s)) { // normally assert !
		return((s->top)->value);
	}
	else
		return(NULL);
}


int main(int argc, char* argv[]){
       int *laby = (int*) malloc(sizeof(int)*LIGNES*COLONNES);
       srand((unsigned) time(NULL)); 
       creation_laby(laby);
       afficher(laby);
       return(1);
}

