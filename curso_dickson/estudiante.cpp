
#include "estudiante.h"

void Estudiante::agregarNota(const double &nota)
{
    notas.push_back(nota);
}

double Estudiante::promedio()
{
    double promedio = 0.0;
    for (int i = 0; i < notas.size(); i++)
    {
        promedio += notas[i];
    }
    return promedio / notas.size();
}
Estudiante::Estudiante(const string &nombre, const string &apellido, const int &docid, const int &cod) : Persona(docid)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->codigo = cod;
}
ostream &operator<<(ostream &os, const Estudiante &e)
{
    os << "Nombre: " << e.nombre << "\n";
    os << "Apellido: " << e.apellido << "\n";
    os << "Documento: " << e.doc_identidad << "\n";
    os << "Código: " << e.codigo << "\n";
    os << "Notas: ";
    for (const auto &nota : e.notas)
    {
        os << nota << " ";
    }
    return os;
}
Estudiante::Estudiante(const int &cod)
{

    cout << "Estudiante: " << nombre << " " << apellido << " Documento: " << doc_identidad << endl;
}
