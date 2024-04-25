#pragma once
#include <ctime>
#include "Utiles_Clases.h"

class Fecha {
public:
	Fecha();
	Fecha(int,int,int);
	virtual ~Fecha();
	int getDia();
	int getMes();
	int getAnio();
	void setDia(int);
	void setMes(int);
	void setAnio(int);
	string mostrarFecha(); //toString

	static Fecha* obtenerFechaActual() {
		time_t tiempoActual = time(0);
		struct tm fecha;
		localtime_s(&fecha, &tiempoActual);
		int dia = fecha.tm_mday;
		int mes = fecha.tm_mon + 1; // Sumar 1 porque enero es 0
		int anio = fecha.tm_year + 1900; // Sumar 1900 porque el año base es 1900

		return new Fecha(dia, mes, anio);
	}

private:
	int dia;
	int mes;
	int anio;
};