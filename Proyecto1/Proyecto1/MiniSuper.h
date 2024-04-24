#pragma once
#include "Utiles_Clases.h"
#include "Lista_Producto.h"
#include "Lista_Generica.h"
#include "Venta.h"

class MiniSuper {
public:
	MiniSuper(ContenedorLProducto*, Lista<Venta>*);
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

private:
	ContenedorLProducto* Cont_Prod;
	Lista<Venta>* Cont_Venta;
};
MiniSuper::MiniSuper(ContenedorLProducto* cont, Lista<Venta>* vent) {
	Cont_Prod = cont;
	Cont_Venta = vent;
}
MiniSuper::~MiniSuper() {
	if (Cont_Prod != NULL) {
		delete Cont_Prod;
		Cont_Prod = NULL;
	}
	if (Cont_Venta != NULL) {
		delete Cont_Venta;
		Cont_Venta = NULL;
	}
}
void MiniSuper::EliminarFactura(int num_factura) {
	Cont_Venta->eliminar(Cont_Venta->buscarNumeroFactura(num_factura));
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