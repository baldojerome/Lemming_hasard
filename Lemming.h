#ifndef LEMMING_H
#define LEMMING_H

#include <iostream>

using namespace std;

//modification de la classe Lemming 
//1er modif : enlever le count et ses methodes 
//2e modif : rajouter un setter servant pour le triage 

class Lemming
{
private:
	int id;

public:
	Lemming(int indice);
	friend ostream& operator<< (ostream&, const Lemming&);
	int getId();
	void SetId(int temp);

};

#endif
