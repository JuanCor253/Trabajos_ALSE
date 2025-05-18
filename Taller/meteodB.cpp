// Codigo corregido by Juan Cortés y Dickson Trujillo
// Fecha: 18-05-2025
#include "meteodB.h"

Meteodb::Meteodb()
{
    url = "meteo.als";
    if (sqlite3_open(url.c_str(), &db))
    {
        cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << endl;
        db = nullptr;
    }
    else
    {
        cout << "Base de datos abierta correctamente." << endl;
    }
}

Meteodb::~Meteodb()
{
    if (db)
        sqlite3_close(db);
}

void Meteodb::insertardato(dato d)
{
    if (!db)
    {
        cerr << "Base de datos no abierta." << endl;
        return;
    }
    char *errmsg;
    string sql = "INSERT INTO TBL_DATOS (fecha, hora, latitud, longitud, altura, temperatura, humedad, velocidad_viento, direccion_viento, precipitacion) VALUES ('" +
                 d.fecha + "', '" + d.hora + "', " + to_string(d.latitud) + ", " + to_string(d.longitud) + ", " +
                 to_string(d.altura) + ", " + to_string(d.temp) + ", " + to_string(d.humedad) + ", " +
                 to_string(d.vel_viento) + ", " + to_string(d.dir_viento) + ", " + to_string(d.precipitacion) + ");";

    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errmsg) != SQLITE_OK)
    {
        cerr << "Error insertando dato: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    else
    {
        cout << "Dato insertado correctamente." << endl;
    }
}

int Meteodb::callback(void *data, int argc, char **argv, char **azColName)
{
    if (data)
    {
        dato *d = static_cast<dato *>(data);
        for (int i = 0; i < argc; i++)
        {
            std::string col = azColName[i];
            if (col == "fecha")
                d->fecha = argv[i] ? argv[i] : "";
            else if (col == "hora")
                d->hora = argv[i] ? argv[i] : "";
            else if (col == "latitud")
                d->latitud = argv[i] ? atof(argv[i]) : 0;
            else if (col == "longitud")
                d->longitud = argv[i] ? atof(argv[i]) : 0;
            else if (col == "altura")
                d->altura = argv[i] ? atof(argv[i]) : 0;
            else if (col == "direccion_viento")
                d->dir_viento = argv[i] ? atof(argv[i]) : 0;
            else if (col == "velocidad_viento")
                d->vel_viento = argv[i] ? atof(argv[i]) : 0;
            else if (col == "temperatura")
                d->temp = argv[i] ? atof(argv[i]) : 0;
            else if (col == "humedad")
                d->humedad = argv[i] ? atof(argv[i]) : 0;
            else if (col == "precipitacion")
                d->precipitacion = argv[i] ? atof(argv[i]) : 0;
        }
    }
    return 0;
}

dato Meteodb::leerdato(int i)
{
    dato d;
    if (!db)
    {
        cerr << "Base de datos no abierta." << endl;
        return d;
    }
    char *errmsg = nullptr;
    string sql = "SELECT * FROM TBL_DATOS WHERE id_muestra = " + to_string(i) + ";";
    int rc = sqlite3_exec(db, sql.c_str(), callback, &d, &errmsg);
    if (rc != SQLITE_OK)
    {
        if (errmsg) {
            cerr << "Error leyendo dato con id " << i << ": " << errmsg << endl;
            sqlite3_free(errmsg);
        } else {
            cerr << "Error leyendo dato con id " << i << ": código de error " << rc << endl;
        }
    }
    return d;
}
