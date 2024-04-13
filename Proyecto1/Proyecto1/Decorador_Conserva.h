#pragma once
#include "Decorador_Abstracto.h"
#include "Conserva.h"

class Decorador_Conserva : public Decorador_Abstracto {
public:
	Decorador_Conserva(Componente_Abstracto*, Conserva*);
	virtual ~Decorador_Conserva();
	virtual double costo();
	virtual string toString();

private:
	Conserva* conservar;
};
