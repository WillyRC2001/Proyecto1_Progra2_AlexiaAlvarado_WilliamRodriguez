#include "Embutido.h"

Embutido::Embutido(string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, Fecha* fech1, Fecha* fech2, bool nacion, double pes, string nom_ani, string part_ani, string marc, Empaque* emp):
	Carne(cod, nom_comerc, descr, preci, categ, existe, limit, fech1, fech2, nacion, pes, nom_ani, part_ani), marca(marc),empaque(emp)
{

}

Embutido::~Embutido()
{
}

Empaque* Embutido::getEmpaque()
{
	return this->empaque;
}

string Embutido::getMarca()
{
	return this->marca;
}

void Embutido::setEmpaque(Empaque* empaquetadoEmbutido)
{
	this->empaque = empaquetadoEmbutido;
}

void Embutido::setMarca(string marcaEmbutido)
{
	this->marca = marcaEmbutido;
}

string Embutido::toString() const
{
	stringstream s;
	s << Carne::toString();
	if (empaque) {
		s << "Empaque: " << empaque->toString();
	}
	s << "Marca: " << marca << std::endl;
	s << "------------------------------" << endl;
	return s.str();
}
