#include "Percedero.h"

Percedero::Percedero(Fecha* venceEl): venceEl(venceEl)
{
}

Percedero::~Percedero()
{
}

Fecha* Percedero::getVenceEl() const
{
    return venceEl;
}

void Percedero::setVenceEl(Fecha* venceTalFecha)
{
    venceEl = venceTalFecha;
}

string Percedero::toString()
{
    stringstream s; 
    s << "Fecha de vencimiento: " << venceEl->mostrarFecha();
    return s.str();
}

