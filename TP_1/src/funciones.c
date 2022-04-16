/*
 * funciones.c
 *
 *  Created on: 1 abr. 2022
 *      Author: manu
 */

#include "funciones.h"
#include "calculos.h"
#include <stdio.h>
#include <stdlib.h>

int pedirNumero(char mensaje[]) {
	int numero;
	printf("\nIngrese el numero: \n");
	scanf("%d", &numero);

	printf("\nEl numero ingresado es: %d\n", numero);

	return numero;

}

void MostrarResultados(float debitoAA, float debitoLTM, float creditoAA,
		float creditoLTM, float bitcoinAA, float bitcoinLTM,
		float precioUnitarioAA, float precioUnitarioLTM, float diferenciaPrecio) {

	printf("\nAerolineas: \n");
	printf("\nEl precio con debito es: %2.f\n", debitoAA);
	printf("\nEl precio con credito es: %2.f\n", creditoAA);
	printf("\nEl precio con Bitcoin es: %f\n BTC", bitcoinAA);
	printf("\nEl precio por kilometro es: %.2f\n", precioUnitarioAA);
	printf("\nLatam: \n");
	printf("\nEl precio con debito es: %2.f\n", debitoLTM);
	printf("\nEl precio con credito es: %2.f\n", creditoLTM);
	printf("\nEl precio con Bitcoin es: %f\n", bitcoinLTM);
	printf("\nEl precio por kilometro es: %.2f\n", precioUnitarioLTM);

	printf("\nLa diferencia de precio es: %.2f\n", diferenciaPrecio);

}

float IngresarFlotante(char mensaje[]) {
	float numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numero);

	return numero;
}

void CargaForzada(float kilometros, float aerolineas, float latam, float debitoAA, float debitoLTM,float creditoAA,float creditoLTM,float bitcoinAA,float bitcoinLTM,
		float precioUnitarioAA,  float precioUnitarioLTM,float diferenciaPrecio) {

	kilometros = 7090;
	aerolineas = 162965;
	latam = 159339;

	debitoAA = CalcularTarjetaDebito(aerolineas);
	creditoAA = CalcularTarjetaCredito(aerolineas);
	bitcoinAA = CalcularPrecioBitcoin(aerolineas);
	precioUnitarioAA = CalcularPrecioUnitario(aerolineas, kilometros);


	debitoLTM = CalcularTarjetaDebito(latam);
	creditoLTM = CalcularTarjetaCredito(latam);
	bitcoinLTM = CalcularPrecioBitcoin(latam);
	precioUnitarioLTM = CalcularPrecioUnitario(latam,kilometros);
    diferenciaPrecio = CalcularDiferenciaPrecio(latam,aerolineas);

	MostrarResultados(debitoAA,debitoLTM,creditoAA,creditoLTM,bitcoinAA,bitcoinLTM,
						precioUnitarioAA,precioUnitarioLTM,diferenciaPrecio);

}



