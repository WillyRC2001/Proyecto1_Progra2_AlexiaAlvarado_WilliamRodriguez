#pragma once
#include "Venta.h"
#include "Fecha.h"

#define PORCENTAJE_IVA 13.00

class Factura {
private:
    int numeroFactura;
    Fecha* fecha;
    Venta** productosVendidos;
    int numProductos;
    double subtotal;
    double impuestoIVA;
    double totalPagar;

public:
    Factura(int numero, Fecha* fecha);
    ~Factura();
    void agregarVenta(Venta* venta);
    double calcularTotalPagar();
    double calcularGanancia();
};
