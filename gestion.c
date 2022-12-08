#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define SIZE_CHAINE 25
#define SIZE_ID 5

typedef struct
{
   int Duree;
   char ID[SIZE_ID];
   char Nom[SIZE_CHAINE];
   char Categorie[SIZE_CHAINE];
   char ActeurStar[SIZE_CHAINE];
   char ActeurStar2[SIZE_CHAINE];
   char ActeurStar3[SIZE_CHAINE];
} VHS;
typedef struct
{
   char ID[SIZE_ID];
   char NumTel[SIZE_CHAINE];
   char Nom[SIZE_CHAINE];
   char Mail[SIZE_CHAINE];
   int NbLocation;
   int PtsFidelite;
} CLIENT;
typedef struct
{
    
    char emetteur[50];
    char destinataire[50];
    char objet[SIZE_CHAINE];
    char corps[150]; 
}MAIL;


void displayMenu();
void adminMenu();
int checkChaine(char chaine[], char chaine2[],int l1,int l2);
int longeurChaine(char chaine[]);

void creerVHS(VHS *pfilm, FILE *fichier);
void displayVhsInfo(VHS *vhs);
void displayALLVHS(FILE *fichier);
void searchVHSbyCategorie(MAIL pmail, FILE *fichier);

void creerMail(MAIL *pmail);

FILE* OpenFileClient(FILE *fichier, int mode);
FILE* OpenFileVhs(FILE *fichier, int mode);




FILE* OpenFileClient(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        // open file in order to write
        fichier = fopen("clientDataBase.bin", "a");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	// open file in order to READ
        fichier = fopen("clientDataBase.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    }
    return fichier;
}
FILE* OpenFileVhs(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        // open file in order to write
        fichier = fopen("vhsDataBase.bin", "a");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	// open file in order to READ
        fichier = fopen("vhsDataBase.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    }
    return fichier;
}
void creerVHS(VHS *pfilm, FILE *fichier){
	printf("Rentrer ID de la VHS: ");
	scanf("%s",pfilm->ID);

	printf("Rentrer nom de la VHS: ");
	scanf("%s",pfilm->Nom);

	printf("Rentrer la catégorie de la VHS: ");
	scanf("%s",pfilm->Categorie);

	int i;
	printf("Combien il y a t-il d'acteur?: ");
	scanf("%d",&i);

	switch(i){

	case(1):
		printf("Rentrer le nom de l'acteur: ");
		scanf("%s",pfilm->ActeurStar);
		break;
	case(2):
		printf("Rentrer le nom du premier acteur: ");
		scanf("%s",pfilm->ActeurStar);
		printf("Rentrer le nom du deuxième acteur: ");
		scanf("%s",pfilm->ActeurStar2);
		break;
	case(3):
		printf("Rentrer le nom du premier acteur: ");
		scanf("%s",pfilm->ActeurStar);
		printf("Rentrer le nom du deuxième acteur: ");
		scanf("%s",pfilm->ActeurStar2);
		printf("Rentrer le nom du troisième acteur: ");
		scanf("%s",pfilm->ActeurStar3);
		break;
	}
	printf("\n");
    	fichier = OpenFileVhs(fichier, 1);
	fseek(fichier,0,SEEK_END);
	fwrite(pfilm, sizeof(VHS),1, fichier);
	fclose(fichier);
}

void displayVhsInfo(VHS *vhs)
{
	printf("nom ID : %s\n", vhs->ID);
    	printf("nom Nom : %s\n", vhs->Nom);
    	printf("nom Categorie : %s\n", vhs->Categorie);
    	printf("\n");
}

void displayALLVHS(FILE *fichier)
{   
    VHS vhs;
    fichier = OpenFileVhs(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {
    	displayVhsInfo(&vhs);
    }
    fclose(fichier);
}

void creerMail(MAIL *pmail){

    printf("Rentrer l emetteur du mail: ");
    scanf("%s",pmail->emetteur);

    printf("\nRentrer le destinataire du mail ");
    scanf("%s",pmail->destinataire);
 
    printf("\nRentrer l objet du mail: ");
    scanf("%s",pmail->objet);

    printf("\n Rentrer le corps du mail: ");
    scanf("%s",pmail->corps);  
}

void HowAnswer(MAIL pmail, FILE *fichier)
{
    
}

void searchVHSbyCategorie(MAIL pmail, FILE *fichier)
{
    VHS vhs;
    printf("recherche en cours....\n");
    fichier = OpenFileVhs(fichier, 2);
    bool finded = false;
    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {
    	if(strcmp(vhs.Categorie, pmail.objet) == 0)
    	{
    	   printf("Correspondance trouvé pour : %s\n", pmail.objet);
    	   displayVhsInfo(&vhs);
    	   finded = true;
    	}
    }
    if(finded == false)
    {
    	printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    
}

void searchVHSbyNom(VHS vhsToFind, FILE *fichier)
{
    VHS vhs;
    printf("recherche en cours....\n");
    fichier = OpenFileVhs(fichier, 2);
    bool finded = false;
    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {
    	if(strcmp(vhs.Nom, vhsToFind.Nom) == 0)
    	{
    	   printf("Correspondance trouvé pour : %s\n", vhsToFind.Nom);
    	   displayVhsInfo(&vhs);
    	   finded = true;
    	}
    }
    if(finded == false)
    {
    	printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    
}

int longeurChaine(char chaine[]){
	int i=0;
	while(chaine[i]!='\0')
	{
	   i++;
	}
	return i;	
}

int checkChaine(char *chaine, char *chaine2,int l1,int l2){
	
	if(l1!=l2){	
		return 0;
	}
	else {
		for(int i=0;i<l1-1;i++){	
			if(chaine[i]!=chaine2[i]){
				return 0;
				}	
	      }
		return 1;
	}
}
void adminMenu()
{
	int adminLoop=0,adminVar=0,adminTypeRecherche=0;
	VHS vhs;
        MAIL client_mail;
        FILE *fichier;
	while(adminLoop==0)
	{
			printf("Menu admin\n");
			printf("Pour ajouter ou supprimer une VHS, tapez 1\n");
			printf("Pour ajouter ou supprimer un compte client, tapez 2\n");
			printf("Pour afficher la liste des clients, tapez 3\n");
			printf("Pour quitter le mode admin, tapez 4\n");
			
			scanf("%d",&adminVar);
			
			switch(adminVar){
				
				case 1:
				printf("Si vous souhaitez ajouter une VHS, tapez 1\n");
				printf("Si vous souhaitez supprimer une VHS, tapez 2\n");
				scanf("%d",&adminTypeRecherche);
				
				if(adminTypeRecherche==1){
					
					creerVHS(&vhs, fichier);
					
				}else{
					
					//Fonction supprimer VHS
					
				}
				break;
				
				
				case 2:
				printf("Si vous souhaitez ajouter un compte client, tapez 1\n");
				printf("Si vous souhaitez supprimer un compte client, tapez 2\n");
				scanf("%d",&adminTypeRecherche);
				
				if(adminTypeRecherche==1){
					
					//Fonction ajouter client
					
				}else{
					
					//Fonction supprimer client
					
				}
				break;
				
				case 3:
				
					//fonction afficher tous les clients
				
				break;
				
				case 4:
				
					adminLoop=1;
				
				break;
			}
			
		
		
		
		printf("\n\n");		
	}
}
void displayMenu()
{
    int mainLoop=0,intMenu=0, intTypeRecherche=0;
    char MDPadmin[50]="4321";
    char MDPentree[50];	
    VHS vhs;
    MAIL client_mail;
    FILE *fichier;
	
	while(mainLoop==0)
	{
		printf("Menu principal\n");
		printf("Pour chercher une ou des VHS, tapez 1\n");
		printf("Pour chercher un client, tapez 2\n");
		printf("Pour tester la fonction de répose automatique, tapez 3\n");
		printf("Pour passer en mode admin, tapez 4\n");
		printf("Pour fermer le programme, tapez 5\n");
		scanf("%d",&intMenu);
	
		switch(intMenu)
		{
		
			case 1:
				printf("Pour utiliser le nom de la VHS, tapez 1\n");
				printf("sinon, pour utiliser son ID, tapez 2\n");
				printf("enfin, pour afficher toute les VHS disponible, tapez 3\n");
				scanf("%d",&intTypeRecherche);
				
				if(intTypeRecherche==1)
				{
					VHS vhsToFind;
					printf("Veuillez saisir le nom du film\n");
					scanf("%s", vhsToFind.Nom);
					searchVHSbyNom(vhsToFind, fichier);
					
				}
				else if(intTypeRecherche==2)
				{
					//Fonction de recherche VHS avec ID
				}
				else
				{
					displayALLVHS(fichier);
				}
				
				break;
				
			case 2:
				printf("Pour utiliser le nom du client, tapez 1, sinon, pour utiliser son ID tapez 2\n");
				scanf("%d",&intTypeRecherche);
				
				if(intTypeRecherche==1){
					//Fonction de recherche client avec nom
				}
				else{
					//Fonction de recherche client avec ID
				}
			
				break;
			
			case 3:
			        creerMail(&client_mail);
			        searchVHSbyCategorie(client_mail, fichier);
			        	
				break;
			
			case 4:
				printf("Rentrez le mot de passe admin: ");
				scanf("%s",MDPentree);
			
				if(checkChaine(&MDPentree,&MDPadmin,longeurChaine(&MDPentree),longeurChaine(&MDPadmin))==1)
				{
					printf("Acces autorise\n");
					adminMenu();
					
				}
				else
				{
					printf("Acces refuse\n");
				}				
				break;
			case 5:
				mainLoop=1;
				break;
	        }			
		printf("\n\n");
	}
}

int main( int argc, char * argv[] ) {
	VHS vhs;
	MAIL client_mail;
	FILE *fichier;
	displayMenu();
}
