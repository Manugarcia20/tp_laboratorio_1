/*
 * menu.c
 *
 *  Created on: 4 abr. 2022
 *      Author: manu
 */

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int menu() {
	int opcion;
	printf("\n\n1 - Ingresar Kilometros\n");
	printf("\n2 - Ingresar precio de vuelos\n");
	printf("\n3 - Calcular costos\n");
	printf("\n4 - Informar resultados\n");
	printf("\n5 - Carga Forzada\n");
	printf("\n6 - Salir\n");

	printf("\nElija una opcion: ");

	scanf("%d", &opcion);

	return opcion;
}
