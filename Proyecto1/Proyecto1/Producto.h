#pragma once
#include "Fecha.h"
#include "Categoria.h"

class Producto {
public:
	Producto(Fecha* fech, string cod, string nom_comerc, string descr, double precio, string categ , int existe, int limit);
	virtual ~Producto();
	virtual string toString();
private:
	Fecha* fecha;
	string codigo;
	string nombre_comercial;
	string descripion;
	double precio_costo;
	string categoria;
	int existencia;
	int limite;
};