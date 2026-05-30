/*
5. Búsqueda Binaria de Valores Cargar un vector con N números enteros. Una vez
cargados, aplicar un algoritmo de ordenamiento ascendente. Luego, solicitar un valor al
usuario para:
●​ Realizar la búsqueda del valor mediante el algoritmo de búsqueda binaria.
●​ Informar la posición encontrada o mostrar un mensaje de error si el valor no existe
en el vector.
*/

#include <iostream>
#include <string>

using namespace std;


void cargarVector (int numeros[],  int& cant ) {

    cout << "Ingresar la cantidad de numeros a ingresar" << endl;
    cin >> cant;

    for (int i = 0; i < cant; i++)
    {
        cout << "ingresar el apellido" << endl;
        cin >> numeros[i];
    }
    
}

void burbujeoMejorado (int numeros[], int n) {
    int i = 0, j;
    int aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j+1]) {

                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}

int busquedaBinaria (int numeros[], int n, int numeroBuscado) {
    int inicio = 0;
    int fin = n - 1;

    while (fin >= inicio) { 
        int mitad = inicio + (fin - inicio) / 2;

        if (numeros[mitad] == numeroBuscado) {
            return mitad;
        }

        if (numeros[mitad] > numeroBuscado) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }
    
    return -1;
}

void imprimir(int numeros[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Posicicion " << i +1 << " Apellido : " << numeros[i] << endl;
    }
}

int main () {
    int cant;
    int numeroBuscado;
    int numeros[100]; 
    
    cargarVector(numeros, cant);
    
    burbujeoMejorado(numeros, cant); 
    
    cout << "\n--- Vector de numeros ordenados asc ---" << endl;
    
    imprimir(numeros, cant);


    cout << "Ingresar el numero que queres buscar" << endl;
    cin >> numeroBuscado;

    int posicion = busquedaBinaria (numeros, cant, numeroBuscado);
    
    if (posicion != -1) {
        cout << "El numero '" << numeroBuscado << "' SI esta en la lista (Posicion: " << posicion + 1 << ")." << endl;
    } else {
        cout << "El numero '" << numeroBuscado << "' NO se encuentra en la lista." << endl;
    }

    return 0;
}