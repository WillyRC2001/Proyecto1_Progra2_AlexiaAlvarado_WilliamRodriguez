#pragma once
#include "Utiles_Clases.h"
#include "baseObject.h"

class Componente_Abstracto : public base::baseObject {
private: 
public:
    virtual ~Componente_Abstracto(){}
    virtual double costo() = 0;
    virtual string toString() = 0;
};
