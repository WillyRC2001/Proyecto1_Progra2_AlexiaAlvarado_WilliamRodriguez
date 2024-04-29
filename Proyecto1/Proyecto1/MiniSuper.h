#pragma once
#include "Utiles_Clases.h"
#include "Lista_Producto.h"
#include "Lista_Generica.h"
#include "Factura.h"

class MiniSuper {
public:
	MiniSuper(ContenedorLProducto*, Lista<Factura>*);
	virtual ~MiniSuper();

	Producto* buscarProducto(string cod);

	//Metodos que pide Mantenimiento
	void EliminarFactura(int num_factura);				//Contenedor Factura
	void ActualizarFactura(int num_factura);			//Contenedor Factura
	Factura* buscarFactura(int num_factura);              //Contenedor Factura
	void IngresarElProducto(string codigo, Producto* nuevo);				//Contenedor Producto
	void EliminaProducto(string codigo);				//Contenedor Producto
	void ModificarProducto(string codigo, Producto* nuevo);				//Contenedor Producto
	//Metodos que pide Factura 
	void CrearNuevaFactura(Factura*); //Contendor Factura
	
	//Metodos que pide Reportar
	string TodosLosProductos();	//Contenedor Producto
	string ProductoDeUnaCategoria(string categoria);	//Contenedor Producto
	string ProductosConMinExistencia();					//Contenedor Producto
	string FacturasDeCliente(string cedula);			//Contenedor Factura
	string CedulaDeLas5MejoresVentas();					//Contenedor Factura

	void guardar(); //archivos
	void recuperar();

private:
	ContenedorLProducto* Cont_Prod; 
	Lista<Factura>* Cont_Factura;
};
MiniSuper::MiniSuper(ContenedorLProducto* cont, Lista<Factura>* fact) {
	Cont_Prod = cont;
	Cont_Factura = fact;
}
MiniSuper::~MiniSuper() {
	if (Cont_Prod != NULL) {
		delete Cont_Prod;
		Cont_Prod = NULL;
	}
	if (Cont_Factura != NULL) {
		delete Cont_Factura;
		Cont_Factura = NULL;
	}
}
Producto* MiniSuper::buscarProducto(string cod) {
	return Cont_Prod->busca(cod);
}
void MiniSuper::EliminarFactura(int num_factura) {
	Cont_Factura->eliminar(Cont_Factura->buscarNumeroFactura(num_factura));
}

void MiniSuper::ActualizarFactura(int num_factura) {
	Factura* factura = Cont_Factura->buscarNumeroFactura(num_factura);
	if (factura != nullptr) {
		int nuevoNumFactura;
		cout << "Ingrese el nuevo numero de factura: ";
		cin >> nuevoNumFactura;
		factura->setNumeroFactura(nuevoNumFactura);
		cout << "Factura actualizada correctamente." << endl;
		cout << factura->toString();
	}
	else {
		cout << "Error: La factura no se encontró en la lista." << endl;
	}
}
Factura* MiniSuper::buscarFactura(int num_factura) {
	return Cont_Factura->buscarNumeroFactura(num_factura);
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

void MiniSuper::CrearNuevaFactura(Factura* nueva) {
	Cont_Factura->agregarFinal(nueva);
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

string MiniSuper::CedulaDeLas5MejoresVentas(){
	return Cont_Factura->CedulaMejoresVentas();
}

string MiniSuper::FacturasDeCliente(string cedula) {
	return Cont_Factura->obtenerFacturaPorCedula(cedula);
}

void MiniSuper::guardar() { //archivos
	Cont_Prod->guardar();
}

void MiniSuper::recuperar() {
	Cont_Prod->recuperar();
}