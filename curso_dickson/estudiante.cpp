#include "estudiante.h"
#include <iostream>
#include <vector>

using namespace std;

Estudiante::Estudiante(): Persona("", "", 0)
{
    codigo = 0;
}

void Estudiante::agregarNota(const double &nota)
{
    notas.push_back(nota);
}

double Estudiante::promedio() const
{
    double promedio = 0.0;
    for (int i = 0; i < notas.size(); i++)
    {
        promedio += notas[i];
    }
    return promedio / notas.size();
}

Estudiante::Estudiante(const int &cod) : Persona("", "", 0)
{
    codigo = cod;
}

Estudiante::Estudiante(const string &nombre, const string &apellido, const int &docid, const int &cod) : Persona(nombre, apellido, docid)
{
    codigo = cod;
}

int Estudiante::Codigo()
{
    return codigo;
}

ostream &operator<<(ostream &os, const Estudiante &e)
{
    os << e.Nombre() << " " << e.Apellido() << " con C.C: " << e.Doc_identidad() << " y codigo: " << e.codigo;
    return os;
}

void Estudiante::Codigo(const int &cod)
{
    codigo = cod;
}

double Estudiante::Nota(const int &i)
{
    return notas[i];
}
