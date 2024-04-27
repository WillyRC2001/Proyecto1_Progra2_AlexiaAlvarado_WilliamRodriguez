#pragma once
#include "ExcepcionUsuario.h"

class ExcepcionProducto : public ExcepcionesUsuario {
public:
	ExcepcionProducto();
	virtual ~ExcepcionProducto();
	string toString() const;
};