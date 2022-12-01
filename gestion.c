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

void GenererVhs(VHS *vhs, FILE *fichier);
void displaylastVHS(VHS *vhs);

void GenererVhs(VHS *vhs, FILE *fichier)
{
   char tabActeurs[SIZE_CHAINE][SIZE_CHAINE] = {"Johnny Cos", "Manuel Ferrari", "Papo Siffredi"};
   char nomFilms[SIZE_CHAINE][SIZE_CHAINE] = {"La bonne, la bite et la truante", "Fuck club", "Forest cum", "Gangbangable"};
   for(int i = 0; i < 3; i++)
   {
   	for(int y = 0; y < SIZE_CHAINE; y++)
   	{
   		vhs->Nom[y] = nomFilms[i][y];
   		vhs->ActeurStar[y] = tabActeurs[i][y];
   		//mettre une fonction qui insere la vhs generer
   	}
	fseek(fichier,0,SEEK_END);
	fwrite(&vhs, sizeof(VHS),1, fichier);
	fwrite (&input1, sizeof(struct person), 1, outfile);
    	fwrite (&input2, sizeof(struct person), 1, outfile);
   	printf("\n");
   } 
}

//provisoire
void displayVHS(VHS *vhs)
{
	printf("Films : %s\n", vhs->Nom);
	printf("nom acteur star : %s\n", vhs->ActeurStar);
}

void displayALLVHS(FILE *fichier)
{
    printf("affichage VHS\n");
    VHS vhs;
    fseek(fichier,0,SEEK_SET);

     while(fread(&vhs, sizeof(VHS), 1, fichier))
     {
        printf ("id = %s name = %s\n", vhs.Nom, vhs.ActeurStar);
     }
    

}

int main( int argc, char * argv[] ) {
	VHS vhs;
	FILE *fichier;
	fichier = fopen("database.dat", "w");
	GenererVhs(&vhs, fichier);
	displaylastVHS(&vhs);
}
