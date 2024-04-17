#pragma once
#include "Decorador_Abstracto.h"
#include "Conserva.h"

class Decorador_Conserva : public Decorador_Abstracto {
public:
	Decorador_Conserva(Componente_Abstracto*, Conserva*);
	virtual ~Decorador_Conserva();

	Conserva* getConserva();
	void setConserva(Conserva* nuevaConserva);

	string obtener_nombre();
	string obtener_codigo();
	double obtener_costo();

	string toString();

private:
	Conserva* ptrConservas;
};
