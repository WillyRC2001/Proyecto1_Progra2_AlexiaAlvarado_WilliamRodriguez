#pragma once
#include "Componente_Abstracto.h"

class Carrito : public Componente_Abstracto {
private:
public:
    Carrito(){}
    virtual ~Carrito(){}
    virtual string obtener_nombre() { return "Carrito"; }
    virtual string obtener_codigo() { return " "; }
    virtual double obtener_costo() { return 0.0; }
    
    virtual string toString() 
    {
        stringstream s; 
        s << "Carrito..." << endl;
        return s.str();
    }
};
