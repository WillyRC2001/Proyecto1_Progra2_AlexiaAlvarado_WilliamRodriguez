#include "Fecha.h"

Fecha::Fecha(int d, int m, int a)
{
	dia = d;
	mes = m;
	anio = a;
}

Fecha::~Fecha()
{
}

string Fecha::ToString()
{
	stringstream s; 
	s << " " << dia << " / " << mes" / " << anio << endl;
	return string();
}
