#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>

/*

Los floreros del Salvador

Hace algún tiempo Salvador compró 100 floreros para venderlos en un mercadillo.La semana pasada, después de haber vendido algunos de ellos en los días anteriores,
tenía los floreros ordenados en seis filas, con el mismo número de unidades en cada una de ellas.En esta semana vendió ocho floreros y en la actualidad tiene los que
le quedan ordenados en 11 filas, con el mismo número de floreros en cada una.

¿Cuántos floreros tiene salvador para vender todavía ?*/

using namespace std;

int main()
{
	int floreros = 100;

	for (size_t vendidos = 1; vendidos < floreros; vendidos++)
	{
		if ((floreros - vendidos) % 6 == 0)
		{
			//posibles soluciones en multiplos de 6
			/*cout << "Se vendieron " << vendidos << " floreros" << endl;
			cout << "Quedan " << floreros - vendidos << " floreros en 6 filas" << "\n" << endl;*/

			if ((floreros - vendidos - 8) % 11 == 0)
			{
				//posibles soluciones en multiplos de 11
				cout << "Se vendieron " << vendidos << " floreros" << endl;
				cout << "Quedan " << floreros - vendidos - 8 << " floreros en 11 filas" << endl;
				//cout << "quedaron " << (floreros - vendidos) / 11 << " en cada filas" << "\n" << endl;
			}

		}

	}

	cout << endl;

	_getch();
	return 0;

};