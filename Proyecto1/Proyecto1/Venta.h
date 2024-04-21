#pragma once
#include "Factura.h"


class Venta {
private:
    Cliente* clienteCompra;
    Fecha* fechaCompra;
    Decorador_Abstracto* productoCompra;
    Factura* facturaCompra;

public:
    Venta();
    Venta(Cliente*, Fecha*, Decorador_Abstracto*,Factura*);
    virtual ~Venta();

    Cliente* getClienteComprador();
    Fecha* getFechaCompra();
    Decorador_Abstracto* getProductoComprado();
    Factura* getFacturaCompra();
 

    void setClienteComprador(Cliente*);
    void setFechaCompra(Fecha*);
    void setProductoComprado(Decorador_Abstracto*);
    void setFacturaCompra(Factura*);

    string toString();
};