#include "Archivos.h"

GestorDeArchivos::GestorDeArchivos(string client):cliente(client){}

GestorDeArchivos::~GestorDeArchivos(){}

void GestorDeArchivos::abrirFlujoModoEscritura()
{
	archivo.open(cliente.c_str(), ios::out);
}

void GestorDeArchivos::abrirFlujoModoLectura()
{
	archivo.open(cliente.c_str(), ios::in);
}

void GestorDeArchivos::cerrarFlujo()
{
	archivo.close();
}

int GestorDeArchivos::obtenerInt(std::string s)
{
	int v;
	stringstream r(s);
	r >> v;
	return v;
}

double GestorDeArchivos::obtenerDouble(std::string s) {
	double v;
	stringstream r(s);
	r >> v;
	return v;
}

void GestorDeArchivos::guardarInt(int i, char delimitador) {
	archivo << i << delimitador;
}

void GestorDeArchivos::guardarDouble(double d, char delimitador) {
	archivo << d << delimitador;
}

void GestorDeArchivos::guardarString(string s, char delimitador) {
	archivo << s << delimitador;
}

int GestorDeArchivos::recuperarInt(char delimitador) {
	string r;
	getline(archivo, r, delimitador);
	return obtenerInt(r);
}
double GestorDeArchivos::recuperarDouble(char delimitador) {
	string r;
	getline(archivo, r, delimitador);
	return obtenerDouble(r);
}
string GestorDeArchivos::recuperarString(char delimitador) {
	string r;
	getline(archivo, r, delimitador);
	return r;
}

//void GestorDeArchivos::guardarCliente(Cliente* c)
//{
//	guardarString(c->toString(), '\n');
//}
//
//void GestorDeArchivos::guardarVenta(Venta* v)
//{
//	guardarString(v->toString(), '\n');
//
//}
//
//void GestorDeArchivos::guardarFactura(Factura* f)
//{
//	guardarString(f->mostrarResumenFactura(), '\n');
//}
//
//Fecha* GestorDeArchivos::recuperarFecha()
//{
//	int dia = recuperarInt('\t');
//	int mes = recuperarInt('\t');
//	int anio = recuperarInt('\t');
//	return new Fecha(dia, mes, anio);;
//}
//
//Cliente* GestorDeArchivos::recuperarCliente()
//{
//	string cedula = recuperarString('\t');
//	string nombre = recuperarString('\t');
//	return new Cliente(cedula, nombre);
//}
//
//Venta* GestorDeArchivos::recuperarVenta()
//{
//	Venta* venta = NULL;
//	Fecha* fecha = recuperarFecha();
//	Factura* factura = recuperarFactura();
//	Cliente* cliente = recuperarCliente();
//	Decorador_Abstracto* producto = recuperarProducto();
//	/*int cod = recuperarInt(delimitador);*/
//
//	/*Venta = new Venta(cliente, fecha,producto,factura);
//	Venta->setCodigo(cod);
//
//	return venta;*/
//
//
//}
//
//Factura* GestorDeArchivos::recuperarFactura()
//{
//	Venta* venta = recuperarVenta();
//	/*int cantPasajeros = recuperarInt('\t');
//	string cedulaPersona = recuperarString('\n');
//	return new Reservacion(viaje, cantPasajeros, cedulaPersona);*/
//
//}
//
//Decorador_Abstracto* GestorDeArchivos::recuperarProducto() {
//	string nombreComercial = recuperarString('\n');
//	string codigo = recuperarString('\n');
//	
//	/*return new Decorador_Abstracto(nombreComercial, codigo);*/
//}
//
//void GestorDeArchivos::guardarCliente(Lista<Cliente>* listaC)
//{
//	listaC->incializarActual();
//	Cliente* cliente;
//
//	int n = listaC->getCantElem();
//	guardarInt(n, '\n');
//
//	int i = 0;
//	while (i < n) {
//		cliente = &listaC->recuperarDato("Ruta");
//		guardarCliente(cliente);
//		i++;
//	}
//
//
//}
//
//void GestorDeArchivos::guardarVenta(Lista<Venta>*)
//{
//}
//
//void GestorDeArchivos::guardarFactura(Lista<Factura>*)
//{
//}
//
//Lista<Cliente>* GestorDeArchivos::recuperarClientes()
//{
//    return nullptr;
//}
//
//Lista<Venta>* GestorDeArchivos::recuperarVentas()
//{
//    return nullptr;
//}
//
//Lista<Factura>* GestorDeArchivos::recuperarFacturas()
//{
//    return nullptr;
//}
