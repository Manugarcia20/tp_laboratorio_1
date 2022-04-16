/*
 ============================================================================
 Name        : ejercicio.c
 Author      : manu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "calculos.h"
#include "menu.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	float aerolineas;
	float latam;
	float kilometros;
	float debitoAA;
	float debitoLTM;
	float creditoAA;
	float creditoLTM;
	float bitcoinAA;
	float bitcoinLTM;
	float precioUnitarioAA;
	float precioUnitarioLTM;
	float diferenciaPrecio;
	int flagKm = 1;
	int flagPrecio = 1;
	int flagCostos = 1;

	do {
		opcion = menu();

		switch (opcion) {
		case 1:
			printf("\nUsted eligio: Ingresar Kilometros\n");
			kilometros = IngresarFlotante("\nIngrese los kilometros: ");
			flagKm = 0;
			break;
		case 2:
			printf("\nUsted eligio: Ingresar precio de vuelos\n");
			if(flagKm !=0){
				printf("\nError. No se puede ingresar el precio del vuelo sin ingresar antes los kilometros\n");
			}else{
			aerolineas = IngresarFlotante("\nPrecio Aerolineas: \n");
			latam = IngresarFlotante("\nPrecio de LATAM: \n");
			flagPrecio = 0;
			}
			break;
		case 3:
			if(flagKm != 0 && flagPrecio != 0){
				printf("Error. No se pueden calcular los costos sin haber ingresado los kilometros"
						" y los precios de los vuelos");
			}else if (flagPrecio != 0){
				printf("\nError. No se puede calcular los costos sin haber ingresado\nlos precios de los vuelos\n");
			}else{
			printf("\nUsted eligio: Calcular costos\n");
			CalcularCostos(kilometros,aerolineas,latam,&debitoAA,&debitoLTM,&creditoAA,&creditoLTM,&bitcoinAA,&bitcoinLTM
					,&precioUnitarioAA,&precioUnitarioLTM,&diferenciaPrecio);

			flagCostos = 0;
			if(flagCostos == 0){
				printf("Se han hecho todos los calculos. Seleccione la opcion 4 para ver los resultados");
			}
			}
			break;
		case 4:
			if(flagCostos != 0){
				printf("\nError. No se puede mostrar los rsultados sin haber calculado los costos\n");
			}else{
			printf("\nUsted eligio: Informar resultados\n");
			MostrarResultados(debitoAA,debitoLTM,creditoAA,creditoLTM,bitcoinAA,bitcoinLTM,
					precioUnitarioAA,precioUnitarioLTM,diferenciaPrecio);
			}
			break;
		case 5:
			printf("\nUsted eligio: Carga Forzada \n");
			CargaForzada( kilometros,  aerolineas,  latam,  debitoAA,  debitoLTM, creditoAA, creditoLTM, bitcoinAA, bitcoinLTM,
				precioUnitarioAA,precioUnitarioLTM, diferenciaPrecio);
			break;
		case 6:
			printf("\nUsted eligio: Salir \n");
			break;
		default:
			printf("\nOpcion incorrecta. Ingrese una opcion valida: ");
		}

	} while (opcion != 6);

	return 0;

}
