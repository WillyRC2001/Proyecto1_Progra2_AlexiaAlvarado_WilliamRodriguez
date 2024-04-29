#pragma once
#include "Venta.h"

class Factura {
private:
    Venta* venta;
    int numFactura;
public:
    Factura(Venta*, int); 
    virtual ~Factura();
    int getNumeroFactura();
    Venta* getVenta();
    void setNumeroFactura(int);
    void setVenta(Venta*);
    bool buscarClientePorCedula(string cedula);

    string toString();
};
