#pragma once
#include "Decorador_Abstracto.h"
#include "Abarrote.h"

class Decorador_Abarrote : public Decorador_Abstracto {
public:
	Decorador_Abarrote(Componente_Abstracto*, Abarrote*);
	virtual ~Decorador_Abarrote();

	Abarrote* getAbarrote();
	void setAbarrote(Abarrote* nuevoAbarrote);

	string obtener_nombre();
	string obtener_codigo();
	double obtener_costo();

	string toString();

private:
	Abarrote* ptrAbarrotes;
};
