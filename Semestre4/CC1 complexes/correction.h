/* création des structures */ 

typedef struct {
	float a;
	float b;
} Complexe_Cartesien;

typedef struct {
	float rho;
	float theta;
} Complexe_Polaire;


enum  type {CARTESIEN=0, POLAIRE};

/* création de la structre Complexe avec une union */
typedef struct {
	enum type t;
	union {
		Complexe_Cartesien c;
		Complexe_Polaire p;
	};
} Complexe;

/* Prototype des fonctions */
Complexe CarttoPol(Complexe);
Complexe PoltoCart(Complexe);
Complexe EntreCart();
void Affiche(Complexe c);
Complexe Additionne(Complexe c1, Complexe c2);

