#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
using namespace std;
#include <iostream>

struct dato
{
    string fecha, hora;
    double latitud, longitud, altura;
    double dir_viento, vel_viento, temp, humedad;
    double precipitacion;
};

class Meteodb
{

    string url;
    sqlite3 *db;

public:
    Meteodb();
    ~Meteodb();
    dato leerdato(int i);
    void insertardato(dato d);
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
};