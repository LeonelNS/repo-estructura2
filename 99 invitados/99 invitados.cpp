/*En una fiesta hay 99 personas, a cada una de ellas se le ha dado un numero entero comprendido entre uno
y 99 acompañado de unas instrucciones, estas dicen, si el numero es par dividalo por 2, si es impar
multipliquelo por 3 y al resultado añadele 1
repita las instrucciones anteriores con el numero que resulte hasta
que este sea igual a 4
por tanto, cada invitado obtendra una cadena de numeros enteros que terminara con el numero 4
por ejemplo: el invitado con el numero 3 formará la siguiente cadena:
3 - 10 - 5 - 16 - 08 - 4
qué invitado tiene la cadena más larga?*/

#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int cadena, menor = 0;
    int i = 1;
    int mayor, inicial, contador = 0;
    int container[500];

    for (i = 1; i < 100; i++)
    {

        cadena = i;
        do
        {
            container[contador] = cadena;
            if (cadena % 2 == 0)
            {
                cadena = cadena / 2;
            }
            else
            {
                cadena = (cadena * 3) + 1;
            }
            contador++;


        } while (cadena != 4);

        mayor = contador;
        contador = 1;

        if (mayor > menor)
        {
            menor = mayor;
            inicial = container[1];
        }

    }

    if (mayor > menor)
    {
        cout << "Cantidad de la cadena: " << mayor << "\n";
        cadena = inicial;
        cout << cadena << "-";
        do
        {
            if (cadena % 2 == 0)
            {
                cadena = cadena / 2;
                cout << cadena << " - ";
            }
            else
            {
                cadena = (cadena * 3) + 1;
                cout << cadena << " - ";
            }
            cout << cadena;
        } while (cadena != 4);

    }
    else
    {
        cout << "Cantidad de la cadena: " << menor << "\n";
        cadena = inicial;
        cout << cadena << "- ";
        do
        {
            if (cadena % 2 == 0)
            {
                cadena = cadena / 2;
                cout << cadena << " - ";
            }
            else
            {
                cadena = (cadena * 3) + 1;
                cout << cadena << " - ";
            }

        } while (cadena != 4);
    }


};