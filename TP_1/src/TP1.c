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

	do {
		opcion = menu();

		switch (opcion) {
		case 1:
			printf("\nUsted eligio: Ingresar Kilometros\n");
			kilometros = IngresarFlotante("\nIngrese los kilometros: ");
			break;
		case 2:
			printf("\nUsted eligio: Ingresar precio de vuelos\n");

			aerolineas = IngresarFlotante("\nPrecio Aerolineas: \n");
			latam = IngresarFlotante("\nPrecio de LATAM: \n");
			break;
		case 3:
			printf("\nUsted eligio: Calcular costos\n");
//			CalcularCostos(&kilometros, &aerolineas, &latam, &debitoAA , &debitoLTM, &creditoAA, &creditoLTM, &bitcoinAA,
//					 &bitcoinLTM, &precioUnitarioAA, &precioUnitarioLTM, &diferenciaPrecio);
			debitoAA = CalcularTarjetaDebito(aerolineas);
			debitoLTM = CalcularTarjetaDebito(latam);
			creditoAA = CalcularTarjetaCredito(aerolineas);
			creditoLTM = CalcularTarjetaCredito(latam);
			bitcoinAA = CalcularPrecioBitcoin(aerolineas);
			bitcoinLTM = CalcularPrecioBitcoin(latam);
			precioUnitarioAA = CalcularPrecioUnitario(aerolineas,kilometros);
			precioUnitarioLTM = CalcularPrecioUnitario(latam,kilometros);
			diferenciaPrecio = CalcularDiferenciaPrecio(latam,aerolineas);
			break;
		case 4:
			printf("\nUsted eligio: Informar resultados\n");
			MostrarResultados(debitoAA,debitoLTM,creditoAA,creditoLTM,bitcoinAA,bitcoinLTM,
					precioUnitarioAA,precioUnitarioLTM,diferenciaPrecio);
			break;
		case 5:
			printf("\nUsted eligio: Carga Forzada \n");
			CargaForzada( kilometros,  aerolineas,  latam,  debitoAA,  debitoLTM, creditoAA, creditoLTM, bitcoinAA, bitcoinLTM,
				precioUnitarioAA,precioUnitarioLTM, diferenciaPrecio);
			break;
		case 6:
			printf("\nUsted eligio: Salir \n");
			break;
		}

	} while (opcion != 6);

	return 0;

}
