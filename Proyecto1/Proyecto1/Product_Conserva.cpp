#include "Product_Conserva.h"

Product_Conserva::Product_Conserva(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, bool enva):
	Producto(fech,cod,nom_comerc,descr,preci,categ,existe,limit),envasado(enva)
{
}

Product_Conserva::~Product_Conserva()
{
}

string Product_Conserva::toString()
{
	stringstream s;
	s << Producto::toString();
	s << "Envasado: " << envasado << endl;
	s << "------------------------------------" << endl;
	return s.str();
}
