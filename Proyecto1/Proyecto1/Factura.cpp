#include "Factura.h"

Factura::Factura(int numero, Fecha* fecha) : numeroFactura(numero), fecha(fecha), productosVendidos(nullptr), numProductos(0), subtotal(0.0), impuestoIVA(0.0), totalPagar(0.0) {}

Factura::~Factura() {
    // Liberar la memoria asignada a los productos vendidos
    if (productosVendidos != NULL) {
        for (int i = 0; i < numProductos; ++i) {
            delete productosVendidos[i];
        }
        delete[] productosVendidos;
    }
}

void Factura::agregarVenta(Venta* venta) {
    // Incrementar el tamaño del arreglo de productos vendidos
    Venta** temp = new Venta * [numProductos + 1];
    for (int i = 0; i < numProductos; ++i) {
        temp[i] = productosVendidos[i];
    }
    temp[numProductos] = venta;
    delete[] productosVendidos;
    productosVendidos = temp;
    numProductos++;
}
double Factura::calcularTotalPagar() {
    // Calcular el subtotal sumando el precio total de cada venta
    subtotal = 0.0;
    for (int i = 0; i < numProductos; ++i) {
        subtotal += productosVendidos[i]->getPrecioTotal();
    }

    
    impuestoIVA = subtotal * PORCENTAJE_IVA;

    
    totalPagar = subtotal + impuestoIVA;

    return totalPagar;
}

double Factura::calcularGanancia() {
    // Calcular la ganancia restando el costo total de los productos vendidos al subtotal
    double costoTotal = 0.0;
    for (int i = 0; i < numProductos; ++i) {
        costoTotal += productosVendidos[i]->getProducto()->getPrecio() * productosVendidos[i]->getCantidad();
    }

    return subtotal - costoTotal;
}