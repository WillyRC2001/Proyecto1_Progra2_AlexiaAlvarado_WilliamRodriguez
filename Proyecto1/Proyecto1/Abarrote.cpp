#include "Abarrote.h"

Abarrote::Abarrote(string cod, string nom_comerc, string descr, double preci, string categ, Categoria*categor, int existe, int limit, Fecha* fech,bool nacion, double pes, string nom_empre):
	Product_Perecedero(cod,nom_comerc,descr,preci,categ,categor,existe,limit,fech,nacion,pes),nombre_empresa(nom_empre)
{
}

Abarrote::~Abarrote()
{
}

string Abarrote::getAbarroteNombreEmpresa()
{
	return this->nombre_empresa;
}

void Abarrote::setAbarroteNombreEmpresa(string N_E)
{
	this->nombre_empresa = N_E;
}

string Abarrote::toString()
{
	stringstream s;
	s << Product_Perecedero::toString()<<endl;
	s << "Nombre Empresa: " << nombre_empresa << endl;
	s << "--------------------------------------------" << endl;
	return s.str();
}
