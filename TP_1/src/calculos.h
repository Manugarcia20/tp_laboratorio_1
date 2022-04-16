

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @param Se le pasa el flotante de precio de vuelo por parametro para calcular el descuento con debito.
/// @return Retorna el precio final del vuelo con descuento por tarjeta de debito.
float CalcularTarjetaDebito(float);


/// @param Se le pasa el flotante de precio de vuelo por parametro para calcular el interes con tarjeta de credito.
/// @return Retorna el precio final del vuelo con interes por tarjeta de credito.
float CalcularTarjetaCredito(float);


/// @param Se le pasa el flotante de precio de vuelo por parametro para calcular el valor transformado a Bitcoin.
/// @return Retorna el precio del vuelo transformado a Bitcoin.
float CalcularPrecioBitcoin(float);


/// @param Se le pasa el flotante de precio de vuelo por parametro.
/// @param Se le pasa el flotante de kilometros por parametro.
/// @return Retorna el valor del precio por kilometro del vuelo.
float CalcularPrecioUnitario(float,float);


/// @param Se le pasa el flotante de precio de vuelo de la primera aerolinea.
/// @param Se le pasa el flotante de precio de vuelo de la segunda aerolinea.
/// @return Retorna el valor de la diferencia de precio de los vuelos por aerolinea.
float CalcularDiferenciaPrecio(float,float);



/// Esta funcion lo que hace es agrupar todas las funciones anteriormente documentadas para que se realizen los calculos dentro de ella.
/// Por parametro se le pasan por referencia las variables donde se guardaran los valores de cada uno de los calculos. No retorna nada ya que
/// su intencion es solo calcular.
void CalcularCostos(float,float,float,float*,float*,float*,float*,float*,float*,float*,float*,float*);


#endif /* CALCULOS_H_ */
