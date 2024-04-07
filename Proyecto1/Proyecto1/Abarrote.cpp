#include "Abarrote.h"

Abarrote::Abarrote(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, Categoria*categor, int existe, int limit, bool nacion, double pes, string nom_empre):
	Product_Perecedero(fech,cod,nom_comerc,descr,preci,categ,categor,existe,limit,nacion,pes),nombre_empresa(nom_empre)
{
}

Abarrote::~Abarrote()
{
}

string Abarrote::toString()
{
	stringstream s;
	s << Product_Perecedero::toString();
	s << "Nombre Empresa: " << nombre_empresa << endl;
	s << "--------------------------------------------" << endl;
	return s.str();
}
