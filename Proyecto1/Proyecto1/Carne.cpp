#include "Carne.h"

Carne::Carne(string cod, string nom_comerc, string descr, double preci, string categ, Categoria* categor, int existe, int limit, Fecha* fech, bool nacion, double pes, string nom_ani, string part_ani) :
	Product_Perecedero(cod, nom_comerc, descr, preci, categ, categor, existe, limit, fech, nacion, pes), nom_animal(nom_ani), part_animal(part_ani)
{
}

Carne::~Carne()
{
}

string Carne::getNombreAnimal()
{
	return this->nom_animal;
}

string Carne::getParteAnimal()
{
	return this->part_animal;
}

void Carne::setNombreAnimal(string nomAnimal)
{
	this->nom_animal = nomAnimal;
}

void Carne::setParteAnimal(string partAnimal)
{
	this->part_animal = partAnimal;
}

string Carne::toString()
{
	stringstream s;
	s << Product_Perecedero::toString()<<endl;
	s << "Nombre del Animal: " << nom_animal << endl;
	s << "Parte del Animal: " << part_animal << endl;
	s << "-----------------------------------------" << endl;
	return s.str();
}
