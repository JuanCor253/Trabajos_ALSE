//Juan Cortés y Dickson Trujillo Version beta 1.0

#include "meteodB.h"

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName)
{
    double *local = (double *)data;
    for (int i = 0; i < argc; i++)
    {
        local[i] = atof(argv[i]);
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

meteodB::meteodB()
{
    url = "meteod.db";
    lc = sqlite3_open(url.c_str(), &db);
    if (lc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }
}

meteodB::~meteodB()
{
    sqlite3_close(db);
}

dato meteodB::LeerDato(int i)
{
    dato d;
    char *zErrMsg = 0;
    string sql = "SELECT fecha, hora, latitud, longitud, altura, temperatura, humedad,
                dir_viento, vel_viento, precipitación FROM meteodatos WHERE id = " + to_string(i) + ";";
    double local[10];
    if (sqlite3_exec(db, sql.c_str(), callback, local, &zErrMsg) != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    d.fecha = to_string(local[0]);
    d.hora = to_string(local[1]);
    d.latitud = local[2];
    d.longitud = local[3];
    d.altura = local[4];
    d.temp = local[5];
    d.humedad = local[6];
    d.dir_viento = local[7];
    d.vel_viento = local[8];
    d.precipitacion = local[9];
    return d;
}
