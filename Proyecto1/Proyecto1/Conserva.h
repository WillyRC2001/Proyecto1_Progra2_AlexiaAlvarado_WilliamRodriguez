#pragma once
#include "Producto.h"

class Conserva : public Producto {

public:
    
    Conserva(string cod, string nom_comerc, string descr, double precio, string categ, Categoria* categor, int existe, int limit, Fecha* fech, bool envasado);
   
    // Métodos getters y setters
    bool getEnvasado();
    void setEnvasado(bool envasado);

    string toString();

private:
    bool envasado;
};
