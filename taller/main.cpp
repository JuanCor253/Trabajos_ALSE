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

    // Leer el dato más reciente (puedes cambiar el ID si conoces uno específico)
    int id_a_leer = 1; // Asegúrate de que exista, o cambia por el último ID
    dato leido = db.leerdato(id_a_leer);

    // Mostrar el dato leído
    cout << "Fecha: " << leido.fecha << endl;
    cout << "Hora: " << leido.hora << endl;
    cout << "Latitud: " << leido.latitud << endl;
    cout << "Longitud: " << leido.longitud << endl;
    cout << "Altura: " << leido.altura << endl;
    cout << "Temperatura: " << leido.temp << endl;
    cout << "Humedad: " << leido.humedad << endl;
    cout << "Vel. Viento: " << leido.vel_viento << endl;
    cout << "Dir. Viento: " << leido.dir_viento << endl;
    cout << "Precipitacion: " << leido.precipitacion << endl;

    return 0;
}
