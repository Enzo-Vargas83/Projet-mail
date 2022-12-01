#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define SIZE_CHAINE 15

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
void displayActeur(VHS *vhs);

void GenererVhs(VHS *vhs)
{
   char str[SIZE_CHAINE][SIZE_CHAINE] = {"Johnny Cos", "Manuel Ferrari"};
   for(int i = 0; i < 2; i++)
   {
   	for(int y = 0; y < SIZE_CHAINE; y++)
   	{
   		vhs->Nom[y] = str[i][y];
   	}
   	printf("\n");
   } 
}

void displayActeur(VHS *vhs)
{
	printf("nom : %s\n", vhs->Nom);
}

int main( int argc, char * argv[] ) {
	VHS vhs;
	GenererVhs(&vhs);
	displayActeur(&vhs);
}
