#pragma once
#include "Nodo_Generico.h"
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class Lista {
public:
	Lista();
	Lista(const Lista&);
	//Lista& operator =(const Lista&);
	virtual ~Lista();
	void agregarInicio(T*);
	void agregarFinal(T*);
	T* eliminar();
	//string toString();
	void eliminarTodos();
	int size();
	void remover(int lugar);
	void removerInicio();
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
	//Aqui me falta hacer la eliminacion de los objetos
}

template<class T>
void Lista<T>::agregarInicio(T* n) {
	T* aux = new T(*n);	
	primerNodo = new Nodo<T>(primerNodo, *aux);
}

template<class T>
void Lista<T>::agregarFinal(T* n) {
	if (ths.isEmpty())
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
T* Lista<T>::eliminar() {
	//Me falta
}

template<class T>
void Lista<T>::eliminarTodos() {
	//Me falta
}

template<class T>
int Lista<T>::size() {
	Nodo<T>* pExt = primerNodo;
	int i = 0;
	while (pExt) {
		pEXt = pExt->GetSiguiente();
		i++;
	}
	return i;
}

template<class T>
void Lista<T>::remover(int lugar) {
	//Me falta
}

template<class T>
void Lista<T>::removerInicio() {
	//Me falta
}

template <class T>
bool Lista<T>::isEmpty() {
	return (primerNodo == NULL);
}