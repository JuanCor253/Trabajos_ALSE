#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

    cout << "He recibido " << argc << " argumentos de los cuales" << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "Argumento " << i << " es " << argv[i] << endl;
    }
}
