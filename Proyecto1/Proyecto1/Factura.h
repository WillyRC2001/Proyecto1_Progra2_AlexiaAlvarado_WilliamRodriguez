#pragma once
#include "Cliente.h"
#include "Fecha.h"
#include "Decorador_Abstracto.h"

class Factura {
private:
    Fecha* fechaFactura;
    Cliente* cliente;
    int numFactura;
public:
    Factura();
    Factura(Fecha*, int); 
    virtual ~Factura();
    Fecha* getFactura();
    int getNumeroFactura();
    void setNumeroFactura(int);
    void setFactura(Fecha*);
    void setCliente(Cliente*);

    string mostrarResumenFactura();
};
