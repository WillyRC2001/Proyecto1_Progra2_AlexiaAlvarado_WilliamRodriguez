#pragma once
#include "Producto.h"

class NodoProducto{
private:
	Producto* prod;
	NodoProducto* sig;

public:
	NodoProducto(Producto*);
	virtual ~NodoProducto();
	void setsig(NodoProducto*);
	void setProd(Producto*);
	Producto* getProd();
	NodoProducto* getsig();
};


NodoProducto::NodoProducto(Producto* p)
{
	prod = p;
	sig = NULL;
}

NodoProducto::~NodoProducto()
{
	if (prod != NULL)
	{
		delete prod;
	}
}

void NodoProducto::setsig(NodoProducto* np)
{
	sig = np;
}

void NodoProducto::setProd(Producto* p)
{
	prod = p;
}

Producto* NodoProducto::getProd()
{
	return prod;
}

NodoProducto* NodoProducto::getsig()
{
	return sig;
}
