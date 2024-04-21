#pragma once
#include "Utiles_Clases.h";
#include "MenuPrincipal.h";
#include "MenuMantenimiento.h";
#include "MenuReporte.h";

class Controler {
public:
	Controler(){}
	void VerMenus();
private:

};

void Controler::VerMenus() {
	int opt = 0;
	cout << MenuPrincipal::menuPrincipal() << endl;
	cin >> opt;
	if (opt == 1) {
		cout << MenuPrincipal::menuMantenimiento() << endl;
		cin >> opt;
		if (opt == 1) {
			cout << MenuMantenimiento::Facturas() << endl;
			cin >> opt;
			//Continua con las opciones de factura
		}
		if (opt == 2) {
			cout << MenuMantenimiento::Producto() << endl;
			cin >> opt;
			//Continua con las opciones de Producto
		}
	}
	if (opt == 2) {
		cout << MenuPrincipal::menuVentas() << endl;
		cin >> opt;
		if (opt == 1) {
			int num_factura;
			int id_cliente;
			cout << "Digite un nuevo numero de factura: "; cin >> num_factura;
			cout << "Digite la cedula del cliente: "; cin >> id_cliente;
			//Listo para agregar los metodos
		}
		if (opt == 2) {
			//opcion de retornar
		}
	}
	if (opt == 3) {
		cout << MenuPrincipal::menuReportes() << endl;
		cin >> opt;
		if (opt == 1) {
			cout << MenuReporte::TodosLosProductos() << endl;
		}
		if (opt == 2) {
			cout << MenuReporte::ProductoPorCategoria() << endl;
		}
		if (opt == 3) {
			cout << MenuReporte::MinimoDeExistencia() << endl;
		}
		if (opt == 4) {
			cout << MenuReporte::FacturasDeterminadoCliente() << endl;
		}
		if (opt == 5) {
			cout << MenuReporte::Mejores5ComprasPorCedula() << endl;
		}
	}
}