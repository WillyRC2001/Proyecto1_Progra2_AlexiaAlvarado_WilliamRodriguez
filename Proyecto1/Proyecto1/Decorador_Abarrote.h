#pragma once
#include "Decorador_Abstracto.h"
#include "Abarrote.h"

class Decorador_Abarrote : public Decorador_Abstracto {
public:
	Decorador_Abarrote(Componente_Abstracto*, Abarrote*);
	virtual ~Decorador_Abarrote();
	virtual double costo();
	virtual string toString();

private:
	Abarrote* abarrotes;
};
