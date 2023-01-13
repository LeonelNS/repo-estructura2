// nReinas.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
#include <string>


using namespace std;

bool esValido(int filas, int col, int reinas[])
{
	for (int i = 0; i < filas; i++)
	{
		if (col == reinas[i])
		{
			return false;
		}
		if (abs(col - reinas[i]) == abs(filas - i))
		{
			return false;
		}
	}
	return true;
}

int posicionarReinas(int filas, int reinas[], int n)
{

	if (filas == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << reinas[i] << ", ";
		}

		cout << " | ";

		return 1;

	}
	else {
		int totalSoluciones = 0;

		for (int col = 0; col < n; col++)
		{

			if (esValido(filas, col, reinas))
			{
				reinas[filas] = col;
				totalSoluciones += posicionarReinas(filas + 1, reinas, n);
			}
		}
		return totalSoluciones;
	}
}

int nReinas(int n)
{
	int* reinas = (int*)malloc(n * sizeof(int));
	int filas = 0;
	return posicionarReinas(filas, reinas, n);
}

void menu()
{
	cout << "\n \n \n0. Jugar \n";
	cout << "1. Salir \n";

	cout << "\n";

}

int main()
{
	int opcion;

	do {
		try
		{
			menu();
			cin.exceptions(istream::failbit); // capta bits fallidos
			cout << "Elija la opcion que desea jugar \n";
			cout << "\n";
			cin >> opcion;
		}
		catch (exception fail)
		{
			cin.clear();
			string tmp;
			getline(cin, tmp);
			cout << "Solo se puden ingresar numeros, intente nuevamente \n \n";
			_getch();
		}

		switch (opcion)
		{
		case 0:
			try
			{
				system("cls");
				cin.exceptions(istream::failbit); // capta bits fallidos
				cout << "Introduzca la cantidad de Reinas: ";
				int n;
				cin >> n;
				cout << "\n";
				cout << "Soluciones: ";
				nReinas(n);
				_getch();
			}
			catch (exception fail)
			{
				cin.clear();
				string tmp;
				getline(cin, tmp);
				cout << "Solo se puden ingresar numeros, intente nuevamente \n \n";
				_getch();
			}

			break;
		default:
			cout << "Elija una opcion valida";
			break;
		}
	} while (opcion != 1);
}
