/*
// Una institución educativa necesita registrar estudiantes. De cada estudiante se conoce su número de 
// legajo, nombre y apellido.
// Se pide:
// 1. Definir una estructura Estudiante.
// 2. Cargar los datos en un vector mediante una función. La carga finalizará cuando el usuario 
// responda N o n a la pregunta "¿Desea cargar otro estudiante?" o cuando se complete la capacidad 
// máxima del vector.
// 3. Mostrar el listado cargado.
// 4. Ordenar el vector por número de legajo de menor a mayor utilizando el algoritmo de Burbujeo 
// Mejorado.
// 5. Mostrar el listado ordenado.
*/

#include <iostream>
using namespace std;

const int MAX = 1000;

struct Estudiante
{
    int legajo;
    string nombre;
    string apellido;
};


//carga la cantidad por referencia
void cargarEstudiantes(Estudiante estudiantes[], int& cant) {
    char continuar;
    cant = 0;

    do {
        cout << "Ingresa el legajo del estudiante: ";
        cin >> estudiantes[cant].legajo;

        cout << "Ingresa el nombre del estudiante: ";
        cin >> estudiantes[cant].nombre;

        cout << "Ingresa el apellido del estudiante: ";
        cin >> estudiantes[cant].apellido;

        cant++;

        if (cant == MAX) {
            cout << "Se alcanzo la cap maxima de carga " << endl;
            break; 
        } 

        cout << "Queres cargar otro estudiante? (S/N): ";
        cin >> continuar;

    } while (continuar != 'N' && continuar != 'n');
}
void burbujeoMejorado (Estudiante estudiantes[], int n) {
    int i = 0, j;
    Estudiante aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (estudiantes[j].legajo > estudiantes[j+1].legajo) {

                aux = estudiantes[j];
                estudiantes[j] = estudiantes[j+1];
                estudiantes[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}

// al muestrar por valor
void imprimir(Estudiante estudiantes[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Estudiante " << i +1 << " Legajo : " << estudiantes[i].legajo << endl;
        cout << "NOmbre "  << estudiantes[i].nombre << endl;
        cout << "Apellid " << estudiantes[i].apellido << endl;
    }
}

int main () {

    int cant = 0;
    const int MAX = 1000;

    Estudiante estudiantes[MAX];
    cargarEstudiantes(estudiantes, cant);

    imprimir(estudiantes, cant);


    burbujeoMejorado(estudiantes, cant);
    imprimir(estudiantes, cant);
    
    
    return 0;
}