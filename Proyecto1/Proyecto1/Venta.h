#pragma once
#include "Producto.h"

class Venta {
private:
    Producto* producto;
    int cantidad;
    double precioUnitario;

public:
    Venta(Producto* producto, int cantidad, double precioUnitario);
    // Métodos getters
    Producto* getProducto() const;
    int getCantidad() const;
    double getPrecioUnitario() const;
    double getPrecioTotal() const;
    void setProducto(Producto* producto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(double precioUnitario);
};