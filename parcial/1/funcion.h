#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
//Funcion by: Juan Cortes y Dickson Trujillo

using namespace std;

void max_min(const double x[], const int &cant, double &min, double &max){
  min = x[0];
  max = x[0];
  
  for(int i = 1; i < cant; i++){
    if(x[i] < min){
      min = x[i];
    }

    if(x[i] > max){
      max = x[i];
    }
}
