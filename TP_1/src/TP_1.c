/*
=============================================================================
Alumno: Ezequiel Rosales Milano
Division: 1°C

Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: (km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout, NULL);

	int option;
	int optionTravel;
	float enteredKm;
	float enteredPriceLatam;
	float enteredPriceAerolineas;
	float totalDiscountLatam;
	float totalDiscountAerolineas;
	float totalInterestLatam;
	float totalInterestAerolineas;
	float totalBitcoinLatam;
	float totalBitcoinAerolineas;
	float totalUnitaryLatam;
	float totalUnitaryAerolineas;
	float totalDifference;
	int flagKm = 0;
	int flagAerolineas = 0;
	int flagLatam = 0;
	int flagResult = 0;
	int flagShow = 0;

	do
	{
		if(flagKm == 0)
		{
			printf("1. Ingresar Kilómetros: (km=x)\n");
		}
		else
		{
			printf("1. Ingresar Kilómetros: (km=%.2f)\n", enteredKm);
		}
		printf("2. Ingresar Precio de Vuelos ");
		if(flagAerolineas == 0)
		{
			printf("(Aerolineas=y,");
		}
		else
		{
			printf("(Aerolineas=$%.2f,", enteredPriceAerolineas);
		}
		if(flagLatam == 0)
		{
			printf(" Latam=z)\n");
		}
		else
		{
			printf(" Latam=$%.2f)\n", enteredPriceLatam);
		}
		printf("3. Calcular todos los costos:\na) Tarjeta de débito (descuento 10%%)\nb) Tarjeta de crédito (interés)\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nd) Mostrar precio por km (precio unitario)\n");
		if(flagResult == 0)
		{
			printf("4. Informar Resultados\nLatam:\na) Precio con tarjeta de débito: r\nb) Precio con tarjeta de crédito: r\nc) Precio pagando con bitcoin: r\nd) Precio unitario: r\n");
			printf("Aerolíneas:\na) Precio con tarjeta de débito: r\nb) Precio con tarjeta de crédito: r\nc) Precio pagando con bitcoin: r\nd) Precio unitario: r\nLa diferencia de precio es: r\n");
		}
		else
		{
			printf("4. Informar Resultados\nLatam:\na) Precio con tarjeta de débito: $%.2f\nb) Precio con tarjeta de crédito: $%.2f\nc) Precio pagando con bitcoin: $%.6f\nd) Precio unitario: $%.2f\n", totalDiscountLatam, totalInterestLatam, totalBitcoinLatam, totalUnitaryLatam);
			printf("Aerolíneas:\na) Precio con tarjeta de débito: $%.2f\nb) Precio con tarjeta de crédito: $%.2f\nc) Precio pagando con bitcoin: $%.6f\nd) Precio unitario: $%.2f\n\nLa diferencia de precio es: $%.2f\n", totalDiscountAerolineas, totalInterestAerolineas, totalBitcoinAerolineas, totalUnitaryAerolineas, totalDifference);
		}
		printf("5. Carga forzada de datos\n6. Salir");

		option = getInteger(option, "\n\nBienvenido!! Elija una opcion para continuar: ");

		switch(option)
		{
			case 1:
				cleanConsole();
				enteredKm = getFloat(enteredKm, "Ingrese los kilómetros: ");
				flagKm = 1;
				system("pause");
			break;
			case 2:
				do
				{
					cleanConsole();
					showSubMenu();
					optionTravel = getInteger(optionTravel, "\n\nElija una opcion: ");

					switch(optionTravel)
					{
						case 1:
							enteredPriceAerolineas = getFloat(enteredPriceAerolineas, "Ingrese un precio para Aerolineas: ");
							flagAerolineas = 1;
						break;
						case 2:
							enteredPriceLatam = getFloat(enteredPriceLatam, "Ingrese un precio para Latam: ");
							flagLatam = 1;
						break;
						case 3:
							getMessage("Regresando al menu...\n");
							system("pause");
						break;
						default:
							getMessage("Error, elija una opcion correcta\n");
							system("pause");
						break;
					}
				}while(optionTravel != 3);
			break;
			case 3:
				if(flagKm == 1 && flagLatam == 1 && flagAerolineas == 1)
				{
					getMessage("Calculando resultados...\n");
					totalDiscountAerolineas = makeDiscount(enteredPriceAerolineas);
					totalDiscountLatam = makeDiscount(enteredPriceLatam);
					totalInterestAerolineas = makeInterest(enteredPriceAerolineas);
					totalInterestLatam = makeInterest(enteredPriceLatam);
					totalBitcoinAerolineas = calculateBitcoin(enteredPriceAerolineas);
					totalBitcoinLatam = calculateBitcoin(enteredPriceLatam);
					totalUnitaryAerolineas = calculateUnitary(enteredPriceAerolineas, enteredKm);
					totalUnitaryLatam = calculateUnitary(enteredPriceLatam, enteredKm);
					totalDifference = calculateDifference(enteredPriceLatam, enteredPriceAerolineas);
					flagShow = 1;
				}
				else
				{
					getMessage("ERROR, no se puede calcular si no se han ingresado los datos correspondientes\n");
				}
				system("pause");
				cleanConsole();
			break;
			case 4:
				if(flagShow == 1)
				{
					flagResult = 1;
					getMessage("Cargando resultados...\n");
				}
				else
				{
					getMessage("ERROR, no se puede informar los resultados si no se han calculado los datos correspondientes\n");
				}
				system("pause");
				cleanConsole();
			break;
			case 5:
				enteredKm = 7090;
				enteredPriceAerolineas = 162965;
				enteredPriceLatam = 159339;
				totalDiscountAerolineas = makeDiscount(enteredPriceAerolineas);
				totalDiscountLatam = makeDiscount(enteredPriceLatam);
				totalInterestAerolineas = makeInterest(enteredPriceAerolineas);
				totalInterestLatam = makeInterest(enteredPriceLatam);
				totalBitcoinAerolineas = calculateBitcoin(enteredPriceAerolineas);
				totalBitcoinLatam = calculateBitcoin(enteredPriceLatam);
				totalUnitaryAerolineas = calculateUnitary(enteredPriceAerolineas, enteredKm);
				totalUnitaryLatam = calculateUnitary(enteredPriceLatam, enteredKm);
				totalDifference = calculateDifference(enteredPriceLatam, enteredPriceAerolineas);
				flagResult = 1;
				flagKm = 1;
				flagAerolineas = 1;
				flagLatam = 1;
			break;
			case 6:
				getMessage("\nPrograma finalizado, adios!!\n");
				system("pause");
			break;
			default:
				getMessage("\nError, Ingrese una opcion valida\n");
				system("pause");
			break;
		}

	}while(option != 6);


	return 0;
}
