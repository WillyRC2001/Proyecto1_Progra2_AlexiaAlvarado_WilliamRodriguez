#pragma once
#include "Nodo_Generico.h"
#include "Utiles_Clases.h"

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
private:
	Nodo<T>* primerNodo;
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