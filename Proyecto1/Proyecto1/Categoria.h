#pragma once
#include "Utiles_Clases.h"
#include <stdexcept>

class Categoria {

public:

	Categoria(string);
	virtual~Categoria();
	int getTipoCategoria();
	void setTipoCategoria(int);
	void Tipo(string);
	double porcentajeDeGanancia(); 
   

private: 
	int tipo;
	string categ;
};