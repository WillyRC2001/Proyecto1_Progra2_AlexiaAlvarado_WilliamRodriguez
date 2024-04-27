#pragma once
#include "Nodo_Producto.h"
#include "Producto.h"
#include "Utiles_Clases.h"

class ContenedorLProducto {
private:
	NodoProducto* ppio;
public:
	ContenedorLProducto();
	virtual~ContenedorLProducto();
	NodoProducto* getPpio();
	bool esVacio();
	bool ingresaProducto(Producto*);
	string toString();
	Producto* busca(string);
	bool eliminarProducto(string);
	bool cambiarProducto(string, Producto*);
	void IngresarProducto(string codigo, Producto* nuevo);				//Contenedor Producto
	string TodosLosProductos();							//Contenedor Producto
	string ProductoDeUnaCategoria(string categoria);	//Contenedor Producto
	string ProductosConMinExistencia();					//Contenedor Producto
	/*bool obtenerEnvasadoDeConserva(string codigo);*/
};


ContenedorLProducto::ContenedorLProducto() :ppio(NULL) {

}

ContenedorLProducto::~ContenedorLProducto()
{
	if (ppio != NULL) {
		delete ppio;
	}
}
NodoProducto* ContenedorLProducto::getPpio()
{
	return ppio;
}
bool ContenedorLProducto::esVacio()
{
	return (ppio == NULL);
}
bool ContenedorLProducto::ingresaProducto(Producto* pro)
{
	NodoProducto* p = ppio;

	if (esVacio()) {
		ppio = new NodoProducto(pro);
		return true;
	}
	else {
		while (p->getsig() != NULL)
			p = p->getsig();
		p->setsig(new NodoProducto(pro));
		return true;
	}
	return false;
}

string ContenedorLProducto::toString()
{
	stringstream s;
	NodoProducto* p = ppio;
	while (p != NULL) {
		s << p->getProd()->toString();
		p = p->getsig();
		s << endl;
	}
	return s.str();
}
Producto* ContenedorLProducto::busca(string cod)
{
	NodoProducto* p = ppio;
	if (!esVacio()) {
		while (p != NULL) {
			if (p->getProd()->getCodigo() == cod) {
				// return true
				return p->getProd();

			}
			p = p->getsig();
		}
	}
	//return false
	return NULL;
}

bool ContenedorLProducto::eliminarProducto(string cod)
{
	NodoProducto* p = ppio;
	NodoProducto* anterior = NULL;
	if (!esVacio() && p->getProd()->getCodigo() == cod) {
		NodoProducto* actual = ppio;
		if (!esVacio()) {
			ppio = actual->getsig();
			delete actual;
			return true;
		}
	}
	else
		if (!esVacio()) {
			while (p != NULL && p->getProd()->getCodigo() != cod) {
				anterior = p;
				p = p->getsig();
			}
			anterior->setsig(p->getsig());
			delete p;
			return true;
		}
	return false;


}

bool ContenedorLProducto::cambiarProducto(string cod, Producto* per)
{
	NodoProducto* p = ppio;
	if (!esVacio()) {
		if (ppio->getProd()->getCodigo() == cod) {
			ppio->setProd(per);
			return true;
		}

		while (p != NULL)
		{

			if (p->getProd()->getCodigo() == cod) {
				p->setProd(per);
				return true;
			}
			p = p->getsig();

		}
	}
	return false;

}
///////////////////////////////////////////////////////////////////////////////////////
void ContenedorLProducto::IngresarProducto(string codigo, Producto* nuevo){
	if (this->busca(codigo) == NULL) {
		this->ingresaProducto(nuevo);
	}
}
string ContenedorLProducto::TodosLosProductos(){
	return this->toString();
}
string ContenedorLProducto::ProductoDeUnaCategoria(string categoria){
	stringstream s;
	NodoProducto* p = ppio;
	if (!esVacio()) {
		while (p != NULL) {
			if (p->getProd()->getCategoria() == categoria) {
				s << p->getProd()->toString();
			}
			p = p->getsig();
		}
	}
	return s.str();
}
string ContenedorLProducto::ProductosConMinExistencia(){	//minimo de existencia quiere decir que no hay??
	stringstream s;
	NodoProducto* p = ppio;
	if (!esVacio()) {
		while (p != NULL) {
			if (p->getProd()->getLimite() <= 5) {
				s << p->getProd()->toString();
			}
			p = p->getsig();
		}
	}
	return s.str();
}
//bool ContenedorLProducto::obtenerEnvasadoDeConserva(string codigo) {
//	// Buscar el producto por su código
//	Producto* producto = busca(codigo);
//
//	// Verificar si el producto encontrado es una instancia de Conserva
//	Conserva* conserva = dynamic_cast<Conserva*>(producto);
//		 //Verificar si el producto es una instancia de Conserva
//		if (conserva) {
//			// Si es una conserva, devolver el valor de envasado
//			return conserva->getEnvasado();
//		}
//		else {
//			// Si el producto no es una conserva, mostrar un mensaje de error o devolver un valor predeterminado
//			// Aquí puedes manejar la situación según sea necesario
//			// Por ejemplo:
//			// cout << "El producto no es una conserva" << endl;
//			// return false; // o algún valor predeterminado
//		}
//		return false;
//}