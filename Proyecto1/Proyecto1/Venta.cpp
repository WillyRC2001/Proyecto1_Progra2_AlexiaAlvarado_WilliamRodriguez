#include "Venta.h"

Venta::Venta()
{
    this->clienteCompra = NULL;
    this->fechaCompra = NULL;
    this->productoCompra = NULL;
    this->facturaCompra = NULL;
    
}

Venta::Venta(Cliente* cl, Fecha* fc, Decorador_Abstracto* pc, Factura* fac)
{
    this->clienteCompra = cl;
    this->fechaCompra = fc;
    this->productoCompra = pc;
    this->facturaCompra = fac;
}

Venta::~Venta()
{    
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

Factura* Venta::getFacturaCompra()
{
    return facturaCompra;
}

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

void Venta::setFacturaCompra(Factura* fac)
{
    facturaCompra = fac;
}

void Venta::setNumeroFactura(int numeroFactura)
{
   if (facturaCompra != nullptr) {
        facturaCompra->setNumeroFactura(numeroFactura);
   }
}

Cliente* Venta::buscarClientePorCedula(string cedula) {
    if (clienteCompra->getCedulaCliente() == cedula) {
        return clienteCompra;
    }
    return nullptr; // Cliente no encontrado
}

string Venta::toString() 
{
    stringstream s; 
    s << "------- FACTURA ---------" << endl;
    s << "Cedula Cliente: " << this->clienteCompra->getCedulaCliente()<<endl;
    s << "Nombre del Cliente: " << this->clienteCompra->getNombreCliente() << endl;
    s << "Factura: " << this->facturaCompra->mostrarResumenFactura();
    s << "--------- PRODUCTOS ----------" << endl; 
    s << this->productoCompra->toString()<<"\n";
    s << "---------------------------------------" << endl;
    
    return s.str();
}
