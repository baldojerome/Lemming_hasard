#include <iostream>
#include "Lemming.h"
#include <list>

using namespace std;

//---------POINT DE SITUATION--------
//modification de la classe Lemming 
//1er modif : enlever le count 
//2e modif : rajouter un setter servant le triage 

//la list est paramétré avec une taille de 50 pour 50 lemmings 
//les chiffres générés sont compris entre 1 et N (N = 50)
//-----------------------------------

//methode verifiant si le nombre est déja dans la list
// parcourt la list et verifie si le nombre est déjà dedans 
// si le nombre est présent alors retourne false 
//entrée : la list à examiner + nobre à comparé 
//sortie : booléen 
bool VerifEntier(list<Lemming>& tab, int nbr)
{
	bool verif = true;
	for (auto it : tab)
	{
		if (it.getId() == nbr)
		{
			verif = false;
		}
	}
	return verif;
}
//methode permettant de retourner un nombre aléatoire compris entre 1 et max donné en entrée 
//entree : int max / sortie : nombre généré 
int Proba(int max)
{
	int chiffreAlea = 0;
	chiffreAlea = 1 + rand() % (max + 1 - 1);
	return chiffreAlea;
}
//methode de tris à bulle adapté aux lists
void triBulles(list<Lemming>& a)
{
	int temp = 0;
	int i = 0;
	//double boucle 
	for (auto it : a)
	{
		//itérateur j positionné à 1 grace à advance 
		list<Lemming>::iterator j = a.begin();
		advance(j, 1);
		//iterateur end positionné à la fin. il décrémentera avec la soustraction de i
		list<Lemming>::iterator end = a.end();
		advance(end, -i);//i s'incrémente 

		for (j; j != end; j++)
		{
			list<Lemming>::iterator it1 = j;
			advance(it1, -1);
			//iterateur it1 prend la position de j
			//it1 se positionne avant 
			if (it1->getId() > j->getId())//condition qui compare les deux positions 
			{
				//intervertir avec une variable temporaire temp
				temp = it1->getId();
				it1->SetId(j->getId());
				j->SetId(temp);
			}
		}
		i++;
	}
}

int main()
{
    //taille donnée à 50 lemmings
	int taille = 50;
	list<Lemming>listLemming;

	for (int i = 0; i < taille; i++)
	{
		int choixLemming = 0;
		do
		{
			//generation de l'indice du lemming selon la methode Proba
			choixLemming = Proba(taille);
		} while (!VerifEntier(listLemming, choixLemming));
		//tant que le nombre généré est identique alors on génére
		//utilisation de la methode VerifEntier()

		listLemming.push_back(Lemming(choixLemming));
	}
	cout << "liste des Lemmings non triee" << endl;
	//affichage de la liste non triée
	for (auto it : listLemming)
	{
		cout << it << " - ";
	}
	cout << endl << endl;
	cout << "liste des Lemmings triee avec tri bulle" << endl;
	//utilisation du tri à bulle 
	triBulles(listLemming);
	//affichage de la liste triée
	for (auto it : listLemming)
	{
		cout << it << " - ";
	}
	cout << endl << endl;
    return 0;
}

