#include "Empaque.h"

Empaque::Empaque(bool trip):tripa(trip)
{
}

Empaque::~Empaque()
{
}

bool Empaque::getTripa() const
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
	s << "Tipo de empaque: " << (tripa ? "Si" : "No") << endl;
	return s.str();
}
