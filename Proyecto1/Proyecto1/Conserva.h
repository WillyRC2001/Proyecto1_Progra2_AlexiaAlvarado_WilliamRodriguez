#pragma once
#include "Producto.h"

class Conserva : public Producto {

public:
    Conserva(Fecha* fech, string cod, string nom_comerc, string descr, double precio, string categ, Categoria* categor, int existe, int limit, bool envasado);
    // Métodos getters y setters
    // ...

private:
    bool envasado;
};
