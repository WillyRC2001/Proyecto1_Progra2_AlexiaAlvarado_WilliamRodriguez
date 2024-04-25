#pragma once
#include "Utiles_Clases.h";
#include "MenuPrincipal.h";
#include "MenuMantenimiento.h";
#include "MiniSuper.h"
#include "Producto_Clases.h"

class Controler {
public:
	Controler(){}
	void VerMenus(MiniSuper*);
	void PausaAndClose();	//Para no estar copiando y pegando los system pause and close
	Producto* CrearModificarProducto(string cod); //Este metodo está porque el ingreso o modificacion del producto recibe por parametros un nuevo producto
private:

};
void Controler::PausaAndClose() {	//Metodo que llama a las opciones del sistema 
	system("pause");
	system("cls");
}
Producto* Controler::CrearModificarProducto(string cod) {
	string nom_comercial,descrip,categ;
	double precio;
	int existe,limit,dia,mes,anio;
	cout << "Digite el nombre comercial "; cin >> nom_comercial;
	cout << "Digite el descripcion: "; cin >> descrip;
	cout << "Digite el categoria(Conserva/Abarrote/Embutido): "; cin >> categ;
	cout << "Digite el precio: "; cin >> precio;
	cout << "Digite el existencia: "; cin >> existe;
	cout << "Digite el limite: "; cin >> limit;
	cout << "Digite el dia de ingreso: "; cin >> dia;
	cout << "Digite el mes de ingreso: "; cin >> mes;
	cout << "Digite el anio de ingreso: "; cin >> anio;
	Fecha* fechIng = new Fecha(dia, mes, anio);
	string opt;
	if (categ == "Conserva" || categ == "conserva") {
		bool envasado;
		cout << "Envasado? (Si/NO): "; cin >> opt;
		if (opt == "Si")
			envasado = true;
		else
			envasado = false;
		Producto* prodConserva = new Conserva(cod, nom_comercial, descrip, precio, categ, existe, limit, fechIng, envasado);
		this->PausaAndClose();
		return prodConserva;
	}
	else {
		cout << "Digite el dia de vencimiento: "; cin >> dia;
		cout << "Digite el mes de vencimiento: "; cin >> mes;
		cout << "Digite el anio de vencimiento: "; cin >> anio;
		Fecha* fechVenc = new Fecha(dia, mes, anio);
		Percedero* perecedero = new Percedero(fechVenc);
		double peso;
		bool nacional;
		cout << "Digite el peso del producto: "; cin >> peso;
		cout << "Es Producto Nacional? (Si/NO): "; cin >> opt;
		if (opt == "Si")
			nacional = true;
		else
			nacional = false;
		if (categ == "Abarrote" || categ == "abarrote") {
			string nom_empresa;
			cout << "Digite el Nombre de la empresa: "; cin >> nom_comercial;
			Producto* prodAbarrote = new Abarrote(cod, nom_comercial, descrip, precio, categ, existe, limit, fechIng,fechVenc,nacional,peso,nom_empresa);
			this->PausaAndClose();
			return prodAbarrote;
		}
		else {
			string nom_animal, parte_animal, marca;
			bool tripa;
			cout << "Digite la marca: "; cin >> marca;
			cout << "El Producto tiene Tripas? (Si/NO)"; cin >> opt;
			if (opt == "Si")
				tripa = true;
			else
				tripa = false;
			Empaque* empaque = new Empaque(tripa);
			cout << "Digite el nombre del animal: "; cin >> nom_animal;
			cout << "Digite la parte del animal: "; cin >> parte_animal;
			Producto* prodEmbutido = new Embutido(cod, nom_comercial, descrip, precio, categ, existe, limit, fechIng, fechVenc, nacional, peso, nom_animal,parte_animal,marca,empaque);
			this->PausaAndClose();
			return prodEmbutido;
		}
	}
}

void Controler::VerMenus(MiniSuper* miniSuper) {
	int opt = 0;
	cout << MenuPrincipal::menuPrincipal() << endl;
	cin >> opt;
	this->PausaAndClose();
	if (opt == 1) {
		cout << MenuPrincipal::menuMantenimiento() << endl;
		cin >> opt;
		this->PausaAndClose();
		if (opt == 1) {
			cout << MenuMantenimiento::Facturas() << endl;
			cin >> opt;
			int n_fact;
			cout << "Digite el numero de factura: "; cin >> n_fact;
			switch (opt) {
			case 1:
				//Listo Para agregar el metodo de Eliminar factura
				miniSuper->EliminarFactura(n_fact);
				cout << "Se ha eliminado" << endl;
				break;
			case 2:
				miniSuper->ActualizarFactura(n_fact);
				cout << "Se ha actualizado" << endl;
				break;
			case 3:
				system("cls");
				//Retornar
				break;
			}
		}
		else {
			if (opt == 2) {
				cout << MenuMantenimiento::Producto() << endl;
				cin >> opt;
				this->PausaAndClose();
				string cod;
				cout << "Digite el codigo del producto: "; cin >> cod;
				switch (opt) {
				case 1:
					cout << "Para ingresar el producto se debe completar su informacion: " << endl;
					this->PausaAndClose();
					miniSuper->IngresarElProducto(cod,this->CrearModificarProducto(cod));
					cout << "Se ha ingresado el producto" << endl;
					break;
				case 2:
					miniSuper->EliminaProducto(cod);
					break;
				case 3:
					cout << "Para modificar el producto se necesita reingresar los datos: " << endl;
					this->PausaAndClose();
					miniSuper->ModificarProducto(cod, this->CrearModificarProducto(cod));
					cout << "Se ha modificado el producto" << endl;
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
					cout << miniSuper->TodosLosProductos() << endl;
					break;
				case 2:
					cout << "Digite la categoria del producto que quieres reportar: "; cin >> categ;
					cout << miniSuper->ProductoDeUnaCategoria(categ);
					break;
				case 3:
					cout << "---> Lista de Productos con minimo de existencia <---" << endl;
					cout << miniSuper->ProductosConMinExistencia();
					break;
				case 4:
					cout << "Digite la cedula de cliente: "; cin >> ced;
					//Listo para agregar el metodo
					miniSuper->FacturasDeCliente(ced);
					
					break;
				case 5:
					cout << "--> Lista de las 5 mejores compras <--" << endl;
					//Listo Para Agregar el metodo
					miniSuper->CedulaDeLas5MejoresVentas();
					break;
				case 6:
					break;

				}
			}
			else {
				system("cls");	//Retornar
			}
		}
	}
}