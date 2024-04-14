#pragma once
#include "Utiles_Clases.h"
#include <stdexcept>

class Categoria {

public:

	Categoria(); 
	Categoria(int);
	virtual~Categoria();
	int getTipoCategoria();
	void setTipoCategoria(int);
	void Tipo(string);
	double porcentajeDeGanancia(string); 
   

private: 
	int tipo; 
};