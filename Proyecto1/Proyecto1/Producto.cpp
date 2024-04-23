#include "Producto.h"

Producto::Producto()
{
	this->porcentajeGanancia = new Categoria(nullptr);
	this->fecha = nullptr;
	this->codigo = "";
	this->nombre_comercial = "";
	this->descripion = "";
	this->precio_costo = 0.0;
	this->categoria = "";
	this->existencia = 0;
	this->limite = 0;
}

Producto::Producto(string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, Fecha* fech) :
	codigo(cod), nombre_comercial(nom_comerc),
	descripion(descr), precio_costo(preci), categoria(categ),
	existencia(existe), limite(limit), fecha(fech)
{
	porcentajeGanancia = new Categoria(categoria);
}

Producto::Producto(const Producto& p)
{
	this->porcentajeGanancia = new Categoria(*(p.porcentajeGanancia));
	this->fecha = new Fecha(*(p.fecha));
	this->codigo = p.codigo;
	this->nombre_comercial = p.nombre_comercial;
	this->descripion = p.descripion;
	this->precio_costo = p.precio_costo;
	this->categoria = p.categoria;
	this->existencia = p.existencia;
	this->limite = p.limite;

}

Producto::~Producto()
{
	if (porcentajeGanancia != nullptr) { delete porcentajeGanancia; }
	if (fecha != nullptr) { delete fecha; }

}

Fecha* Producto::getFecha()
{
	return this->fecha;
}

Categoria* Producto::getPorcentajeGanancia()
{
	return this->porcentajeGanancia;
}

string Producto::getCodigo()
{
	return this->codigo;
}

string Producto::getNombre_Comercial()
{
	return this->nombre_comercial;
}

string Producto::getDescripcion()
{
	return this->descripion;
}

double Producto::getPrecio()
{
	return this->precio_costo;
}

string Producto::getCategoria()
{
	return this->categoria;
}

int Producto::getExistencias()
{
	return this->existencia;
}

int Producto::getLimite()
{
	return this->limite;
}

void Producto::setFecha(Fecha* f)
{
	this->fecha = f;
}

void Producto::setCodigo(string cod)
{
	this->codigo = cod; 
}

void Producto::setNombre_Comercial(string NC)
{
	this->nombre_comercial = NC; 
}

void Producto::setDescripcion(string description)
{
	this->descripion = description; 
}

void Producto::setPrecio(double precioColon)
{
	this->precio_costo = precioColon;
}

void Producto::setCategoria(string categoRIA)
{
	this->categoria = categoRIA;
}

void Producto::setPorcentajeGanancia(Categoria* porcentaje)
{
	this->porcentajeGanancia = porcentaje;
}

void Producto::setExistencias(int existenciasProductos)
{
	this->existencia = existenciasProductos;
}

void Producto::setLimite(int limiteProductos)
{
	this->limite = limiteProductos; 
}

bool Producto::verificarExistencia()
{
	if (existencia > 0) {
		return true; 
	}
	else 
		return false;
}

void Producto::venderProducto(int cantidad)
{
	
	if (cantidad > existencia) {
		cout << "Error: No hay suficientes existencias para realizar la venta." << endl;
		return;
	}

	
	existencia -= cantidad;

	// Aquí podrías agregar lógica adicional, como registrar la venta en un archivo o base de datos
	cout << "Venta realizada: " << cantidad << " unidades de " << nombre_comercial << " vendidas." << endl;
}

double Producto::calcularPrecioVenta() {

	return precio_costo * porcentajeGanancia->porcentajeDeGanancia(categoria);
}

double Producto::calcularGanancia() {
	
	return porcentajeGanancia->porcentajeDeGanancia(categoria);
}

string Producto::toString() const
{
	stringstream s;
	s << "-------------------PRODUCTO-----------------" << endl<<endl;
	if (fecha != nullptr) {
		s << "La fecha de ingreso es de " << *(&fecha) << endl;
	}
	s << "Codigo: " << codigo << endl;
	s << "Nombre: " << nombre_comercial << endl;
	s << "Descripcion: " << descripion << endl;
	s << "Precio: " << precio_costo << endl;
	s << "Categoria: " << categoria << endl;
	s << "Porcentaje de Ganancia: " << porcentajeGanancia->porcentajeDeGanancia(categoria) <<" %"<< endl;
	s << "Existencia: " << existencia << endl;
	s << "Limite: " << limite << endl;
	s << "----------------------------------------------" << endl;
	return s.str();
}

ostream& operator<<(ostream& os, const Producto& producto) {
	os << producto.toString();
	return os;
}