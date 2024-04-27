#include "ExcepcionFactura.h"

ExcepcionFactura::ExcepcionFactura(){}

ExcepcionFactura::~ExcepcionFactura(){}

string ExcepcionFactura::toString() const
{
	return "ERROR: el numero de factura no existe.\n";
}
