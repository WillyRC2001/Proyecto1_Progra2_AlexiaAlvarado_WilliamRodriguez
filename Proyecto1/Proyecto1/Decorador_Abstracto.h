#pragma once
#include "Componente_Abstracto.h"

class Decorador_Abstracto : public Componente_Abstracto {
public:
    Decorador_Abstracto() {}
    virtual ~Decorador_Abstracto() { delete ptrComponenteAbs; }
    virtual double costo()=0;
    virtual string toString()=0;
protected:
    Componente_Abstracto* ptrComponenteAbs;
};