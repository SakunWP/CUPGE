#include<stdio.h>
#include <stdlib.h>
#include <time.h>

enum Couleur {TREFLE, CARREAU, PIQUE, COEUR};
enum Numero {SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI, AS};

typedef struct Carte {
    enum Numero numero;
    enum Couleur couleur;
} Carte;

void initjeu(Carte jeu[]){
    int i=0;
    for(int j=AS; j<=SEPT; j++){
        for(int k=COEUR; k<=TREFLE; k++){
            jeu[i].numero=j;
            jeu[i].couleur=k;
            i++;
        }
    }
}

int alea32(){
    return rand() % 32;
}

void permute(Carte * carte1, Carte * carte2){
    Carte temp= *carte1;
    *carte1= *carte2;
    *carte2= temp;
}

void melange(Carte jeu[]){
    for(int i=0; i<100; i++){
        permute(&jeu[alea32()],&jeu[alea32()]);
    }
}

void affiche_carte(Carte X){
    /*int n1= &X.couleur;
    int n2= &X.numero;
    printf();*/
    switch(X.numero){
        case AS:
            printf("As");
            break;
        case ROI:
            printf("Roi");
            break;
        case DAME:
            printf("Dame");
            break;
        case VALET:
            printf("Valet");
            break;
        case DIX:
            printf("10");
            break;
        case NEUF:
            printf("9");
            break;
        case HUIT:
            printf("8");
            break;
        case SEPT:
            printf("7");
            break;
    }
    printf("de");
    switch(X.couleur){
        case COEUR:
            printf("Coeur");
            break;
        case PIQUE:
            printf("Pique");
            break;
        case CARREAU:
            printf("Carreau");
            break;
        case TREFLE:
            printf("Trefle");
            break;
    }
    printf("\n");
}

void affiche(Carte jeu[], int N){
    for(int i=0; i<N; i++){
        affiche_carte(jeu[i]);
    }
}

void distribue(Carte jeu[], Carte jeu1[], Carte jeu2[]){
    for(int i=0; i<32; i++){
        if(i<16){
            jeu1[i]=jeu[i];
        }
        else{
            jeu2[i]=jeu[i];
        }
        
    }
    affiche(jeu1, 16);
    affiche(jeu2,16);
}

void joue1coup(Carte jeu1[], Carte jeu2[], int * N1, int * N2){
    Carte n1=jeu1[0];
    Carte n2=jeu2[0];
    if(n1.numero>n2.numero){
        printf("le joueur 1 a gagné");
        *N1=*N1+1;
        *N2=*N2-1;
        jeu1[*N1]=jeu1[0];
        jeu1[*N1+1]=jeu2[0];
    }
    else if (n2.numero>n1.numero)
    {
        printf("le joueur 2 a gagné");
        *N2=*N2+1;
        *N1=*N1-1;
        jeu2[*N2]=jeu2[0];
        jeu2[*N2+1]=jeu1[0];
    }
    else if (n2.numero==n1.numero)
    {
        if(n1.couleur>n2.couleur){
            printf("le joueur 1 a gagné");
            *N1=*N1+1;
            *N2=*N2-1;
            jeu1[*N1]=jeu1[0];
            jeu1[*N1+1]=jeu2[0];
        }else{
            printf("le joueur 2 a gagné");
            *N2=*N2+1;
            *N1=*N1-1;
            jeu2[*N2]=jeu2[0];
            jeu2[*N2+1]=jeu1[0];
        }
    }
    for(int i=0; i<*N1-1;i++){
        jeu1[i]=jeu1[i+1];
    }
    for(int j=0; j<*N2-1; j++){
        jeu2[j]=jeu2[j+1];
    }
}

int main(int argc, char *argv[])
{
    Carte jeu[32];
    Carte jeuJ1[32]; 
    Carte jeuJ2[32];
    int NJ1 = 16; 
    int NJ2 = 16;
	srand((unsigned) time(NULL)); 
    initjeu(jeu);
	melange(jeu);
	distribue(jeu,jeuJ1,jeuJ2);
    printf(" __ Jeu Joueur1 __\n");
	affiche(jeuJ1,16);	
    printf(" __ Jeu Joueur2 __\n");
	affiche(jeuJ2,16);	
	
	int NBcoups = 0;
	
	while ((NJ1 > 0) && (NJ2>0)) {
		joue1coup(jeuJ1, jeuJ2, &NJ1, &NJ2);
		NBcoups++;
		printf("J1 : %d cartes, J2 : %d cartes\n",NJ1,NJ2);
	}
	if (NJ1 ==0) {
		printf("Le joueur 2 a gagné");		
	}
	else
		printf("Le joueur 1 a gagné");
	printf(" en %d coups\n",NBcoups);
	
    return 0;
}