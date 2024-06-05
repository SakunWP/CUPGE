enum methode{
    Cartesien,
    Polaire
};

typedef struct Complexe_Cartesien
{
    float a;
    float b;
} Complexe_Cartesien;

typedef struct Complexe_Polaire
{
    float theta;
    float rho;
} Complexe_Polaire;

typedef struct 
{
    enum methode forme;
    union 
    {
        Complexe_Cartesien cartesien ;
        Complexe_Polaire polaire;
    };
}Complexe;

Complexe CarttoPol(Complexe);
Complexe PoltoCart(Complexe);
Complexe EntreCart();
void Affiche(Complexe c);
Complexe Addition(Complexe c1, Complexe c2);