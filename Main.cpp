#include "MatCreuse.h"

int main()
{
	MatCreuse matthew;
	if(matthew.LireFichier())
		cout << "réussi" << endl;
	else
		cout << "caca" << endl;
	return 0;
}
