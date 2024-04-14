#include "Conserva.h"

Conserva::Conserva(string cod, string nom_comerc, string descr, double precio, string categ, int existe, int limit, Fecha* fech, bool envasado)
    : Producto(cod, nom_comerc, descr, precio, categ, existe, limit, fech), envasado(envasado)
{

}

bool Conserva::getEnvasado() {
    return envasado;
}

void Conserva::setEnvasado(bool ProdEnvasado) {
    this->envasado = ProdEnvasado;
}

string Conserva::toString()
{
	stringstream s;
	s << Producto::toString();
	s << "Envasado: " << envasado << endl;
	s << "------------------------------------" << endl;
	return s.str();
}
