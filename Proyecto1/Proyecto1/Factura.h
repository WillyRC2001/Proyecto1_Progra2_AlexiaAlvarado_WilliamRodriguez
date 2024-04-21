#pragma once
#include "Cliente.h"
#include "Fecha.h"
#include "Decorador_Abstracto.h"

class Factura {
private:
    Fecha* fechaFactura;
    int numFactura;
public:
    Factura();
    Factura(Fecha*, int); 
    virtual ~Factura();
    Fecha* getFactura();
    int getNumeroFactura();
    void setFactura(Fecha*);

    string mostrarResumenFactura();
};
