#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listeChainee.h"

struct s_cellule{
    int val;
    Cellule next;
    Cellule back;
};

struct s_liste{
    int taille;
    Cellule debut;
};

Liste constructeurListe(){
    Liste l=malloc(sizeof(struct s_liste));
    Cellule c= malloc(sizeof(struct s_cellule));
    c->val=NULL;
    c->next=c;
    l->debut=c;
    l->taille++;
    return l;
}

bool tester(int x,Liste l){
    Cellule cActuelle= malloc(sizeof(struct s_cellule));
    cActuelle=l->debut;
    while(cActuelle->next!=l->debut){
        if (cActuelle->val==x){
            return true;
        }
        cActuelle=cActuelle->next;
    }
    return false;
}

Cellule ajouter(int x, Liste l){
    assert(tester(x,l)==false);
    Cellule add= malloc(sizeof(struct s_cellule));
    add->val=x;
    add->next=NULL;
    Cellule cActuelle= malloc(sizeof(struct s_cellule));
    cActuelle=l->debut;
    while(cActuelle->next!=l->debut){
        cActuelle->next=add;
        add->next=l->debut;
        l->taille++;
    }
    return add;
}


int main(){
    Liste l=constructeurListe();
    ajouter(4,l);
    return 0;
}

