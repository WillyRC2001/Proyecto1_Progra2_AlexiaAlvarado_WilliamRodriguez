#pragma once
#include <exception> 
#include "Utiles_Clases.h"
#include "MenuPrincipal.h"
#include "MenuMantenimiento.h"
#include "MiniSuper.h"
#include "Producto_Clases.h"
#include "Decorador_Clases.h"

class Controler {
public:
	Controler(){}
	void VerMenus(MiniSuper*);
	void PausaAndClose();	//Para no estar copiando y pegando los system pause and close
	Producto* CrearModificarProducto(string cod); //Este metodo está porque el ingreso o modificacion del producto recibe por parametros un nuevo producto
	Factura* CrearFactura(Decorador_Abstracto*);
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
	cout << "Digite el nombre comercial: "; cin >> nom_comercial;
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
		if (opt == "Si"||"SI"||"si")
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
		if (opt == "Si"||"SI"||"si")
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
			cout << "El Producto tiene Tripas? (Si/NO): "; cin >> opt;
			if (opt == "Si"||"SI"||"si")
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

Factura* Controler::CrearFactura(Decorador_Abstracto* productos) {		
	string nom, ced;
	int d, m, a, num_factura;
	Carrito* carrito = new Carrito();
	//Factura(Venta*,int)
	//Venta(Cliente*,Fecha*,DecoradorAbs*)
	//DecoradorAbs(Decorador,ProductoCorrespondiente*)
	//Cliente(ced,nom)
	//Fecha(d,m,a)
	cout << "Digite un nuevo numero de factura: "; cin >> num_factura;
	cout << "Digite la cedula del cliente: "; cin >> ced;
	cout << "Digite el nombre del cliente: "; cin >> nom;
	cout << "Digite el dia: "; cin >> d;
	cout << "Digite el mes: "; cin >> m;
	cout << "Digite el anio: "; cin >> a;
	Cliente* clientenuevo = new Cliente(ced, nom);
	Fecha* fechanueva = new Fecha(d, m, a);
	Venta* ventanueva = new Venta(clientenuevo, fechanueva, productos);
	Factura* facturanueva = new Factura(ventanueva, num_factura);
	return facturanueva;
}

void Controler::VerMenus(MiniSuper* miniSuper) 
{
	MenuPrincipal::entrada();

	bool retornar = true;
	try {
		do {
			int opt = 0;
			cout << MenuPrincipal::menuPrincipal() << endl;
			cout << "Ingrese la opcion: ";
			cin >> opt;
			this->PausaAndClose();
			if (opt == 1) {
				bool retornarMantenimiento = false;
				do {
					cout << MenuPrincipal::menuMantenimiento() << endl;
					cin >> opt;
					this->PausaAndClose();
					if (opt == 1) {
						cout << MenuMantenimiento::Facturas() << endl;
						cout << "Ingrese la opcion: ";
						cin >> opt;
						int n_fact;
						switch (opt) {
						case 1:
							cout << "Digite el numero de factura: "; cin >> n_fact;
							miniSuper->EliminarFactura(n_fact);
							cout << "Se ha eliminado" << endl;
							this->PausaAndClose();
							retornarMantenimiento = false;
							break;
						case 2:
							cout << "Digite el numero de factura: "; cin >> n_fact;
							miniSuper->ActualizarFactura(n_fact);
							this->PausaAndClose();
							retornarMantenimiento = false;
							break;
						case 3:
							system("cls");
							retornar = true;
							break;
						}
					}
					else {
						if (opt == 2) {
							cout << MenuMantenimiento::Producto() << endl;
							cout << "Ingrese la opcion: ";
							cin >> opt;
							this->PausaAndClose();
							string cod;
							switch (opt) {
							case 1:
								cout << "Digite el codigo del producto: "; cin >> cod;
								cout << "Para ingresar el producto se debe completar su informacion: " << endl;
								this->PausaAndClose();
								miniSuper->IngresarElProducto(cod, this->CrearModificarProducto(cod));
								cout << "Se ha ingresado el producto" << endl;
								this->PausaAndClose();
								retornarMantenimiento = false;
								break;
							case 2:
								cout << "Digite el codigo del producto: "; cin >> cod;
								miniSuper->EliminaProducto(cod);
								this->PausaAndClose();
								retornarMantenimiento = false;
								break;
							case 3:
								cout << "Digite el codigo del producto: "; cin >> cod;
								cout << "Para modificar el producto se necesita reingresar los datos: " << endl;
								this->PausaAndClose();
								miniSuper->ModificarProducto(cod, this->CrearModificarProducto(cod));
								cout << "Se ha modificado el producto" << endl;
								this->PausaAndClose();
								retornarMantenimiento = false;
								break;
							case 4:
								retornarMantenimiento = true; //Retornar al menu 
								break;
							}
						}
					} //OCUPO QUE ARREGLE EL RETORNAR DE MANTENIMIENTO PORQUE NO RETORNA AL MENU PRINCIPAL
				} while (retornar == true);
			}
			else {
				if (opt == 2) {
					bool retornarVentas = false;
					do {
						cout << MenuPrincipal::menuVentas() << endl;
						cout << "Ingrese la opcion: ";
						cin >> opt;
						if (opt == 1) {
							cout << "--- PROCEDE A REALIZAR UNA NUEVA COMPRA ---" << endl;
							cout << miniSuper->TodosLosProductos() << endl << endl;
							int cant;
							cout << "Digite la cantidad de Productos que quieres: "; cin >> cant;
							string codprod;
							cout << "Digite el codigo del primer producto: "; cin >> codprod;
							Producto* producto = miniSuper->buscarProducto(codprod);
							Componente_Abstracto* aux;
							if (producto != NULL) {	//Encontro el producto para agregar el primer elemento
								system("cls");
								Carrito* carrito = new Carrito();
								if (producto->getCategoria() == "Conserva") {
									Conserva* conserva = dynamic_cast<Conserva*>(producto);
									Decorador_Conserva* dec = new Decorador_Conserva(carrito, conserva);
									aux = dec;
								}
								else {
									if (producto->getCategoria() == "Abarrote") {
										Abarrote* abarrote = dynamic_cast<Abarrote*>(producto);
										Decorador_Abarrote* dec = new Decorador_Abarrote(carrito, abarrote);
										aux = dec;
									}
									else {
										Embutido* embutido = dynamic_cast<Embutido*>(producto);
										Decorador_Embutido* dec = new Decorador_Embutido(carrito, embutido);
										aux = dec;
									}
								}
								//Se crea un ciclo en donde comienza a agregar los demas elementos que quiere
								for (int i = 1; i < cant; i++) {
									system("cls");
									cout << miniSuper->TodosLosProductos() << endl;
									cout << "Digite el codigo del siguiente producto: "; cin >> codprod;
									producto = miniSuper->buscarProducto(codprod);
									if (producto != NULL) {
										if (producto->getCategoria() == "Conserva") {
											Conserva* conserva = dynamic_cast<Conserva*>(producto);
											Decorador_Conserva* decoCons = new Decorador_Conserva(aux, conserva);
											aux = decoCons;
										}
										else {
											if (producto->getCategoria() == "Abarrote") {
												Abarrote* abarrote = dynamic_cast<Abarrote*>(producto);
												Decorador_Abarrote* decoAbar = new Decorador_Abarrote(aux, abarrote);
												aux = decoAbar;
											}
											else {
												Embutido* embutido = dynamic_cast<Embutido*>(producto);
												Decorador_Embutido* decoEmbu = new Decorador_Embutido(aux, embutido);
												aux = decoEmbu;
											}
										}
									}
									else {
										cout << "ERROR, No se encontró el producto" << endl;
										this->PausaAndClose();
										i = i--;
									}
								}
								Decorador_Abstracto* producTotales = dynamic_cast<Decorador_Abstracto*>(aux);
								miniSuper->CrearNuevaFactura(this->CrearFactura(producTotales));
								cout << "Se a agregado la Nueva Factura!" << endl;
								this->PausaAndClose();
								retornarVentas = false;
							}
							else {
								cout << "No se encontró el producto" << endl;
								this->PausaAndClose();
								retornarVentas = true;
							}
						}
						if (opt == 2) {
							retornar = true;	//Retornar a menu 
						}
					} while (retornarVentas == true);
				}
				else {
					if (opt == 3) {
						bool retornarReportes = false;
						do {
							cout << MenuPrincipal::menuReportes() << endl;
							cout << "Ingrese la opcion: ";
							cin >> opt;
							string categ;
							string ced;
							switch (opt) {
							case 1:
								cout << "---> Lista de Todos los Productos <---" << endl;
								cout << miniSuper->TodosLosProductos() << endl;
								this->PausaAndClose();
								retornarReportes = true;
								break;
							case 2:
								cout << "Digite la categoria del producto que quieres reportar: "; cin >> categ;
								cout << miniSuper->ProductoDeUnaCategoria(categ);
								this->PausaAndClose();
								retornarReportes = true;
								break;
							case 3:
								cout << "---> Lista de Productos con minimo de existencia <---" << endl;
								cout << miniSuper->ProductosConMinExistencia();
								this->PausaAndClose();
								retornarReportes = true;
								break;
							case 4:
								cout << "Digite la cedula de cliente: "; cin >> ced;
								cout << miniSuper->FacturasDeCliente(ced);
								this->PausaAndClose();
								retornarReportes = true;
								break;
							case 5:
								cout << "--> Lista de las 5 mejores compras <--" << endl;
								cout << miniSuper->CedulaDeLas5MejoresVentas();
								this->PausaAndClose();
								retornarReportes = true;
								break;
							default:
								retornarReportes = false;
								break;

							}
						} while (retornarReportes == true);
					}
					else {
						retornar = false;	//Salir del menu principal
					}
				}
			}
			system("cls");
		} while (retornar == true);
	}
	catch (...){}

	MenuPrincipal::despedida();
}

