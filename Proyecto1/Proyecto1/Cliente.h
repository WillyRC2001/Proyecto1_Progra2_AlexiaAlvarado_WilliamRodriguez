#pragma once
#include "Utiles_Clases.h"

class Cliente {
private:
	string nombre; 
	string cedula; 
public: 
	Cliente();
	Cliente(string, string);
	virtual ~Cliente();

	string getNombreCliente();
	string getCedulaCliente();

	void setNombreCliente(string);
	void setCedulaCliente(string);

	string toString();

};