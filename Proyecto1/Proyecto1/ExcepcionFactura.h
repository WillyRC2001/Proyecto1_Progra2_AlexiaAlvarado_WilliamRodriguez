#pragma once
#include "ExcepcionUsuario.h"

class ExcepcionFactura : public ExcepcionesUsuario {
public:
	ExcepcionFactura();
	virtual ~ExcepcionFactura();
	string toString() const;
};