#include "Venta.h"

Venta::Venta()
{
    this->clienteCompra = NULL;
    this->fechaCompra = NULL;
    this->productoCompra = NULL;
    
}

Venta::Venta(Cliente* cl, Fecha* fc, Decorador_Abstracto* pc)
{
    this->clienteCompra = cl;
    this->fechaCompra = fc;
    this->productoCompra = pc;
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

Cliente* Venta::buscarClientePorCedula(string cedula) {
    if (clienteCompra->getCedulaCliente() == cedula) {
        return clienteCompra;
    }
    return nullptr; // Cliente no encontrado
}

string Venta::toString() 
{
    stringstream s; 
    s << "------- VENTA ---------" << endl;
    s << "Cedula Cliente: " << this->clienteCompra->getCedulaCliente()<< endl;
    s << "Nombre del Cliente: " << this->clienteCompra->getNombreCliente() << endl;
    s << "Fecha: " << this->fechaCompra->mostrarFecha() << endl;
    s << "Total a pagar: " << this->ObtenerTotalVenta()<< endl;
    s << "---------------------------------------" << endl;
    
    return s.str();
}

double Venta::ObtenerTotalVenta()
{
    Componente_Abstracto* aux = productoCompra;
    double total = 0.0;
    while (aux != NULL && aux->obtener_nombre() != "Carrito") {
        total = total + aux->obtener_costo();
        aux = aux->SiguienteComponente();
    }
    return total;
}
