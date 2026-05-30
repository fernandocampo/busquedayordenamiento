/*

1. Localización de Datos Desarrollar una aplicación que permita ingresar N números
enteros en un vector. Luego, solicitar un número al usuario para buscarlo en el arreglo.
●​ Informar si el número se encuentra o no.
●​ Indicar la posición de su primera aparición.
●​ Mostrar la cantidad total de veces que se repite.

*/

#include <iostream>
using namespace std;

void cargarVector (int numeros[],  int& cant ) {

    cout << "Ingresar el tamano del vector" << endl;
    cin >> cant;

for (int i = 0; i < cant; i++)
{
    cout << "Ingresar el numero" << endl;
    cin >> numeros[i];
}

}

void busquedaSecuencial (int numeros[], int cant, int valorBuscado, int& primerPos, int& cantRepeticiones) {
    
    cantRepeticiones = 0;
    primerPos = -1; 

    for (int i = 0; i < cant; i++) {
        if (numeros[i] == valorBuscado) {
            cantRepeticiones++; 
        
            if (primerPos == -1) {
                primerPos = i;
            }
        }
    }
}

int main () {

    int cant;
    int numeros[100];
    int valorBuscado;
    int cantRepeticiones = 0;

    int primerPos;
    
    cargarVector(numeros, cant);

    cout << "QUe numero queres buscar" << endl;
    cin >> valorBuscado;

    busquedaSecuencial(numeros, cant, valorBuscado, primerPos, cantRepeticiones);

    if (primerPos == -1)
    {
        cout << "El numero " << valorBuscado << "No se encuentra" << endl;

    } else
    {
        cout << "El numero " << valorBuscado << " se encuentra en la posicion" << primerPos << endl;
        cout << "Cantidad total de repeticiones de " << valorBuscado << cantRepeticiones << endl;
    }
    
    
    return 0;
}