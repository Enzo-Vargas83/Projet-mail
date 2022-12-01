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
} VHS
typedef struct
{
   char NumTel[SIZE_CHAINE];
   char Nom[SIZE_CHAINE];
   char Mail[SIZE_CHAINE];
   int NbLocation = 0;
   int PtsFidelite = 0; 
} CLIENT

int main( int argc, char * argv[] ) {
}
