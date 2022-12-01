#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define SIZE_CHAINE 35

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
typedef struct
{
   char NumTel[SIZE_CHAINE];
   char Nom[SIZE_CHAINE];
   char Mail[SIZE_CHAINE];
   int NbLocation;
   int PtsFidelite;
} CLIENT;

void GenererVhs(VHS *vhs);
void displaylastVHS(VHS *vhs);

void GenererVhs(VHS *vhs)
{
   char tabActeurs[SIZE_CHAINE][SIZE_CHAINE] = {"Johnny Cos", "Manuel Ferrari", "Papo Siffredi"};
   char nomFilms[SIZE_CHAINE][SIZE_CHAINE] = {"La bonne, la bite et la truante", "Fuck club", "Forest cum"};
   for(int i = 0; i < 3; i++)
   {
   	for(int y = 0; y < SIZE_CHAINE; y++)
   	{
   		vhs->Nom[y] = nomFilms[i][y];
   		vhs->ActeurStar[y] = tabActeurs[i][y];
   		//mettre une fonction qui insere la vhs generer
   	}
   	printf("\n");
   } 
}

//provisoire
void displaylastVHS(VHS *vhs)
{
	printf("Films : %s\n", vhs->Nom);
	printf("nom acteur star : %s\n", vhs->ActeurStar);
}

int main( int argc, char * argv[] ) {
	VHS vhs;
	GenererVhs(&vhs);
	displaylastVHS(&vhs);
}
