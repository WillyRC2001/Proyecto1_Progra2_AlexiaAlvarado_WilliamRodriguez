#pragma once
#include <stdexcept> 
#include "Utiles_Clases.h"

class ExcepcionesUsuario {
public:
	ExcepcionesUsuario();
	virtual ~ExcepcionesUsuario();
	virtual string toString() const = 0;
};
