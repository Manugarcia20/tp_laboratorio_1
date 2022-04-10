/*
 * calculos.c
 *
 *  Created on: 4 abr. 2022
 *      Author: manu
 */

#include "calculos.h"

float CalcularTarjetaDebito(float aerolinea) {
	float descuento;
	float precioFinal;

	descuento = aerolinea * 10 / 100;
	precioFinal = aerolinea - descuento;

	return precioFinal;
}

float CalcularTarjetaCredito(float aerolinea) {

	float incremento;
	float precioFinal;

	incremento = aerolinea * 25 / 100;
	precioFinal = aerolinea + incremento;

	return precioFinal;

}

float CalcularPrecioBitcoin(float aerolinea) {
	float precioBTC;
	float precioVuelo;

	precioBTC = 4606954.55;
	precioVuelo = aerolinea / precioBTC;

	return precioVuelo;
}

float CalcularPrecioUnitario(float aerolinea, float kilometros) {
	float precioUnitario;

	precioUnitario = aerolinea / kilometros;

	return precioUnitario;

}
float CalcularDiferenciaPrecio(float latam, float aerolineas) {
	float diferencia;

	diferencia = latam - aerolineas;

	return diferencia;
}

void CalcularCostos(float kilometros ,float aerolineas ,float latam ,float*debitoAA,float*debitoLTM,float*creditoAA,float*creditoLTM,float*bitcoinAA,float*bitcoinLTM
		,float*precioUnitarioAA,float*precioUnitarioLTM,float*diferenciaPrecio){


				*debitoAA = CalcularTarjetaDebito(aerolineas);
				*debitoLTM = CalcularTarjetaDebito(latam);
				*creditoAA = CalcularTarjetaCredito(aerolineas);
				*creditoLTM = CalcularTarjetaCredito(latam);
				*bitcoinAA = CalcularPrecioBitcoin(aerolineas);
				*bitcoinLTM = CalcularPrecioBitcoin(latam);
				*precioUnitarioAA = CalcularPrecioUnitario(aerolineas,kilometros);
				*precioUnitarioLTM = CalcularPrecioUnitario(latam,kilometros);
				*diferenciaPrecio = CalcularDiferenciaPrecio(latam,aerolineas);



}
