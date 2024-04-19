#pragma once
#include "Product_Perecedero.h"

class Carne : public Product_Perecedero {
public:
	
	Carne(string cod, string nom_comerc, string descr, double precio, string categ, int existe, int limit, Fecha* fechingreso,Fecha* fechvencido, bool nacion, double pes,string nom_ani, string part_ani);
	virtual ~Carne();

	string getNombreAnimal();
	string getParteAnimal(); 

	void setNombreAnimal(string);
	void setParteAnimal(string);

	virtual string toString() const;
private:
	string nom_animal;
	string part_animal;
};