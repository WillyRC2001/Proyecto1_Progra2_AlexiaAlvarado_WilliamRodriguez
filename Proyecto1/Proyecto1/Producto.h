#pragma once
#include "Utiles_Clases.h"
#include "Fecha.h"
#include "Categoria.h"

using namespace std; 

class Producto {
public:
	Producto(string cod, string nom_comerc, string descr, double precio, string categ, int existe, int limit, Fecha* fech);
	virtual ~Producto();
	friend ostream& operator<<(ostream& os, const Producto& producto);
	//get´s
	Fecha* getFecha(); 
	string getCodigo();
	string getNombre_Comercial(); 
	string getDescripcion();
	double getPrecio();
	string getCategoria();
	double PorcentajeGanancia();
	int getExistencias(); 
	int getLimite();

	//set´s
	void setFecha(Fecha*);
	void setCodigo(string);
	void setNombre_Comercial(string);
	void setDescripcion(string);
	void setPrecio(double);
	void setCategoria(string);
	void setPorcentajeGanancia(Categoria*);
	void setExistencias(int);
	void setLimite(int);

	bool verificarExistencia();
	void venderProducto(int cantidad);
	bool calcularPrecioVenta();
	double obtenerFactorIncrementoPorCategoria();

	virtual string toString() const;

private:

	string codigo;
	string nombre_comercial;
	string descripion;
	double precio_costo;
	string categoria;
	Categoria* porcentajeGanancia;
	int existencia;
	int limite;
	Fecha* fecha;

};