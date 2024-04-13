#pragma once
#include "Utiles_Clases.h"

class Fecha {
public:
	Fecha(int,int,int);
	virtual ~Fecha();
	int getDia();
	int getMes();
	int getAnio();
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	string mostrarFecha(); //toString
private:
	int dia;
	int mes;
	int anio;
};