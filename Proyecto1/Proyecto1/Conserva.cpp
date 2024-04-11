#include "Conserva.h"

Conserva::Conserva(string cod, string nom_comerc, string descr, double precio, string categ, Categoria* categor, int existe, int limit, Fecha* fech, bool envasado)
    : Producto(cod, nom_comerc, descr, precio, categ, categor, existe, limit, fech), envasado(envasado)
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
