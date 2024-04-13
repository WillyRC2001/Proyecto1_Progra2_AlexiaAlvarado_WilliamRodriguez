#include "Decorador_Conserva.h"

Decorador_Conserva::Decorador_Conserva(Componente_Abstracto* com, Conserva* cons)
{
    this->ptrComponenteAbs = com;
    this->conservar = cons;
}

Decorador_Conserva::~Decorador_Conserva()
{
    delete conservar;
}

double Decorador_Conserva::costo()
{
    return conservar->calcularPrecioVenta() + ptrComponenteAbs->costo();
}

string Decorador_Conserva::toString()
{
    stringstream s;
    s << this->conservar->getNombre_Comercial() << " y el costo sera de : " << conservar->getPrecio() << endl;
    s << ptrComponenteAbs->toString() << endl;
    return s.str();
}
