#include "Factura.h"

Factura::Factura()
{
    this->fechaFactura = NULL;
    this->numFactura = 0;
}

Factura::Factura(Fecha* fecFactura,int numeroFactura): fechaFactura(fecFactura),numFactura(numeroFactura)
{
}

Factura::~Factura() {
   
}

Fecha* Factura::getFactura()
{
    return fechaFactura;
}

int Factura::getNumeroFactura()
{
    return numFactura;
}

void Factura::setFactura(Fecha* ff)
{
    fechaFactura = ff;
}


string Factura::mostrarResumenFactura()
{
    stringstream s; 
    s << "-------------------------------------" <<endl;
    s << "Fecha de Factura: " << this->fechaFactura->mostrarFecha() << endl;
    s << "Numero de la Factura: " << numFactura << endl;
    
    return s.str();
}
