#include "Decorador_Abarrote.h"


Decorador_Abarrote::Decorador_Abarrote(Componente_Abstracto* com, Abarrote* abarr):
    Decorador_Abstracto(com),ptrAbarrotes(abarr)
{
    
}

Decorador_Abarrote::~Decorador_Abarrote()
{
    
}

Abarrote* Decorador_Abarrote::getAbarrote()
{
    return ptrAbarrotes;
}

void Decorador_Abarrote::setAbarrote(Abarrote* nuevoAbarrote)
{
    ptrAbarrotes = nuevoAbarrote;
}

string Decorador_Abarrote::obtener_nombre()
{
    return ptrAbarrotes->getNombre_Comercial();
}

string Decorador_Abarrote::obtener_codigo()
{
    return ptrAbarrotes->getCodigo();
}

double Decorador_Abarrote::obtener_costo()
{
    return ptrAbarrotes->calcularPrecioVenta() + ptrComponenteAbs->obtener_costo();
}


string Decorador_Abarrote::toString()
{
    stringstream s;
    s << this->ptrAbarrotes->getNombre_Comercial() << " y el costo sera de : " << ptrAbarrotes->getPrecio() << endl;
    s << "-----------------------------------------------------------------------------------------------------" << endl;
    s << ptrComponenteAbs->toString() << endl;
    return s.str();
}
