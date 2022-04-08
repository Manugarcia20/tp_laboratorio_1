/*
 * calculos.h
 *3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

 *      Author: manu
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_


float CalcularTarjetaDebito(float);
float CalcularTarjetaCredito(float);
float CalcularPrecioBitcoin(float);
float CalcularPrecioUnitario(float,float);
float CalcularDiferenciaPrecio(float,float);

#endif /* CALCULOS_H_ */
