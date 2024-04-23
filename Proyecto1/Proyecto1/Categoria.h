#pragma once
#include "Utiles_Clases.h"


class Categoria {

public:

	Categoria(string);
	virtual~Categoria();
	int getTipoCategoria();
	void setTipoCategoria(int);
	void Tipo(string);
	double porcentajeDeGanancia(string); 
   

private: 
	int tipo;
	string categ;
};