#include "persona.h"
#include <iostream>

using namespace std;

Persona::Persona(int docid)
{
    doc_identidad = docid;
}
void Persona::Nombre(const string &nombre)
{
    this->nombre = nombre;
}
string Persona::Nombre()
{
    return nombre;
}

void Persona::Apellido(const string &apellido)
{
    this->apellido = apellido;
}
string Persona::Apellido()
{
    return apellido;
}

void Persona::Doc_identidad(const int &docid)
{
    doc_identidad = docid;
}

int Persona::Doc_identidad()
{
    return doc_identidad;
}

Persona::Persona()
{
    doc_identidad = 0;
    nombre = "";
    apellido = "";
}

Persona::~Persona()
{
    cout << "Llamando destructor de Persona" << endl;
}
