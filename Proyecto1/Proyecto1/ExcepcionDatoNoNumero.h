#pragma once
#include "Utiles_Clases.h"
#include <stdexcept> // Para usar invalid_argument

class ExcepcionDatoNoNumerico : public invalid_argument {
public:
    ExcepcionDatoNoNumerico() : invalid_argument("Se esperaba un dato numérico") {}
};