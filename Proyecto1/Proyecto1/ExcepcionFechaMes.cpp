#include "ExcepcionFechaMes.h"

ExcepcionFechaMes::ExcepcionFechaMes()
{
}

ExcepcionFechaMes::~ExcepcionFechaMes()
{
}

string ExcepcionFechaMes::toString() const
{
    return "ERROR: el dato digitado esta fuera de rango de fecha.\n";
}
