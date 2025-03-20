
#include <vector>
#include <string>

using namespace std;

class Persona
{
  string nombre;
  string apellido;
  int doc_identidad;
  Persona();

public:
  
  Persona(string nombre, string apellido, int docid);

  string Nombre();
  void Nombre(const string &nombre);

  string Apellido();
  void Apellido(const string &apellido);

  int Doc_identidad();
  void Doc_identidad(const int &docid);

  ostream &operator<<(ostream &os, const Persona &p);
  ~Persona();
};
