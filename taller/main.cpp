#include "taller._dick.h"

int main()
{
    Meteodb db;

    // Crear un dato simulado
    dato d;
    d.fecha = "2025-05-15";
    d.hora = "14:30";
    d.latitud = 19.42;
    d.longitud = -99.13;
    d.altura = 2240.0;
    d.temp = 25.5;
    d.humedad = 55.0;
    d.vel_viento = 10.2;
    d.dir_viento = 180.0;
    d.precipitacion = 0.0;

    // Insertar el dato
    db.insertardato(d);

    for (int i = 1; i < 70; i++)
    {
        cout << "Leyendo dato con ID: " << i << endl;
        dato d2 = db.leerdato(i);
        cout << "ID: " << i << endl;
        cout << "Fecha: " << d2.fecha << endl;
        cout << "Hora: " << d2.hora << endl;
        cout << "Latitud: " << d2.latitud << endl;
        cout << "Longitud: " << d2.longitud << endl;
        cout << "Altura: " << d2.altura << endl;
        cout << "Temperatura: " << d2.temp << endl;
        cout << "Humedad: " << d2.humedad << endl;
        cout << "Vel. Viento: " << d2.vel_viento << endl;
        cout << "Dir. Viento: " << d2.dir_viento << endl;
        cout << "Precipitacion: " << d2.precipitacion << endl;
    }
    return 0;
}
