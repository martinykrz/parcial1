#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "ej1.h"

#define ARRAY_SIZE 5
#define NUM_ARRAYS 5

uint32_t shuffle_int(uint32_t min, uint32_t max){
	return (uint32_t) (rand() % (max + 1)) + min;
}

int main (void){
	/* Acá pueden realizar sus propias pruebas */
	for (int i=0; i < NUM_ARRAYS; ++i) {
		templo* arrayTemplos = malloc(ARRAY_SIZE * sizeof(templo));
		for (int j=0; j < ARRAY_SIZE; ++j) {
			bool clasico = false;
			arrayTemplos[j].colum_corto = shuffle_int(1,1024);
			if (shuffle_int(0,1)) {
				arrayTemplos[j].colum_largo = 2 * arrayTemplos[j].colum_corto + 1;
				clasico = true;
			} else {
				arrayTemplos[j].colum_largo = shuffle_int(1,2048);
			}
			printf("Valores %d -> Largo: %d, Corto: %d => %d\n", i, arrayTemplos[j].colum_largo, arrayTemplos[j].colum_corto, clasico);
		}
		printf("Clasicos %d: %d\n", i, cuantosTemplosClasicos(arrayTemplos, ARRAY_SIZE));
		free(arrayTemplos);
	}
	return 0;    
}
