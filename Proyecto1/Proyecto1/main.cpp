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
#include "Controler.h"

int main() {
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

	//empaque
	Empaque* empac = new Empaque(true);

	//creando objetos tipo Conserva
	Conserva* conserv1 = new Conserva("012", "Carne Molida", "carne molidita", 400, "Conserva", 50, 10, fech1, true);
	Conserva* conserv2 = new Conserva("034", "Torta de Jamon", "jamon", 700, "Conserva", 80, 5, fech2, true);
	Conserva* conserv3 = new Conserva("056", "Bistec", "corte fino", 1000, "Conserva", 45, 7, fech3, true);

	//creando objetos perecederos (Abarrote y Embutido)
	Abarrote* abarrot1 = new Abarrote("078", "Atun", "atun sulli", 600,"Abarrote",100,6,fech4,fech10,true,45.0,"suli");
	Embutido* embuti1 = new Embutido("090","salchichas", "salchichas de pavo", 2500,"Embutido",100,2,fech3,fech9,false,90.0,"pavo","la parte del pavo", "cinta azul",empac);
	Abarrote* abarrot2 = new Abarrote("010", "Sardina", "sardina con tomate", 650, "Abarrote", 80, 9, fech6, fech9, true, 30.0, "sardimar");

	/*carrito*/
	Carrito* car = new Carrito();

	//Carrito* car2 = new Carrito();
	//int cant = 3;
	//Decorador_Conserva* dec1 = new Decorador_Conserva(car2, conserv1); //Primer ingreso
	//Componente_Abstracto* aux = dec1;
	//for (int i = 0; i <= cant - 1; i++) {
	//	//Se busca el producto
	//	//Se cambia al atributo correspondiente, en este caso conserva
	//	DecoradorConserva* dec2 = new Decorador_Conserva(aux, productoconserva);
	//	Componente_Abstracto* aux = dec2;
	//}

	//decoradores
	Decorador_Conserva* Carne = new Decorador_Conserva(car, conserv1);
	Decorador_Conserva* Jamon = new Decorador_Conserva(Carne, conserv2);
	Decorador_Conserva* Bistec = new Decorador_Conserva(Jamon, conserv3);
	Decorador_Abarrote* Atun = new Decorador_Abarrote(Bistec, abarrot1);
	Decorador_Embutido* Salchichas = new Decorador_Embutido(Atun, embuti1);
	Decorador_Abarrote* Sardina = new Decorador_Abarrote(Salchichas, abarrot2);

	//mostrar
	cout << "el carrito contiene: " << endl<<endl;
	cout << Sardina->toString() << endl; 

	system("pause");
	system("cls");
	

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
	Factura* fact1 = new Factura(venta1,numerofactura1);
	Factura* fact2 = new Factura(venta2, numerofactura2);
	Factura* fact3 = new Factura(venta3, numerofactura3);
	Factura* fact4 = new Factura(venta4, numerofactura4);
	Factura* fact5 = new Factura(venta5, numerofactura5);

	// Mostrar información de la venta
	cout << "Informacion de la Venta:" <<endl;
	cout << venta1->toString() << endl;

	system("pause");
	system("cls");

	// Creación del contenedor de productos
	ContenedorLProducto* contenedorProductos = new ContenedorLProducto();

	// Agregar productos al contenedor
	contenedorProductos->ingresaProducto(conserv1);
	contenedorProductos->ingresaProducto(conserv2);
	contenedorProductos->ingresaProducto(conserv3);
	contenedorProductos->ingresaProducto(abarrot1);
	contenedorProductos->ingresaProducto(abarrot2);
	contenedorProductos->ingresaProducto(embuti1);

	Producto* producto = contenedorProductos->busca("codigo_del_producto");

	//if (producto) {
	//	// Crear un objeto Carrito (u otro componente abstracto)
	//	Carrito* carrito = new Carrito();

	//	// Crear un objeto Conserva utilizando los datos del producto
	//	Conserva* conserva2 = dynamic_cast<Conserva*>(producto);
	//	//Conserva* conserva = new Conserva(producto->getCodigo(), producto->getNombre_Comercial(), producto->getDescripcion(), producto->getPrecio(), producto->getCategoria(), producto->getExistencias(), producto->getLimite(), producto->getFecha(), true);

	//	// Crear un objeto Decorador_Conserva utilizando el producto y el carrito
	//	Decorador_Conserva* decoradorConserva = new Decorador_Conserva(carrito,conserva2);

	//	// Ahora puedes utilizar el decoradorConserva en la creación de un objeto Venta
	//	Venta* venta = new Venta(cliente1,fechaVenta1, decoradorConserva);

	//	// Asegúrate de liberar la memoria cuando ya no necesites los objetos
	//	delete venta;
	//	delete decoradorConserva;
	//	delete carrito;
	//}


	//Creación del Contenedor de Ventas (template)
	Lista<Factura>* contenedorFactura = new Lista<Factura>();

	//Agregar Ventas al contenedor
	contenedorFactura->agregarInicio(fact1);
	contenedorFactura->agregarInicio(fact2);
	contenedorFactura->agregarInicio(fact3);
	contenedorFactura->agregarInicio(fact4);
	contenedorFactura->agregarInicio(fact5);

	//Pruebas con los menu no toque
	Controler* cont = new Controler();
	MiniSuper* mini = new MiniSuper(contenedorProductos, contenedorFactura);
	cont->VerMenus(mini);

	system("pause");
	system("cls");


	return 0;
}