#include<stdio.h>
#include <stdlib.h>
#include "liste.h"

struct s_cellule{
    int val;
    Cellule next;
};

struct s_liste{
    int taille;
    Cellule debut;
};

Liste constructeurListe(){
    Liste l= malloc(sizeof(struct s_liste));
    l->debut=NULL;
    l->taille=0;
}

Liste ajouter(int x, Liste L){
    if(L->debut==NULL){
        Cellule debut= malloc(sizeof(struct s_cellule));
        debut->val=x;
        debut->next=NULL;
        L->taille++;
    }
    else{
        if(x<L->debut->val){
            Cellule c= malloc(sizeof(struct s_cellule));
            c->val=x;
            c->next=L->debut;
            L->taille++;
        }
        else{
            int i=0;
            while(i<L->taille-1){
                
            }
        }
    }
}

