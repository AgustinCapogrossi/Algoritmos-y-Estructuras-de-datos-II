#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "weather.h"
#include "array_helpers.h"

int min_temperature (int a[YEARS][MONTHS][DAYS][PHYS_QTTYS]){
	int min_temp = a[0u][january][0u][temp_m];
	for (unsigned int year = 0; year<YEARS; year++){
		for (t_month month = january; month<MONTHS; month++){
			for (unsigned int days = FST_DAY ; days<DAYS; days++){
				if (min_temp> a[year][month][days][temp_m]){
					min_temp = a[year][month][days][temp_m];
				}
			}
		}
	} 
	return min_temp;
}

void max_temperature (int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]){
		int max_temp;
		for (unsigned int year = 0; year<YEARS; year++){
			max_temp = a[year][january][0u][temp_M];
			for (t_month month = january; month<MONTHS; month++){
				for (unsigned int days = FST_DAY ; days<DAYS; days++){
					if (max_temp<a[year][month][days][temp_M]){
						max_temp = a[year][month][days][temp_M];
					}
					output[YEARS] = max_temp;
				}
			}
		} 
}

void max_precip (int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int out[YEARS]){
		for (unsigned int year = 0; year<YEARS; year++){
			int max_preci = 0;
			for (t_month month = january; month<MONTHS; month++){
				int preci = 0;
				for (unsigned int days = FST_DAY ; days<DAYS; days++){
					preci = preci + a[year][month][days][precip];
					if (preci<max_preci){
						max_preci = preci;
					}
					out[YEARS] = max_preci;
				}
			}
		} 
}


