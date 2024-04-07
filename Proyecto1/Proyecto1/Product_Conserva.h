#pragma once
#include "Producto.h"

class Product_Conserva : public Producto {
public:
	Product_Conserva(Fecha* fech, string cod, string nom_comerc, string descr, double precio, string categ, Categoria* categor, int existe, int limit, bool envasado);
	virtual ~Product_Conserva();
	string toString();
private:
	bool envasado;
};