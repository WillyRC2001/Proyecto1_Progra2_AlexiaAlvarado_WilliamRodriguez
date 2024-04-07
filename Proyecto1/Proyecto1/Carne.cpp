#include "Carne.h"

Carne::Carne(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, Categoria* categor, int existe, int limit, bool nacion, double pes, string nom_ani, string part_ani) :
	Product_Perecedero(fech, cod, nom_comerc, descr, preci, categ, categor, existe, limit, nacion, pes), nom_animal(nom_ani), part_animal(part_ani)
{
}

Carne::~Carne()
{
}

string Carne::toString()
{
	stringstream s;
	s << Product_Perecedero::toString();
	s << "Nombre del Animal: " << nom_animal << endl;
	s << "Parte del Animal: " << part_animal << endl;
	s << "-----------------------------------------" << endl;
	return s.str();
}
