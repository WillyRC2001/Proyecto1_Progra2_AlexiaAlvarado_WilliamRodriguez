#pragma once
#include "Utiles_Clases.h"

class MenuMantenimiento {
public:
	static string Facturas();
	static string Producto();

};
string MenuMantenimiento::Facturas() {
	stringstream s;
	s << "----> Facturas <----" << endl;
	s << "[1] Eliminar Factura" << endl;
	s << "[2] Actualizar Factura" << endl;
	s << "[3] Retornar" << endl;
	return s.str();
}

string MenuMantenimiento::Producto() {
	stringstream s;
	s << "----> Producto <----" << endl;
	s << "[1] Ingresar" << endl;
	s << "[2] Eliminar" << endl;
	s << "[3] Modificar" << endl;
	s << "[4] Retornar" << endl;
	return s.str();
}