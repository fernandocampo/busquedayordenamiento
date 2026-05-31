/*

9. Limpieza de Datos y Duplicados Ingresar N números enteros en un vector. Al finalizar la
carga, ordenar el vector de mayor a menor para luego:
●​ Procesar el arreglo eliminando todos los valores repetidos, de modo que solo
queden elementos únicos.
●​ Mostrar el vector resultante y el nuevo tamaño del mismo tras la limpieza.

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

void burbujeoMejorado (int numeros[], int n) {
    int i = 0, j, aux; 
    bool ordenado = false;
    
    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (numeros[j] < numeros[j+1]) {
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void imprimir(int numeros[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Posicicion " << i +1 << " Valor : " << numeros[i] << endl;
    }
}

void quitarDuplicados(int numeros[], int& cant) {
    for (int i = 0; i < cant - 1; i++) {
        
        if (numeros[i] == numeros[i + 1]) {
            
            for (int j = i + 1; j < cant - 1; j++) {
                numeros[j] = numeros[j + 1];
            }
    
            cant--;
            i--; 
        }
    }
}

int main () {
    
    const int MAX_ELEMENTOS = 100;
    int numeros[MAX_ELEMENTOS]; 

    int cant;
    
    cargarVector(numeros, cant);
    
    burbujeoMejorado(numeros, cant); 
    
    cout << "\n--- Vector Ordenado de mayor a menor ---" << endl;
    imprimir(numeros, cant);

    quitarDuplicados(numeros, cant);


    cout << "\n--- Vector sin duplicados ---" << endl;
    imprimir(numeros,cant);

    cout << "Vector sin duplicados tiene " << cant << " elementos" << endl;



    return 0;
}