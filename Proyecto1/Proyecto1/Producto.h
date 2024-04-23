#pragma once
#include "Utiles_Clases.h"
#include "Fecha.h"
#include "Categoria.h"

using namespace std; 

class Producto {
public:
	
	Producto();
	Producto(string cod, string nom_comerc, string descr, double precio, string categ, int existe, int limit, Fecha* fech);
	Producto(const Producto&);
	virtual ~Producto();
	
	//get´s
	Fecha* getFecha(); 
	Categoria* getPorcentajeGanancia();
	string getCodigo();
	string getNombre_Comercial(); 
	string getDescripcion();
	double getPrecio();
	string getCategoria();
	int getExistencias(); 
	int getLimite();

	//set´s
	void setFecha(Fecha*);
	void setPorcentajeGanancia(Categoria*);
	void setCodigo(string);
	void setNombre_Comercial(string);
	void setDescripcion(string);
	void setPrecio(double);
	void setCategoria(string);
	void setExistencias(int);
	virtual void setLimite(int);

	//metodos
	bool verificarExistencia();
	void venderProducto(int cantidad);
	virtual double calcularPrecioVenta();
	double calcularGanancia();

	//mostrar toString
	virtual string toString() const;

	/*Sobrecarga de metodos*/
	friend ostream& operator<<(ostream& os, const Producto& producto);

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