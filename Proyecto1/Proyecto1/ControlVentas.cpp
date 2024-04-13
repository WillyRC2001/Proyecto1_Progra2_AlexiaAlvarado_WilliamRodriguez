#include "ControlVentas.h"

ControlVentas::ControlVentas() : facturas(nullptr), numFacturas(0), ventaTotalDiaria(0.0), gananciaTotal(0.0) {}

ControlVentas::~ControlVentas() {
    // Liberar la memoria asignada a las facturas
    if (facturas != nullptr) {
        for (int i = 0; i < numFacturas; ++i) {
            delete facturas[i];
        }
        delete[] facturas;
    }
}

void ControlVentas::registrarVenta(Factura* factura) {
    // Incrementar el tamaño del arreglo de facturas
    Factura** temp = new Factura * [numFacturas + 1];
    for (int i = 0; i < numFacturas; ++i) {
        temp[i] = facturas[i];
    }
    temp[numFacturas] = factura;
    delete[] facturas;
    facturas = temp;
    numFacturas++;

    // Actualizar los totales diarios de venta y ganancia
    ventaTotalDiaria += factura->calcularTotalPagar();
    gananciaTotal += factura->calcularGanancia();
}

double ControlVentas::calcularVentaTotalDiaria() {
    return ventaTotalDiaria;
}

double ControlVentas::calcularGananciaTotal() {
    return gananciaTotal;
}