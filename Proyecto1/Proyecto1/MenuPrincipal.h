#pragma once
#include "Utiles_Clases.h"
#include "Excepciones_Clases.h"
#include "MiniSuper.h"

class MenuPrincipal {
public:

	//Entrada
	static void entrada();

	//Principal
	static string menuPrincipal();

	//Mantenimiento
	static string menuMantenimiento();
	
	//Ventas
	static string menuVentas();

	//Reportes
	static string menuReportes();

	//Despedida
	static void despedida();

	//Excepciones
	static void excepcionRango(ExcepcionesUsuario*);
	static void errorGeneral();
};

void MenuPrincipal::entrada() {
	cout << "---------------------> BIENVENIDOS AL MINI SUPER 'PALI SIEMPRE EL PRECIO MAS BAJO' <-------------------- - " << endl << endl;
}

string MenuPrincipal::menuPrincipal() {
	stringstream s;

	s << "----> Menu principal <----" << endl;
	s << "[1] Mantenimiento" << endl;
	s << "[2] Ventas" << endl;
	s << "[3] Reportes" << endl;
	s << "[4] Salir" << endl;
	return s.str();
}

string MenuPrincipal::menuMantenimiento() {
	stringstream s;
	s << "----> Mantenimiento <----" << endl;
	s << "[1] Facturas" << endl;
	s << "[2] Productos" << endl;
	s << "[3] Retornar" << endl;
	return s.str();
}

string MenuPrincipal::menuVentas() {
	stringstream s;
	s << "----> Ventas <----" << endl;
	s << "[1] Crear Factura Nueva" << endl;
	s << "[2] Retornar" << endl;
	return s.str();
}

string MenuPrincipal::menuReportes() {
	stringstream s;
	s << "[1] Reportar todos los productos del minisuper" << endl;
	s << "[2] Reportar solo los productos de una determinada categoria" << endl;
	s << "[3] Reportar los productos que esta por debajo del minimo de su existencia" << endl;
	s << "[4] Reportar las facturas de un determinado cliente por su cedula" << endl;
	s << "[5] Reportar las cedulas de los 5 mejores clientes que compran en el minisuper" << endl;
	s << "[6] Retornar" << endl;
	return s.str();
}

void MenuPrincipal::despedida() {
	cout << "---------------------> GRACIAS POR COMPRAR EN EL MINI SUPER 'PALI SIEMPRE EL PRECIO MAS BAJO' <-------------------- - " << endl << endl;
	cout << "---------------------> Proyecto No.1 EIF204 Programacion II <---------------------" << endl << endl;
	cout << "  Profesor: Georges Alfaro"<<endl; 
	cout << "  Estudiantes: " << endl;
	cout << "  Alexia Alvarado Alfaro. //Horario clases 1pm" << endl;
	cout << "  William Rodriguez Campos. // Horario clases 3pm" << endl;
	cout << endl << "----------> G R A C I A S   P O R   U T I L I Z A R <----------" << endl << endl;
}

void MenuPrincipal::excepcionRango(ExcepcionesUsuario* e) {
	cout << e->toString() << endl;
}

void MenuPrincipal::errorGeneral() {
	cout << "ERROR: Se genero un error desconocido.\n";
}