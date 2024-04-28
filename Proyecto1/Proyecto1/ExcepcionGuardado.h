#pragma once
#include "ExcepcionUsuario.h"

class ExcepcionGuardado : public ExcepcionesUsuario {
public:
	ExcepcionGuardado();
	virtual ~ExcepcionGuardado();
	string toString() const;
};