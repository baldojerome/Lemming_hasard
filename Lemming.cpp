#include "Lemming.h"

#include <iostream>

using namespace std;

//modification de la classe Lemming 
//1er modif : enlever le count et ses methodes 
//2e modif : rajouter un setter servant le triage

Lemming::Lemming(int indice)
{
	this->id = indice;
}

int Lemming::getId()
{
	return id;
}

void Lemming::SetId(int temp)
{
	this->id = temp;
}

ostream& operator<< (ostream& out, const Lemming& lemming)
{
	out << lemming.id;
	return out;
}
