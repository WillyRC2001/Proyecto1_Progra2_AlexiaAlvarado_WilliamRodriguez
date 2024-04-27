#pragma once
#include "ExcepcionUsuario.h"

class ExcepcionFechaMes: public ExcepcionesUsuario {
public:
	ExcepcionFechaMes();
	virtual ~ExcepcionFechaMes();
	string toString() const;
};