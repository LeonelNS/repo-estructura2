/*
    Esta programa recibe un arreglo con múltiples valores y imprime la ocurrencia de cada elemento en el mismo.
    Solo se permiten números en el programa.
*/
#include <iostream>  //Incluye la librería Input/Output
#include <string>    //Incluye la librería para trabajar con strings
#include <conio.h>

using namespace std;  //Declaración del uso del espacio de nombres std

int main() {

    int salir = 0;

    do
    {
        try {
            system("cls");
            cin.exceptions(istream::failbit); // capta bits fallidos
            int lista[20];  //Declaración del arreglo con un tamaño máximo de 20
            int cantidad;   //Declaración de la variable cantidad
            int contador;   //Declaración de la variable contador

            cout << "¿Cuantos numeros deseas ingresar? (Maximo 20): ";  //Imprime en pantalla el mensaje
            cin >> cantidad; //Tomamos la cantidad ingresada por el usuario

            //Validamos que el usuario no ingrese un numero mayor a 20
            if (cantidad > 20) {
                cout << "No puedes ingresar mas de 20 numeros. Intentalo de nuevo." << endl;
                return 0; //Termina el programa
            }

            //Recorremos el arreglo para ingresar los numeros
            for (int i = 0; i < cantidad; i++) {
                cout << "Ingresa el numero " << i + 1 << ": ";
                cin >> lista[i];
            }

            //Recorremos el arreglo para imprimir los numeros ingresados
            cout << "Los numeros ingresados son: ";
            for (int x = 0; x < cantidad; x++) {
                cout << lista[x] << " ";
            }
            cout << endl;

            //Recorremos el arreglo para contar la ocurrencia de los numeros
            for (int j = 0; j < cantidad; j++) {
                contador = 0;
                for (int k = 0; k < cantidad; k++) {
                    if (lista[j] == lista[k]) {
                        contador++;
                    }
                }
                cout << "El numero " << lista[j] << " se repite " << contador << " veces." << endl;
            }
            return 0;
        }
        catch (exception fail){
            cin.clear();
            string tmp;
            getline(cin, tmp);
            cout << "Solo se puden ingresar numeros, intente nuevamente \n \n";
            _getch();
        }
    } while (salir != 1);
}
