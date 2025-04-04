#include "persona.h"
#include <vector>
#include <iostream>
#include <string>   
using namespace std;


Persona::Persona(string nombre, string apellido, int docid)
{
    this->apellido = apellido;
    this->nombre = nombre;
    this->doc_identidad = docid;
}

string Persona::Apellido() const
{
    return apellido;
}

int Persona::Doc_identidad() const
{
    return doc_identidad;
}

string Persona::Nombre() const
{
    return nombre;
}

ostream &operator<<(ostream &os, const Persona &p)
{
    os << p.nombre << " " << p.apellido << " con C.C: " << p.doc_identidad;
    return os;
}

Persona::~Persona()
{
    cout << "Lllamando destructor" << endl;
}