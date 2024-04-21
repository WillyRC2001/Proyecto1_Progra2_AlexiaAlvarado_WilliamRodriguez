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
	/*if(busca(pro->getCodigo() == true)){
	* return false;
	}
	else{
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
	}*/

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


