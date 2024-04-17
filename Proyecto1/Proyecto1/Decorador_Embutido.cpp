#include "Decorador_Embutido.h"

Decorador_Embutido::Decorador_Embutido(Componente_Abstracto* com, Embutido* embut) :Decorador_Abstracto(com), ptrEmbutidos(embut)
{

}

Decorador_Embutido::~Decorador_Embutido()
{

}

Embutido* Decorador_Embutido::getEmbutido()
{
    return ptrEmbutidos;
}

void Decorador_Embutido::setEmbutido(Embutido* nuevoEmbutido)
{
    ptrEmbutidos = nuevoEmbutido;
}

string Decorador_Embutido::obtener_nombre()
{
    return ptrEmbutidos->getNombre_Comercial();
}

string Decorador_Embutido::obtener_codigo()
{
    return ptrEmbutidos->getCodigo();
}

double Decorador_Embutido::obtener_costo()
{
    return ptrEmbutidos->calcularPrecioVenta() + ptrComponenteAbs->obtener_costo();
}


string Decorador_Embutido::toString()
{
    stringstream s;
    s << this->ptrEmbutidos->getNombre_Comercial() << " y el costo sera de : " << ptrEmbutidos->getPrecio() << endl;
    s << "-----------------------------------------------------------------------------------------------------" << endl;
    s << ptrComponenteAbs->toString() << endl;
    return s.str();
}