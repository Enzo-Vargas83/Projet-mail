#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define SIZE_CHAINE 20

typedef struct
{
   int Duree;
   char ID[SIZE_CHAINE];
   char Nom[SIZE_CHAINE];
   char Categorie[SIZE_CHAINE];
   char ActeurStar[SIZE_CHAINE];
   char ActeurStar2[SIZE_CHAINE];
   char ActeurStar3[SIZE_CHAINE];
} VHS;



int main( int argc, char * argv[] ) {
VHS gangbangAble;

creerVHS(&gangbangAble);


}


void creerVHS(VHS *pfilm){

printf("Rentrer ID de la VHS: ");
scanf("%s",&pfilm->ID);

printf("Rentrer nom de la VHS: ");
scanf("%s",&pfilm->Nom);

printf("Rentrer la catégorie de la VHS: ");
scanf("%s",&pfilm->Categorie);

int i;
printf("Combien il y a t-il d'acteur?: ");
scanf("%d",&i);

switch(i){

case(1):
printf("Rentrer le nom de l'acteur: ");
scanf("%s",&pfilm->ActeurStar);

break;
case(2):
printf("Rentrer le nom du premier acteur: ");
scanf("%s",&pfilm->ActeurStar);
printf("Rentrer le nom du deuxième acteur: ");
scanf("%s",&pfilm->ActeurStar2);

break;
case(3):
printf("Rentrer le nom du premier acteur: ");
scanf("%s",&pfilm->ActeurStar);
printf("Rentrer le nom du deuxième acteur: ");
scanf("%s",&pfilm->ActeurStar2);
printf("Rentrer le nom du troisième acteur: ");
scanf("%s",&pfilm->ActeurStar3);

break;
}
}
