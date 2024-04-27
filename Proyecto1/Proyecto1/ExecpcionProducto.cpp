#include "ExecpcionProducto.h"

ExcepcionProducto::ExcepcionProducto(){}

ExcepcionProducto::~ExcepcionProducto(){}

string ExcepcionProducto::toString() const
{
    return "ERROR: el codigo del producto no existe.\n";
}
