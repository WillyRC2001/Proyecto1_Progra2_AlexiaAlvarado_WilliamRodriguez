#include "Venta.h"

Venta::Venta(Producto* producto, int cantidad, double precioUnitario) : producto(producto), cantidad(cantidad), precioUnitario(precioUnitario) 
{
}
// Métodos getters
Producto* Venta::getProducto() const {
    return producto;
}

int Venta::getCantidad() const {
    return cantidad;
}

double Venta::getPrecioUnitario() const {
    return precioUnitario;
}

double Venta::getPrecioTotal() const {
    return cantidad * precioUnitario;
}

// Métodos setters
void Venta::setProducto(Producto* producto) {
    this->producto = producto;
}

void Venta::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void Venta::setPrecioUnitario(double precioUnitario) {
    this->precioUnitario = precioUnitario;
}