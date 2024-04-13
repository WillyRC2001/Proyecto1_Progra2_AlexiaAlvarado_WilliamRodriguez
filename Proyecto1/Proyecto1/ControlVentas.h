#pragma once
#include "Factura.h"

class ControlVentas {
private:
    Factura** facturas;
    int numFacturas;
    double ventaTotalDiaria;
    double gananciaTotal;

public:
    ControlVentas();
    ~ControlVentas();
    void registrarVenta(Factura* factura);
    double calcularVentaTotalDiaria();
    double calcularGananciaTotal();
};