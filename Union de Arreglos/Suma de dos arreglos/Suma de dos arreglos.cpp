/*Este programa dados dos arreglos ordenados los une en un nuevo arreglo también ordenado*/

#include <iostream> //Libreria para usar cout y cin
#include <vector> //Libreria para usar vectores
#include <algorithm> //Libreria para usar funciones de ordenamiento

using namespace std;

int main()
{
    int tamano_arreglo1, tamano_arreglo2; //Variables que guardan el tamaño de los arreglos

    cout << "Introduzca la cantidad de elementos del primer arreglo: "; //Se pide el tamaño del primer arreglo
    cin >> tamano_arreglo1; //Se guarda el tamaño del primer arreglo

    //Validacion para que solo se permitan numeros
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Error! Introduzca un numero entero: ";
        cin >> tamano_arreglo1;
    }

    //Se crea el vector del primer arreglo
    vector<int> arreglo1(tamano_arreglo1);

    //Se llena el segundo arreglo
    for (int i = 0; i < tamano_arreglo1; i++)
    {
        cout << "Introduzca el elemento " << i + 1 << " del primer arreglo: ";
        cin >> arreglo1[i];

        //Validacion para que solo se permitan numeros
        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error! Introduzca un numero entero: ";
            cin >> arreglo1[i];
        }
    }

    //Se ordena el primer arreglo de menor a mayor
    sort(arreglo1.begin(), arreglo1.end());

    cout << "Introduzca la cantidad de elementos del segundo arreglo: "; //Se pide el tamaño del segundo arreglo
    cin >> tamano_arreglo2; //Se guarda el tamaño del segundo arreglo

    //Validacion para que solo se permitan numeros
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error! Introduzca un numero entero: ";
        cin >> tamano_arreglo2;
    }

    //Se crea el vector del segundo arreglo
    vector<int> arreglo2(tamano_arreglo2);

    //Se llena el segundo arreglo
    for (int i = 0; i < tamano_arreglo2; i++)
    {
        cout << "Introduzca el elemento " << i + 1 << " del segundo arreglo: ";
        cin >> arreglo2[i];

        //Validacion para que solo se permitan numeros
        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error! Introduzca un numero entero: ";
            cin >> arreglo2[i];
        }
    }

    //Se ordena el segundo arreglo de menor a mayor
    sort(arreglo2.begin(), arreglo2.end());

    //Se crea el vector con el tamaño de la suma de los arreglos
    vector<int> arreglo_unido(tamano_arreglo1 + tamano_arreglo2);

    //Se unen los arreglos
    merge(arreglo1.begin(), arreglo1.end(), arreglo2.begin(), arreglo2.end(), arreglo_unido.begin());

    //Se imprime el arreglo unido
    cout << "Arreglo unido: ";
    for (int i = 0; i < tamano_arreglo1 + tamano_arreglo2; i++)
        cout << arreglo_unido[i] << " ";

    return 0;
}