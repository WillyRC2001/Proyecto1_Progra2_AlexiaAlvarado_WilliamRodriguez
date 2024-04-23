#pragma once
#include "Utiles_Clases.h"

class Empaque {
public:
	Empaque(bool trip);
	virtual ~Empaque();

	bool getTripa() const;
	void setTripa(bool); 

	string toString();
private:
	bool tripa;
};