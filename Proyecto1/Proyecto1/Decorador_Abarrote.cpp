#include "Decorador_Abarrote.h"


Decorador_Abarrote::Decorador_Abarrote(Componente_Abstracto* com, Abarrote* abarr)
{
    this->ptrComponenteAbs = com;
    this->abarrotes = abarr;
}

Decorador_Abarrote::~Decorador_Abarrote()
{
    delete abarrotes;
}

double Decorador_Abarrote::costo()
{
    return abarrotes->calcularPrecioVenta() + ptrComponenteAbs->costo();
}

string Decorador_Abarrote::toString()
{
    stringstream s;
    s << this->abarrotes->getNombre_Comercial() << " y el costo sera de : " << abarrotes->getPrecio() << endl;
    s << ptrComponenteAbs->toString() << endl;
    return s.str();
}
