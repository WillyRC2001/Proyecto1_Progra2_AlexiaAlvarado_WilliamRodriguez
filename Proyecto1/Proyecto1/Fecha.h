#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Fecha {
public:
	Fecha(int,int,int);
	virtual ~Fecha();
	string ToString();
private:
	int dia;
	int mes;
	int anio;
};