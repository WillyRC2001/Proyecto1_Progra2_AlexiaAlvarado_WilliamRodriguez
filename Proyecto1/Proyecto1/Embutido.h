#pragma once
#include "Carne.h"
#include "Empaque.h"

class Embutido : public Carne {
public:
	Embutido(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, Categoria* categoria2, int existe, int limit, bool nacion, double pes, string nom_ani, string part_ani, string marc);
	virtual ~Embutido();
	string toString();
private:
	Empaque* empaque;
	string marca;
};