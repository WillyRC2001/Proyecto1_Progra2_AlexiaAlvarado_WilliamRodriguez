#pragma once
#include "Componente_Abstracto.h"

class Carrito : public Componente_Abstracto {
private:
public:
    Carrito();
    virtual ~Carrito();
    virtual double costo();
    virtual string toString();
};
