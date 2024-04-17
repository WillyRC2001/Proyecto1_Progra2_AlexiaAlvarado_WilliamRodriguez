#pragma once
#include "Componente_Abstracto.h"

class Decorador_Abstracto : public Componente_Abstracto {
public:
    Decorador_Abstracto(Componente_Abstracto* comAbs) { this->ptrComponenteAbs = comAbs; }
    virtual ~Decorador_Abstracto() { /*delete ptrComponenteAbs; */ }

    virtual string obtener_nombre() = 0;
    virtual string obtener_codigo() = 0;
    virtual double obtener_costo() = 0; //este metodo de obtener costos hay que revisarlo por que es la relacion de producto con categoria (%ganacia)

    virtual string toString() = 0;

protected:
    Componente_Abstracto* ptrComponenteAbs;
};