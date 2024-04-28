#pragma once
#include "Lista_Generica.h"
#include "Lista_Producto.h"
#include "MiniSuper.h"
#include "Cliente.h"
#include "Factura.h"
#include "Fecha.h"

class GestorDeArchivos {
private:
	string cliente;
	fstream archivo;
public:
	GestorDeArchivos(string);
	virtual ~GestorDeArchivos();

	//****Paso 1****
	virtual void abrirFlujoModoEscritura();
	virtual void abrirFlujoModoLectura();
	virtual void cerrarFlujo();

	//****Paso 2****
	static int obtenerInt(string);
	static double obtenerDouble(string);

	//****Paso 3****
	virtual void guardarInt(int, char);
	virtual void guardarDouble(double, char);
	virtual void guardarString(string, char);

	virtual int recuperarInt(char);
	virtual double recuperarDouble(char);
	virtual string recuperarString(char);

	//****Paso 4****

	virtual void guardarCliente(Cliente*);
	virtual void guardarFactura(Factura*);
	virtual void guardarProducto(Decorador_Abstracto*);
	virtual void guardarFecha(Fecha* );

	
	virtual Fecha* recuperarFecha();
	virtual Cliente* recuperarCliente();
	//virtual Venta* recuperarVenta();
	virtual Factura* recuperarFactura();
	virtual Decorador_Abstracto* recuperarProducto(); //

	//****Paso 5****

	/*virtual void guardarCliente(Lista<Cliente>*);
	virtual void guardarVenta(Lista<Venta>*);
	virtual void guardarFactura(Lista<Factura>*);

	virtual Lista<Cliente>* recuperarClientes();
	virtual Lista<Venta>* recuperarVentas();
	virtual Lista<Factura>* recuperarFacturas();*/
};