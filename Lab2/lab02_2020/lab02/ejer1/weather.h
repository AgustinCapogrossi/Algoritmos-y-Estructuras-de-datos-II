#define weather_h

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

int min_temperature (int a[YEARS][MONTHS][DAYS][PHYS_QTTYS]);
	//Devuelve la temperatura minima historica registrada en la ciudad de Córdoba

void max_temperature (int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]);
	//Devuelve un arreglo con la mayor temperatura máxima registrada para cada año entre 1980 y 2016
	
void max_precip (int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int out[YEARS]);
