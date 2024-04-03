#include "Producto.h"

Producto::Producto(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit):
	fecha(fech),codigo(cod),nombre_comercial(nom_comerc),
	descripion(descr),precio_costo(preci),categoria(categ),
	existencia(existe),limite(limit)
{
}

Producto::~Producto()
{
}

string Producto::toString()
{
	stringstream s;
	s << "-------------------PRODUCTO-----------------" << endl<<endl;
	s << "Codigo: " << codigo << endl;
	s << "Nombre: " << nombre_comercial << endl;
	s << "Precio: " << precio_costo << endl;
	s << "Categoria: " << categoria << endl;
	s << "Descripcion: " << descripion << endl;
	s << "Existencia: " << existencia << endl;
	s << "Limite: " << limite << endl;
	s << "----------------------------------------------" << endl;
	return s.str();
}
