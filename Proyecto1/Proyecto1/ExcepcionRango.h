#pragma once
#include "ExcepcionUsuario.h"

class ExcepcionFueraRango : public ExcepcionesUsuario {
public:
	ExcepcionFueraRango();
	virtual ~ExcepcionFueraRango();
	string toString() const;
};