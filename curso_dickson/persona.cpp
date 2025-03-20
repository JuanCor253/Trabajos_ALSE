#include "persona.h"
#include <iostream>

using namespace std;


Persona::Persona(string nombre, string apellido, int docid)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this ->doc_identidad = docid;
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

ostream &operator<<(ostream &os, const Persona &p)
{
    os << "Nombre: " << p.nombre << "\n";
    os << "Apellido: " << p.apellido << "\n";
    os << "Documento: " << p.doc_identidad << "\n";
    return os;
}

Persona::~Persona()
{
    cout << "Llamando destructor de Persona" << endl;
}
