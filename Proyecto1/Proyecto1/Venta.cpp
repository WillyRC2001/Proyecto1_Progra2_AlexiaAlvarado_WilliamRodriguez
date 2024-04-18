#include "Venta.h"

Venta::Venta()
{
    this->clienteCompra = nullptr;
    this->fechaCompra = nullptr;
    this->productoCompra = nullptr;
    
}

Venta::Venta(Cliente* clientes, Fecha* fechas, Decorador_Abstracto* productos)
{
    this->clienteCompra = clientes;
    this->fechaCompra = fechas;
    this->productoCompra = productos;
    
}

Venta::~Venta()
{
    if (clienteCompra) delete clienteCompra;
    if (fechaCompra) delete fechaCompra;
    if (productoCompra) delete productoCompra;
    
}

Cliente* Venta::getClienteComprador()
{
    return clienteCompra;
}

Fecha* Venta::getFechaCompra()
{
    return fechaCompra;
}

Decorador_Abstracto* Venta::getProductoComprado()
{
    return productoCompra;
}

//Factura* Venta::getFacturaCompra()
//{
//    return facturaCompra;
//}

void Venta::setClienteComprador(Cliente* c)
{
    clienteCompra = c;
}

void Venta::setFechaCompra(Fecha* f)
{
    fechaCompra = f;
}

void Venta::setProductoComprado(Decorador_Abstracto* p)
{
    productoCompra = p;
}

//void Venta::setFacturaCompra(Factura* fac)
//{
//    facturaCompra = fac;
//}

string Venta::toString() 
{
    stringstream s; 
    s << "------- FACTURA ---------" << endl;
    s << "Cedula Cliente: " << this->clienteCompra->getCedulaCliente()<<endl;
    s << "Fecha de Compra: " << this->fechaCompra->mostrarFecha();
    s << "--------- PRODUCTOS ----------" << endl; 
    s << this->productoCompra->toString();
    s << "---------------------------------------" << endl;
    
    return s.str();
}
