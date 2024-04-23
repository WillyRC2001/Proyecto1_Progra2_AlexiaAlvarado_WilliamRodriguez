#include "Decorador_Conserva.h"

Decorador_Conserva::Decorador_Conserva(Componente_Abstracto* com, Conserva* conser) :
    Decorador_Abstracto(com), ptrConservas(conser)
{

}

Decorador_Conserva::~Decorador_Conserva()
{

}

Conserva* Decorador_Conserva::getConserva()
{
    return ptrConservas;
}

void Decorador_Conserva::setConserva(Conserva* nuevaConserva)
{
    ptrConservas = nuevaConserva;
}

string Decorador_Conserva::obtener_nombre()
{
    return ptrConservas->getNombre_Comercial();
}

string Decorador_Conserva::obtener_codigo()
{
    return ptrConservas->getCodigo();
}

double Decorador_Conserva::obtener_costo()
{
    return ptrConservas->calcularPrecioVenta() + ptrComponenteAbs->obtener_costo();
}


string Decorador_Conserva::toString()
{
    stringstream s;
    s << this->ptrConservas->getNombre_Comercial() << " y el costo sera de : " << ptrConservas->getPrecio() << endl;
    s << "-----------------------------------------------------------------------------------------------------" << endl;
    s << ptrComponenteAbs->toString() << endl;
    return s.str();
}