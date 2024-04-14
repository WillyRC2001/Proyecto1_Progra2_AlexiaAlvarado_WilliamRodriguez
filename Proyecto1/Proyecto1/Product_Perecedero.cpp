#include "Product_Perecedero.h"

Product_Perecedero::Product_Perecedero(string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, Fecha* fech1,Fecha* fech2,bool nacion, double pes):
	Producto(cod,nom_comerc,descr,preci,categ,existe,limit, fech1), nacional(nacion), peso(pes), percedero(new Percedero(fech2))
{
}

Product_Perecedero::~Product_Perecedero()
{
	delete percedero;
}

bool Product_Perecedero::getNacional() 
{
	return this->nacional;
}

double Product_Perecedero::getPeso() 
{
	return this->peso;
}

Percedero* Product_Perecedero::getPercedero() 
{
	return this->percedero;
}

void Product_Perecedero::setNacional(bool NacioN)
{
	this->nacional = NacioN;
}

void Product_Perecedero::setPeso(double pes)
{
	this->peso = pes;
}

void Product_Perecedero::setPercedero(Percedero* perced)
{
	this->percedero = perced;
}

string Product_Perecedero::toString()
{
	stringstream s;
	s << Producto::toString();
	s << "Producto Nacional: " << (nacional ? "Si" : "No") <<endl;
	s << "Peso: " << peso <<endl;
	s << "Percedero: " << percedero->toString() << endl;
	s << "----------------------------------" << endl;
	return s.str();
}
