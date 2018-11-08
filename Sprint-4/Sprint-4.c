#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define max_champs 25 // Nombre maximum de champs d’une table
#define lgMot 30 // Longueur max d’une chaine de caractères
#define lgMax 80 // Longueur maximale d’une ligne de commande
#define max_enregistrement 185 // Longueur maximale d’une ligne de commande
typedef struct {
	char nom[lgMot + 1]; //nom des champs
	char type[lgMot + 1]; //type des champs 
} Champ;

typedef struct {
	char nomdata[lgMot + 1];//nom
}Data;
typedef struct {
	Data data[lgMot + 1];//une donnée a un nom 
}Enregistrement;
typedef struct {
	char nom[lgMot + 1];
	Champ schema[max_champs];// creation d'un tableau ,dans chacune des cases il y'aura nom et type 
	unsigned char nbChamps;//nombre de champs
	int nbEnregistrement;//nombre d'enregistrements
	Enregistrement lignes[lgMax + 1];//un enregistrement est composé de données et une donnée a un nom
} Table;


void Create_table(Table*  t);//Fonction Create_table 
void Afficher_schema(Table* t);//Fonction  qui permet d'afficher le structure d'un table de donnée
void Insert_enregistrement(Table* t);//Fonction d'insertion d'un enregistrement
void Afficher_enregistrements(Table* t);//Fonction d'affichage de tout les enregistrements 
void Delete_enregistrement(Table* t);//Fonction de supression d'une ligne d'enregistrement
void Afficher_enregistrement(Table* t);//Fonctiond'affichage d'un enregistrement choisie
void Delete_table(Table* t);//Fonction de Suppression d'une table

int main() {
	Table t;

	t.nbEnregistrement = 0;
	while (1) { // ou do {…} while(1); // boucle infinie sur les 7 commandes
		char mot[30];
		scanf("%s", mot); 
		if (strcmp(mot, "Create_table") == 0) {
			Create_table(&t);
		}
		else if (strcmp(mot, "Afficher_schema") == 0) {
			Afficher_schema(&t);
		}
		else if (strcmp(mot, "Insert_enregistrement") == 0) {

			Insert_enregistrement(&t);
		}
		else if (strcmp(mot, "Delete_enregistrement") == 0) {
			Delete_enregistrement(&t);
		}
		else if (strcmp(mot, "Afficher_enregistrements") == 0) {
			Afficher_enregistrements(&t);
		}
		else if (strcmp(mot, "Afficher_enregistrement") == 0) {
			Afficher_enregistrement(&t);
		}
		else if (strcmp(mot, "Delete_table") == 0) {
			Delete_table(&t);
		}
		else if (strcmp(mot, "Exit") == 0) {
			exit(0); // sortie du programme principal
		}

	}
	system("pause");
	return 0;
}
void Create_table(Table*  t) {
	char nom[lgMot + 1];
	scanf("%s", &nom);

	if (strcmp(nom, t->nom) == 0) {//on verfie si  la table existe
		printf("table existante\n");
	}
	else {
		strcpy(t->nom, nom);//on memorise le nom de table saisie 
		scanf("%hhu", &t->nbChamps);//memorise le nb de champs de la table 
		for (unsigned int i = 0; i < t->nbChamps; ++i) {//tant que i est inferieur au nombre de champs on continu de proposer une saisie
			scanf("%s", &t->schema[i].nom);//saise du nom du champ
			scanf("%s", &t->schema[i].type);//saisie du type du champ

		}
	}
}
void Afficher_schema(Table* t) {
	char nom[lgMot + 1];
	scanf("%s", nom);//saisie
	if (strcmp(nom, t->nom) == 0) {//on verifie si la table existe
		printf("%s %u\n", t->nom, t->nbChamps);
		for (unsigned int j = 0; j < t->nbChamps; ++j) {//boucle FOR pour afficher les donnees du tableau schema
			printf("%s %s\n", t->schema[j].nom, t->schema[j].type);
		}
	}
	else {
		printf("table inconnue\n");
	}
}
void Insert_enregistrement(Table* t) {
	char nomTable[lgMot + 1];
	scanf("%s", &nomTable);
	if (strcmp(nomTable, t->nom) == 0) {//verifie si la table existe
		for (int i = 0; i < t->nbChamps; ++i) {
			scanf("%s", &t->lignes[t->nbEnregistrement].data[i].nomdata);//premier tableau pour la ligne de l'enregistrement et le deuxieme tableau pour la donnee de cette enregistrement
		}
		t->nbEnregistrement++;//on incremmente a chaque fois que on fait appel a cette fonction
	}
	else
	{
		printf("table inconnue\n");
	}
}
void Afficher_enregistrements(Table* t) {
	char nomtable[lgMot + 1];
	scanf("%s", &nomtable);
	if (strcmp(nomtable, t->nom) == 0)//verifie si la table existe
	{
		for (int j = 0; j < t->nbEnregistrement; ++j) {
			printf("%d", j + 1);
			for (int i = 0; i < t->nbChamps; ++i) {
				printf(" %s %s", t->schema[i].type, t->lignes[j].data[i].nomdata);
			}
			printf("\n");
		}
	}
	else {
		printf("table inconnue");
	}
}
void Delete_enregistrement(Table* t) {
	char nomtable[30];
	int numeroEnregistrement;

	scanf("%s", &nomtable);
	if (strcmp(nomtable, t->nom) == 0) {//verifie si la table existe
		scanf("%d", &numeroEnregistrement);
		int NumeroEnregistrement = numeroEnregistrement - 1;
		if (NumeroEnregistrement > t->nbEnregistrement - 1) {//verfie si le numero d'enregistrement saisie existe
			printf("Enregistrement inexistant");
		}
		else {
			for (int i = NumeroEnregistrement; i < t->nbEnregistrement; ++i) {//la boucle commence  a partir du numero saisie -1
				for (int j = 0; j<t->nbChamps; ++j) {
					strcpy(t->lignes[i].data[j].nomdata, t->lignes[i + 1].data[j].nomdata);//on ecrase la donnee suivante avec la donnee precedente
				}
			}
			t->nbEnregistrement--;//on decremente 
		}
	}
	else {
		printf("table inconnue");
	}
}
void Afficher_enregistrement(Table* t) {
	char nomtable[30];
	int numeroEnregistrement;

	scanf("%s", &nomtable);
	if (strcmp(nomtable, t->nom) == 0) {//verfie si la table existe
		scanf("%d", &numeroEnregistrement);
		int NumeroEnregistrement = numeroEnregistrement - 1;
		if (NumeroEnregistrement + 1 > t->nbEnregistrement) {//verifie si l'enregistrement existe si le nombre saisie est supperieur au nb total d'enregistrement alors il existe pas
			printf("enregistrement inconnu");
		}
		else {
			printf("%d", numeroEnregistrement);
			for (int j = 0; j<t->nbChamps; ++j) {
				printf(" %s %s", t->schema[j].type, t->lignes[NumeroEnregistrement].data[j].nomdata);//on affiche l'enregistrement demandé
			}
			printf("\n");
		}
	}
	else {
		printf("table inconnue");
	}
}
void Delete_table(Table* t) {
	char nom[lgMot + 1];
	scanf("%s", nom);
	if (strcmp(nom, t->nom) != 0) {//verifie si la table existe
		printf("table inconnue\n");
	}
	else {
	// \0 signifie fin de chaine de caractere donc remet a 0 toute les enregistrements
		for (int j = 0; j < t->nbEnregistrement; ++j) {
			for (int i = 0; i < t->nbChamps; ++i) {
			strcpy(t->schema[i].nom, "\0");
			strcpy(t->schema[i].type, "\0");
			
				strcpy(t->lignes[j].data[i].nomdata, "\0");
			}
		}
		t->nbEnregistrement = 0;
		t->nbChamps = 0;

		strcpy(t->nom, "\0");
	}
}