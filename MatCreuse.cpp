#include "MatCreuse.h"

MatCreuse::MatCreuse()
{
	LireFichierMat1();
	LireFichierMat2();

	Afficher(Mat1);
	cout << endl;
	Afficher(Mat2);
	//EcrireFichierMat1();
	//EcrireFichierMat2();
	Additionner(Mat1, Mat2, Mat3);
	//Transposee(Mat1);
	cout << endl;
	Afficher(Mat3);
}

//Méthodes opérations élémentaires

void MatCreuse::Additionner(Matrice Mat, Matrice Mata, Matrice Matadd)
{
	/*
	for(int i=0 ; i<Mat.tabLignes.size() ; i++)
	{
		for(int j=0 ; j<Mata.tabLignes.size() ; j++)
		{
			if((Mat.tabLignes[i] == Mata.tabLignes[j]) && (Mat.tabColonnes[i] == Mata.tabColonnes[j]))
			{
				Matadd.tabLignes.push_back(Mat.tabLignes[i]);
				Matadd.tabColonnes.push_back(Mat.tabColonnes[i]);
				Matadd.tabValeurs.push_back(Mat.tabValeurs[i] + Mata.tabValeurs[i]);
				i++;
			}
			else if((Mat.tabLignes[i] <= Mata.tabLignes[j]) && (Mat.tabColonnes[i] < Mata.tabColonnes[j]))
			{
				Matadd.tabLignes.push_back(Mat.tabLignes[i]);
				Matadd.tabColonnes.push_back(Mat.tabColonnes[i]);
				Matadd.tabValeurs.push_back(Mat.tabValeurs[i]);
				i++;
			}
			else if((Mat.tabLignes[i] >= Mata.tabLignes[j]) && (Mat.tabColonnes[i] > Mata.tabColonnes[j]))
			{
				Matadd.tabLignes.push_back(ata.tabLignes[j]);
				Matadd.tabColonnes.push_back(Mata.tabColonnes[j]);
				Matadd.tabValeurs.push_back(Mata.tabValeurs[j]);
			}
		}
	}*/

	int i=0;
	int j=0;
	int tmp;
	while(i<Mat.tabLignes.size())
	{
			if((Mat.tabLignes[i] == Mata.tabLignes[j]) && (Mat.tabColonnes[i] == Mata.tabColonnes[j]))
			{
				Matadd.tabLignes.push_back(Mat.tabLignes[i]);
				Matadd.tabColonnes.push_back(Mat.tabColonnes[i]);
				tmp = Mat.tabValeurs[i] + Mata.tabValeurs[j];
				cout << Mat.tabValeurs[0] << Mata.tabValeurs[0];
				cout << Matadd.tabValeurs[0];
				cin >> tmp;
				Matadd.tabValeurs.push_back(tmp);
				i++;
				j++;
			}
			else if((Mat.tabLignes[i] <= Mata.tabLignes[j]) && (Mat.tabColonnes[i] < Mata.tabColonnes[j]))
			{
				Matadd.tabLignes.push_back(Mat.tabLignes[i]);
				Matadd.tabColonnes.push_back(Mat.tabColonnes[i]);
				Matadd.tabValeurs.push_back(Mat.tabValeurs[i]);
				i++;
			}
			else if((Mat.tabLignes[i] >= Mata.tabLignes[j]) && (Mat.tabColonnes[i] > Mata.tabColonnes[j]))
			{
				Matadd.tabLignes.push_back(Mata.tabLignes[j]);
				Matadd.tabColonnes.push_back(Mata.tabColonnes[j]);
				Matadd.tabValeurs.push_back(Mata.tabValeurs[j]);
				j++;
			}
	}
	
	cout << endl;
	cout << Matadd.tabLignes.size() << endl;
	cout << "ligne  Colonne  Valeur" << endl;
	for(int i=0 ; i<Mat.tabLignes.size() ; i++)
	{
		cout << Mat.tabLignes[i] << "      ";
		cout << Mat.tabColonnes[i] << "        ";
		cout << Mat.tabValeurs[i] << endl;
	}
}

void MatCreuse::Soustraire()
{
	
}

void MatCreuse::Multiplier()
{
	
}

void MatCreuse::Transposee(Matrice Mat)
{
	int tailleMax = Mat.tabLignes.size();
	int tmp;
	for(int i=0 ; i<Mat.tabLignes.size() ; i++)
	{
		tmp = Mat.tabLignes[i];
		Mat.tabLignes[i] = Mat.tabColonnes[i];
		Mat.tabColonnes[i] = tmp;
	}
}

//Méthodes de fond
void MatCreuse::Afficher(Matrice Mat)
{
	cout << "ligne  Colonne  Valeur" << endl;
	for(int i=0 ; i<Mat.tabLignes.size() ; i++)
	{
		cout << Mat.tabLignes[i] << "      ";
		cout << Mat.tabColonnes[i] << "        ";
		cout << Mat.tabValeurs[i] << endl;
	}
}

bool TailleIdentique(Matrice Mat, Matrice Mata)
{
	if((Mat.tabLignes.size() == Mata.tabLignes.size()) && (Mat.tabColonnes.size() == Mata.tabColonnes.size()))
		return true;
	else
		return false;
}

bool MatCreuse::TailleLigCol(Matrice Mat, Matrice Mata)
{
	if((Mat.tabLignes.size() == Mata.tabColonnes.size()) && (Mat.tabColonnes.size() == Mata.tabLignes.size()))
		return true;
	return false;
}

//Méthodes liées aux fichiers
int MatCreuse::NombreLignesMat1()
{
	string str;
	int nbLignes = 0;
	ifstream fichier("bin/MatriceCreuseMat1.txt", ios::in);
	if(fichier)
	{
		while(getline(fichier, str))					// tant que l'on peut lire une ligne
			nbLignes++;									//Incrémentation du nombre de lignes
		fichier.close();	
	}
	return nbLignes;
}

int MatCreuse::NombreLignesMat2()
{
	string str;
	int nbLignes = 0;
	ifstream fichier("bin/MatriceCreuseMat2.txt", ios::in);
	if(fichier)
	{
		while(getline(fichier, str))					// tant que l'on peut lire une ligne
			nbLignes++;									//Incrémentation du nombre de lignes
		fichier.close();	
	}
	return nbLignes;
}

int MatCreuse::NombreColMat1()
{
	char caractere;
	int nbCol = 1;
	ifstream fichier("bin/MatriceCreuseMat1.txt", ios::in);
	if(fichier)
	{
		do
		{
			fichier.get(caractere);
			if(caractere == ' ')					// si le caractère est un espace
				nbCol++;							//Incrémentation du nombre de colonnes
		}while(caractere != '\n');					// tant que le caractère n'est pas un retour à la ligne
		fichier.close();
	}
	return nbCol;
}

int MatCreuse::NombreColMat2()
{
	char caractere;
	int nbCol = 1;
	ifstream fichier("bin/MatriceCreuseMat2.txt", ios::in);
	if(fichier)
	{
		do
		{
			fichier.get(caractere);
			if(caractere == ' ')					// si le caractère est un espace
				nbCol++;							//Incrémentation du nombre de colonnes
		}while(caractere != '\n');					// tant que le caractère n'est pas un retour à la ligne
		fichier.close();
	}
	return nbCol;
}

bool MatCreuse::LireFichierMat1()
{
	int nbLignes = NombreLignesMat1();
	int nbCol = NombreColMat1();
	int valeurLue;

	ifstream fichier("bin/MatriceCreuseMat1.txt", ios::in);
	if(fichier)
	{
		for(int i=0 ; i<nbLignes ; i++)					//Parcourt des lignes de la matrice
		{
			for(int j=0 ; j<nbCol ; j++)				//Parcourt des colonnes de la matrice
			{
				fichier >> valeurLue;
				if((valeurLue != 0) || ((i == nbLignes-1) && (j == nbCol-1)))
				{
					Mat1.tabLignes.push_back(i);			//Récupération de la ligne
					Mat1.tabColonnes.push_back(j);			//Récupération de la colonne
					Mat1.tabValeurs.push_back(valeurLue);	//Récupération de la valeur
				}
			}
		}
		return true;
	}
	else
		cout << "Impossible d'ouvrir le fichier." << endl;
	return false;
}

bool MatCreuse::LireFichierMat2()
{
	int nbLignes = NombreLignesMat2();
	int nbCol = NombreColMat2();
	int valeurLue;

	ifstream fichier("bin/MatriceCreuseMat2.txt", ios::in);
	if(fichier)
	{
		for(int i=0 ; i<nbLignes ; i++)					//Parcourt des lignes de la matrice
		{
			for(int j=0 ; j<nbCol ; j++)				//Parcourt des colonnes de la matrice
			{
				fichier >> valeurLue;
				if((valeurLue != 0) || ((i == nbLignes-1) && (j == nbCol-1)))
				{
					Mat2.tabLignes.push_back(i);				//Récupération de la ligne
					Mat2.tabColonnes.push_back(j);			//Récupération de la colonne
					Mat2.tabValeurs.push_back(valeurLue);	//Récupération de la valeur
				}
			}
		}
		return true;
	}
	else
		cout << "Impossible d'ouvrir le fichier." << endl;
	return false;
}

void MatCreuse::EcrireFichierMat1()
{
	ofstream fichier("bin/MatriceCompresseeMat1.txt", ios::out | ios::trunc);
	if(fichier)
	{
		fichier << "ligne  Colonne  Valeur" << endl;
		for(int i=0 ; i<Mat1.tabLignes.size() ; i++)
		{
			fichier << Mat1.tabLignes[i] << "      ";
			fichier << Mat1.tabColonnes[i] << "        ";
			fichier << Mat1.tabValeurs[i] << endl;
		}
	}
}

void MatCreuse::EcrireFichierMat2()
{
	ofstream fichier("bin/MatriceCompresseeMat2.txt", ios::out | ios::trunc);
	if(fichier)
	{
		fichier << "ligne  Colonne  Valeur" << endl;
		for(int i=0 ; i<Mat2.tabLignes.size() ; i++)
		{
			fichier << Mat2.tabLignes[i] << "      ";
			fichier << Mat2.tabColonnes[i] << "        ";
			fichier << Mat2.tabValeurs[i] << endl;
		}
	}
}
