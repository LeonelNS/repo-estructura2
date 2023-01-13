/* Este programa dado un número entero retorna los dígitos del número dado*/

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	int salir = 0;
	do
	{
		try
		{
			system("cls");
			cin.exceptions(istream::failbit); // capta bits fallidos
			int numero;
			cout << "Ingrese un numero entero: ";
			cin >> numero;

			string resultado = "";

			while (numero > 0)
			{
				int digito = numero % 10;
				resultado = to_string(digito) + "," + resultado;
				numero /= 10;
			}

			if (resultado.length() > 0)
			{
				resultado.pop_back();
			}

			cout << "Los digitos del numero son: " << resultado << endl;

			return 0;
		}
		catch (exception fail)
		{
            cin.clear();
            string tmp;
            getline(cin, tmp);
            cout << "Solo se puden ingresar numeros, intente nuevamente \n \n";
            _getch();
		}
	} while (salir != 1);
}
