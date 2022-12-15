#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define SIZE_CHAINE 70
#define SIZE_ID 5

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
   char ID[SIZE_CHAINE];
   char NumTel[SIZE_CHAINE];
   char Nom[SIZE_CHAINE];
   char Mail[SIZE_CHAINE];
   int NbLocation;
   int PtsFidelite;
   int important;
} CLIENT;
typedef struct
{
    char ID[5];
    char emetteur[50];
    char destinataire[50];
    char objet[SIZE_CHAINE];
    char corps[150]; 
}MAIL;
typedef struct
{
    char WORD[SIZE_CHAINE];
    char ANSWER[150]; 
}KEYWORD;
typedef struct
{
    char ID[5];
    char emetteur[50];
    char destinataire[50];
    char objet[SIZE_CHAINE];
    char corps[150]; 
}REPONSE;


void displayMenu();
void adminMenu();
int checkChaine(char chaine[], char chaine2[]);
int longeurChaine(char chaine[]);

void checkForKeyword(MAIL *mail);
void displayKeyword(KEYWORD *keyword);

REPONSE lowerREP(REPONSE pmail);
void creerREP(MAIL *pmail);

int checkIDVHS(char *IDtest);
void creerVHS(VHS *pfilm);
void DeleteVHSByID();
void DeleteVHSByNom();

void displayVhsInfo(VHS *vhs);
void displayALLVHS(FILE *fichier);
void searchVHSbyCategorie(MAIL pmail);
void displayAllREP();
void displayREP(REPONSE *mail);
void searchVHSbyNom(VHS vhsToFind, FILE *fichier);

int checkIDClient(char *IDtest);
void displayCLIENT(CLIENT *client);
void displayALLClient();

void creerMail(MAIL *pmail);
int checkIDMAIL(char *IDtest);

FILE* OpenFileClient(FILE *fichier, int mode);
FILE* OpenFileVhs(FILE *fichier, int mode);
FILE* OpenFileMail(FILE *fichier, int mode);
FILE* OpenFileREP(FILE *fichier, int mode);

FILE* OpenFileREP(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        // open file in order to write
        fichier = fopen("reponseDataBase.bin", "ab+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	// open file in order to READ
        fichier = fopen("reponseDataBase.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    }
    return fichier;
}
FILE* OpenFileClient(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        //create and open file in order to write at the end of it
        fichier = fopen("clientDataBase.bin", "ab+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	//open file in order to READ
    	fichier = fopen("clientDataBase.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("clientDataBase.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 3:
    	//create and open file in order to write at the end of it
    	fichier = fopen("tempc.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("tempc.bin", "wb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 4:
    	// open file in order to READ
    	fichier = fopen("clientDataBase.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("clientDataBase.bin", "wb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 5:
    	// open file in order to READ
    	fichier = fopen("tempc.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("tempc.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    }
    return fichier;
}
FILE* OpenFileKeyword(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        //create and open file in order to write at the end of it
        fichier = fopen("keywordDataBase.bin", "ab+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	//open file in order to READ
    	fichier = fopen("keywordDataBase.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("keywordDataBase.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 3:
    	//create and open file in order to write at the end of it
    	fichier = fopen("tempk.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("tempk.bin", "wb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 4:
    	// open file in order to READ
    	fichier = fopen("keywordDataBase.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("keywordDataBase.bin", "wb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 5:
    	// open file in order to READ
    	fichier = fopen("tempk.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("tempk.bin", "rb+");
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
        //create and open file in order to write at the end of it
        fichier = fopen("vhsDataBase.bin", "ab+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	//open file in order to READ
    	fichier = fopen("vhsDataBase.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("vhsDataBase.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 3:
    	//create and open file in order to write at the end of it
    	fichier = fopen("temp.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("temp.bin", "wb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 4:
    	// open file in order to READ
    	fichier = fopen("vhsDataBase.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("vhsDataBase.bin", "wb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 5:
    	// open file in order to READ
    	fichier = fopen("temp.bin", "ab+");
    	fclose(fichier);
        fichier = fopen("temp.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    }
    return fichier;
}

FILE* OpenFileMail(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        // open file in order to write
        fichier = fopen("mailDataBase.bin", "ab+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	// open file in order to READ
        fichier = fopen("mailDataBase.bin", "rb+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    }
    return fichier;
}

void creerVHS(VHS *pfilm){

	FILE *fichier;
	int checkID=0;	
	
	while(checkID==0){
		printf("Rentrer l ID de la VHS : ");
    		scanf("%s",pfilm->ID);
    		checkID=checkIDVHS(pfilm->ID);
	}
	printf("Rentrer nom de la VHS: ");
	getchar();
	fgets(pfilm->Nom,SIZE_CHAINE,stdin);
	fflush(stdout);
	
	printf("Rentrer la catégorie de la VHS: ");
	fgets(pfilm->Categorie,SIZE_CHAINE,stdin);
	fflush(stdout);

	int i;
	printf("Combien il y a t-il d'acteur?: ");
	scanf("%d",&i);

	switch(i){

	case(1):
		printf("Rentrer le nom de l'acteur: ");
		getchar();
		fgets(pfilm->ActeurStar,SIZE_CHAINE,stdin);
		fflush(stdout);
		break;
	case(2):
		getchar();
		printf("Rentrer le nom du premier acteur: ");
		fgets(pfilm->ActeurStar,SIZE_CHAINE,stdin);
		fflush(stdout);
		printf("Rentrer le nom du deuxième acteur: ");
		fgets(pfilm->ActeurStar2,SIZE_CHAINE,stdin);
		fflush(stdout);
		break;
	case(3):
		getchar();
		printf("Rentrer le nom du premier acteur: ");
		fgets(pfilm->ActeurStar,SIZE_CHAINE,stdin);
		fflush(stdout);
		printf("Rentrer le nom du deuxième acteur: ");
		fgets(pfilm->ActeurStar2,SIZE_CHAINE,stdin);
		fflush(stdout);
		printf("Rentrer le nom du troisième acteur: ");
		fgets(pfilm->ActeurStar3,SIZE_CHAINE,stdin);
		fflush(stdout);
		break;
	}
	printf("\n");
    	fichier = OpenFileVhs(fichier, 1);
	fseek(fichier,0,SEEK_END);
	fwrite(pfilm, sizeof(VHS),1, fichier);
	fclose(fichier);
}
int checkIDMAIL(char *IDtest){
    FILE *fichier;
    MAIL mail;
	
    fichier = OpenFileMail(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&mail, sizeof(MAIL), 1, fichier))
    {
	if(checkChaine(IDtest,mail.ID)==1)
	{
		fclose(fichier);
		return 0;
	}
    }
    fclose(fichier);	
    return 1;
}
int checkIDVHS(char *IDtest){
    FILE *fichier;
    VHS vhs;
	
    fichier = OpenFileVhs(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {
	if(checkChaine(IDtest,vhs.ID)==1)
	{
		fclose(fichier);
		return 0;
     	}


    }
    fclose(fichier);
    return 1;	
    //return 1 si l'ID est unique
}

void creerMail(MAIL *pmail){
   int checkID=0;
   FILE *fichier;	
   while(checkID==0)
   {
	printf("Rentrer l ID du mail: ");
    	scanf("%s",pmail->ID);
    	checkID=checkIDMAIL(pmail->ID);
   }


    printf("\nRentrer l emetteur du mail: ");
    scanf("%s",pmail->emetteur);

    printf("\nRentrer le destinataire du mail ");
    scanf("%s",pmail->destinataire);
 
    printf("\nRentrer l objet du mail: ");
    getchar();
    fgets(pmail->objet,25,stdin);

    printf("\nRentrer le corps du mail: ");
    getchar();
    fgets(pmail->corps,150,stdin); 
    
    fichier = OpenFileMail(fichier, 1);
    fseek(fichier,0,SEEK_END);
    fwrite(pmail, sizeof(MAIL),1, fichier);
    fclose(fichier);
}

void displayMail(MAIL *mail)
{
	printf("\n******************************************\n");
	printf("ID : %s\n", mail->ID);
    	printf("Emetteur : %s\n", mail->emetteur);
    	printf("Destinataire : %s\n", mail->destinataire);
    	printf("objet : %s\n",mail->objet);
    	printf("corps : %s",mail->corps);
}

void displayAllMail()
{   FILE *fichier;
	
	
    MAIL mail;
    fichier = OpenFileMail(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&mail, sizeof(MAIL), 1, fichier))
    {
    	displayMail(&mail);
    }
    fclose(fichier);
}

void displayVhsInfo(VHS *vhs)
{
	printf("\n==========================\n");
	printf("ID : %s\n", vhs->ID);
    	printf("Nom : %s\n", vhs->Nom);
    	printf("Categorie : %s", vhs->Categorie);
    	printf("Acteur principal : %s", vhs->ActeurStar);
    	printf("\n==========================\n");
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

MAIL lowerMAIL(MAIL pmail)
{
	for(int i = 0; pmail.objet[i]; i++)
	{
          pmail.objet[i] = tolower(pmail.objet[i]);
	}
		for(int i = 0; pmail.corps[i]; i++)
	{
          pmail.corps[i] = tolower(pmail.corps[i]);
	}
	
	
	return pmail;
}

VHS lowerVHS (VHS vhs)
{
	for(int i = 0; vhs.Categorie[i]; i++)
	{
          vhs.Categorie[i] = tolower(vhs.Categorie[i]);
	}
	return vhs;
}

CLIENT lowerClient (CLIENT client)
{
	for(int i = 0; client.Nom[i]; i++)
	{
          client.Nom[i] = tolower(client.Nom[i]);
	}
	return client;
}

void searchVHSbyCategorie(MAIL pmail)
{
    VHS vhs;
    FILE *fichier;
    printf("recherche en cours....\n");
    fichier = OpenFileVhs(fichier, 2);
    bool finded = false;
    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {
    	if(strstr(lowerMAIL(pmail).objet,lowerVHS(vhs).Categorie)!=NULL)
    	{
    	   printf("Correspondance trouvé pour : %s\n", pmail.objet);
    	   displayVhsInfo(&vhs);
    	   finded = true;
    	}
    }
    if(finded == false)
    {
    	printf("Aucune correspondance trouvé dans notre catalogue,\n");
    	printf("nous vous présentons nos excuse, cordialement.\n");
    }
    
}
void DeleteKeyword()
{
    printf("Entrer le mot clé : ");
    KEYWORD input;
    getchar();
    fgets(input.WORD,SIZE_CHAINE,stdin);
    fflush(stdout);
    input.WORD[strlen(input.WORD)-1] = '\0';
    KEYWORD key;
    FILE *fichier;
    FILE *temp;
    printf("recherche en cours....\n");
    fichier = OpenFileKeyword(fichier, 2);
    temp = OpenFileKeyword(fichier, 3);
    bool finded = false;
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&key, sizeof(KEYWORD), 1, fichier))
    {    
    	printf("keyword input : [%s]\n", input.WORD);
    	printf("keyword data : [%s]\n", key.WORD);
        if(strcmp(key.WORD, input.WORD) == 0)
        {
           printf("correspondance trouver, vhs supprimer");
           finded = true;
        }
        else 
        {
        fwrite(&key, sizeof(KEYWORD),1, temp);
        }
    }
    if(finded == false)
    {
        printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    fclose(fichier);
    fclose(temp);
    temp = OpenFileKeyword(fichier, 5);
    fichier = OpenFileKeyword(fichier, 4);
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&key, sizeof(KEYWORD), 1, temp))
    {    
           fwrite(&key, sizeof(KEYWORD),1, fichier);
    }
    fclose(fichier);
    fclose(temp);
}

void DeleteVHSByID()
{
    printf("Entrer l'ID de la VHS à supprimer : ");
    VHS input;
    getchar();
    fgets(input.ID,SIZE_CHAINE,stdin);
    fflush(stdout);
    input.ID[strlen(input.ID)-1] = '\0';
    VHS vhs;
    FILE *fichier;
    FILE *temp;
    printf("recherche en cours....\n");
    fichier = OpenFileVhs(fichier, 2);
    temp = OpenFileVhs(fichier, 3);
    bool finded = false;
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {    
        if(strcmp(vhs.ID, input.ID) == 0)
        {
           printf("correspondance trouver, vhs supprimer");
           finded = true;
        }
        else 
        {
        fwrite(&vhs, sizeof(VHS),1, temp);
        }
    }
    if(finded == false)
    {
        printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    fclose(fichier);
    fclose(temp);
    temp = OpenFileVhs(fichier, 5);
    fichier = OpenFileVhs(fichier, 4);
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&vhs, sizeof(VHS), 1, temp))
    {    
           fwrite(&vhs, sizeof(VHS),1, fichier);
    }
    fclose(fichier);
    fclose(temp);
}

void DeleteVHSByNom()
{
    printf("Entrer le nom de la VHS à supprimer : ");
    VHS input;
    getchar();
    fgets(input.Nom,SIZE_CHAINE,stdin);
    fflush(stdout);
    VHS vhs;
    FILE *fichier;
    FILE *temp;
    printf("recherche en cours....\n");
    fichier = OpenFileVhs(fichier, 2);
    temp = OpenFileVhs(fichier, 3);
    bool finded = false;
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);

    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {    
        if(strcmp(vhs.Nom, input.Nom) == 0)
        {
           printf("correspondance trouver, vhs supprimer");
           finded = true;
        }
        else 
        {
        fwrite(&vhs, sizeof(VHS),1, temp);
        }
    }
    if(finded == false)
    {
        printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    fclose(fichier);
    fclose(temp);
    temp = OpenFileVhs(fichier, 5);
    fichier = OpenFileVhs(fichier, 4);
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&vhs, sizeof(VHS), 1, temp))
    {    
           fwrite(&vhs, sizeof(VHS),1, fichier);
    }
    fclose(fichier);
    fclose(temp);
}

void DeleteClientByID()
{
    printf("Entrer l'ID du client à supprimer : ");
    CLIENT input;
    getchar();
    fgets(input.ID,SIZE_CHAINE,stdin);
    fflush(stdout);
    input.ID[strlen(input.ID)-1] = '\0';
    CLIENT client;
    FILE *fichier;
    FILE *temp;
    printf("recherche en cours....\n");
    fichier = OpenFileClient(fichier, 2);
    temp = OpenFileClient(fichier, 3);
    bool finded = false;
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);

    while(fread(&client, sizeof(CLIENT), 1, fichier))
    {    
        if(strcmp(client.ID, input.ID) == 0)
        {
           printf("correspondance trouver, vhs supprimer");
           finded = true;
        }
        else 
        {
        fwrite(&client, sizeof(CLIENT),1, temp);
        }
    }
    if(finded == false)
    {
        printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    fclose(fichier);
    fclose(temp);
    temp = OpenFileClient(fichier, 5);
    fichier = OpenFileClient(fichier, 4);
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&client, sizeof(CLIENT), 1, temp))
    {    
           fwrite(&client, sizeof(CLIENT),1, fichier);
    }
    fclose(fichier);
    fclose(temp);
}

void AddPtstoclient()
{
    printf("Entrer le nom du client : ");
    CLIENT input;
    getchar();
    fgets(input.Nom,SIZE_CHAINE,stdin);
    fflush(stdout);
    input.Nom[strlen(input.Nom)-1] = '\0';
    CLIENT client;
    FILE *fichier;
    FILE *temp;
    printf("recherche en cours....\n");
    fichier = OpenFileClient(fichier, 2);
    temp = OpenFileClient(fichier, 3);
    bool finded = false;
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&client, sizeof(CLIENT), 1, fichier))
    {    
        if(strcmp(lowerClient(client).Nom, lowerClient(input).Nom) == 0)
        {
           printf("Entrer le nombre de point à ajouter : ");
           int nb = 0;
           scanf("%d", &nb);
           client.PtsFidelite = client.PtsFidelite + nb;
           fwrite(&client, sizeof(CLIENT),1, temp);
           finded = true;
        }
        else 
        {
        fwrite(&client, sizeof(CLIENT),1, temp);
        }
    }
    if(finded == false)
    {
        printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    fclose(fichier);
    fclose(temp);
    temp = OpenFileClient(fichier, 5);
    fichier = OpenFileClient(fichier, 4);
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&client, sizeof(CLIENT), 1, temp))
    {    
           fwrite(&client, sizeof(CLIENT),1, fichier);
    }
    fclose(fichier);
    fclose(temp);
}
void DeleteClientByNom()
{
    printf("Entrer le nom du client à supprimer : ");
    CLIENT input;
    getchar();
    fgets(input.Nom,SIZE_CHAINE,stdin);
    fflush(stdout);
    input.ID[strlen(input.ID)-1] = '\0';
    CLIENT client;
    FILE *fichier;
    FILE *temp;
    printf("recherche en cours....\n");
    fichier = OpenFileClient(fichier, 2);
    temp = OpenFileClient(fichier, 3);
    bool finded = false;
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);

    while(fread(&client, sizeof(CLIENT), 1, fichier))
    {    
        if(strcmp(client.Nom, input.Nom) == 0)
        {
           printf("correspondance trouver, vhs supprimer");
           finded = true;
        }
        else 
        {
        fwrite(&client, sizeof(CLIENT),1, temp);
        }
    }
    if(finded == false)
    {
        printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    fclose(fichier);
    fclose(temp);
    temp = OpenFileClient(fichier, 5);
    fichier = OpenFileClient(fichier, 4);
    fseek(fichier,0,SEEK_SET);
    fseek(temp,0,SEEK_SET);
    while(fread(&client, sizeof(CLIENT), 1, temp))
    {    
           fwrite(&client, sizeof(CLIENT),1, fichier);
    }
    fclose(fichier);
    fclose(temp);
}

void searchClientbyNom(CLIENT clientToFind)
{
    CLIENT client;
    FILE *fichier;
    printf("recherche en cours....\n");
    fichier = OpenFileClient(fichier, 2);
    bool finded = false;
    while(fread(&client, sizeof(CLIENT), 1, fichier))
    {
    	printf("\nclient fic : %s\n", client.Nom);
    	printf("\nclient : %s\n", clientToFind.Nom);
    	if(strcmp(client.Nom, clientToFind.Nom) == 0)
    	{
    	   printf("Correspondance trouvé pour : %s\n", client.Nom);
    	   displayCLIENT(&client);
    	   finded = true;
    	}
    }
    if(finded == false)
    {
    	printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    
}
void searchClientbyID(CLIENT clientToFind)
{
    CLIENT client;
    FILE *fichier;
    printf("recherche en cours....\n");
    fichier = OpenFileClient(fichier, 2);
    bool finded = false;
    while(fread(&client, sizeof(CLIENT), 1, fichier))
    {
    	if(strcmp(client.ID, clientToFind.ID) == 0)
    	{
    	   printf("Correspondance trouvé pour : %s\n", client.Nom);
    	   displayCLIENT(&client);
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

void searchKEYWORDbyWORD(KEYWORD keyTo)
{
    FILE *fichier;
    KEYWORD key;
    printf("recherche en cours....\n");
    fichier = OpenFileKeyword(fichier, 2);
    bool finded = false;
    while(fread(&key, sizeof(KEYWORD), 1, fichier))
    {
    	if(strcmp(key.WORD, keyTo.WORD) == 0)
    	{
    	   printf("Correspondance trouvé pour : %s\n", key.WORD);
    	   displayKeyword(&key);
    	   finded = true;
    	}
    }
    if(finded == false)
    {
    	printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    
}

void searchVHSbyID(VHS vhsToFind, FILE *fichier)
{
    VHS vhs;
    printf("recherche en cours....\n");
    fichier = OpenFileVhs(fichier, 2);
    bool finded = false;
    while(fread(&vhs, sizeof(VHS), 1, fichier))
    {
    	if(strcmp(vhs.ID, vhsToFind.ID) == 0)
    	{
    	   printf("Correspondance trouvé pour : %s\n", vhsToFind.ID);
    	   displayVhsInfo(&vhs);
    	   finded = true;
    	}
    }
    if(finded == false)
    {
    	printf("Aucune correspondance trouvé dans notre catalogue\n");
    }
    
}

int checkIDClient(char *IDtest)
{
	FILE *fichier;
	CLIENT client;
	
    fichier = OpenFileClient(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
		while(fread(&client, sizeof(CLIENT), 1, fichier))
		{   
			if(checkChaine(IDtest,client.ID)==1){
			fclose(fichier);
			return 0;
			}   
		}
    fclose(fichier);
	
	return 1;
	
	//return 1 si l'ID est unique
}

void creerClient(CLIENT *pclient)
{
    int checkID=0;
    FILE *fichier;	
	
    while(checkID==0)
    {
	printf("Rentrer l ID du client: ");
        scanf("%s",pclient->ID);
        checkID=checkIDClient(pclient->ID);
    }


    printf("\nRentrer nom du client : ");
    scanf("%s",pclient->Nom);

    printf("\nRentrer le numéro de téléphone du client ");
    scanf("%s",pclient->NumTel);
 
    printf("\nRentrer un mail: ");
    scanf("%s",pclient->Mail);
    
    printf("\nRentrer l'importance du client: ");
    scanf("%d",&pclient->important);

    
    pclient->NbLocation = 0;
    pclient->PtsFidelite = 0;
    
    fichier = OpenFileClient(fichier, 1);
	fseek(fichier,0,SEEK_END);
	fwrite(pclient, sizeof(CLIENT),1, fichier);
	fclose(fichier);
}


void displayCLIENT(CLIENT *client)
{
	printf("\n==========================\n");
	printf("IDclient : %s\n", client->ID);
    	printf("Nom : %s\n", client->Nom);
    	printf("Numero de telephone : %s\n", client->NumTel);
    	printf("Adresse mail : %s\n",client->Mail);
    	printf("Nombre de location : %d\n",client->NbLocation);
    	printf("Nombre de points de fidélité : %d",client->PtsFidelite);
    	printf("\n==========================\n");
}

void displayALLClient()
{   
    FILE *fichier;	
    CLIENT client;
    fichier = OpenFileClient(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&client, sizeof(CLIENT), 1, fichier))
    {
    	displayCLIENT(&client);
    }
    fclose(fichier);
}

void creerKEYWORD(KEYWORD *keyword)
{
    FILE *fichier;
    printf("\nRentrer le mot clé: ");
    scanf("%s",keyword->WORD);

    printf("\nRentrer la réponse associé : ");
    getchar();
    fgets(keyword->ANSWER,150,stdin); 
    
    fichier = OpenFileKeyword(fichier, 1);
    fseek(fichier,0,SEEK_END);
    fwrite(keyword, sizeof(KEYWORD),1, fichier);
    fclose(fichier);
}

void displayKeyword(KEYWORD *keyword)
{
	printf("\n==========================\n");
	printf("Mot clé : %s\n", keyword->WORD);
    	printf("Réponse associé : %s", keyword->ANSWER);
    	printf("\n==========================\n");
}

void displayALLKEYWORD()
{   
    FILE *fichier;
    KEYWORD keyword;
    fichier = OpenFileKeyword(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&keyword, sizeof(KEYWORD), 1, fichier))
    {
    	displayKeyword(&keyword);
    }
    fclose(fichier);
}


int longeurChaine(char chaine[]){
	int i=0;
	while(chaine[i]!='\0')
	{
	   i++;
	}
	return i;	
}

int checkChaine(char *chaine, char *chaine2){
	int l1,l2;
	
	l1=longeurChaine(chaine);
	l2=longeurChaine(chaine2);
	
	
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
	
	//return 1 si la chaine est la meme
}

void adminMenu()
{
	int adminLoop=0,adminVar=0,adminTypeRecherche=0;
	VHS vhs;
        MAIL client_mail;
        CLIENT client;
        KEYWORD keyword;
        FILE *fichier;
	while(adminLoop==0)
	{
		adminmenu:
			printf("==================Menu admin==================\n");
			printf("1) Ajouter ou supprimer une VHS\n");
			printf("2) Ajouter ou supprimer un compte client\n");
			printf("3) Afficher la liste des clients\n");
			printf("4) Ajouter ou supprimer des mots clés\n");
			printf("5) Afficher la liste des mots clés\n");
			printf("6) Afficher les réponses automatiques envoyées\n");
			printf("7) Rechercher un mot clé et sa réponse associé\n");
			printf("8) Ajouter des pts à un client\n");
			printf("9) Quitter le mode admin\n");
			printf("==============================================\n");		
			
			if (scanf("%d", &adminVar) != 1)

			{

			    while (getchar() != '\n')

			    continue;

			    printf("Erreur de saisie, rentrez un nombre entre 1 et 7 \n");

			    goto adminmenu;

			}
			
			switch(adminVar){
				
				case 1:
				printf("1) Si vous souhaitez ajouter une VHS\n");
				printf("2) Si vous souhaitez supprimer une VHS\n");
				scanf("%d",&adminTypeRecherche);
				
				if(adminTypeRecherche==1){
					
					creerVHS(&vhs);
					
				}else{
					int inputV=0;
					printf("1) Si vous souhaitez supprimer une VHS par nom\n");
					printf("2) Si vous souhaitez supprimer une VHS par id \n");
					scanf("%d",&inputV);
					if(inputV==1)
					{
					    DeleteVHSByNom();
					}
					else
					{
					   DeleteVHSByID();
					}			
				}
				break;
				
				
				case 2:
					printf("1) Ajouter un compte client\n");
					printf("2) Supprimer un compte client\n");
					scanf("%d",&adminTypeRecherche);
					
					if(adminTypeRecherche==1)
					{
						
						creerClient(&client);
						
					}
					else{
						int inputV=0;
						printf("1) Si vous souhaitez supprimer un client par nom\n");
						printf("2) Si vous souhaitez supprimer un client par id \n");
						scanf("%d",&inputV);
						if(inputV==1)
						{
						    DeleteClientByNom();
						}
						else
						{
						   DeleteClientByID();
						}	
						
						}
					break;
				
				case 3:
				
					displayALLClient();
					break;
				
				case 4:
					printf("1) Ajouter un mot clé\n");
					printf("2) Supprimer un mot clé\n");
					scanf("%d",&adminTypeRecherche);
					
					if(adminTypeRecherche==1)
					{
						creerKEYWORD(&keyword);	
					}
					else
					{
						DeleteKeyword();
					}
					break;
				case 5:
				
					displayALLKEYWORD();
					break;
					
				case 6:
					displayAllREP();
					break;
				case 7:
					KEYWORD keyToFind;
					printf("Veuillez un mot clé : \n");
					scanf("%s", keyToFind.WORD);
					searchKEYWORDbyWORD(keyToFind);
				case 8:
					AddPtstoclient();
					break;
				case 9:
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
	  menu:
		printf("==============Menu principal==============\n");
		printf("1) Recherche de VHS\n");
		printf("2) Chercher un client\n");
		printf("3) Réponse automatique de mail\n");
		printf("4) Passer en mode admin\n");
		printf("5) Quitter\n");
		printf("==========================================\n");	
		if (scanf("%d", &intMenu) != 1)
		{
		    while (getchar() != '\n')
		    continue;
		    printf("Erreur de saisie, rentrez un nombre entre 1 et 5 \n");
		    goto menu;
		}
		switch(intMenu)
		{
		
			case 1:

				printf("==============================================\n");
				printf("1) Recherche en utilisant le nom de la VHS\n");
				printf("2) Recherche en utilisant l'ID\n");
				printf("3) Afficher toutes les VHS en stock\n");
				printf("==============================================\n");
				scanf("%d",&intTypeRecherche);
				
				if(intTypeRecherche==1)
				{
					VHS vhsToFind;
					printf("Veuillez saisir le nom du film : \n");
					getchar();
					fgets(vhsToFind.Nom,SIZE_CHAINE,stdin);
					searchVHSbyNom(vhsToFind, fichier);
					
				}
				else if(intTypeRecherche==2)
				{
					VHS vhsToFind;
					printf("Veuillez saisir l'ID du film : \n");
					scanf("%s", vhsToFind.ID);
					searchVHSbyID(vhsToFind, fichier);
				}
				else
				{
					displayALLVHS(fichier);
				}
				
				break;
				
			case 2:
				printf("1) Recherche par le nom du client\n");
				printf("2) Recherche par l'ID du client\n");

				scanf("%d",&intTypeRecherche);
				
				if(intTypeRecherche==1){
					CLIENT clientToFind;
					printf("Veuillez saisir le nom du client : \n");
					scanf("%s", clientToFind.Nom);
					searchClientbyNom(clientToFind);
				}
				else{
					CLIENT clientToFind;
					printf("Veuillez saisir l'ID du client : \n");
					scanf("%s", clientToFind.ID);
					searchClientbyID(clientToFind);
				}
			
				break;
			
			case 3:
			        creerMail(&client_mail);
			        checkForKeyword(&client_mail);
			        	
				break;
			
			case 4:
				printf("Rentrez le mot de passe administrateur : \n");
				scanf("%s",MDPentree);
			
				if(checkChaine(MDPentree,MDPadmin)==1)
				{
					printf("Accès autorisé\n");
					adminMenu();
					
				}
				else
				{
					printf("Accès refusé\n");
				}				
				break;
			case 5:
				mainLoop=1;
				break;
	        }			
		printf("\n\n");
	}
}

void createAllFile(){

	FILE *fichier;

        fichier = fopen("clientDataBase.bin", "ab+");
        fclose(fichier);
        fichier = fopen("vhsDataBase.bin", "ab+");
        fclose(fichier);
        fichier = fopen("mailDataBase.bin", "ab+");
        fclose(fichier);  
        fichier = fopen("keywordDataBase.bin", "ab+");
        fclose(fichier);  
        fichier = fopen("reponseDataBase.bin", "ab+");
        fclose(fichier);  
}

void checkForKeyword(MAIL *mail){
	
	FILE *fichier;
    KEYWORD keyword;
    MAIL reponse;
    
    


    fichier = OpenFileKeyword(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&keyword, sizeof(KEYWORD), 1, fichier))
    {

		if(strstr(mail->objet,keyword.WORD)!=NULL || strstr(mail->corps,keyword.WORD)!=NULL){
			
		strcpy(reponse.ID,mail->ID);
		strcpy(reponse.emetteur,"leo@xgerbille.com");
		strcpy(reponse.destinataire,mail->emetteur);
		strcpy(reponse.objet,"Reponse a votre requete");
		strcpy(reponse.corps,keyword.ANSWER);
		
		printf("\nReponse automatique:");
		displayMail(&reponse);
		creerREP(&reponse);
			
		}

    }
    fclose(fichier);
	
}

void displayREP(REPONSE *mail)
{
	printf("\n******************************************\n");
	printf("ID : %s\n", mail->ID);
    	printf("Emetteur : %s\n", mail->emetteur);
    	printf("Destinataire : %s\n", mail->destinataire);
    	printf("objet : %s\n",mail->objet);
    	printf("corps : %s",mail->corps);
}


void displayAllREP()
{   
	FILE *fichier;
	
	
    REPONSE mail;
    fichier = OpenFileREP(fichier, 2);
    fseek(fichier, 0 ,SEEK_SET);
    while(fread(&mail, sizeof(REPONSE), 1, fichier))
    {
    	displayREP(&mail);
    }
    fclose(fichier);
}

REPONSE lowerREP(REPONSE pmail)
{
	for(int i = 0; pmail.objet[i]; i++)
	{
          pmail.objet[i] = tolower(pmail.objet[i]);
	}
		for(int i = 0; pmail.corps[i]; i++)
	{
          pmail.corps[i] = tolower(pmail.corps[i]);
	}
	
	
	return pmail;
}

void creerREP(MAIL *pmail){
   FILE *fichier;	
   
   REPONSE rep;

   strcpy(rep.ID,pmail->ID);
   strcpy(rep.emetteur,pmail->emetteur);
   strcpy(rep.destinataire,pmail->destinataire);
   strcpy(rep.objet,pmail->objet);
   strcpy(rep.corps,pmail->corps);

    
    fichier = OpenFileREP(fichier, 1);
    fseek(fichier,0,SEEK_END);
    fwrite(&rep, sizeof(REPONSE),1, fichier);
    fclose(fichier);
}


int main( int argc, char * argv[] ) {
	VHS vhs;
	MAIL client_mail;
	FILE *fichier;
	createAllFile();
	displayMenu();
}
