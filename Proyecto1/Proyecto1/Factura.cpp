#include "Factura.h"

Factura::Factura(Venta* venta, int numFactura, int cantidadProd,double sub,double IVA, double total)
{
    ventaAsociada = venta;
    numeroFactura = numFactura;
    cantidadProductos = cantidadProd;
    subtotal = sub;
    iva = IVA;
    totalAPagar = total;
}

Factura::~Factura() {  
    delete ventaAsociada;
}

void Factura::calcularSubtotal()
{
    subtotal = 0.0;
    Decorador_Abstracto* producto = ventaAsociada->getProductoComprado();
    subtotal += producto->obtener_costo();
}

void Factura::calcularIVA()
{
    iva = subtotal * 0.13;
}

void Factura::calcularTotalAPagar()
{
    totalAPagar = subtotal + iva;
}

void Factura::mostrarDetallesProductos()
{
    Decorador_Abstracto* producto = ventaAsociada->getProductoComprado();

    cout << "Producto: " << producto->obtener_nombre() << endl;
    cout << "Codigo: " << producto->obtener_codigo() << endl;
    cout << "Precio unitario: " << producto->obtener_costo() << endl;
    
}

string Factura::mostrarResumenFactura()
{
    calcularSubtotal();
    calcularIVA();
    calcularTotalAPagar();

    stringstream s; 
    s << "-------------------------------------" <<endl;
    s << "Numero de la Factura: " << numeroFactura << endl;
    s << "Cantidad de Productos: " << cantidadProductos << endl;
    s << "Subtotal: " << subtotal << endl;
    s << "IVA: " << iva << endl;
    s << "Total a pagar: " << totalAPagar << endl;
    return s.str();
}
