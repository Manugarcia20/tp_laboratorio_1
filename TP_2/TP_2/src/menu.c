/*
 * menu.c
 *
 *  Created on: 29 abr. 2022
 *      Author: manu
 */


#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int menu() {
	int opcion;
	printf("\n\n1 - ALTA\n");
	printf("\n2 - MODIFICAR\n");
	printf("\n3 - BAJA\n");
	printf("\n4 - INFORMAR\n");

	printf("\nElija una opcion: ");

	scanf("%d", &opcion);

	return opcion;
}
