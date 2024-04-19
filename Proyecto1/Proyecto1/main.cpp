#include "Utiles_Clases.h"
#include "Producto_Clases.h"
#include "Decorador_Clases.h"
#include "Lista_Generica.h"
#include "Nodo_Generico.h"
#include "Factura.h"
#include "Cliente.h"
#include "Venta.h"

int main() {

	//pruebas decorador

	//fechas
	Fecha* fech1 = new Fecha(01, 1, 2021);
	Fecha* fech2 = new Fecha(22, 2, 2022);
	Fecha* fech3 = new Fecha(30, 3, 2023);
	Fecha* fech4 = new Fecha(14, 4, 2024);
	Fecha* fech5 = new Fecha(25, 5, 2021);
	Fecha* fech6 = new Fecha(16, 6, 2022);
	Fecha* fech7 = new Fecha(07, 7, 2023);
	Fecha* fech8 = new Fecha(12, 8, 2024);
	Fecha* fech9 = new Fecha(19, 9, 2021);
	Fecha* fech10 = new Fecha(10, 10, 2020);

	//percederos
	/*Percedero* pc1 = new Percedero(fech10);
	Percedero* pc2 = new Percedero(fech8);
	Percedero* pc3 = new Percedero(fech5);*/

	//empaque
	Empaque* empac = new Empaque(true);

	//creando objetos tipo Conserva
	Conserva* conserv1 = new Conserva("012", "Carne Molida", "carne molidita", 400, "Conserva", 50, 10, fech1, true);
	Conserva* conserv2 = new Conserva("034", "Torta de Jamon", "jamon", 700, "Conserva", 80, 5, fech2, true);
	Conserva* conserv3 = new Conserva("056", "Bistec", "corte fino", 1000, "Conserva", 45, 7, fech3, true);

	//creando objetos perecederos (Abarrote y Embutido)
	Abarrote* abarrot1 = new Abarrote("078", "Atun", "atun sulli", 600,"Abarrote",100,6,fech4,fech10,true,45.0,"suli");
	Embutido* embuti1 = new Embutido("090","salchichas", "salchichas de pavo", 2500,"Embutido",100,2,fech3,fech9,false,90.0,"pavo","la parte del pavo", "cinta azul");
	Abarrote* abarrot2 = new Abarrote("010", "Sardina", "sardina con tomate", 650, "Abarrote", 80, 9, fech6, fech9, true, 30.0, "sardimar");

	/*carrito*/
	Carrito* car = new Carrito();

	//decoradores
	Decorador_Conserva* Carne = new Decorador_Conserva(car, conserv1);
	Decorador_Conserva* Jamon = new Decorador_Conserva(Carne, conserv2);
	Decorador_Conserva* Bistec = new Decorador_Conserva(Jamon, conserv3);
	Decorador_Abarrote* Atun = new Decorador_Abarrote(Bistec, abarrot1);
	Decorador_Embutido* Salchichas = new Decorador_Embutido(Atun, embuti1);
	Decorador_Abarrote* Sardina = new Decorador_Abarrote(Salchichas, abarrot2);

	//Contenedor de productos usando la lista Generica
	Lista<Producto>* listaprod = new Lista<Producto>();

	
	
	//Agregando los productos al contenedor
	listaprod->agregarInicio(conserv1);
	listaprod->agregarInicio(conserv2);
	listaprod->agregarInicio(conserv3);
	listaprod->agregarInicio(abarrot1);
	listaprod->agregarInicio(abarrot2);
	listaprod->agregarInicio(embuti1);
	//Mostrando lista del contenedor
	cout << "=============================================================" << endl;
	cout << "Lista de productos" << endl;
	cout << listaprod->toString() << endl;
	cout << "===============================================================" << endl;

	//mostrar
	cout << "el carrito contiene: " << endl<<endl;
	cout << Sardina->toString() << endl; 

	system("pause");
	system("cls");


	//factura
	
	 //Crear objetos de Cliente
	Cliente* cliente1 = new Cliente("1111", "William");

	 //Crear objetos de Venta
	Venta* venta1 = new Venta(cliente1, fech1,Sardina);

	 //Crear objetos de Factura
	Factura* factura1 = new Factura(venta1, 1, 1, 1000, 130, 1130);

	factura1->calcularSubtotal();
	factura1->calcularIVA();
	factura1->calcularTotalAPagar();
	cout << "Resumen de la factura:" << endl;
	cout << factura1->mostrarResumenFactura() << endl;

	system("pause");
	system("cls");
	return 0;
}