#pragma once
#include "Nodo_Producto.h"
#include "Producto.h"
#include "Producto_Clases.h"
#include "Utiles_Clases.h"
#include <vector>


class ContenedorLProducto {
private:
	NodoProducto* ppio;
public:
	ContenedorLProducto();
	virtual~ContenedorLProducto();
	NodoProducto* getPpio();
	bool esVacio();
	bool ingresaProducto(Producto*);
	string toString();
	Producto* busca(string);
	bool eliminarProducto(string);
	bool cambiarProducto(string, Producto*);
	void IngresarProducto(string codigo, Producto* nuevo);				//Contenedor Producto
	string TodosLosProductos();							//Contenedor Producto
	string ProductoDeUnaCategoria(string categoria);	//Contenedor Producto
	string ProductosConMinExistencia();					//Contenedor Producto
	bool guardar(); //archivos
	bool recuperar();
};


ContenedorLProducto::ContenedorLProducto() :ppio(NULL) {

}

ContenedorLProducto::~ContenedorLProducto()
{
	if (ppio != NULL) {
		delete ppio;
	}
}
NodoProducto* ContenedorLProducto::getPpio()
{
	return ppio;
}
bool ContenedorLProducto::esVacio()
{
	return (ppio == NULL);
}
bool ContenedorLProducto::ingresaProducto(Producto* pro)
{
	NodoProducto* p = ppio;

	if (esVacio()) {
		ppio = new NodoProducto(pro);
		return true;
	}
	else {
		while (p->getsig() != NULL)
			p = p->getsig();
		p->setsig(new NodoProducto(pro));
		return true;
	}
	return false;
}

string ContenedorLProducto::toString()
{
	stringstream s;
	NodoProducto* p = ppio;
	while (p != NULL) {
		s << p->getProd()->toString();
		p = p->getsig();
		s << endl;
	}
	return s.str();
}
Producto* ContenedorLProducto::busca(string cod)
{
	NodoProducto* p = ppio;
	if (!esVacio()) {
		while (p != NULL) {
			if (p->getProd()->getCodigo() == cod) {
				return p->getProd();

			}
			p = p->getsig();
		}
	}
	return NULL;
}

bool ContenedorLProducto::eliminarProducto(string cod)
{
	NodoProducto* p = ppio;
	NodoProducto* anterior = NULL;
	if (!esVacio() && p->getProd()->getCodigo() == cod) {
		NodoProducto* actual = ppio;
		if (!esVacio()) {
			ppio = actual->getsig();
			delete actual;
			return true;
		}
	}
	else
		if (!esVacio()) {
			while (p != NULL && p->getProd()->getCodigo() != cod) {
				anterior = p;
				p = p->getsig();
			}
			anterior->setsig(p->getsig());
			delete p;
			return true;
		}
	return false;


}

bool ContenedorLProducto::cambiarProducto(string cod, Producto* per)
{
	NodoProducto* p = ppio;
	if (!esVacio()) {
		if (ppio->getProd()->getCodigo() == cod) {
			ppio->setProd(per);
			return true;
		}

		while (p != NULL)
		{

			if (p->getProd()->getCodigo() == cod) {
				p->setProd(per);
				return true;
			}
			p = p->getsig();

		}
	}
	return false;

}
///////////////////////////////////////////////////////////////////////////////////////
void ContenedorLProducto::IngresarProducto(string codigo, Producto* nuevo){
	if (this->busca(codigo) == NULL) {
		this->ingresaProducto(nuevo);
	}
}
string ContenedorLProducto::TodosLosProductos(){
	return this->toString();
}
string ContenedorLProducto::ProductoDeUnaCategoria(string categoria){
	stringstream s;
	NodoProducto* p = ppio;
	if (!esVacio()) {
		while (p != NULL) {
			if (p->getProd()->getCategoria() == categoria) {
				s << p->getProd()->toString();
			}
			p = p->getsig();
		}
	}
	return s.str();
}
string ContenedorLProducto::ProductosConMinExistencia(){
	stringstream s;
	NodoProducto* p = ppio;
	if (!esVacio()) {
		while (p != NULL) {
			if (p->getProd()->getLimite() <= 5) {
				s << p->getProd()->toString();
			}
			p = p->getsig();
		}
	}
	return s.str();
}

bool ContenedorLProducto::guardar() { //archivos
	try {
		ofstream archivo("producto.txt");
		if (archivo.is_open()) {
			NodoProducto* actual = ppio;
			while (actual != nullptr) {
				Producto* producto = actual->getProd();

				Categoria* categoria = producto->getPorcentajeGanancia();
				string categoriaprod = producto->getCategoria();
				if (categoriaprod == "Conserva" || categoriaprod == "conserva") {
					Conserva* conserva = dynamic_cast<Conserva*>(producto);
					Fecha* fecha = producto->getFecha();
					archivo << "1," << conserva->getCodigo() << "," << conserva->getNombre_Comercial() << "," << conserva->getDescripcion() << "," << conserva->getPrecio() << "," << conserva->getCategoria() << "," << conserva->getExistencias() << "," << conserva->getLimite() << "," << conserva->getEnvasado() << endl;
					archivo << fecha->getDia() << "," << fecha->getMes() << "," << fecha->getAnio() << endl;
				}
				if (categoriaprod == "Abarrote" || categoriaprod == "abarrote") {
					Abarrote* abarrote = dynamic_cast<Abarrote*>(producto);
					Percedero* percedero = abarrote->getPercedero();
					Fecha* fechaing = abarrote->getFecha();
					Fecha* fechavenc = percedero->getVenceEl();
					archivo << "2," << abarrote->getCodigo() << "," << abarrote->getNombre_Comercial() << "," << abarrote->getDescripcion() << "," << abarrote->getPrecio() << "," << abarrote->getCategoria() << "," << abarrote->getExistencias() << "," << abarrote->getLimite() << "," << abarrote->getNacional() << "," << abarrote->getPeso() << "," << abarrote->getAbarroteNombreEmpresa() << endl;
					archivo << fechaing->getDia() << "," << fechaing->getMes() << "," << fechaing->getAnio() << endl;
					archivo << fechavenc->getDia() << "," << fechavenc->getMes() << "," << fechavenc->getAnio() << endl;
				}
				if (categoriaprod == "Embutido" || categoriaprod == "embutido") {
					Embutido* embutido = dynamic_cast<Embutido*>(producto);
					Percedero* percedero = embutido->getPercedero();
					Empaque* empaque = embutido->getEmpaque();
					Fecha* fechaing = embutido->getFecha();
					Fecha* fechavenc = percedero->getVenceEl();
					archivo << "3," << embutido->getCodigo() << "," << embutido->getNombre_Comercial() << "," << embutido->getDescripcion() << "," << embutido->getPrecio() << "," << embutido->getCategoria() << "," << embutido->getExistencias() << "," << embutido->getLimite() << "," << embutido->getNacional() << "," << embutido->getPeso() << "," << embutido->getNombreAnimal() << "," << embutido->getParteAnimal() << "," << embutido->getMarca() << "," << empaque->getTripa() << endl;
					archivo << fechaing->getDia() << "," << fechaing->getMes() << "," << fechaing->getAnio() << endl;
					archivo << fechavenc->getDia() << "," << fechavenc->getMes() << "," << fechavenc->getAnio() << endl;
				}
				actual = actual->getsig();
			}
			archivo.close();
			return true;
		}
		return false;
	}
	catch (exception excep) {
		return false;
	}
}

bool ContenedorLProducto::recuperar(){
	const string archivo = "producto.txt";
	ifstream archivoEntrada(archivo);
	if (archivoEntrada.is_open()) {
		string linea;
		while (getline(archivoEntrada, linea)) {
			vector<string> campos;
			stringstream ss(linea);
			string campo;
			while (getline(ss, campo, ',')) {
				campos.push_back(campo);
			}
			if (campos[0] == "1") {
				bool env = (campos[8]=="1") ? true : false;
				Conserva* conserva = new Conserva(campos[1], campos[2], campos[3], stod(campos[4]), campos[5], stoi(campos[6]), stoi(campos[7]),nullptr,env);
				string fechaLine;
				getline(archivoEntrada, fechaLine);
				vector<string> camposfecha;
				stringstream sss(fechaLine);
				string a;
				while (getline(sss, a, ',')) {
					camposfecha.push_back(a);
				}
				int dia = stoi(camposfecha[0]);
				int mes = stoi(camposfecha[1]);
				int anio = stoi(camposfecha[2]);
				Fecha* fecha1 = new Fecha(dia,mes,anio);
				conserva->setFecha(fecha1);
				this->ingresaProducto(conserva);
			}
			if (campos[0] == "2") {
				bool nacion = (campos[8] == "1") ? true : false;
				Abarrote* abarrote = new Abarrote(campos[1], campos[2], campos[3], stod(campos[4]), campos[5], stoi(campos[6]), stoi(campos[7]), nullptr, nullptr, stoi(campos[8]), stod(campos[9]), campos[10]);
				string fechaLine1;
				getline(archivoEntrada, fechaLine1);
				vector<string> camposfecha;
				stringstream sss(fechaLine1);
				string a;
				while (getline(sss, a, ',')) {
					camposfecha.push_back(a);
				}
				int dia = stoi(camposfecha[0]);
				int mes = stoi(camposfecha[1]);
				int anio = stoi(camposfecha[2]);
				Fecha* fecha1 = new Fecha(dia, mes, anio);
				abarrote->setFecha(fecha1);
				//Recuperando fecha vencimiento
				string fechaLine2;
				getline(archivoEntrada, fechaLine2);
				vector<string> camposfecha2;
				stringstream ssss(fechaLine2);
				string b;
				while (getline(ssss, b, ',')) {
					camposfecha2.push_back(b);
				}
				dia = stoi(camposfecha2[0]);
				mes = stoi(camposfecha2[1]);
				anio = stoi(camposfecha2[2]);
				Fecha* fecha2 = new Fecha(dia, mes, anio);
				Percedero* percedero = new Percedero(fecha2);
				abarrote->setPercedero(percedero);
				this->ingresaProducto(abarrote);
			}
			if (campos[0] == "3") {
				bool tripa = (campos[13] == "1") ? true : false;
				Embutido* embutido = new Embutido(campos[1], campos[2], campos[3], stod(campos[4]), campos[5], stoi(campos[6]), stoi(campos[7]), nullptr, nullptr, stoi(campos[8]), stod(campos[9]),campos[10],campos[11],campos[12],nullptr);
				string fechaLine1;
				getline(archivoEntrada, fechaLine1);
				vector<string> camposfecha;
				stringstream sss(fechaLine1);
				string a;
				while (getline(sss, a, ',')) {
					camposfecha.push_back(a);
				}
				int dia = stoi(camposfecha[0]);
				int mes = stoi(camposfecha[1]);
				int anio = stoi(camposfecha[2]);
				Fecha* fecha1 = new Fecha(dia, mes, anio);
				embutido->setFecha(fecha1);
				//Recuperando fecha vencimiento
				string fechaLine2;
				getline(archivoEntrada, fechaLine2);
				vector<string> camposfecha2;
				stringstream ssss(fechaLine2);
				string b;
				while (getline(ssss, b, ',')) {
					camposfecha2.push_back(b);
				}
				dia = stoi(camposfecha2[0]);
				mes = stoi(camposfecha2[1]);
				anio = stoi(camposfecha2[2]);
				Fecha* fecha2 = new Fecha(dia, mes, anio);
				Percedero* percedero = new Percedero(fecha2);
				embutido->setPercedero(percedero);
				Empaque* empaque = new Empaque(tripa);
				embutido->setEmpaque(empaque);
				this->ingresaProducto(embutido);
			}
		}
	}
	archivoEntrada.close();
	return true;
}