#include<stdio.h>
#include <stdlib.h>
#include "projet.h"
#define size 50

struct s_date{
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
};

struct s_villes{
    char * ville[size];
    int nbr_villes;
};

struct s_trajet{
    Client c;
    char * etape[size];
    int nbr_etape;
    Date date;
};

struct s_client{
    char * prenom;
    Trajet liste[size];
};

struct s_conducteur{
    int identifiant;
    char * mdp;
    Trajet t_cond[size];
    int nb_trajet;
};

struct s_admin{
    Conducteur tab_cond[size];
    int nbr_cond;
    Client tab_client[size];
    int nbr_client;
    Villes v;

};

int verifId(int id, Admin ad){
    int i;
    while(id!=ad->tab_cond[i] && i<ad->nbr_cond+1){
        i=i+1;
        if (i==ad->nbr_cond){
            printf("conducteur inconnu\n");
            menuConducteur();
        }
    }
    return i;
}

int verifIdCl(int idCl, Admin ad){
    int i;
    while(idCl!=ad->tab_client[i] && i<ad->nbr_client+1){
        i=i+1;
        if (i==ad->nbr_client){
            printf("client inconnu\n");
            menuClient();
        }
    }
    return i;
}

int verifVille(char * ville, Admin ad){
    
    int i;
    while(ville!=ad->v->ville[i] && i<ad->v->nbr_villes+1){
        i=i+1;
        if (i==ad->v->nbr_villes){
            printf("ville introuvable\n");
            menuConducteur();
        }
    }
    return i;
}

void menuInitial(){
    printf("selectionnez 1 si vous êtes conducteur, 2 pour client et 3 pour administrateur\n");
    int a;
    scanf("%d",&a);
    if (a==1){
        menuConducteur();
    }
    else if(a==2)
    {
        menuClient();
    }
    else if(a==3){
        menuAdministrateur();
    }
    else{
        printf("erreur sellectionnez 1 ou 2 ou 3\n");
        menuInitial();
    }
}

void menuConducteur(){
    Admin ad= malloc(sizeof(struct s_admin));
    printf("selectionnez 1 si vous êtes un nouveau conducteur, 2 sinon\n");
    int a;
    scanf("%d",&a);
    if (a==1){
        char * b;
        int c;
        printf("tapez votre mot de passe (lettres)\n");
        scanf("%s",&b);
        printf("tapez votre identifiant (chiffres)\n");
        scanf("%d",&c);
        setNewConducteur(b,c);  //utiliser le chifrement
        menuConducteur();
    }
    else if(a==2){
        Conducteur cond= malloc(sizeof(struct s_conducteur));
        int id;
        printf("tapez votre identifiant (chiffres)\n");
        scanf("%d",&id);
        int j=verifId(id,ad);
        cond=ad->tab_cond[j];
        char * mdp;
        printf("tapez votre mot de passe (lettres)\n");
        scanf("%s",&mdp);
        verifMDP(mdp,id);
        printf("selectinnez 1 pour creer un nouveau trajet, 2 pour modifier votre mdp, 3 pour afficher les trajets et 0 pour quitter le menu conducteur\n");
        int a;
        scanf("%d",&a);
        while(a!=0){
            if (a==1){
                int z;
                Trajet t =malloc(sizeof(struct s_trajet));
                t->nbr_etape=0;
                printf("Combien de villes souhaitez vous parcourir?\n");
                scanf("%d",&z);
                for(int i=0; i<z; i++){
                    char * ville;
                    printf("tapez une ville\n");
                    scanf("%s",&ville);  //verif de ville possible
                    int k= verifVille(ville,ad);
                    t->etape[i]=ad->v->ville[k];
                    t->nbr_etape++;
                }
                cond->t_cond[cond->nb_trajet+1]=t;
                cond->nb_trajet++;
            }
        else if(a==2)
        {
            printf("selectionnez un nouveau mdt (lettres)\n");
            char * nmdp;
            scanf("%s",&nmdp);
            cond->mdp=nmdp;

        }
        else if(a==3){
            for(int i=0; i<ad->nbr_cond; i++){
                for(int j=0;j<ad->tab_cond[i]->nb_trajet;j++){
                    for(int l=0;l<ad->tab_cond[i]->t_cond[j]->nbr_etape;l++){
                        printf("%s",ad->tab_cond[i]->t_cond[j]->etape[l]);
                    }
                } 
            }
        }
        else{
            printf("erreur sellectionnez 1 ou 2 ou 3\n");
            menuConducteur();
        }
        }
        menuInitial();
        
    }
}
void menuClient(){
    printf("selectionnez 1 si vous êtes un nouveau client, 2 sinon\n");
    int x;
    scanf("%d",&x);
    if (x==1){
        printf("tapez votre identifiant (chiffres)\n");
        scanf("%d",&x);
        setNewClient(x);// paramètres à revoir pour mdp
        menuClient();
    }
    else if(x==2){
        Conducteur cond= malloc(sizeof(struct s_conducteur));
        int idCl;
        printf("tapez votre identifiant (chiffres)\n");
        scanf("%d",&idCl);
        int j=verifIdCl(idCl,ad);

    }
}
