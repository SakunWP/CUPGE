#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexe.h"

Complexe PoltoCart(Complexe c){
    Complexe cart;
    cart.forme=Cartesien;
    if(c.forme==Polaire){
        cart.cartesien.a=c.polaire.rho*cos(c.polaire.theta);
        cart.cartesien.b=c.polaire.rho*sin(c.polaire.theta);
    }
    else{
        cart.cartesien.a=cart.cartesien.a;
        cart.cartesien.b=cart.cartesien.b;
    }
    return cart;
}

Complexe CarttoPol(Complexe c){
    Complexe pol;
    pol.forme=Polaire;
    if(c.forme==Cartesien){
        pol.polaire.rho=sqrt((c.cartesien.a)*(c.cartesien.a)+(c.cartesien.b)*(c.cartesien.b));
        pol.polaire.theta=atan((c.cartesien.b)/(c.cartesien.a));
    }
    else{
        pol.polaire.rho=pol.polaire.rho;
        pol.polaire.theta=pol.polaire.theta;
    }
    return pol;
}

Complexe EntreCart(){
    Complexe c;
    c.forme=Cartesien;
    printf("entrez la valeur de a");
    scanf("%f", &(c.cartesien.a));
    printf("entrez la valeur de b");
    scanf("%f", &(c.cartesien.b));
    return c;
}

void Affiche (Complexe c) {
	switch(c.forme) {
		case Cartesien:
			printf("\nComplexe c - a=%.2f b=%.2f\n",c.cartesien.a,c.cartesien.b);
			break;
		case Polaire:
			printf("\nComplexe c - rho=%.2f theta=%.2f\n",c.polaire.rho,c.polaire.theta);
			break;
		default:
			printf("\n -- Erreur %d --\n",c.forme);
			break;
	}
}

Complexe Addition(Complexe c1, Complexe c2){
    Complexe c;
    c.forme=Cartesien;
    if(c1.forme==Cartesien){
        c1=PoltoCart(c1);
    }
    if(c2.forme==Polaire){
        c2=PoltoCart(c2);
    }
    c.cartesien.a=c1.cartesien.a+c2.cartesien.a;
    c.cartesien.b=c1.cartesien.b+c2.cartesien.b;
    return c;
}

int main(){
    Complexe c1;
    Complexe c2;
    Complexe c3;
    c1=EntreCart();
    Affiche(c1);
    c2=EntreCart();
    c3=Addition(c1,c2);
    Affiche(c3);
    return 1;

}