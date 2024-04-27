#pragma once
#include "ExcepcionUsuario.h"

class ExcepcionFechaDia : public ExcepcionesUsuario {
public:
	ExcepcionFechaDia();
	virtual ~ExcepcionFechaDia();
	string toString() const;
};