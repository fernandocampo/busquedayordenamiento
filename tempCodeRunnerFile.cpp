/*
2. Verificación de Intercambios Ingresar N números enteros en un vector. Al finalizar la
carga, ordenar el vector de menor a mayor utilizando el método de burbujeo:
●​ Mostrar el vector resultante ya ordenado.
●​ Informar la cantidad exacta de intercambios que realizó el algoritmo para completar
la tarea.
*/


#include <iostream>
using namespace std;

void cargarVector (int numeros[],  int& cant ) {

    cout << "Ingresar el tamano del vector" << endl;
    cin >> cant;

    for (int i = 0; i < cant; i++)
    {
        cout << "ingresar el numero" << endl;
        cin >> numeros[i];
    }
    
}

void burbujeoMejorado (int numeros[], int n, int& cantIntercambios) {
    int i = 0, j, aux; 
    bool ordenado = false;
    
    cantIntercambios = 0;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j+1]) {
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
                ordenado = false;
                
                cantIntercambios++;
            }
        }
        i++;
    }
}

void imprimir(int numeros[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Posicicion " << i +1 << "Valor : " << numeros[i] << endl;
    }
}

int main () {
    int cant;
    int numeros[100]; 
    int cantIntercambios = 0;
    
    cargarVector(numeros, cant);
    
    burbujeoMejorado(numeros, cant, cantIntercambios); 
    
    cout << "\n--- Vector Ordenado ---" << endl;
    imprimir(numeros, cant);


    cout << "Cantidad de intercambios realizados: " << cantIntercambios << endl;
    
    return 0;
}