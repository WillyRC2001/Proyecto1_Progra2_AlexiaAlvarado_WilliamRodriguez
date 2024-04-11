#include "Producto.h"

Producto::Producto(string cod, string nom_comerc, string descr, double preci, string categ, Categoria* categor,int existe, int limit, Fecha* fech):
	codigo(cod),nombre_comercial(nom_comerc),
	descripion(descr),precio_costo(preci),categoria(categ), categoria2(categor),
	existencia(existe),limite(limit), fecha(fech)
{

}

Producto::~Producto()
{
}

Fecha* Producto::getFecha()
{
	return this->fecha;
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

Categoria* Producto::getCategoria2()
{
	return this->categoria2;
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

void Producto::setCategoria2(Categoria* categoRIA2)
{
	this->categoria2 = categoRIA2;
}

void Producto::setExistencias(int existenciasProductos)
{
	this->existencia = existenciasProductos;
}

void Producto::setLimite(int limiteProductos)
{
	this->limite = limiteProductos; 
}

/*
void Producto::establecerPrecioVenta(double precioVenta)
{
	this->precio_costo = precioVenta; 
}

void Producto::establecerCategoria(Categoria* cat)
{
	this->categoria2 = cat; 
}
*/
bool Producto::verificarExistencia()
{
	//revise si esto esta bien jajaj
	if (existencia > 0) {
		return true; 
	}
	else 
		return false;
}

string Producto::toString()
{
	stringstream s;
	s << "-------------------PRODUCTO-----------------" << endl<<endl;
	s << "Codigo: " << codigo << endl;
	s << "Nombre: " << nombre_comercial << endl;
	s << "Precio: " << precio_costo << endl;
	s << "Categoria: " << categoria << endl;
	s << "Categoria del Producto: " << categoria2 << endl; 
	s << "Descripcion: " << descripion << endl;
	s << "Existencia: " << existencia << endl;
	s << "Limite: " << limite << endl;
	s << "----------------------------------------------" << endl;
	return s.str();
}
