#pragma once
#include "Decorador_Abstracto.h"
#include "Embutido.h"

class Decorador_Embutido : public Decorador_Abstracto {
public:
	Decorador_Embutido(Componente_Abstracto*, Embutido*);
	virtual ~Decorador_Embutido();

	Embutido* getEmbutido();
	void setEmbutido(Embutido* nuevoEmbutido);

	string obtener_nombre();
	string obtener_codigo();
	double obtener_costo();

	string toString();

private:
	Embutido* ptrEmbutidos;
};
