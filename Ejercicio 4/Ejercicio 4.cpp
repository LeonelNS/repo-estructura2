#include <iostream>
#include <algorithm>

using namespace std;

// Función para dividir el array y hacer los intercambios
int dividir(int* arr, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = arr[start];
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right) {
        while (arr[right] > pivot) {
            right--;
        }

        while ((left < right) && (arr[left] <= pivot)) {
            left++;
        }

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = arr[right];
    arr[right] = arr[start];
    arr[start] = temp;

    // La nueva posición del pivot
    return right;
}

// Función recursiva para hacer el ordenamiento
void quicksort(int* arr, int start, int end)
{
    int pivot;

    if (start < end) {
        pivot = dividir(arr, start, end);

        // Ordeno la lista de los menores
        quicksort(arr, start, pivot - 1);

        // Ordeno la lista de los mayores
        quicksort(arr, pivot + 1, end);
    }
}

int main() {
    const int MAX = 100;
    int nums[MAX];
    int i;
    int n;
    cout << "Indique el tamano del arreglo: ";
    cin >> n;
    cout << "Introduzca los elementos del arreglo: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Arreglo desordenado: ";
    for (i = 0; i < n; i++) {
        cout << " " << nums[i];
    }
    cout << endl;

    // Ordenamos el arreglo
    quicksort(nums, n - n, n - 1);

    cout << "Arreglo ordenado: ";
    for (i = 0; i < n; i++) {
        cout << " " << nums[i];
    }
    cout << endl;

    int posicion;
    cout << "Ingresa la posicion (Empezando desde 0): ";
    cin >> posicion;
    if (n > posicion)
    {
        cout << "El numero proximo a la posición seleccionada es: " << nums[posicion + 1];
    }
    else
    {
        cout << "Haz seleccionado el numero mas grande";
    }

    cout << endl;
}
