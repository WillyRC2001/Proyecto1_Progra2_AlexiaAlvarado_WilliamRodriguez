#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std; 

class Categoria {

public:

	Categoria(); 
	Categoria(int);
	virtual~Categoria();
	int getTipoCategoria();
	void setTipoCategoria(int);
	double porcentanjeDeGanancia(); 

private: 
	int tipo; 
};