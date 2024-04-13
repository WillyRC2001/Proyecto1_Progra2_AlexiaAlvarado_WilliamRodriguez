#include "Decorador_Embutido.h"

Decorador_Embutido::Decorador_Embutido(Componente_Abstracto* com, Embutido* emb)
{
    this->ptrComponenteAbs = com;
    this->embutidos = emb;
}

Decorador_Embutido::~Decorador_Embutido()
{
    delete embutidos;
}

double Decorador_Embutido::costo()
{
    return embutidos->calcularPrecioVenta() + ptrComponenteAbs->costo();
}

string Decorador_Embutido::toString()
{
    stringstream s; 
    s << this->embutidos->getNombre_Comercial() << " y el costo sera de : " << embutidos->getPrecio()<<endl;
    s << ptrComponenteAbs->toString() << endl;
    return s.str();
}
