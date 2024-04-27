#include "ExcepcionRango.h"

ExcepcionFueraRango::ExcepcionFueraRango()
{
}

ExcepcionFueraRango::~ExcepcionFueraRango()
{
}

string ExcepcionFueraRango::toString() const
{
	return "ERROR: el dato digitado esta fuera de rango.\n";
}
