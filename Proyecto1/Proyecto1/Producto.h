#pragma once
#include "Fecha.h"
#include "Categoria.h"

class Producto {
public:
	Producto(Fecha*, string, string, string, double, string, int, int);
	virtual ~Producto();
	string toString();
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