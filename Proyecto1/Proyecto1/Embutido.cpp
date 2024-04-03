#include "Embutido.h"

Embutido::Embutido(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, bool nacion, double pes, string nom_ani, string part_ani, string marc):
	Carne(fech,cod,nom_comerc,descr,preci,categ,existe,limit,nacion,pes,nom_ani,nom_comerc), marca(marc)
{
}

Embutido::~Embutido()
{
}

string Embutido::toString()
{
	stringstream s;
	s << Carne::toString();
	s << "Marca: " << marca << endl;
	s << "------------------------------" << endl;
	return s.str();
}
