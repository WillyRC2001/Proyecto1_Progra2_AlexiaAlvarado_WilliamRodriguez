#pragma once
#include "Venta.h"

class Factura {
private:
    Venta* ventaAsociada;  
    int numeroFactura;
    int cantidadProductos;
    double subtotal;
    double iva;
    double totalAPagar;

public:
   
    Factura(Venta*,int, int,double,double,double); // Constructor que recibe la venta asociada, número de factura y cantidad de productos
    virtual ~Factura();

    void calcularSubtotal();
    void calcularIVA();
    void calcularTotalAPagar();
    void mostrarDetallesProductos();

    string mostrarResumenFactura();
};
