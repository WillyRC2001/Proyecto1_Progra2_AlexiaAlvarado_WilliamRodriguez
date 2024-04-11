#include "Categoria.h"

Categoria::Categoria()
{
    tipo = 0;
}

Categoria::Categoria(int tipe)
{
    this->tipo = tipe; 
}

Categoria::~Categoria()
{
}

int Categoria::getTipoCategoria()
{
    return this->tipo;
}

void Categoria::setTipoCategoria(int tipoCat)
{
    this->tipo = tipoCat;
}

double Categoria::porcentanjeDeGanancia() //revisar el metodo categoria
{
  
    double porcentaje = 0.0;
    switch (tipo) {
    case 1:
        porcentaje = 15.0; //productos en conserva
        break;
    case 2:
        porcentaje = 20.0; //perecederos como los abarrotes
        break;
    case 3:
        porcentaje = 30.0; //embutidos (que también son perecederos)
        break;
    default:
        throw invalid_argument("Tipo de categoría inválido");
        break;
    }
    return porcentaje;
}
