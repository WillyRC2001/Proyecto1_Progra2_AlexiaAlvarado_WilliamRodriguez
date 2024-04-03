#include "Product_Perecedero.h"

Product_Perecedero::Product_Perecedero(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, bool nacion, double pes):
	Producto(fech,cod,nom_comerc,descr,preci,categ,existe,limit), nacional(nacion), peso(pes)
{
}

Product_Perecedero::~Product_Perecedero()
{
}

string Product_Perecedero::toString()
{
	stringstream s;
	s << Producto::toString();
	s << "Producto Nacional: " << nacional << endl;
	s << "Peso: " << peso << endl;
	s << "----------------------------------" << endl;
	return s.str();
}
