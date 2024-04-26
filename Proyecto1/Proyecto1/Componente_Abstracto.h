#pragma once
#include "Utiles_Clases.h"
#include "baseObject.h"

class Componente_Abstracto : public base::baseObject {
private: 
public:
    virtual ~Componente_Abstracto(){}
    virtual string obtener_nombre() =0;
    virtual string obtener_codigo() = 0;
    virtual double obtener_costo() = 0;
    virtual Componente_Abstracto* SiguienteComponente() = 0;
    virtual string toString() = 0;
};
