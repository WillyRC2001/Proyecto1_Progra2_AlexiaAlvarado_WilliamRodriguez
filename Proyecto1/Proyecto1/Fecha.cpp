#include "Fecha.h"

Fecha::Fecha()
{
	dia = 0;
	mes = 0;
	anio = 0;
}

Fecha::Fecha(int d, int m, int a)
{
	dia = d;
	mes = m;
	anio = a;
}

Fecha::~Fecha()
{
}

int Fecha::getDia()
{
	return this->dia;
}

int Fecha::getMes()
{
	return this->mes;
}

int Fecha::getAnio()
{
	return this->anio;
}

void Fecha::setDia(int d)
{
	this->dia = d;
}

void Fecha::setMes(int m)
{
	this->mes = m;
}

void Fecha::setAnio(int a)
{
	this->anio = a;
}

string Fecha::mostrarFecha()
{
	stringstream s; 
	s << " " << dia << " / " << mes <<" / " << anio << endl;
	return s.str();
}
