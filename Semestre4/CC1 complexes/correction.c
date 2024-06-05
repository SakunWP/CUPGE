/* inclusion des librairies */ 

#include "correction.h"
#include <stdio.h>
#include <math.h>


Complexe CarttoPol(Complexe c) {
	Complexe cp;
	cp.t = POLAIRE;
	if (c.t == CARTESIEN) {
		cp.p.rho=sqrt((c.c.a*c.c.a) + (c.c.b*c.c.b));
		cp.p.theta=atan(c.c.b/c.c.a);
	}
	else {
		cp.p.rho = c.p.rho;
		cp.p.theta = c.p.theta;
	}
	return(cp);
}

Complexe PoltoCart(Complexe c) {
	Complexe cc;
	cc.t = CARTESIEN;
	if (c.t == POLAIRE) { // c est-il codé en POLAIRE ?
		cc.c.a = c.p.rho*cos(c.p.theta);
		cc.c.b= c.p.rho*cos(c.p.theta);
	}
	else {
		cc.c.a = c.c.a;
		cc.c.b = c.c.b;
	} 
	return(cc);
}

Complexe EntreCart() {
	Complexe c;
	c.t = CARTESIEN;
	printf("\nEntrez la valeur de a : ");
	scanf("%f", &(c.c.a));
	printf("Entrez la valeur de b : ");
	scanf("%f", &(c.c.b));
	return(c);
}

void Affiche (Complexe c) {
	switch(c.t) {
		case CARTESIEN:
			printf("\nComplexe c - a=%.2f b=%.2f\n",c.c.a,c.c.b);
			break;
		case POLAIRE:
			printf("\nComplexe c - rho=%.2f theta=%.2f\n",c.p.rho,c.p.theta);
			break;
		default:
			printf("\n -- Erreur %d --\n",c.t);
			break;
	}

}

Complexe Additionne(Complexe c1, Complexe c2) {
	Complexe c;
	if (c1.t == POLAIRE)
		c1 = PoltoCart(c1);
	if (c2.t == POLAIRE)
		c2 = PoltoCart(c2);
	c.t = CARTESIEN;
	c.c.a = c1.c.a + c2.c.a;
	c.c.b = c1.c.b + c2.c.b; 
	return(c);
}

/* ========== PROGRAMME PRINCIPAL ========== */
int main() {
	Complexe C, C1, C2;

	// EntreCart
	C1 = EntreCart();
	Affiche(C1);
	// EntreCart
	C2 = EntreCart();
	// CarttoPol
	C1 = CarttoPol(C1);
	// Additionne
	C = Additionne(C1,C2);
	// Affiche
	Affiche(C);
	return(1);
}
