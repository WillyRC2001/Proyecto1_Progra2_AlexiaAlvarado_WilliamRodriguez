#include "ExcepcionGuardado.h"

ExcepcionGuardado::ExcepcionGuardado()
{
}

ExcepcionGuardado::~ExcepcionGuardado()
{
}

string ExcepcionGuardado::toString() const
{
	return "ERROR: No se pudo guardar el archivo.\n";
}
