#include "Factura.h"

Factura::Factura(Venta* v,int numeroFactura): venta(v),numFactura(numeroFactura)
{
}

Factura::~Factura() {
   
}
Venta* Factura::getVenta() {
    return venta;
}

int Factura::getNumeroFactura()
{
    return numFactura;
}

void Factura::setNumeroFactura(int num)
{
    numFactura = num;
}

void Factura::setVenta(Venta* ventanueva)
{
    venta = ventanueva;
}


string Factura::toString()
{
    stringstream s; 
    s << "-----------FACTURA-------------" << endl;
    s << "Numero de la Factura: " << numFactura << endl;
    s << venta->toString();
    s << "------------------------------------" << endl;
    
    return s.str();
}
