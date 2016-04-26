#include <iostream>
#include <fstream>
#include <string>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class MatCreuse
{
  private:
	int ligne[];
	int col[];
	int val[];
  public:
	//Les constructeurs par défaut créeront une matrice creuse compressée
	MatCreuse();
	MatCreuse(int tailleX, int tailleY);

	//Méthodes opérations élémentaires
	void OperatorPlus();
	void OperatorMoins();
	void OperatorFoie();
	void OperateurTransposee();
		
	//Méthodes de fond
	void Afficher();
	bool TestTailleIdentique();	// Matrices de même taille
	bool TestTailleLigCol();		// mat1.tailleLig = mat2.tailleCol
	void InsererValeursMatrice(int x, int y, int valeur);
	bool LireFichier();		// charger();
	void EcrireFichier();	//sauvegarder();
};
