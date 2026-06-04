/*
El Ordenador de Libros
Contexto
Estás ayudando a organizar la biblioteca de la universidad. Te han dado un lote de 6 libros que tienen impreso un código numérico de clasificación en el lomo. 
Los libros te llegaron en un orden completamente aleatorio, y necesitas ordenarlos de menor a mayor según su código para poder ubicarlos en los estantes.
Para resolverlo de forma eficiente y emular cómo lo harías manualmente (tomando un libro y buscándole su lugar correcto entre los que ya acomodaste), debes implementar el algoritmo de Ordenamiento por Inserción (Insertion Sort).
Requisitos:
Crear un arreglo de enteros estático con los siguientes códigos de libros en este orden exacto: [45, 12, 89, 5, 23, 62].
Implementar la función ordenarLibros(int arr[], int n) utilizando el código analizado en clase.
Mostrar por pantalla el estado del arreglo antes y después de aplicar el ordenamiento para verificar que el algoritmo funcionó correctamente.
*/

#include <iostream>
using namespace std;

void ordenarLibros(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void mostrarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int TAMANIO = 6;
    int libros[TAMANIO] = {45, 12, 89, 5, 23, 62};

    cout << "Códigos originales: ";
    mostrarArreglo(libros, TAMANIO);

    ordenarLibros(libros, TAMANIO);

    cout << "Códigos ordenados de menor a mayor: ";
    mostrarArreglo(libros, TAMANIO);

    return 0;
}