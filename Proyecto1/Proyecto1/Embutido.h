#pragma once
#include "Carne.h"
#include "Empaque.h"

class Embutido : public Carne {
public:
	Embutido(string cod, string nom_comerc, string descr, double preci, string categ, int existe, int limit, Fecha* fechingreso, Fecha* fechvencido, bool nacion, double pes, string nom_ani, string part_ani, string marc);
	virtual ~Embutido();

	Empaque* getEmpaque();
	string getMarca(); 

	void setEmpaque(Empaque*); 
	void setMarca(string); 

	string toString() const;
private:
	Empaque* empaque;
	string marca;
};