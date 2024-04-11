#include "Empaque.h"

Empaque::Empaque(bool trip):tripa(trip)
{
}

Empaque::~Empaque()
{
}

bool Empaque::getTripa()
{
	return this->tripa;
}

void Empaque::setTripa(bool trippa)
{
	this->tripa = trippa;
}

string Empaque::toString()
{
	std::stringstream s;
	s << "Tipo de empaque: " << (tripa ? "Tripa" : "Otro") << endl;
	return s.str();
}
