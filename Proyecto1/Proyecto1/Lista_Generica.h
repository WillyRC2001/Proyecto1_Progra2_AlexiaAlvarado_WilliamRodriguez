#pragma once
#include "Nodo_Generico.h"
#include "Cliente.h"
#include "Utiles_Clases.h"
#include "Factura.h"
#include <map>

template <class T>
class Lista {
public:
	Lista();
	Lista(const Lista&);
	Lista& operator =(const Lista&);
	virtual ~Lista();
	void agregarInicio(T*);
	void agregarFinal(T*);
	bool eliminar(T*);
	string toString();
	void eliminarTodos();
	int size();
	bool isEmpty();
	void incializarActual();
	int getCantElem();
	//Metodos que necesitaba la lista template de ventas
	T* buscarNumeroFactura(int num_factura);
	string FacturaDeCliente(string cedula);
	bool actualizar(T*);
	string CedulaMejoresVentas();
	T* obtenerClientePorCedula(string cedula);


private:
	int cantElementos; 
	Nodo<T>* primerNodo;
	Nodo<T>* actual;
};

template<class T>
Lista<T>::Lista() {
	primerNodo = NULL; 
}

template<class T>
Lista<T>::Lista(const Lista& list) {
	primerNodo = NULL;
	Nodo<T>* pExt = list.primerNodo;
	while (pExt != NULL) {
		this->agregarFinal(pExt->GetObj());
		pExt = pExt->GetSiguiente();
	}
}

template<class T>
Lista<T>::~Lista() {
	Nodo<T>* aux = primerNodo;
	while (aux != NULL) {
		primerNodo = aux->GetSiguiente();
		delete aux;
		aux = primerNodo;
	}
}

template<class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& otra) {
	if (this != &otra) {
		while (primerNodo != NULL) {
			Nodo<T>* aux = primerNodo;
			primerNodo = primerNodo->GetSiguiente();
			delete aux;
		}

		if (otra.primerNodo != NULL) {
			primerNodo = new Nodo<T>(NULL, *(otra.primerNodo->GetObj()));
			Nodo<T>* pExtThis = primerNodo;
			Nodo<T>* pExtOtra = otra.primerNodo->GetObj();
			while (pExtOtra != NULL) {
				pExtThis->SetSiguiente(new Nodo<T>(NULL, *(pExtOtra->GetObj())));
				pExtThis = pExtThis->GetSiguiente();
				pExtOtra = pExtOtra->GetSiguiente();
			}
		}
	}
	return *this;
}

template<class T>
void Lista<T>::agregarInicio(T* n) {
	T* aux = new T(*n);	
	primerNodo = new Nodo<T>(primerNodo, *aux);
}

template<class T>
void Lista<T>::agregarFinal(T* n) {
	if (this->isEmpty())
		agregarInicio(n);
	else {
		Nodo<T>* pExt = primerNodo;
		while (pExt->GetSiguiente() != NULL) {
			pExt = pExt->GetSiguiente();
		}
		T* aux = new T(*n);
		pExt->SetSiguiente(new Nodo<T>(NULL, *aux));
	}
}

template<class T>
bool Lista<T>::eliminar(T* obj) {
	Nodo<T>* aux = primerNodo;
	Nodo<T>* anterior = NULL;
	//si es el primero elimina el nodo
	if (primerNodo != NULL && primerNodo->GetObj() == obj) {
		Nodo<T>* actual = primerNodo;
		primerNodo = actual->GetSiguiente();
		delete actual;
		return true;
	}
	//si no es el primero
	else {
		while (aux != NULL && aux->GetObj() != obj) {
			anterior = aux;
			aux = aux->GetSiguiente();
		}
		if (aux != NULL && aux->GetObj() == obj) {
			if (anterior != NULL)
				anterior->SetSiguiente(aux->GetSiguiente());
			delete aux;
			return true;
		}
	}
	return false;
}
template<class T>
string Lista<T>::toString() {
	stringstream s;
	Nodo<T>* pExt = primerNodo;
	while (pExt != NULL) {
		s << *pExt->GetObj();
		pExt = pExt->GetSiguiente();
	}
	return s.str();
}

template<class T>
void Lista<T>::eliminarTodos() {
	Nodo<T>* aux = primerNodo;
	while (aux != NULL) {
		primerNodo = aux->GetSiguiente();
		delete aux;
		aux = primerNodo;
	}
}

template<class T>
int Lista<T>::size() {
	Nodo<T>* pExt = primerNodo;
	int i = 0;
	while (pExt) {
		pExt = pExt->GetSiguiente();
		i++;
	}
	return i;
}

template <class T>
bool Lista<T>::isEmpty() {
	return (primerNodo == NULL);
}

template<class T>
void Lista<T>::incializarActual() {
	actual = primerNodo;
}

template<class T>
inline int Lista<T>::getCantElem() {
	return cantElementos;
}

template<class T>
T* Lista<T>::buscarNumeroFactura(int num_factura)
{
	Nodo<T>* p = primerNodo;
	if (!NULL) {
		while (p != NULL) {
			if (p->GetObj()->getNumeroFactura() == num_factura) {
				return p->GetObj();

			}
			p = p->GetSiguiente();
		}
	}
	return NULL;
}

template<class T>
bool Lista<T>::actualizar(T* obj) {
	Nodo<T>* aux = primerNodo;
}

template<class T>
string Lista<T>::CedulaMejoresVentas() {
	stringstream s;
	
	map<double, string> myMap;
	Nodo<T>* curr = primerNodo;
	while (curr != nullptr) {
		Factura* factura = curr->GetObj();
		Venta* venta = factura->getVenta();
		Cliente* cliente = venta->getClienteComprador();
		double ventaTotal = venta->ObtenerTotalVenta();
		string cedula = cliente->getCedulaCliente();
		myMap[ventaTotal] = cedula;
		curr = curr->GetSiguiente();
	}
	map<double, string> ultimasVentas;
	auto it = myMap.rbegin();
	int count = 0;
	while (it != myMap.rend() && count < 5) {
		ultimasVentas[it->first] = it->second;
		++it;
		++count;
	}
	for (auto it = ultimasVentas.rbegin(); it != ultimasVentas.rend(); ++it) {
		s << "Venta: " << it->first << ", Cliente: " << it->second << endl;
	}
	string result = s.str();
	return s.str();
}

template<class T>
string Lista<T>::FacturaDeCliente(string cedula){
	stringstream s;
	Nodo<T>* pExt = primerNodo;
	while (pExt != NULL) {
		if (pExt->GetObj()->getVenta()->getClienteComprador()->getCedulaCliente() == cedula) {
			s << pExt->GetObj()->toString() << endl;
			s << "-------------------------------------" << endl;
		}
		pExt = pExt->GetSiguiente();
	}
	return s.str();
}

template<class T>
T* Lista<T>::obtenerClientePorCedula(string cedula) {

	Nodo<T>* pExt = primerNodo;
	while (pExt != nullptr) {
		Cliente* cliente = pExt->GetObj()->buscarClientePorCedula(cedula);
		if (cliente != nullptr) {
			return cliente; // Cliente encontrado
		}
		pExt = pExt->GetSiguiente();
	}
	return nullptr; // Cliente no encontrado en ninguna venta
}