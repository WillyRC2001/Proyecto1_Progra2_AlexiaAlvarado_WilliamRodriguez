#include "Empaque.h"

Empaque::Empaque(bool trip):tripa(trip)
{
}

Empaque::~Empaque()
{
}

string Empaque::toString()
{
	stringstream s;
	s << "Tripa: " << tripa << endl;
	return s.str();
}
