#pragma once
#include "Componente_Abstracto.h"

class Decorador_Abstracto : public Componente_Abstracto {
public:
    Decorador_Abstracto(Componente_Abstracto*);
   

protected:
    virtual Componente_Abstracto* CA() const;

private:
    Componente_Abstracto* _CA;
};