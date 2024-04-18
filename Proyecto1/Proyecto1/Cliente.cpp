#include "Cliente.h"

Cliente::Cliente()
{
    this->nombre = "";
    this->cedula = "";
}

Cliente::Cliente(string nom, string ced): nombre(nom),cedula(ced)
{
}

Cliente::~Cliente()
{
}

string Cliente::getNombreCliente()
{
    return this->nombre;
}

string Cliente::getCedulaCliente()
{
    return this->cedula;
}

void Cliente::setNombreCliente(string nom)
{
    this->nombre = nom;
}

void Cliente::setCedulaCliente(string ced)
{
    this->cedula = ced;
}

string Cliente::toString()
{
    stringstream s; 
    s << "---------CLIENTE---------" << endl; 
    s << "Nombre: " << nombre<<endl;
    s << "Cedula: " << cedula << endl; 
    return s.str();
}
