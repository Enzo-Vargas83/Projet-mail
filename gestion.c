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


void displayMenu();
void adminMenu();
int checkChaine(char chaine[], char chaine2[]);
int longeurChaine(char chaine[]);

int checkIDVHS(char *IDtest);
void creerVHS(VHS *pfilm);
void deleteVHS();
void DeleteByNom(char inputUser[SIZE_CHAINE]);
void displayVhsInfo(VHS *vhs);
void displayALLVHS(FILE *fichier);
void searchVHSbyCategorie(MAIL pmail);

int checkIDClient(char *IDtest);
void displayALLClient();

void creerMail(MAIL *pmail);
int checkIDMAIL(char *IDtest);

FILE* OpenFileClient(FILE *fichier, int mode);
FILE* OpenFileVhs(FILE *fichier, int mode);
FILE* OpenFileMail(FILE *fichier, int mode);


FILE* OpenFileClient(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        // open file in order to write
        fichier = fopen("clientDataBase.bin", "ab+");
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
FILE* OpenFileKeyword(FILE *fichier, int mode)
{
    switch (mode)
    {
    case 1:
        // open file in order to write
        fichier = fopen("keywordDataBase.bin", "ab+");
        if(fichier == NULL)
    	{
		printf("Error opening file\n");
		exit(1);
    	}
        break;
    case 2:
    	// open file in order to READ
        fichier = fopen("keywordDataBase.bin", "rb+");
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
void deleteVHS()
{
    VHS vhs;
    char input[SIZE_CHAINE];
    
    printf("Entrer l'ID ou le nom de la VHS à supprimer : ");
    scanf("%s", input);
    DeleteByNom(input);
}

void displayVhsInfo(VHS *vhs)
{
	printf("\n==========================\n");
	printf("ID : %s\n", vhs->ID);
    	printf("Nom : %s\n", vhs->Nom);
    	printf("Categorie : %s", vhs->Categorie);
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

void DeleteByNom(char inputUser[SIZE_CHAINE])
{
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
    	if(strcmp(vhs.Nom, inputUser) == 0)
    	{
    	   printf("correspondance trouver, vhs supprimer");
    	   finded = true;
    	}
    	else 
    	{
		fwrite(&vhs, sizeof(VHS),4, temp);
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

int checkContenuMail(MAIL mailRecu){
	
	MAIL mail;
	//searchVHSbyCategorie(mailRecu);
	if(strstr(mailRecu.objet,"colis")!=NULL||strstr(mailRecu.corps,"colis")){
		strcpy(mail.ID,mailRecu.ID);
		strcpy(mail.emetteur,"leo@xgerbille.com");
		strcpy(mail.destinataire,mailRecu.emetteur);
		strcpy(mail.objet,"Reponse a votre requete");
		strcpy(mail.corps,"Veuillez vous rediriger vers la societe de transport\nCordialement");
		
		printf("Reponse automatique:\n");
		displayMail(&mail);
		
		return 1;
		
}

	if(strstr(mailRecu.objet,"resiliation")!=NULL||strstr(mailRecu.corps,"resiliation")){
		strcpy(mail.ID,mailRecu.ID);
		strcpy(mail.emetteur,"leo@xgerbille.com");
		strcpy(mail.destinataire,mailRecu.emetteur);
		strcpy(mail.objet,"Reponse a votre requete");
		strcpy(mail.corps,"Nos equipes etant actuellement surcharge, votre demande ne peut pas etre traite. Veuillez reessayer ulterieurement\nCordialement");
		
		printf("Reponse automatique:\n");
		displayMail(&mail);
		
		return 1;
		
}

	if(strstr(mailRecu.objet,"quoi")!=NULL||strstr(mailRecu.corps,"quoi")){
		strcpy(mail.ID,mailRecu.ID);
		strcpy(mail.emetteur,"leo@xgerbille.com");
		strcpy(mail.destinataire,mailRecu.emetteur);
		strcpy(mail.objet,"Reponse a votre requete");
		strcpy(mail.corps,"Feur\nCordialement");
		
		printf("Reponse automatique:\n");
		displayMail(&mail);
		
		return 1;
		
}

	if(strstr(mailRecu.objet,"emploi")!=NULL||strstr(mailRecu.corps,"emploi")){
		strcpy(mail.ID,mailRecu.ID);
		strcpy(mail.emetteur,"leo@xgerbille.com");
		strcpy(mail.destinataire,mailRecu.emetteur);
		strcpy(mail.objet,"Reponse a votre requete");
		strcpy(mail.corps,"Nous ne recherchons pas d’employe actuellement. Cependant, votre CV sera conserve pour nos futures	offres\nCordialement");
		
		printf("Reponse automatique:\n");
		displayMail(&mail);
		
		return 1;	
	}
	else
	{
		strcpy(mail.ID,mailRecu.ID);
		strcpy(mail.emetteur,"leo@xgerbille.com");
		strcpy(mail.destinataire,mailRecu.emetteur);
		strcpy(mail.objet,"Reponse a votre requete");
		strcpy(mail.corps,"");
		
		printf("Reponse automatique:\n");
		displayMail(&mail);
		searchVHSbyCategorie(mailRecu);
		printf("\n******************************************\n");
	}
	


 return 0; //retourne 0 si RAS

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
			printf("Menu admin\n");
			printf("Pour ajouter ou supprimer une VHS, tapez 1\n");
			printf("Pour ajouter ou supprimer un compte client, tapez 2\n");
			printf("Pour afficher la liste des clients, tapez 3\n");
			printf("Pour ajouter des mots clés, 4\n");
			printf("Pour afficher la liste des mots clés, 5\n");
			printf("Pour quitter le mode admin, tapez 6\n");
			
			scanf("%d",&adminVar);
			
			switch(adminVar){
				
				case 1:
				printf("Si vous souhaitez ajouter une VHS, tapez 1\n");
				printf("Si vous souhaitez supprimer une VHS, tapez 2\n");
				scanf("%d",&adminTypeRecherche);
				
				if(adminTypeRecherche==1){
					
					creerVHS(&vhs);
					
				}else{
					
					deleteVHS();
					
				}
				break;
				
				
				case 2:
				printf("Si vous souhaitez ajouter un compte client, tapez 1\n");
				printf("Si vous souhaitez supprimer un compte client, tapez 2\n");
				scanf("%d",&adminTypeRecherche);
				
				if(adminTypeRecherche==1){
					
					creerClient(&client);
					
				}else{
					
					//Fonction supprimer client
					
				}
				break;
				
				case 3:
				
					displayALLClient();
				
				break;
				
				case 4:
				
					creerKEYWORD(&keyword);
				case 5:
				
					displayALLKEYWORD();
					break;
				case 6:
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
					getchar();
					fgets(vhsToFind.Nom,SIZE_CHAINE,stdin);
					searchVHSbyNom(vhsToFind, fichier);
					
				}
				else if(intTypeRecherche==2)
				{
					VHS vhsToFind;
					printf("Veuillez saisir l'ID du film\n");
					scanf("%s", vhsToFind.ID);
					searchVHSbyID(vhsToFind, fichier);
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
			        checkContenuMail(client_mail);
			        //searchVHSbyCategorie(client_mail);
			        	
				break;
			
			case 4:
				printf("Rentrez le mot de passe admin: ");
				scanf("%s",MDPentree);
			
				if(checkChaine(MDPentree,MDPadmin)==1)
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
	}
int main( int argc, char * argv[] ) {
	VHS vhs;
	MAIL client_mail;
	FILE *fichier;
	createAllFile();
	displayMenu();
}
