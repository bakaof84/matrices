#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

typedef struct Matrice Matrice;
struct Matrice
{
	vector<int> tabLignes;
	vector<int> tabColonnes;
	vector<int> tabValeurs;
};

class MatCreuse
{
  private:
	
	Matrice Mat1;
	Matrice Mat2;
	Matrice Mat3;

  public:
	//Le constructeur par défaut
	MatCreuse();

	//Méthodes opérations élémentaires
	void Additionner(Matrice Mat, Matrice Mata, Matrice Matadd);
	void Soustraire();
	void Multiplier();
	void Transposee(Matrice Mat);
		
	//Méthodes de fond
	void Afficher(Matrice Mat);
	bool TailleIdentique(Matrice Mat, Matrice Mata);	// Matrices de même taille
	bool TailleLigCol(Matrice Mat, Matrice Mata);	// mat1.tailleLig = mat2.tailleCol
	
	//Méthodes liées aux fichiers
	bool LireFichierMat1();		//Charger la matrice 1
	bool LireFichierMat2();		//Charger la matrice 2
	int NombreLignesMat1();		//Compter le nombre de lignes de la matrice 1
	int NombreLignesMat2();		//Compter le nombre de lignes de la matrice 2
	int NombreColMat1();		//Compter le nombre de colonnes de la matrice 1
	int NombreColMat2();		//Compter le nombre de colonnes de la matrice 2
	void EcrireFichierMat1();	//sauvegarder la matrice 1
	void EcrireFichierMat2();	//sauvegarder la matrice 2
};
