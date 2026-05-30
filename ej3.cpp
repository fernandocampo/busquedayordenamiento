/*
3. Ordenamiento Alfabético de Apellidos Cargar un vector con los apellidos de N
personas. Una vez finalizada la carga, el programa debe procesar los datos para:
●​ Ordenar el listado alfabéticamente de la A a la Z.
●​ Mostrar el listado completo y ordenado.
●​ Permitir realizar una consulta para saber si un apellido específico está presente en la
lista.
*/

#include <iostream>
#include <string>

using namespace std;


void cargarVector (string apellidos[],  int& cant ) {

    cout << "Ingresar la cantidad de apellidos a ingresar" << endl;
    cin >> cant;

    for (int i = 0; i < cant; i++)
    {
        cout << "ingresar el apellido" << endl;
        cin >> apellidos[i];
    }
    
}

void burbujeoMejorado (string apellidos[], int n) {
    int i = 0, j;
    string aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (apellidos[j] > apellidos[j+1]) {

                aux = apellidos[j];
                apellidos[j] = apellidos[j+1];
                apellidos[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}

int busquedaBinaria (string apellidos[], int n, string apellidoBuscado) {
    int inicio = 0;
    int fin = n - 1;

    while (fin >= inicio) { 
        int mitad = inicio + (fin - inicio) / 2;

        if (apellidos[mitad] == apellidoBuscado) {
            return mitad;
        }

        if (apellidos[mitad] > apellidoBuscado) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }
    
    return -1;
}

void imprimir(string apellidos[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Posicicion " << i +1 << " Apellido : " << apellidos[i] << endl;
    }
}

int main () {
    int cant;
    string apellidoBuscado;
    string apellidos[100]; 
    
    cargarVector(apellidos, cant);
    
    burbujeoMejorado(apellidos, cant); 
    
    cout << "\n--- Vector de Apellidos ordenados alfabeticamente ---" << endl;
    
    imprimir(apellidos, cant);


    cout << "Ingresar el apellido que queres buscar" << endl;
    cin >> apellidoBuscado;

    int posicion = busquedaBinaria (apellidos, cant, apellidoBuscado);
    
    if (posicion != -1) {
        cout << "El apellido '" << apellidoBuscado << "' SI esta en la lista (Posicion: " << posicion + 1 << ")." << endl;
    } else {
        cout << "El apellido '" << apellidoBuscado << "' NO se encuentra en la lista." << endl;
    }

    return 0;
}