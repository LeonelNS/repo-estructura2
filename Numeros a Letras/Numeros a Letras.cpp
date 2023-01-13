#include <iostream>
#include <string>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h> 
#include<limits>

/*
Carlos Jimenez - 1105749
Leonel Sepulveda - 1104995
Adam Guerrero - 1106149

Programa que lee los numeros para imprimirlos como palabras en la consola.

*/


using namespace std;


const string VACIO = "";

const string X[] = { VACIO, "Uno ", "Dos ", "Tres ", "Cuatro ", "Cinco ",
                "Seis ", "Siete ", "Ocho ", "Nueve ", "Diez ", "Once ",
                "Doce ", "Trece ", "Catorce ", "Quince ",
                "Dieciseis ", "Diecisiete ", "Dieciocho ", "Diecinueve " };

const string Y[] = { VACIO, VACIO, "Veinte ", "Treinta ", "Cuarenta ", "Cincuenta ",
                "Sesenta ", "Setenta ", "Ochenta ", "Noventa " };

const string Z[] = { VACIO, VACIO, "Veinte y ", "Treinta y ", "Cuarenta y ", "Cincuenta y ",
                "Sesenta y ", "Setenta y ", "Ochenta y ", "Noventa y " };


// Función para convertir un número de uno o dos dígitos en palabras
string convertDigit(unsigned long long n, string suffix)
{
    // si `n` es cero
    if (n == 0) {
        return VACIO;
    }

    // dividir `n` si es más de 19
    if (n > 19) {

        if (n % 10 == 0) {

            return Y[n / 10] + X[n % 10] + suffix;
        }
        else
        {
            return Z[n / 10] + X[n % 10] + suffix;
        }
    }
    else {
        return X[n] + suffix;
    }
}

// Función para convertir un número dado (máximo 9 dígitos) en palabras
string convert(unsigned long long n)
{
    // string para almacenar la representación de palabras del número dado
    string res;

    // esto maneja dígitos en el lugar de las unidades y las decenas
    res = convertDigit((n % 100), "");

    // esto maneja el dígito en el lugar de las centenas
    res = convertDigit(((n / 100) % 10), "Cientos ") + res;

    if (n == 100) {
        res = "Cien";
    }

    // esto maneja dígitos en el lugar de mil y decenas de mil
    res = convertDigit(((n / 1000) % 100), "Mil, ") + res;

    if (n == 1000) {
        res = "Mil";
    }

    res = convertDigit(((n / 100000) % 100), "Cientos, ") + res;

    res = convertDigit((n / 1000000) % 100, "Millones, ") + res;

    if (n == 1000000) {
        res = "Un Millon";
    }

    res = convertDigit((n / 100000000) % 100, "Cientos Millones, ") + res;

    return res;
}

// Programa en C++ para convertir números a palabras
int main()
{
    char opcion;

    do
    {
        try
        {
            cout << "Introduzca una opcion: \n" << endl;

            cout << "1. Continuar \n \n" << endl;
            cout << "2. Salir \n" << endl;
            cin >> opcion;

            while (!isdigit(opcion)) {

                system("cls");
                cout << "Introduzca una opcion correcta \n" << endl;

                cout << "Introduzca una opcion: \n" << endl;

                cout << "1. Continuar \n \n" << endl;
                cout << "2. Salir \n" << endl;
                cin >> opcion;
            }

            int n = 0;
            cout << "\nIntroduzca un numero: \n" << endl;

            while (!(cin >> n)) {
                system("cls");
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Introduzca una opcion correcta \n" << endl;

                cout << "\nIntroduzca un numero: \n" << endl;
                cout << convert(n) << endl;
            }

            cout << convert(n) << endl;

            cout << "\n \n PRESIONE CUALQUIER TECLA PARA CONTINUAR \n" << endl;
            cout << opcion << endl;
            _getch();
            system("cls");

        }
        catch (const std::exception&)
        {
            cout << "Introduce una opcion valida" << endl;
        }

    } while (opcion != 2);

    return 0;
}