#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "doublechaine.h"

struct s_cellule{
    int val;
    Cellule next;
    Cellule back;
};

struct s_liste{
    int taille;
    Cellule debut;
};

Liste dc(){
    Liste l=malloc(sizeof(struct s_liste));
    l->debut=NULL;
    l->taille=0;
    return l;
}

Liste ajouter(int x, Liste l){
    Cellule nc= malloc(sizeof(struct s_cellule));
    nc->val=x;
    nc->next=NULL;
    Cellule cCourant= malloc(sizeof(struct s_cellule));
    cCourant->next=l->debut;
    if(l->debut==NULL){
        nc->back=NULL;
        l->debut=nc;
        return l;
    }
    else{
        while(cCourant->next!=NULL){
            cCourant=cCourant->next;
        }
        nc->back=cCourant;
        cCourant->next=nc;
        return l;
    }
    
}

bool trouver(int x, Liste l){
    Cellule cCourant= malloc(sizeof(struct s_cellule));
    cCourant->next=l->debut;
    if(l->debut==NULL){
        return false;
    }
    if(l->debut->next==NULL){
        if(l->debut->val==x){
            return true;
        }
        else{
            return false;
        }
    }
    while(cCourant->next!=NULL){
        if(cCourant->val==x){
            return true;
        }
        cCourant=cCourant->next;
    }
    return false;
    
}

Liste supprimer(int x, Liste l){
    if(trouver(x,l)==false || l->debut==NULL){
        return l;
    }
    Cellule cCourant= malloc(sizeof(struct s_cellule));
    cCourant->next=l->debut;
    while(cCourant->next->val!=x){
        cCourant=cCourant->next;
    }
    cCourant->back->next=cCourant->next;
    cCourant->next->back=cCourant->back;
    l->taille--;
    return l;

}

/*Liste alenvers(Liste l) {
    Cellule courante = l->debut;
    Cellule temp = NULL;

    while (courante != NULL) {
        temp = courante->next;
        courante->next = courante->back;
        courante->back = temp;
        courante = courante->back; 
    }

    l->debut = temp->back;

    return l;
}*/

Liste alenvers(Liste l) {
    Cellule courante = l->debut;
    Cellule temp = NULL;
    Cellule precedent = NULL;

    while (courante != NULL) {
        temp = courante->next;
        courante->next = precedent;
        courante->back = temp;
        precedent = courante;
        courante = temp;
    }

    l->debut = precedent;

    return l;
}

void affiche(int * ch){

}




int main(){
    Liste DC=dc();
    //ajouter(4,DC);
    //trouver(4,DC);
    //supprimer(4,DC);
    //printf("lol1");
    int ln[7] = {83, 79, 71, 78, 65, 84, 83};
    for(int i=0; i<7;i++){
        ajouter(ln[i],DC);
    }
    trouver(83,DC);
    //supprimer(83,DC);   //segmentation erreur associé à supprimer!!
    alenvers(DC);
    return 0;

}