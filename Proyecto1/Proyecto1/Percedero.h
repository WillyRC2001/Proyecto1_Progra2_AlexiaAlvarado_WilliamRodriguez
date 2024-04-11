#pragma once
#include "Fecha.h"

class Percedero {
private:
    Fecha* venceEl;
public:
    Percedero(Fecha* venceEl);
    ~Percedero();

    Fecha* getVenceEl() const;
    void setVenceEl(Fecha* venceEl);
    string toString();
};
