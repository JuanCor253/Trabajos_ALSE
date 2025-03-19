
#include "persona.h"
#include <vector>
#include <iostream>

using namespace std;

class Estudiante : public Persona
{
    vector<double> notas;
    int codigo;
    void Codigo(const int &cod);
    double Nota(const int &i);

public:
    Estudiante(const int &cod);
    Estudiante(const string &nombre, const string &apellido, const int &docid, const int &cod);
    int Codigo();
    void agregarNota(const double &nota);
    double promedio();
    friend ostream &operator<<(ostream &os, const Estudiante &e);
};
