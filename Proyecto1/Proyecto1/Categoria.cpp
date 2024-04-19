#include "Categoria.h"

Categoria::Categoria(string tip_prod)
{
    tipo = 0;
    categ = tip_prod;
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
void Categoria::Tipo(string categoria) {
    if (categoria == "Conserva") {
        setTipoCategoria(1);
    }
    else if (categoria == "Abarrote") {
        setTipoCategoria(2);
    }
    else if (categoria == "Embutido") {
        setTipoCategoria(3);
    }
}

double Categoria::porcentajeDeGanancia()
{
    this->Tipo(categ);
    double porcentaje = 0.0;
    switch (this->tipo) {
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
        //throw invalid_argument("Tipo de categoría inválido");
        cout << "Tipo de Categoria invalido" << endl;
        break;
    }
    return porcentaje;
}
