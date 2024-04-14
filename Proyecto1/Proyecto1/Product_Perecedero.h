#pragma once
#include "Producto.h"
#include "Percedero.h"

class Product_Perecedero : public Producto {

public:

	Product_Perecedero (string cod, string nom_comerc, string descr, double precio, string categ, int existe, int limit, Fecha* fechingreso,Fecha* fechvencido, bool nacion,double pes);
	virtual ~Product_Perecedero();

	// Getters
	bool getNacional() ;
	double getPeso() ;
	Percedero* getPercedero() ;

	// Setters
	void setNacional(bool nacion);
	void setPeso(double pes);
	void setPercedero(Percedero* percedero);

	virtual string toString();

private:
	bool nacional;
	double peso;
	Percedero* percedero; 
};