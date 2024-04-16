#pragma once
#include "Utiles_Clases.h"

template <class T>
class Nodo {
private:
	Nodo* sig;
	T* obj;
public:
	Nodo(Nodo<T>*, T&);	//(Puntero al sig nodo, Objeto de tipo T)
	virtual ~Nodo();
	Nodo<T>* GetSiguiente() const;
	T* GetObj() const;
	void SetObj(T*);
	void SetSiguiente(Nodo<T>* n);
};

template <class T>
Nodo<T>::Nodo(Nodo<T>* sigNodo, T& objeto)
	: sig(sigNodo), obj(&objeto) {
}

template <class T>
Nodo<T>::~Nodo() {
	if (obj != NULL)
		delete obj;
}

template <class T>
Nodo<T>* Nodo<T>::GetSiguiente() const{
	return sig;
}

template <class T>
T* Nodo<T>::GetObj() const{
	return obj;
}

template <class T>
void Nodo<T>::SetSiguiente(Nodo<T>* n) {
	sig = n;
}

template <class T>
void Nodo<T>::SetObj(T* n) {
	obj = n;
}
