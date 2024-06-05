#ifndef __Projet_H__
#define __Projet_H__

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//include "md5.h"

typedef struct s_conducteur * Conducteur;   // mdp, id, trajets
typedef struct s_client * Client;           // mdp, identification, trajets (éventuellement vide)
typedef struct s_trajet * Trajet;           // depart, arrivée, client, date
typedef struct s_admin * Admin;             // mot de passe et identification
typedef struct s_villes * Villes;           // liste de villes , éventuellement une index
typedef struct s_date * Date;               // jour, mois et heure

void exporterJsonconducteur(Admin ad);
int verifMDP(char mdp[25], Admin ad);
int verifMDPcond(char mdp[25], Admin ad); // vérifie le mdp est correcte (en le dechifrant)
int verifId(int id, Admin ad);//verifie si l'id existe et renvoie la position dans le tableau
int verifIdCl(char idCl[25], Admin ad); //verifie si l'id existe et renvoie la position dans le tableau
char * chiffrement_cesar(char password[],int cle);
Conducteur changeMDP(char * mdp, Conducteur cond); // permet de changer le mdp
Client changeMDPcl(char mdp[25], Client cl);
Client setNewClient(char prenom[25],char mdp[25],Admin ad);  // permet à un client de s'enregistrer
Conducteur setNewConducteur(char * mdp, int num_id,Admin ad);
Conducteur changeMDP(char  mdp[25], Conducteur cond);
Date constructeurDate(int jour, int mois, int heure);
Villes constructeurVille();
Trajet constructeurTrajet();
Client constructeurClient();
Conducteur constructeurCond();
Admin constructeurAdmin();
void supprimeTrajetPassager(Client client, Trajet trajet); //dans le cas où le passager décide d'abondonner son voyage
void menuInitial(); // propose de s'inscrire ou de se diriger vers les autres menus 
void menuConducteur();   //les menus vont appeler les fonctions haut dessus. par example setnewTrajet pour créer un nouvea trajet, etc..
void menuClient();
void menuAdministrateur();



#endif