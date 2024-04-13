#pragma once
#include "Decorador_Abstracto.h"
#include "Embutido.h"

class Decorador_Embutido : public Decorador_Abstracto {
public:
	Decorador_Embutido(Componente_Abstracto*, Embutido*);
	virtual ~Decorador_Embutido();
	virtual double costo();
	virtual string toString();

private:
	Embutido* embutidos;
};
