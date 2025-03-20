
#include "persona.h"
#include <vector>


using namespace std;

class Estudiante : public Persona
{
    vector<double> notas;
    int codigo;
    Estudiante();
    void Codigo(const int &cod);
    double Nota(const int &i);

public:
    Estudiante(const int &cod);
    Estudiante(const string &nombre, const string &apellido, const int &docid, const int &cod);
    int Codigo();
    void agregarNota(const double &nota);
    double promedio() const;
    friend ostream &operator<<(ostream &os, const Estudiante &e);
};
