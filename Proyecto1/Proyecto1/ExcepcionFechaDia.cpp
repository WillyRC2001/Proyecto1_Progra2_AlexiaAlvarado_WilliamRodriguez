#include "ExcepcionFechaDia.h"

ExcepcionFechaDia::ExcepcionFechaDia()
{
}

ExcepcionFechaDia::~ExcepcionFechaDia()
{
}

string ExcepcionFechaDia::toString() const
{
    return "ERROR: el dato digitado esta fuera de rango de fecha.\n";
}
