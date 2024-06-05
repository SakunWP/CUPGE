#include <stdio.h>

void chiffrement_cesar(char password[],int cle) {
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
}

int main() {
    char password[100];
    int cle;

    printf("Entrez le mot de passe à chiffrer : ");
    scanf("%s", password);

    //printf("Entrez la clé de chiffrement : ");
    //scanf("%d", &cle);

    chiffrement_cesar(password,3);

    printf("Le mot de passe chiffré est : %s\n", password);

    return 0;
}