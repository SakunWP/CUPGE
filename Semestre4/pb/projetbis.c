#include<stdio.h>
#include <stdlib.h>
#include "projetbis.h"
#include <string.h>
#include <jansson.h>
#include <time.h>
//include <openssl/sha.h>
//#include <openssl/evp.h>
//#include <cJSON.h>

#define size 50

struct s_date{
    int jour;
    int mois;
    //int annee;
    int heure;
    //int minute;
};

struct s_villes{
    char * ville[size];
    int nbr_villes;
};

struct s_trajet{
    Conducteur cond;
    Client c;
    char * etape[size];
    int nbr_etape;
    Date date;
};

struct s_client{
    char prenom[25];
    char* mdp;
    Trajet liste[size];
    int nb_trajets;
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

Date constructeurDate(int jour, int mois, int heure){
    Date d=(Date) malloc(sizeof(struct s_date));
    d->jour=jour;
    d->mois=mois;
    //d->annee=annee;
    d->heure=heure;
    //d->minute=minute;
    return d;
}

Villes constructeurVille(){
    Villes v = malloc(sizeof(struct s_villes));
    v->nbr_villes = 8;
    for (int i = 0; i < v->nbr_villes; i++) {
        v->ville[i] = malloc(sizeof(char) * 50); 
    }
    strcpy(v->ville[0], "Lille");
    printf("%d",v->ville[0]);
    strcpy(v->ville[1], "Strasbourg");
    strcpy(v->ville[2], "Lyon");
    strcpy(v->ville[3], "Bordeaux");
    strcpy(v->ville[4], "Toulouse");
    strcpy(v->ville[5], "Montpellier");
    strcpy(v->ville[6], "Marseille");
    strcpy(v->ville[7], "Nice");
    return v;
}

Trajet constructeurTrajet(){
    Trajet t=(Trajet) malloc(sizeof(struct s_trajet));
    //t->c=NULL;
    //t->date=NULL;
    t->nbr_etape=0;
    for(int i=0;i<size;i++){
        t->etape[i]=NULL;
    }
    return t;
}

Client constructeurClient(){
    Client c=(Client) malloc(sizeof(struct s_client));
    //c->prenom=NULL;
    c->nb_trajets=0;
    //c->mdp=NULL;
    for(int i=0; i<size;i++){
        c->liste[i]=constructeurTrajet();
    }
    return c;
}

Conducteur constructeurCond(){
    Conducteur cond=(Conducteur) malloc (sizeof(struct s_conducteur));
    //cond->identifiant=NULL;
    //cond->mdp=NULL;
    cond->nb_trajet=0;
    for(int i=0;i<size;i++){
        cond->t_cond[i]=constructeurTrajet();
    }
    return cond;
}

Admin constructeurAdmin(){
    Admin ad= malloc(sizeof(struct s_admin));
    Villes v= constructeurVille();
    ad->v=v;
    ad->nbr_client=0;
    ad->nbr_cond=0;
    for(int i=0; i<size;i++){
        ad->tab_cond[i]=constructeurCond();
        ad->tab_client[i]=constructeurClient();
    }
    return ad;
}

Client setNewClient(char prenom[25],char * mdp,Admin ad){
    Client c=constructeurClient();
    strcpy(c->prenom,prenom);
    c->mdp=mdp;
    ad->nbr_client++;
    ad->tab_client[ad->nbr_client]=c;
    return c;
}

Conducteur setNewConducteur(char * mdp, int num_id,Admin ad){
    Conducteur c=constructeurCond();
    c->identifiant=num_id;
    c->mdp=mdp;
    ad->nbr_cond++;
    ad->tab_cond[ad->nbr_cond]=c;
    return c;
}

//void exportTrajet()

void exporterJsonconducteur(Admin ad){
    // Ouvrir le fichier pour l'écriture
    FILE* fichier = fopen("conducteurs.json", "w");
    if (fichier == 0) {
        printf("Erreur : impossible d'ouvrir le fichier conducteurs.json\n");
        return;
    }
    // Écrire le début du tableau JSON
    fprintf(fichier, "[\n");
    printf("testjson");
    for (int i = 1; i < ad->nbr_cond; i=i+2) {
        Conducteur conducteur = ad->tab_cond[i];
        fprintf(fichier, "  {\n");
        fprintf(fichier, "    \"identifiant\": \"%s\",\n", conducteur->identifiant);
        fprintf(fichier, "    \"mot de passe\": \"%s\",\n", conducteur->mdp);
        printf("%d",ad->tab_cond[i]->nb_trajet);
        for(int boo=0;boo<ad->tab_cond[i]->nb_trajet;boo++){
            //printf("grosse boucle\n");
            fprintf(fichier, " \"trajet(s)\":");
            fprintf(fichier, " \"%s\"", ad->tab_cond[i]->t_cond[boo]->etape[0]);
            for(int l=1;l<ad->tab_cond[i]->t_cond[boo]->nbr_etape+1;l++){
                fprintf(fichier, "  \"%s\",", ad->tab_cond[i]->t_cond[boo]->etape[l]);
                //printf("petite boucle\n");
            fprintf(fichier, " \"Date et heure du trajet\": \"%d/%d à %dh, \n",ad->tab_cond[i]->t_cond[boo]->date->jour,ad->tab_cond[i]->t_cond[boo]->date->mois,ad->tab_cond[i]->t_cond[boo]->date->heure);
            }
        }
        if (i < ad->nbr_cond) {
            fprintf(fichier, "  },\n");
        } else {
            fprintf(fichier, "  }\n");
        }
    }

    // Écrire la fin du tableau JSON
    fprintf(fichier, "]\n");
    // Fermer le fichier
    fclose(fichier);
}

    


void exporterJsonClient(Admin ad){
    FILE* fichier = fopen("clients.json", "w");
    if (fichier == 0) {
        printf("Erreur : impossible d'ouvrir le fichier clients.json\n");
        return;
    }
    fprintf(fichier, "[\n");
    for (int i = 1; i < ad->nbr_client+1; i++) {
        Client client = ad->tab_client[i];
        fprintf(fichier, "  {\n");
        fprintf(fichier, "    \"prenom\": \"%s\",\n", client->prenom);
        fprintf(fichier, "    \"mot de passe\":\"%s\",\n", client->mdp);
        // Écrire une virgule si ce n'est pas le dernier conducteur
        if (i < ad->nbr_cond - 2) {
            fprintf(fichier, "  },\n");
        } else {
            fprintf(fichier, "  }\n");
        }
        //printf("lil\n");
    }
    printf("%d",ad->nbr_client);
    fprintf(fichier, "]\n");
    // Fermer le fichier
    fclose(fichier);
}

/*void exporterTrajetJson(Admin ad){
    FILE* fichier = fopen("trajets.json", "w");
     if (fichier == 0) {
        printf("Erreur : impossible d'ouvrir le fichier conducteurs.json\n");
        return;
    }
    fprintf(fichier, "[\n");
    for (int i = 1; i < ad->nbr_cond+1; i++) {
        for(int boo=0;boo<ad->tab_cond[i]->nb_trajet;boo++){
            printf("lili");

        }
    }




}*/



//MARCHE WOOOOOOO
int verifId(int id, Admin ad){
    int i=0;
    //printf("knkl");
    int var;
    while(i<ad->nbr_cond+1){
        var=ad->tab_cond[i]->identifiant;
        if(id==var){
            printf("%d yep\n",i);
            return i;
            
        }
        if (i==ad->nbr_cond){
                printf("conducteur inconnu\n");
                //menuConducteur();
                printf("Tapez 1 pour redonner votre id et 2 pour quitter le menu conducteur\n");
                int lh;
                scanf("%d",&lh);
                if(lh==1){
                    printf("Redonnez votre id\n");
                    int idn;
                    scanf("%d",&idn);
                    verifId(idn,ad);
                }else if(lh==2){
                    menuConducteur(ad);
                }else{
                    printf("tapez 1 ou 2 svp\n");
                    scanf("%d",&lh);
                }
                
        }
        i++;
    }
    
    printf("lol");
    return i;
}

int verifIdCl(char idCl[25], Admin ad){
    int i=0;
    //char *var=malloc(sizeof(char));
    //strcpy(var,ad->tab_client[i]->prenom);
    //printf("tyyytyhb");
    //strncpy(var,ad->tab_client[i]->prenom, 100);
    while(i<ad->nbr_client+1){
        //printf("okokokok");
        if(strcmp(idCl,ad->tab_client[i]->prenom)==0){
            printf("%d\n",i);
            return i;
        }
        if (i==ad->nbr_client){
            printf("client inconnu\n");
            printf("Tapez 1 pour redonner votre id et 2 pour revenir le menu client\n");
                int lh;
                scanf("%d",&lh);
                if(lh==1){
                    printf("Redonnez votre id\n");
                    char idn[25];
                    scanf("%s",&idn);
                    verifIdCl(idn,ad);
                }else if(lh==2){
                    menuClient(ad);
                }else{
                    printf("tapez 1 ou 2 svp\n");
                    scanf("%d",&lh);
                }
        }
        i=i+1;
    }
    return i;
}

/*void afficheTrajet(Trajet t){
    
    printf("Depart: %s\n",t->etape[0]);
    printf("Arivée: %s\n",t->etape[t->nbr_etape]);
    printf("Date: %d %d %d à %dh%d",t->date->jour,t->date->mois,t->date->annee,t->date->heure,t->date->minute);
}*/

int verifVille(char * ville, Admin ad){
    
    int i;
    while(ville!=ad->v->ville[i] && i<ad->v->nbr_villes){
        i=i+1;
        printf("%s test ville \n",ad->v->ville[i]);
        if (i==ad->v->nbr_villes){
            printf("ville introuvable\n");
            //menuConducteur();
        }
    }
    return i;
}

void reserver(Trajet trajet, Client c){
    //assert(trajet->c->nb_trajets<size);
    trajet->c=c;
    trajet->c->liste[trajet->c->nb_trajets+1]=trajet;
    trajet->c->nb_trajets++;
    //trajet->cond->t_cond[trajet->cond->nb_trajet+1]=trajet;
    //trajet->cond->nb_trajet++;
}

Conducteur changeMDP(char  mdp[25], Conducteur cond){
    cond->mdp=mdp;
    return cond;
}

Client changeMDPcl(char mdp[25], Client cl){
    cl->mdp=mdp;
    return cl;
}


/*Trajet choix(Villes depart, Villes destination, Date date){
    //
}*/

void importJSON(Admin ad){
    char* filename = "conducteurs.json";
    FILE* file = fopen(filename, "r");

    if (!file) {
        printf("Impossible d'ouvrir le fichier %s\n", filename);
        return ;
    }

    fseek(file, 0L, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0L, SEEK_SET);

    char* buffer = (char*) malloc(filesize + 1);
    fread(buffer, 1, filesize, file);
    buffer[filesize] = '\0';

    fclose(file);

    json_error_t error;
    json_t* root = json_loads(buffer, 0, &error);

    if (!root) {
        printf("Erreur lors de l'analyse JSON: %s\n", error.text);
        return ;
    }

    Conducteur c;
    json_t* identifiant = json_object_get(root, "identifiant");
    json_t* mdp = json_object_get(root, "mot de passe");
    //json_t* prenom = json_object_get(root, "prenom");
    //json_t* age = json_object_get(root, "age");

    if (json_is_integer(identifiant)) {
        c->identifiant = json_integer_value(identifiant);
    }

    if (json_is_string(mdp)) {
        strncpy(c->mdp, json_string_value(mdp), 50);
    }
    setNewConducteur(mdp,identifiant,ad);

    /*if (json_is_string(prenom)) {
        strncpy(p.prenom, json_string_value(prenom), 50);
    }

    if (json_is_integer(age)) {
        p.age = json_integer_value(age);
    }*/

    json_decref(root);
    free(buffer);

    // Utilisez la structure "Personne" ici
    printf("ID: %d\n", c->identifiant);
    printf("Nom: %s\n", c->mdp);
    
}

void supprimeTrajetPassager(Client client, Trajet trajet){
    //assert(client->prenom!=trajet->c->prenom);
    trajet->c=NULL;
    printf("testsupp\n");
    for (int i=0; i<client->nb_trajets+1;i++ ){
        printf("%d nbtrajet\n",client->nb_trajets+1);
        for(int j=i; j<client->nb_trajets;j++){
            client->liste[j]=client->liste[j+1];
        }
    }
}

char * chiffrement_cesar(char password[],int cle) {
    int i = 0;
    while (password[i] != '\0') {
        if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = 'a' + ((password[i] - 'a' + cle) % 26);
        }
        else if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = 'A' + ((password[i] - 'A' + cle) % 26);
        }
        i++;
    }
    return password;
}






void menuInitial(Admin ad){
    printf("selectionnez 1 si vous êtes conducteur, 2 pour client et 3 pour administrateur\n");
    int a;
    scanf("%d",&a);
    if (a==1){
        menuConducteur(ad);
    }
    else if(a==2)
    {
        menuClient(ad);
    }
    else if(a==3){
        menuAdministrateur(ad);
    }
    else{
        printf("erreur sellectionnez 1 ou 2 ou 3\n");
        menuInitial(ad);
    }
}

void menuConducteur(Admin ad){
    //Admin ad=constructeurAdmin();
    /*Villes v= malloc(sizeof(struct s_villes));
    ad->nbr_client=0;
    ad->nbr_cond=0;
    v->nbr_villes=0;
    for(int i=0; i<size;i++){
        ad->tab_cond[i]=NULL;
        ad->tab_client[i]=NULL;
        v->ville[i]=NULL;
    }
    ad->v=v;*/
    
    printf("selectionnez 1 si vous êtes un nouveau conducteur, 2 sinon\n");
    int a;
    scanf("%d",&a);
    if (a==1){
        char b[25];
        int c;
        printf("tapez votre identifiant (chiffres)\n");
        scanf("%d",&c);
        printf("tapez votre mot de passe (lettres)\n");
        scanf("%s",&b);
        Conducteur cond=setNewConducteur(chiffrement_cesar(b,c),c, ad);
        printf("%s",cond->mdp);
        ad->nbr_cond++; //util??? //utiliser le chifrement
        exporterJsonconducteur(ad);
        printf("lol");
        
        //menuConducteur();
        a=2;
    }
    if(a==2){
        Conducteur cond= malloc(sizeof(struct s_conducteur));
		int id;
        printf("\nConnexion \n\ntapez votre identifiant (chiffres)\n");
        scanf("%d",&id);
        //printf("verifid connexion\n");
        int j=verifId(id,ad);
        //printf("initialisation cond \n");
        cond=ad->tab_cond[j];
        //printf("test2");
        char mdp[25];
        printf("tapez votre mot de passe (lettres)\n");
        //printf("nonnnnnnn");
        scanf("%s",&mdp);
        //printf("nonnnnnnn");
        //verifMDP(mdp,id);
        printf("selectionnez 1 pour creer un nouveau trajet, 2 pour modifier votre mdp, 3 pour afficher les trajets et 0 pour quitter le menu conducteur\n");
        int bcc;
        scanf("%d",&bcc);
        while(bcc!=0){
            if (bcc==1){
                int z;
                Trajet t =malloc(sizeof(struct s_trajet));
                t->nbr_etape=0;
                printf("Combien de villes souhaitez vous parcourir?\n");
                scanf("%d",&z);
                for(int i=0; i<z; i++){
                    int r=0;
                    int boucle=0;
                    while(boucle<ad->v->nbr_villes){
                        printf("%d est %s \n",boucle, ad->v->ville[boucle]);
                        boucle++;
                    }
                    printf("tapez un num de ville\n");
                    //printf("xrffff");
                    scanf("%d",&r);
                    printf("%s\n",ad->v->ville[r]);
                    //scanf("%s",&villebb);  //verif de ville possible
                    //printf("verif ville");
                    //int k= verifVille(,ad);
                    //printf("afterverifville");
                    t->etape[i]=ad->v->ville[r];
                    t->nbr_etape=z-1;
                }
                int mois;
                int jour;
                int heure;
                printf("Choisissez le mois de départ(1 à 12)\n");
                scanf("%d",&mois);
                printf("le jour (1-31)\n");
                scanf("%d",&jour);
                printf("l'heure(0-23)\n");
                scanf("%d",&heure);
                t->date=constructeurDate(jour,mois,heure);
                //afficheTrajet(t);
                cond->t_cond[cond->nb_trajet]=t;
                cond->nb_trajet++;
                ad->tab_cond[j]=cond;
                exporterJsonconducteur(ad);
                //printf("ad->tab_cond[j]->nb_trajet: %d",ad->tab_cond[j]->nb_trajet);
                menuConducteur(ad);
            }
            if(bcc==2)
            {
                printf("selectionnez un nouveau mdt (lettres)\n");
                char nmdp[50];
                scanf("%s",&nmdp);
                changeMDP(nmdp,cond);
                printf("Mot de passe modifié");
                menuConducteur(ad);
            }
            if(bcc==3){
                //printf("entrer ok bcc3\n");
                //printf("nbr conducteur:%d\n",ad->nbr_cond);
                for(int i=0; i<ad->nbr_cond; i++){
                    //printf("%d i nbr_cond\n",i);
                    for(int boo=0;boo<ad->tab_cond[i]->nb_trajet;boo++){
                    	//printf("nbr_trajet: %d\n",ad->tab_cond[i]->nb_trajet);
                        //printf("Trajet num %d: \n",boo+1);
                        //afficheTrajet(ad->tab_cond[i]->t_cond[boo]);
                        for(int l=0;l<ad->tab_cond[i]->t_cond[boo]->nbr_etape+1;l++){
                            //printf("entrer L ok%d\n",l);
                            //afficheTrajet(ad->tab_cond[i]->t_cond[boo]);
                            printf("->%s",ad->tab_cond[i]->t_cond[boo]->etape[l]);
                        }
                        printf("\n");
                    } 
                }
                menuConducteur(ad);
            }
            else{
                printf("erreur selectionnez 1 ou 2 ou 3\n");
                menuConducteur(ad);
            }
        }
        menuInitial(ad);
        
    }
}



void menuClient(Admin ad){
    //int menuC=2;
    //Admin ad= constructeurAdmin();
    printf("selectionnez 1 si vous êtes un nouveau client, 2 sinon\n");
    int x;
    scanf("%d",&x);
    if (x==1){
        printf("tapez votre nom et votre prenom (lettres)\n");
        char nom[25];
        scanf("%s",&nom);
        printf("tapez un mot de passe (lettres)\n");
        char mdpcl[25];
        scanf("%s",&mdpcl);
        setNewClient(nom,chiffrement_cesar(mdpcl,12),ad);// paramètres à revoir pour mdp ou pas 
        exporterJsonClient(ad);
        printf("votre compte a été crée vous allez être redirigé vers le menu client\n");
        menuClient(ad);
    }
    else if(x==2){
        Client client= malloc(sizeof(struct s_client));
        char idCl[25];
        printf("tapez votre nom et votre prénom\n");
        scanf("%s",&idCl);
        int j=verifIdCl(idCl,ad);
        client=ad->tab_client[j];
        printf("selectionnez 1 pour réserver un trajet, 3 pour annuler un trajet et 0 pour quitter le menu client\n");
        int z;
        scanf("%d",&z);
        //while(z!=0){
            if (z==1){
            	printf("Voici les trajets dispo:\n\n");
            	for(int i=0; i<ad->nbr_cond; i++){
                    //printf("%d i nbr_cond\n",i);
                    for(int boo=0;boo<ad->tab_cond[i]->nb_trajet;boo++){
                    	printf("Réservé par %s\n",ad->tab_cond[i]->t_cond[boo]->c->prenom);
                        printf("Trajet numero: %d, avec conducteur numero:%d \n",boo,i);
                        //afficheTrajet(ad->tab_cond[i]->t_cond[boo]);
                        for(int l=0;l<ad->tab_cond[i]->t_cond[boo]->nbr_etape+1;l++){
                            //printf("entrer L ok%d\n",l);
                            //afficheTrajet(ad->tab_cond[i]->t_cond[boo]);
                            printf("->%s",ad->tab_cond[i]->t_cond[boo]->etape[l]);
                        }
                        printf("\n");
                    } 
                }
                printf("\n	");
                //Admin ad= malloc(sizeof(struct s_admin));
                //printf("entrer z1 ok\n");
                printf("Selectionner le trajet que vous voulez (numéro de trajet, entré, puis numero du conducteur)\n");
                int numco;
                int numtr;
                scanf("%d",&numtr);
                scanf("%d",&numco);
                ad->tab_cond[numco]->t_cond[numtr]->c=client;
                ad->tab_client[j]->liste[ad->tab_client[j]->nb_trajets]=ad->tab_cond[numco]->t_cond[numtr];
                ad->tab_cond[numco]->t_cond[numtr]->c->nb_trajets++;
                //afficher trajet dun client:
                printf("Vous avez reservé le trajet:");
                //NUM DE nbr trajet monte pas
                for(int boo=0;boo<ad->tab_client[j]->nb_trajets;boo++){
                    	//printf("nbr_trajet: %d\n",ad->tab_client[j]->nb_trajets);
                        //printf("Trajet numero: %d, avec client numero:%d \n",boo,j);
                        for(int l=0;l<ad->tab_client[j]->liste[boo]->nbr_etape+1;l++){
                            //printf("nbr étapes: %d\n",ad->tab_client[j]->liste[boo]->nbr_etape);
                            //afficheTrajet(ad->tab_client[j]->liste[boo]);
                            printf("->%s",ad->tab_client[j]->liste[boo]->etape[l]);
                        }
                        printf("\n");
                 }
                menuClient(ad);
            }
            else if(z==3){
                printf("choisisez le trajet que vous voulez supprimer:\n");

                for(int boo=0;boo<ad->tab_client[j]->nb_trajets;boo++){
                        //printf("nbr_trajet: %d\n",ad->tab_client[j]->nb_trajets);
                        printf("Trajet numero: %d \n",boo);
                        for(int l=0;l<ad->tab_client[j]->liste[boo]->nbr_etape+1;l++){
                            //printf("nbr étapes: %d\n",ad->tab_client[j]->liste[boo]->nbr_etape);
                            //afficheTrajet(ad->tab_client[j]->liste[boo]);
                            printf("->%s",ad->tab_client[j]->liste[boo]->etape[l]);
                        }
                        printf("\n");
                 }
                int p;
                scanf("%d",&p);
                supprimeTrajetPassager(client, ad->tab_client[j]->liste[p]);
                menuClient(ad);
            }
            else if (z==0){
                menuInitial(ad);
            }
            else{
                printf("erreur selectionnez 1, 2, 3 ou 0\n");
                menuClient(ad);
            }
            menuInitial(ad);
            
    
    //}
    }
}

void menuAdministrateur(Admin ad){
    int n;
    printf("Veuillez saisir votre code d'entrer ou 0 pour revenir sur le menu initiale\n");
    scanf("%d",&n);
    if(n==9635){
        printf("Tapez 1 pour la gestion des ville\n");
        printf("Tapez 2 pour modifier un mot de passe d'un client ou d'un conducteur\n");
        printf("Tapez 3 pour exporter la liste des conducteurs enregistrées\n");
        int e;
        scanf("%d",&e);
        if (e==1){
            printf("Tapez 1 pour ajouter une ville\n");
            //printf("Tapez 2 pour modifier le nom d'une ville\n");
            printf("Tapez 2 pour supprimer une ville\n");
            printf("Tapez 0 pour sortir\n");
            int e2;
            scanf("%d",&e2);
            if(e2==1){
                printf("Quelle ville souhaitez vous ajouter?\n");
                char nom_ville[25];
                scanf("%s",&nom_ville);
                ad->v->ville[ad->v->nbr_villes]=nom_ville;
                ad->v->nbr_villes++;
                int bouclef=0;
                while(bouclef<ad->v->nbr_villes){
                        printf("%d pour %s \n",bouclef, ad->v->ville[bouclef]);
                        bouclef++;
                }
            }
            else if(e2==2){
                
                int boucle=0;
                //printf("%d",ad->v->nbr_villes);
                while(boucle<ad->v->nbr_villes){
                        printf("%d pour %s \n",boucle, ad->v->ville[boucle]);
                        boucle++;
                }
                printf("Choisisez la ville que vous souhaitez supprimer\n");
                int s;
                scanf("%d",&s);
                for(int i=s;i<size;i++){
                    ad->v->ville[i]=ad->v->ville[i+1];
                }
                ad->v->nbr_villes--;
                int bouclej=0;
                while(bouclej<ad->v->nbr_villes){
                        printf("%d pour %s  \n",bouclej, ad->v->ville[bouclej]);
                        bouclej++;
                }
            }
            else if(e2==0){
                menuAdministrateur(ad);
            }
            else{
                printf("Tapez 1 ou 2 s'il vous plait\n");
                scanf("%d",&e2);
            }
            menuAdministrateur(ad);
        }
        else if(e==2){
            printf("Tapez 1 pour modifier le mot de passe d'un client\n");
            printf("Tapez 2 pour modifier le mot de passe d'un conducteur");
            int v;
            scanf("%d",&v);
            if(v==1){
                printf("A quel client voulez vous changer le mot de pasee\n");
                char idc[25];
                scanf("%s",&idc);
                int lec=verifIdCl(idc,ad);
                printf("tapez le nouveau mot de passe\n");
                char nmdp[25];
                scanf("%s",&nmdp);
                changeMDPcl(chiffrement_cesar(nmdp,12),ad->tab_client[lec]);
                printf("Le mot de passe a bien été modifié\n");
                printf("%s",ad->tab_client[lec]->mdp);
            }
            else if(v==2){
                printf("A quel conducteur voulez vous changer le mot de passe\n");
                int ida;
                scanf("%d",&ida);
                int ver=verifId(ida,ad);
                printf("Tapez le nouveau mot de passe\n");
                char nmdp[25];
                scanf("%s",&nmdp);
                changeMDP(chiffrement_cesar(nmdp,ad->tab_cond[ver]->identifiant),ad->tab_cond[ver]);
                printf("Le mot de passe a bien été modifié\n");
                printf("%s",ad->tab_cond[ver]->mdp);

            }
        }
    }else if(n==0)
    {
        menuInitial(ad);
    } 
    else{
        printf("Code pin invalide veuillez réessayer\n");
        menuAdministrateur(ad);
    }
}
int main(){
    Admin ad= constructeurAdmin();
    importJSON(ad);
    //Conducteur cond=constructeurCond();
    //Client c=constructeurClient();
    //setNewConducteur("lol",123,ad);
    //setNewClient("sakun","nom",ad);
    menuInitial(ad);
    //exporterJsonAdmin(ad);
    return 0;
}

