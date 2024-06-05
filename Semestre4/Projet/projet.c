#include <stdio.h>
#include <stdlib.h>
#include "projet.h"
#include <string.h>
#include <jansson.h>
#include <time.h>
#define size 50

struct s_date{
    int jour;
    int mois;
    int heure;
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
    char mdp[25];
    Trajet liste[size];
    int nb_trajets;
};

struct s_conducteur{
    char identifiant[25];
    //char * identifiant;
    char mdp[25];
    //char * mdp;
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
    d->heure=heure;
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
    t->nbr_etape=0;
    for(int i=0;i<size;i++){
        t->etape[i]=NULL;
    }
    return t;
}

Client constructeurClient(){
    Client c=(Client) malloc(sizeof(struct s_client));
    c->nb_trajets=0;
    for(int i=0; i<size;i++){
        c->liste[i]=constructeurTrajet();
    }
    return c;
}

Conducteur constructeurCond(){
    Conducteur cond=(Conducteur) malloc (sizeof(struct s_conducteur));
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

Client setNewClient(char prenom[25],char mdp[25],Admin ad){
    Client c=constructeurClient();
    strcpy(c->prenom,prenom);
    strcpy(c->mdp,mdp);
    //printf("%s\n\n",c->mdp);
    ad->tab_client[ad->nbr_client]=c;
    ad->nbr_client++;
    return c;
}

Conducteur setNewConducteur(char mdp[25], char num_id[25],Admin ad){
    Conducteur c=constructeurCond();
    strcpy(c->identifiant,num_id);
    strcpy(c->mdp,mdp);
    ad->tab_cond[ad->nbr_cond]=c;
    ad->nbr_cond++;
    return c;
}

char * afficheId(char id[25]){
    char *c= malloc(25 * sizeof(char));
    for(int i=0;i<25;i++){
        c[i]=id[i];
    }
    return c;
}

void exporterJsonconducteur(Admin ad){
    // Ouvrir le fichier pour l'écriture
    FILE* fichier = fopen("conducteurs.json", "w");
    if (fichier == 0) {
        printf("Erreur : impossible d'ouvrir le fichier conducteurs.json\n");
        return;
    }
    // Écrire le début du tableau JSON
    fprintf(fichier, "[\n");
    for (int i = 0; i < ad->nbr_cond; i=i+2) {
        //printf("nbr cond: %d",ad->nbr_cond);
        Conducteur conducteur = ad->tab_cond[i];
        fprintf(fichier, "  {\n");
        fprintf(fichier, "    \"identifiant\": \"%s\",\n",conducteur->identifiant);
        //printf("id: %s\n",conducteur->identifiant);
        fprintf(fichier, "    \"mot de passe\": \"%s\",\n", conducteur->mdp);
        //printf("mdp: %s",conducteur->mdp);
        //printf("nb trajet: %d",ad->tab_cond[i]->nb_trajet);
        for(int boo=0;boo<ad->tab_cond[i]->nb_trajet;boo++){
            //printf("testboo\n");
            fprintf(fichier, " \"trajet(s)\":");
            fprintf(fichier, " \"%s\"", ad->tab_cond[i]->t_cond[boo]->etape[0]);
            for(int l=1;l<ad->tab_cond[i]->t_cond[boo]->nbr_etape+1;l++){
                fprintf(fichier, "  \"%s\",", ad->tab_cond[i]->t_cond[boo]->etape[l]);
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
    for (int i = 0; i < ad->nbr_client; i++) {
        Client client = ad->tab_client[i];
        fprintf(fichier, "  {\n");
        fprintf(fichier, "    \"prenom\": \"%s\",\n", client->prenom);
        //printf("%s\n",client->prenom);
        fprintf(fichier, "    \"mot de passe\":\"%s\",\n", client->mdp);
        for(int boo=0;boo<ad->tab_client[i]->nb_trajets;boo++){
            fprintf(fichier, " \"trajet(s)\":");
            fprintf(fichier, "  \"%s\",", ad->tab_client[i]->liste[boo]->etape[0]);
            for(int l=1;l<ad->tab_client[i]->liste[boo]->nbr_etape+1;l++){
                fprintf(fichier, "  \"%s\",", ad->tab_client[i]->liste[boo]->etape[l]);
            }
            fprintf(fichier, " \"Date et heure du trajet\": \"%d/%d à %dh, \n",ad->tab_client[i]->liste[boo]->date->jour,ad->tab_client[i]->liste[boo]->date->mois,ad->tab_client[i]->liste[boo]->date->heure);
        }
        // Écrire une virgule si ce n'est pas le dernier conducteur
        if (i < ad->nbr_client - 2) {
            fprintf(fichier, "  },\n");
        } else {
            fprintf(fichier, "  }\n");
        }
    }
    //printf("%d",ad->nbr_client);
    fprintf(fichier, "]\n");
    // Fermer le fichier
    fclose(fichier);
}

/*void importJSON(Admin ad){
    char* filename = "conducteur.json";
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
    }

    json_decref(root);
    free(buffer);

    // Utilisez la structure "Personne" ici
    printf("ID: %d\n", c->identifiant);
    printf("Nom: %s\n", c->mdp);
    
}*/



int verifId(char id[25], Admin ad){
    int i=0;
    while(i<ad->nbr_cond+1){
        if(strcmp(id,ad->tab_cond[i]->identifiant)==0){
            return i;
        }
        if (i==ad->nbr_cond){
                printf("Conducteur inconnu\n");
                printf("Tapez 1 pour redonner votre id et 2 pour quitter le menu conducteur\n");
                int lh;
                scanf("%d",&lh);
                if(lh==1){
                    printf("Redonnez votre id\n");
                    char idn[25];
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
    return i;
}

int verifIdCl(char idCl[25], Admin ad){
    int i=0;
    while(i<ad->nbr_client+1){
        if(strcmp(idCl,ad->tab_client[i]->prenom)==0){
            return i;
        }
        if (i==ad->nbr_client){
            printf("Client inconnu\n");
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
                    printf("Tapez 1 ou 2 svp\n");
                    scanf("%d",&lh);
                }
        }
        i=i+1;
    }
    return i;
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

int danslesborneslettres(char pw[]){
	int i = 0;
	int j=0;
    while (pw[i] != '\0') {
        if( (pw[i] >= 'a' && pw[i] <= 'z') || (pw[i] >= 'A' && pw[i] <= 'Z') ){
        	j=j;
        }
        else{
        	j=j+1;
        }
        i++;
    }
    return j;
}

int danslesborneschiffres(char pw[]){
	int i = 0;
	int j=0;
    while (pw[i] != '\0') {
        if(pw[i] >= '0' && pw[i] <= '9'){
        	j=j;
        }
        else{
        	j=j+1;
        }
        i++;
    }    
    return j;
}



int verifMDP(char mdp[25], Admin ad){
    int i=0;
    char* polo=(char*)malloc(40);
    strcpy(polo,chiffrement_cesar(mdp,12));
    while(i<ad->nbr_client+1){
    	int g=strcmp(polo,ad->tab_client[i]->mdp);
        if(g==0){
            return i;
        }
        if (i==ad->nbr_client){
            printf("Mot de passe erroné\n");
            printf("Tapez 1 pour redonner votre mdp et 2 pour revenir le menu client\n");
                int lh;
                scanf("%d",&lh);
                if(lh==1){
                    printf("Redonnez votre mdp\n");
                    char idn[25];
                    scanf("%s",&idn);
                    verifMDP(idn,ad);
                }else if(lh==2){
                    menuClient(ad);
                }else{
                    printf("Tapez 1 ou 2 svp\n");
                    scanf("%d",&lh);
                }
        }
        i=i+1;
    }
    return i;
}

int verifMDPcond(char mdp[25], Admin ad){
    int i=0;
    char* polo=(char*)malloc(40);
    strcpy(polo,chiffrement_cesar(mdp,12));
    while(i<ad->nbr_cond+1){
    	int g=strcmp(polo,ad->tab_cond[i]->mdp);
        if(g==0){
            return i;
        }
        if (i==ad->nbr_cond){
            printf("Mot de passe erroné\n");
            printf("Tapez 1 pour redonner votre mdp et 2 pour revenir le menu cond\n");
                int lh;
                scanf("%d",&lh);
                if(lh==1){
                    printf("Redonnez votre mdp\n");
                    char idn[25];
                    scanf("%s",&idn);
                    verifMDPcond(idn,ad);
                }else if(lh==2){
                    menuConducteur(ad);
                }else{
                    printf("Tapez 1 ou 2 svp\n");
                    scanf("%d",&lh);
                }
        }
        i=i+1;
    }
    return i;
}

Conducteur changeMDP(char  mdp[25], Conducteur cond){
    strcpy(cond->mdp,chiffrement_cesar(mdp,12));
    return cond;
}

Client changeMDPcl(char mdp[25], Client cl){
    strcpy(cl->mdp,chiffrement_cesar(mdp,12));
    return cl;
}


void supprimeTrajetPassager(Client client, Trajet trajet){
    trajet->c=NULL;
    for (int i=0; i<client->nb_trajets+1;i++ ){
        for(int j=i; j<client->nb_trajets;j++){
            client->liste[j]=client->liste[j+1];
        }
    }
}

void menuInitial(Admin ad){
    printf("\n\n\n\n\n                                        BIENVENUE AU BLABLACAR DU WISH \n                                 Tous droits réservés à Sakun, Ambre et Amira \n");
    printf(" \n\n Sélectionnez:\n	1. Si vous êtes conducteur\n	2. Si vous êtes client\n	3. Si vous êtes administrateur\n");
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
        printf("Erreur sélectionnez 1 ou 2 ou 3\n");
        menuInitial(ad);
    }
}

void menuConducteur(Admin ad){    
    printf("Sélectionnez: \n 1. Si vous êtes un nouveau conducteur, 2. Pour vous connecter\n");
    int a;
    scanf("%d",&a);
    if (a==1){
        char b[25];
        char c[25];
        printf("Tapez votre identifiant (sous forme de chiffre(s))\n");
        scanf("%s",&c);
        if(danslesborneschiffres(c)!=0){
        	printf("Ce n'est pas des chiffres!\n");
        	menuConducteur(ad);
        }
        for(int hg=0;hg<ad->nbr_cond;hg++){
        	int gh=strcmp(c,ad->tab_cond[hg]->identifiant);
        	if(gh==0){
        		printf("Cet identifiant est déja pris, veuillez en choisir un autre\n");
        		menuConducteur(ad);
        	}
        }
        printf("Tapez votre mot de passe (entre 1 et 20 lettres)\n");
        scanf("%s",&b);
        if(danslesborneslettres(b)!=0){
        	printf("Ce n'est pas des lettres!\n");
        	menuConducteur(ad);
        }
        char mdptst[25];
        strcpy(mdptst,chiffrement_cesar(b,12));
        Conducteur cond=setNewConducteur(mdptst,c, ad);
        printf("%s\n",cond->identifiant);
        ad->nbr_cond++;
        a=2;
    }
    if(a==2){
        Conducteur cond= malloc(sizeof(struct s_conducteur));
		char id[25];
        printf("\nConnexion \n\nTapez votre identifiant (chiffres)\n");
        scanf("%s",&id);
        int j=verifId(id,ad);
        char mdp[25];
        printf("Tapez votre mot de passe (lettres)\n");
        scanf("%s",&mdp);
        if(danslesborneslettres(mdp)!=0){
        	printf("Ce n'est pas des lettres!\n");
        	menuConducteur(ad);
        }
        int mdplace=verifMDPcond(mdp,ad);
        cond=ad->tab_cond[j];     
        printf("Sélectionnez:\n	1. Pour créer un nouveau trajet\n	2. Pour modifier votre mdp\n	3. Pour afficher les trajets\n	0. Pour quitter le menu conducteur\n");
        int bcc;
        scanf("%d",&bcc);
        while(bcc!=0){
            if (bcc==1){
                int z;
                Trajet t =malloc(sizeof(struct s_trajet));
                t->nbr_etape=0;
                printf("Combien de villes souhaitez-vous parcourir ?\n");
                scanf("%d",&z);
                for(int i=0; i<z; i++){
                    int r=0;
                    int boucle=0;
                    while(boucle<ad->v->nbr_villes){
                        printf("%d est %s \n",boucle, ad->v->ville[boucle]);
                        boucle++;
                    }
                    printf("Tapez le numéro correspondant à la ville choisie\n");
                    scanf("%d",&r);
                    printf("%s\n",ad->v->ville[r]);
                    t->etape[i]=ad->v->ville[r];
                    t->nbr_etape=z-1;
                }
                int mois;
                int jour;
                int heure;
                printf("Choisissez le mois de départ(1 à 12)\n");
                scanf("%d",&mois);
                printf("Le jour (1-31)\n");
                scanf("%d",&jour);
                printf("L'heure(0-23)\n");
                scanf("%d",&heure);
                t->date=constructeurDate(jour,mois,heure);
                cond->t_cond[cond->nb_trajet]=t;
                cond->nb_trajet++;
                ad->tab_cond[j]=cond;
                printf("%d\n",cond->nb_trajet);
                printf("Vous allez maintenant être redirigé vers le menu de connexion\n");
                menuConducteur(ad);
            }
            if(bcc==2)
            {
                printf("Sélectionnez un nouveau mdp (lettres)\n");
                char nmdp[50];
                scanf("%s",&nmdp);
                changeMDP(nmdp,cond);
                printf("Mot de passe modifié\n");
                menuConducteur(ad);
            }
            if(bcc==3){
                for(int i=0; i<ad->nbr_cond; i++){
                    for(int boo=0;boo<ad->tab_cond[i]->nb_trajet;boo++){
                        for(int l=0;l<ad->tab_cond[i]->t_cond[boo]->nbr_etape+1;l++){
                            printf("->%s",ad->tab_cond[i]->t_cond[boo]->etape[l]);
                        }
                        printf("\n");
                    } 
                }
                menuConducteur(ad);
            }
            else{
                printf("Erreur: Sélectionnez 1 ou 2 ou 3\n");
                menuConducteur(ad);
            }
        }
        exporterJsonconducteur(ad);
        menuInitial(ad);
        
    }
}



void menuClient(Admin ad){
    printf("Sélectionnez: \n 1. Si vous êtes un nouveau client 2. Pour vous connecter\n");
    int x;
    scanf("%d",&x);
    if (x==1){
        printf("Tapez votre nom et votre prénom (ex:TomCruise)\n");
        char nom[25];
        scanf("%s",&nom);
        if(danslesborneslettres(nom)!=0){
        	printf("Ce n'est pas des lettres!\n");
        	menuClient(ad);
        }
        for(int hg=0;hg<ad->nbr_client;hg++){
        	int gh=strcmp(nom,ad->tab_client[hg]->prenom);
        	if(gh==0){
        		printf("Cet identifiant est déja pris, veuillez en choisir un autre\n");
        		menuClient(ad);
        	}
        }
        printf("Tapez un mot de passe (lettres)\n");
        char mdpcl[25];
        scanf("%s",&mdpcl);
        if(danslesborneslettres(mdpcl)!=0){
        	printf("Ce n'est pas des lettres!\n");
        	menuClient(ad);
        }
        char mdptst[25];
        strcpy(mdptst,chiffrement_cesar(mdpcl,12));
        Client client=setNewClient(nom,mdptst,ad);
        printf("Votre compte a été créé, vous allez être redirigé vers le menu client\n");
        menuClient(ad);
    }
    else if(x==2){
        Client client= malloc(sizeof(struct s_client));
        char idCl[25];
        printf("Tapez votre nom et votre prénom\n");
        scanf("%s",&idCl);
        int j=verifIdCl(idCl,ad);
        char mdp[25];
        printf("Tapez votre mot de passe (lettres)\n");
        scanf("%s",&mdp);
        int mdplace=verifMDP(mdp,ad);
        client=ad->tab_client[j];
        printf("Selectionnez: \n    1. Pour réserver un trajet\n	2. Pour annuler un trajet\n	   3. Pour changer de mot de passe\n	0 pour quitter le menu client\n");
        int z;
        scanf("%d",&z);
            if (z==1){
            	printf("Voici les trajets disponibles:\n\n");
            	for(int i=0; i<ad->nbr_cond; i++){
                    for(int boo=0;boo<ad->tab_cond[i]->nb_trajet;boo++){
                        printf("Trajet numéro: %d, avec conducteur numéro:%d \n",boo,i);
                        printf("	Réservé par %s\n",ad->tab_cond[i]->t_cond[boo]->c->prenom);
                        printf("	Date de départ du trajet: le %d/%d à %d heure\n	",ad->tab_cond[i]->t_cond[boo]->date->jour,ad->tab_cond[i]->t_cond[boo]->date->mois,ad->tab_cond[i]->t_cond[boo]->date->heure);
                        for(int l=0;l<ad->tab_cond[i]->t_cond[boo]->nbr_etape+1;l++){
                            printf("->%s",ad->tab_cond[i]->t_cond[boo]->etape[l]);
                        }
                        printf("\n");
                    } 
                }
                printf("\n");
                printf("Selectionner le trajet que vous voulez:\n	Numéro de trajet\n");
                int numco;
                int numtr;
                scanf("%d",&numtr);
                printf("	Numero du conducteur\n");
                scanf("%d",&numco);
                ad->tab_cond[numco]->t_cond[numtr]->c=client;
                ad->tab_client[j]->liste[ad->tab_client[j]->nb_trajets]=ad->tab_cond[numco]->t_cond[numtr];
                ad->tab_cond[numco]->t_cond[numtr]->c->nb_trajets++;
                printf("Vous avez réservé le trajet:");
                for(int boo=0;boo<ad->tab_client[j]->nb_trajets;boo++){
                        for(int l=0;l<ad->tab_client[j]->liste[boo]->nbr_etape+1;l++){
                            printf("->%s",ad->tab_client[j]->liste[boo]->etape[l]);
                        }
                        printf("\n");
                 }
                menuClient(ad);
            }
            else if(z==2){
                printf("Choisisez le trajet que vous voulez supprimer:\n");
                printf("%d \n",j);
                for(int boo=0;boo<ad->tab_client[j]->nb_trajets;boo++){
                        printf("Trajet numero: %d \n",boo);
                        for(int l=0;l<ad->tab_client[j]->liste[boo]->nbr_etape+1;l++){
                            printf("->%s",ad->tab_client[j]->liste[boo]->etape[l]);
                        }
                        printf("\n");
                 }
                int p;
                scanf("%d",&p);
                supprimeTrajetPassager(client, ad->tab_client[j]->liste[p]);
                menuClient(ad);
            }
            if(z==3)
            {
                printf("Selectionnez un nouveau mdp (lettres)\n");
                char nmdp[50];
                scanf("%s",&nmdp);
                changeMDPcl(nmdp,client);
                printf("Mot de passe modifié\n Vous allez etre redirigé vers le menu de connexion");
                menuClient(ad);
            }
            else if (z==0){
                exporterJsonClient(ad); 
                menuInitial(ad);
            }
            else{
                printf("Erreur: selectionnez 1, 2, 3 ou 0\n");
                menuClient(ad);
            }
            
            exporterJsonClient(ad);
            menuInitial(ad);
    }
}

void menuAdministrateur(Admin ad){
    int n;
    printf("Veuillez saisir votre code d'entrer ou 0 pour revenir sur le menu initial\n");
    scanf("%d",&n);
    if(n==9635){
        printf("Tapez 1 pour la gestion des villes\n");
        printf("Tapez 2 pour modifier un mot de passe d'un client ou d'un conducteur\n");
        printf("Tapez 3 pour exporter la liste des conducteurs enregistrées\n");
        int e;
        scanf("%d",&e);
        if (e==1){
            printf("Tapez 1 pour ajouter une ville\n");
            printf("Tapez 2 pour supprimer une ville\n");
            printf("Tapez 0 pour sortir\n");
            int e2;
            scanf("%d",&e2);
            if(e2==1){
                printf("Quelle ville souhaitez vous ajouter? (ex:Tatooine)\n");
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
            printf("Tapez 2 pour modifier le mot de passe d'un conducteur\n");
            int v;
            scanf("%d",&v);
            if(v==1){
                printf("De quel client voulez vous changer le mot de pasee\n");
                char idc[25];
                scanf("%s",&idc);
                int lec=verifIdCl(idc,ad);
                printf("Tapez le nouveau mot de passe(ex:azerty)\n");
                char nmdp[25];
                scanf("%s",&nmdp);
                changeMDPcl(chiffrement_cesar(nmdp,12),ad->tab_client[lec]);
                printf("Le mot de passe a bien été modifié\n");
                //printf("%s",ad->tab_client[lec]->mdp);
            }
            else if(v==2){
                printf("De quel conducteur voulez vous changer le mot de passe\n");
                char ida[25];
                scanf("%s",&ida);
                int ver=verifId(ida,ad);
                printf("Tapez le nouveau mot de passe\n");
                char nmdp[25];
                scanf("%s",&nmdp);
                changeMDP(chiffrement_cesar(nmdp,12),ad->tab_cond[ver]);
                printf("Le mot de passe a bien été modifié\n");
                //printf("%s",ad->tab_cond[ver]->mdp);

            }
        }
    }else if(n==0)
    {
        menuInitial(ad);
    } 
    else{
        printf("Code pin invalide, veuillez réessayer\n");
        menuAdministrateur(ad);
    }
}
int main(){
    Admin ad= constructeurAdmin();
    menuInitial(ad);
    return 0;
}