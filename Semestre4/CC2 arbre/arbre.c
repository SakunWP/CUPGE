#include<stdio.h>
#include <stdlib.h>
 #include <stdbool.h>
#include "arbre.h"

struct s_cellule{
    int val;
    Arbre fg;
    Arbre fd;
};

struct s_arbre{
    Cellule racine;
};

Arbre constructeurArbre(){
    Arbre a=malloc(sizeof(struct s_arbre));
    a->racine=NULL;
    return a;
}

Arbre ajouter(int x,Arbre a){
    if(a->racine==NULL){
        Cellule r=malloc(sizeof(struct s_cellule));
        Arbre fg=malloc(sizeof(struct s_arbre));
        fg->racine=NULL;
        Arbre fd=malloc(sizeof(struct s_arbre));
        fd->racine=NULL;
        r->val=x;
        r->fd=fd;
        r->fg=fg;
        a->racine=r;
    }
    else{
        if(x<=a->racine->val){
            ajouter(x,a->racine->fg);
        }
        else{
            ajouter(x,a->racine->fd);
        }
    }
    return a;
}

bool trouver(int x, Arbre a){
    if(a->racine==NULL){
        return false;
    }
    else if(a->racine->val==x){
        return true;
    }
    else{
        if(x<=a->racine->val){
            trouver(x, a->racine->fg);
        }
        else{
            trouver(x, a->racine->fd);
        }
    }
}

int main(){
    Arbre a=constructeurArbre();
    ajouter(5,a);
    printf("%d",a->racine->val);
    ajouter(12,a);
    return 0;
}