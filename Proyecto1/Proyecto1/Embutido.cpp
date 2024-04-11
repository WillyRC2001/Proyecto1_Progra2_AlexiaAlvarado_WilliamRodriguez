#include "Embutido.h"

Embutido::Embutido(string cod, string nom_comerc, string descr, double preci, string categ, Categoria* categoria2, int existe, int limit, Fecha* fech, bool nacion, double pes, string nom_ani, string part_ani, string marc):
	Carne(cod, nom_comerc, descr, preci, categ, categoria2, existe, limit, fech, nacion, pes, nom_ani, part_ani), marca(marc)
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

string Embutido::toString()
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
