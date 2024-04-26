#pragma once
#include "Utiles_Clases.h"
#include "Lista_Producto.h"
#include "Lista_Generica.h"
#include "Venta.h"

class MiniSuper {
public:
	MiniSuper(ContenedorLProducto*, Lista<Venta>*);
	virtual ~MiniSuper();

	Producto* buscarProducto(string cod);

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
Producto* MiniSuper::buscarProducto(string cod) {
	return Cont_Prod->busca(cod);
}
void MiniSuper::EliminarFactura(int num_factura) {
	Cont_Venta->eliminar(Cont_Venta->buscarNumeroFactura(num_factura));
}

void MiniSuper::ActualizarFactura(int num_factura) {
	Venta* venta = Cont_Venta->buscarNumeroFactura(num_factura);
	if (venta != nullptr) {
		int nuevoNumFactura;
		cout << "Ingrese el nuevo número de factura: ";
		cin >> nuevoNumFactura;
		venta->setNumeroFactura(nuevoNumFactura);
		cout << "Factura actualizada correctamente." << endl;
	}
	else {
		cout << "Error: La factura no se encontró en la lista." << endl;
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

//void MiniSuper::CrearNuevaFactura(int num_factura, string ced) //esta malito no se como hacerlo
//{
//	
//	/*Fecha* fecha_actual = new Fecha();
//	Factura* nueva_factura = new Factura(fecha_actual, num_factura);
//
//	
//	Cliente* cliente = Cont_Cliente->obtenerClientePorCedula(ced); 
//	if (cliente != nullptr) {
//		
//		nueva_factura->setCliente(cliente);
//		Cont_Factura->agregarInicio(nueva_factura);
//
//		cout << "Nueva factura creada correctamente." << endl;
//	}
//	else {
//		cout << "Error: Cliente no encontrado para la cédula proporcionada." << endl;
//	}*/
//}

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

string MiniSuper::CedulaDeLas5MejoresVentas(){
	return Cont_Venta->CedulaMejoresVentas();
}

string MiniSuper::FacturasDeCliente(string cedula) {
	return Cont_Venta->FacturaDeCliente(cedula);
}