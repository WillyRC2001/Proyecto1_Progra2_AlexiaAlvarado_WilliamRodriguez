#pragma once
#include "Utiles_Clases.h"
#include "Fecha.h"
#include "Categoria.h"

using namespace std; 

class Producto {
public:
	Producto(string cod, string nom_comerc, string descr, double precio, string categ , Categoria* categor, int existe, int limit, Fecha* fech);
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
	// revisar estos dos metodos porque creo que se pueden agarrar de los set basicamente
	//void establecerPrecioVenta(double precio);
	//void establecerCategoria(Categoria* cat);
	bool verificarExistencia();
	void venderProducto(int cantidad);

	virtual string toString();

private:

	string codigo;
	string nombre_comercial;
	string descripion;
	double precio_costo;
	string categoria;
	Categoria* categoria2;
	int existencia;
	int limite;
	Fecha* fecha;

};