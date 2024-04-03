#pragma once
#include "Product_Perecedero.h"

class Carne : public Product_Perecedero {
public:
	Carne(Fecha* fech, string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, bool nacion, double pes,string nom_ani, string part_ani);
	virtual ~Carne();
	virtual string toString();
private:
	string nom_animal;
	string part_animal;
};