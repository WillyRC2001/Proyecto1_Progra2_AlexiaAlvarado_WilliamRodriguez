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
			int n_fact;
			cout << "Digite el numero de factura: "; cin >> n_fact;
			switch (opt) {
			case 1:
				//Listo Para agregar el metodo de Eliminar factura
				break;
			case 2:
				//Listo para agregar el metodo de actualizar factura
				break;
			case 3:
				//Retornar
				break;
			}
		}
		else {
			if (opt == 2) {
				cout << MenuMantenimiento::Producto() << endl;
				cin >> opt;
				string cod;
				cout << "Digite el codigo del producto: "; cin >> cod;
				switch (opt) {
				case 1:
					//Listo para agregar el metodo de ingresar producto
					break;
				case 2:
					//Listo para agregar el metodo de eliminar producto
					break;
				case 3:
					//Listo para agregar el metodo de modificar producto
					break;
				case 4:
					//Retornar
					break;
				}
			}
		}
	}
	else {
		if (opt == 2) {
			cout << MenuPrincipal::menuVentas() << endl;
			cin >> opt;
			if (opt == 1) {
				int num_factura;
				int id_cliente;
				cout << "Digite un nuevo numero de factura: "; cin >> num_factura;
				cout << "Digite la cedula del cliente: "; cin >> id_cliente;
				//Listo para agregar los metodos de crear factura
			}
			if (opt == 2) {
				//Retornar
			}
		}
		else {
			if (opt == 3) {
				cout << MenuPrincipal::menuReportes() << endl;
				cin >> opt;
				string categ;
				string ced;
				switch(opt) {
				case 1:
					cout << "---> Lista de Todos los Productos <---" << endl;
					//Listo Para Agregar el metodo
					break;
				case 2:
					cout << "Digite la categoria del producto que quieres reportar: "; cin >> categ;
					//Listo Para Agregar el metodo
					break;
				case 3:
					cout << "---> Lista de Productos con minimo de existencia <---" << endl;
					//Listo Para Agregar el metodo
					break;
				case 4:
					cout << "Digite la cedula de cliente: "; cin >> ced;
					//Listo para agregar el metodo
					break;
				case 5:
					cout << "--> Lista de las 5 mejores compras <--" << endl;
					//Listo Para Agregar el metodo
					break;
				case 6:
					//Retornar
					break;

				}
			}
			else {
				//Retornar
			}
		}
	}
}