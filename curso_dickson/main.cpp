#include "estudiante.h"
#include <iostream>
#include <vector>

int main()
{
    Estudiante e1("Juan", "Perez", 123456, 1);
    e1.agregarNota(3.5);
    e1.agregarNota(4.5);
    e1.agregarNota(5.0);
    cout << e1 << endl;
    cout << "Promedio: " << e1.promedio() << endl;
    return 0;
}