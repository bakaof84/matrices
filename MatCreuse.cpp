#include "MatCreuse.h"

MatCreuse::MatCreuse()
{
	ligne[10];
	col[10];
	val[10];
}

bool MatCreuse::LireFichier()
{
	ifstream fichier("pd.txt", ios::in);
	if(fichier)
	{
		int indice, nbLignes, nbcol = 0;
		string str;
		char caractere;
		
        while(getline(fichier, str))					// tant que l'on peut lire une ligne
        	nbLignes++;									//Incrémentation du nombre de lignes
		cout << nbLignes << endl;
		for(int i=0 ; i<nbLignes ; i++)					//Parcourt les lignes de la matrice
		{
			fichier.seekg(0, ios::beg);
			caractere = 'T';
			cin >> caractere;
			while(caractere != '\0')					// tant que le caractère lu n'est pas un retour à la ligne
			{
				fichier.get(caractere);
				fichier.seekg(1, ios::cur);
				cout << caractere << endl;
				if(caractere == ' ')					// si le caractère est un espace
					nbcol++;							//Incrémentation du nombre de colonnes
			}
			nbcol+=1;

			for(int j=0 ; j<=nbcol ; j++)				//On parcourt les colonnes de la matrice
			{
				fichier.seekg(0, ios::beg);
				ligne[indice] = i;						//Récupération de la ligne
				col[indice] = j;						//Récupération de la colonne
				fichier >>  val[indice];				//Récupération de la valeur
				indice++;
			}

			fichier.seekg(1, ios::cur);					//Déplacement d'un caractère à partir de la position actuelle
			nbcol = 0;
			cout << ligne[1] << col[1] << val[1] << endl;
			return true;
		}
	}
	else
		cout << "Impossible d'ouvrir le fichier." << endl;
	return false;
}

//TODO
//définition de la longueur des tableaux
