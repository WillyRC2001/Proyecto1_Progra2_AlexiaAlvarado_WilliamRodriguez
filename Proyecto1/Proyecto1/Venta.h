#pragma once
#include "Cliente.h"
#include "Fecha.h"
#include "Decorador_Abstracto.h"
#include "Componente_Abstracto.h"


class Venta {
private:
    Cliente* clienteCompra;
    Fecha* fechaCompra;
    Decorador_Abstracto* productoCompra;

public:
    Venta();
    Venta(Cliente*, Fecha*, Decorador_Abstracto*);
    virtual ~Venta();

    Cliente* getClienteComprador();
    Fecha* getFechaCompra();
    Decorador_Abstracto* getProductoComprado();
 

    void setClienteComprador(Cliente*);
    void setFechaCompra(Fecha*);
    void setProductoComprado(Decorador_Abstracto*);
    Cliente* buscarClientePorCedula(string cedula);

    string toString();

    double ObtenerTotalVenta();
};