//Juan Cortés y Dickson Trujillo Version beta 1.0

#ifndef METEODB_H
#define METEODB_H

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include <iostream>

using namespace std;

struct dato
{
    string fecha, hora;
    double latitud, longitud, altura;
    double dir_viento, vel_viento;
    double temp, humedad;
    double precipitacion;
}

class meteodB
{
    string url;
    sqlite3 *db;

private:
    meteodB();
    ~meteodB();
    dato LeerDato(int i);
    void InsertarDato(dato d);
    static int callback(void *data, int argc, char **argv, char **azColName);
}

#endif // METEODB_H