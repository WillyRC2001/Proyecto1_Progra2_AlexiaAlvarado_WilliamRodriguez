#include "Controler.h"
#include "Utiles_Clases.h"
#include "Producto_Clases.h"
#include "Decorador_Clases.h"
#include "Lista_Generica.h"
#include "Nodo_Generico.h"
#include "Nodo_Producto.h"
#include "Lista_Producto.h"
#include "Factura.h"
#include "Cliente.h"
#include "Venta.h"

int main() {

	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Creación del contenedor de productos
	ContenedorLProducto* contenedorProductos = new ContenedorLProducto();
	//Creación del Contenedor de Facturas (template)
	Lista<Factura>* contenedorFactura = new Lista<Factura>();
	//Creacion del minisuper
	Controler* cont = new Controler();
	MiniSuper* mini = new MiniSuper(contenedorProductos, contenedorFactura);
	mini->recuperar();

	//Informacion de productos Quemados para Respaldo
	
	////fechas
	//Fecha* fech1 = new Fecha(01, 1, 2021);
	//Fecha* fech2 = new Fecha(22, 2, 2022);
	//Fecha* fech3 = new Fecha(30, 3, 2023);
	//Fecha* fech4 = new Fecha(14, 4, 2024);
	//Fecha* fech5 = new Fecha(25, 5, 2021);
	//Fecha* fech6 = new Fecha(16, 6, 2022);
	//Fecha* fech7 = new Fecha(07, 7, 2023);
	//Fecha* fech8 = new Fecha(12, 8, 2024);
	//Fecha* fech9 = new Fecha(19, 9, 2021);
	//Fecha* fech10 = new Fecha(10, 10, 2020);

	////empaque
	//Empaque* empac = new Empaque(true);
	//

	//Conserva* conserv1 = new Conserva("012", "Carne Molida", "carne molidita", 400, "Conserva", 50, 10, fech1, true);
	//Conserva* conserv2 = new Conserva("034", "Torta de Jamon", "jamon", 700, "Conserva", 80, 5, fech2, true);
	//Conserva* conserv3 = new Conserva("056", "Bistec", "corte fino", 1000, "Conserva", 45, 7, fech3, true);
	//Abarrote* abarrot1 = new Abarrote("078", "Atun", "atun sulli", 600, "Abarrote", 100, 6, fech4, fech10, true, 45.0, "suli");
	//Embutido* embuti1 = new Embutido("090", "salchichas", "salchichas de pavo", 2500, "Embutido", 100, 2, fech3, fech9, false, 90.0, "pavo", "la parte del pavo", "cinta azul", empac);
	//Abarrote* abarrot2 = new Abarrote("010", "Sardina", "sardina con tomate", 650, "Abarrote", 80, 9, fech6, fech9, true, 30.0, "sardimar");

	//Los productos estan dentro de productos.txt pero como no existe un facturas.txt los ocupamos llamar para usar los decoradores de venta quemados
	Producto* producto = contenedorProductos->busca("012");
	Conserva* conserv1 = dynamic_cast<Conserva*>(producto);
	producto = contenedorProductos->busca("034");
	Conserva* conserv2 = dynamic_cast<Conserva*>(producto);
	producto = contenedorProductos->busca("056");
	Conserva* conserv3 = dynamic_cast<Conserva*>(producto);
	producto = contenedorProductos->busca("078");
	Abarrote* abarrot1 = dynamic_cast<Abarrote*>(producto);
	producto = contenedorProductos->busca("090");
	Embutido* embuti1 = dynamic_cast<Embutido*>(producto);
	producto = contenedorProductos->busca("010");
	Abarrote* abarrot2 = dynamic_cast<Abarrote*>(producto);

	/*carrito*/
	Carrito* car = new Carrito();

	//decoradores
	Decorador_Conserva* Carne = new Decorador_Conserva(car, conserv1);
	Decorador_Conserva* Jamon = new Decorador_Conserva(Carne, conserv2);
	Decorador_Conserva* Bistec = new Decorador_Conserva(Jamon, conserv3);
	Decorador_Abarrote* Atun = new Decorador_Abarrote(Bistec, abarrot1);
	Decorador_Embutido* Salchichas = new Decorador_Embutido(Atun, embuti1);
	Decorador_Abarrote* Sardina = new Decorador_Abarrote(Salchichas, abarrot2);

	// Creación de objetos Cliente
	Cliente* cliente1 = new Cliente("Juan Perez", "1234567890");
	Cliente* cliente2 = new Cliente("Maria Lopez", "0987654321");
	Cliente* cliente3 = new Cliente("Benja", "1235389010");
	Cliente* cliente4 = new Cliente("Andrea", "543566545");
	Cliente* cliente5 = new Cliente("Luis", "1234567890");

	// Creación de objeto Fecha para la venta
	Fecha* fechaVenta1 = new Fecha(20, 4, 2024);

	// Creación de objeto Venta
	Venta* venta1 = new Venta(cliente1, fechaVenta1, Sardina);
	Venta* venta2 = new Venta(cliente2, fechaVenta1, Carne);
	Venta* venta3 = new Venta(cliente3, fechaVenta1, Bistec);
	Venta* venta4 = new Venta(cliente4, fechaVenta1, Atun);
	Venta* venta5 = new Venta(cliente5, fechaVenta1, Sardina);
	// Creación de objeto Venta
	int numerofactura1 = 001;
	int numerofactura2 = 002;
	int numerofactura3 = 003;
	int numerofactura4 = 004;
	int numerofactura5 = 005;
	Factura* fact1 = new Factura(venta1, numerofactura1);
	Factura* fact2 = new Factura(venta2, numerofactura2);
	Factura* fact3 = new Factura(venta3, numerofactura3);
	Factura* fact4 = new Factura(venta4, numerofactura4);
	Factura* fact5 = new Factura(venta5, numerofactura5);

	//Agregar Facturas al contenedor
	contenedorFactura->agregarInicio(fact1);
	contenedorFactura->agregarInicio(fact2);
	contenedorFactura->agregarInicio(fact3);
	contenedorFactura->agregarInicio(fact4);
	contenedorFactura->agregarInicio(fact5);

	//Ingresar Contenedor Producto RESPALDO
	/*contenedorProductos->ingresaProducto(conserv1);
	contenedorProductos->ingresaProducto(conserv2);
	contenedorProductos->ingresaProducto(conserv3);
	contenedorProductos->ingresaProducto(abarrot1);
	contenedorProductos->ingresaProducto(abarrot2);
	contenedorProductos->ingresaProducto(embuti1);*/
	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	cont->VerMenus(mini);

	system("pause");
	system("cls");


	return 0;
}