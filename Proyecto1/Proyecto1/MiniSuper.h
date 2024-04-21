#pragma once
#include "Utiles_Clases.h"
#include "Lista_Producto.h"
//#include "Venta.h"


class MiniSuper {
public:
	MiniSuper();
	virtual ~MiniSuper();

	//Metodos que pide Mantenimiento
	void EliminarFactura(int num_factura);				//Contenedor Ventas
	void ActualizarFactura(int num_factura);			//Contenedor Ventas
	void IngresarElProducto(string codigo, Producto* nuevo);				//Contenedor Producto
	void EliminaProducto(string codigo);				//Contenedor Producto
	void ModificarProducto(string codigo, Producto* nuevo);				//Contenedor Producto
	//Metodos que pide Ventas 
	void CrearNuevaFactura(int num_factura, string ced); //Contendor Ventas
	
	//Metodos que pide Reportar
	string TodosLosProductos();	//Contenedor Producto
	string ProductoDeUnaCategoria(string categoria);	//Contenedor Producto
	string ProductosConMinExistencia();					//Contenedor Producto
	string FacturasDeCliente(string cedula);			//Contenedor Ventas
	string CedulaDeLas5MejoresVentas();					//Contenedor Ventas
public:
	ContenedorLProducto* Cont_Prod;
	//Falta agregar el contenedor Venta
};

MiniSuper::MiniSuper() {
	Cont_Prod = new ContenedorLProducto();
}
MiniSuper::~MiniSuper() {
	if (Cont_Prod != NULL) {
		delete Cont_Prod;
		Cont_Prod = NULL;
	}
}

void MiniSuper::IngresarElProducto(string codigo, Producto* nuevo)
{
	Cont_Prod->IngresarProducto(codigo, nuevo);
}

void MiniSuper::EliminaProducto(string codigo)
{
	Cont_Prod->eliminarProducto(codigo);
}

void MiniSuper::ModificarProducto(string codigo, Producto* nuevo)
{
	Cont_Prod->cambiarProducto(codigo, nuevo);
}

string MiniSuper::TodosLosProductos()
{
	return Cont_Prod->TodosLosProductos();
}

string MiniSuper::ProductoDeUnaCategoria(string categoria)
{
	return Cont_Prod->ProductoDeUnaCategoria(categoria);
}

string MiniSuper::ProductosConMinExistencia()
{
	return Cont_Prod->ProductosConMinExistencia();
}