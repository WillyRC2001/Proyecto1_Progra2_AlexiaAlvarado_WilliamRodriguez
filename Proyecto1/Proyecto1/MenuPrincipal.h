#pragma once
#include "Utiles_Clases.h"
class VerMenus {
public:
	//Principal
	static int menuPrincipal();

	//Mantenimiento
	static int menuMantenimiento();
	
	//Ventas
	static int menuVentas();

	//Reportes
	static int menuReportes();

	//Excepciones
	
};

int VerMenus::menuPrincipal() {
	int opt = 0;

	cout << "----> Menu principal <----" << endl;
	cout << "[1] Mantenimiento" << endl;
	cout << "[2] Ventas" << endl;
	cout << "[3] Reportes" << endl;
	cout << "[4] Salir" << endl;
	cin >> opt;
	return opt;
}

int VerMenus::menuMantenimiento() {
	int menu = 0;
	cout << "----> Mantenimiento <----" << endl;
	cout << "[1] Facturas" << endl;
	cout << "[2] Productos" << endl;
	cout << "[3] Retornar" << endl;
	cin >> menu;
	return menu;
}

int VerMenus::menuVentas() {
	int opt = 0;
	cout << "[1] Crear Factura Nueva" << endl;
	cout << "[2] Retornar" << endl;
	cin >> opt;
	return opt;
}

int VerMenus::menuReportes() {
	int opt = 0;
	cout << "[1] Reportar todos los productos del minisuper" << endl;
	cout << "[2] Reportar solo los productos de una determinada categoria" << endl;
	cout << "[3] Reportar los productos qye esta por debajo del minimo de su existencia" << endl;
	cout << "[4] Reportar las facturas de un determinado cliente por su cedula" << endl;
	cout << "[5] Reportar las cedulas de los 5 mejores clientes que compran en el minisuper" << endl;
	cout << "[6] Retornar" << endl;
	cin >> opt;
	return opt;
}
