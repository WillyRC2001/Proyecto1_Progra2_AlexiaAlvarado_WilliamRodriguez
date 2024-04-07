#pragma once
#include "Fecha.h"
#include "Categoria.h"

class Producto {
public:
	Producto(Fecha* fech, string cod, string nom_comerc, string descr, double precio, string categ , Categoria* categor, int existe, int limit);
	virtual ~Producto();
	
	//get´s
	Fecha* getFecha(); 
	string getCodigo();
	string getNombre_Comercial(); 
	string getDescripcion();
	double getPrecio();
	string getCategoria();
	Categoria* getCategoria2();
	int getExistencias(); 
	int getLimite();

	//set´s
	void setFecha(Fecha*);
	void setCodigo(string);
	void setNombre_Comercial(string);
	void setDescripcion(string);
	void setPrecio(double);
	void setCategoria(string);
	void setCategoria2(Categoria*);
	void setExistencias(int);
	void setLimite(int);

	//metodos 
	void establecerPrecioVenta(double precio);
	void establecerCategoria(Categoria* cat);
	bool verificarExistencia();

	virtual string toString();

private:
	Fecha* fecha;
	string codigo;
	string nombre_comercial;
	string descripion;
	double precio_costo;
	string categoria;
	Categoria* categoria2;
	int existencia;
	int limite;
};