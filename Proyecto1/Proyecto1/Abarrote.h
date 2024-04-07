#pragma once
#include "Product_Perecedero.h"

class Abarrote : public Product_Perecedero{
public:
	Abarrote(Fecha* fech, string cod, string nom_comerc, string descr, double precio, string categ, Categoria* categor, int existe, int limit, bool nacion, double pes, string nom_empre);
	virtual ~Abarrote();
	string toString();
private:
	string nombre_empresa;
};