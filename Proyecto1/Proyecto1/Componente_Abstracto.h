#pragma once
#include "Utiles_Clases.h"
#include "baseObject.h"

class Componente_Abstracto : public base::baseObject {
public:
    
    virtual string toString() const;
};
