#ifndef _PERSONA
#define _PERSONA

#include <string>
#include <iostream>
using namespace std;

class Persona{
  string nombre;
  string apellido;
  int doc_identidad;

public:
  Persona( string nombre, string apellido, int docid);
  string Apellido() const;
  string Nombre() const;
  int Doc_identidad() const;

  friend ostream &operator<<(ostream &os, const Persona &p);

  ~Persona();
};
#endif