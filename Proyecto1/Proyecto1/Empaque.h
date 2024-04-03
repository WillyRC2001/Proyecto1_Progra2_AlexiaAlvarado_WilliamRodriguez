#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Empaque {
public:
	Empaque(bool trip);
	virtual ~Empaque();
	string toString();
private:
	bool tripa;
};