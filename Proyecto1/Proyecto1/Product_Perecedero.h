#pragma once
#include "Producto.h"

class Product_Perecedero : public Producto {
public:
	Product_Perecedero(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, bool nacion,double pes);
	virtual ~Product_Perecedero();
	virtual string toString();
private:
	bool nacional;
	double peso;
};