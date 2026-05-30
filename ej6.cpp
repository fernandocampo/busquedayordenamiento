/*
EJ 6
Padrón de Alumnos Definir una estructura llamada Alumno que contenga Legajo,
Nombre y Nota Final. Cargar N alumnos en un vector y ordenar los registros por número de
legajo de forma ascendente para:
●​ Permitir el ingreso de un legajo por teclado para realizar una búsqueda.
●​ Mostrar de forma inmediata el nombre y la nota del alumno encontrado.
*/


#include <iostream>
using namespace std;

struct Alumno
{
    int legajo;
    string nombre;
    float notaFinal;
};


Alumno obtenerAlumno () {

    Alumno alumno;
 
        cout << "ingresar el legajo del alumno" << endl;
        cin >> alumno.legajo;

        cout << "Ingresar nombre" << endl;
        cin >> alumno.nombre;

        cout << "ingresar nota final" << endl;
        cin >> alumno.notaFinal;

        return alumno;

}

void cargarAlumnos(Alumno alumnos[], int cant) {
    for (int i = 0; i < cant; i++)
    {
        alumnos[i] = obtenerAlumno();
    }
    
}

void burbujeoMejorado (Alumno alumnos[], int n) {
    int i = 0, j;
    Alumno aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (alumnos[j].legajo > alumnos[j+1].legajo) {

                aux = alumnos[j];
                alumnos[j] = alumnos[j+1];
                alumnos[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}


int busquedaBinaria (Alumno alumnos[], int cant, int legajoBuscado) {
    int inicio = 0;
    int fin = cant - 1;

    while (fin >= inicio) { 
        int mitad = inicio + (fin - inicio) / 2;

        if (alumnos[mitad].legajo == legajoBuscado) {
            return mitad;
        }

        if (alumnos[mitad].legajo > legajoBuscado) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }
    
    return -1;
}

int main () {

    int cant;
    
    cout << "Ingresar la cantidad de alumnos a ingresar" << endl;
    cin >> cant;

    Alumno alumnos[cant];

    cargarAlumnos(alumnos, cant);
    burbujeoMejorado(alumnos, cant);

    int legajoBuscado;

    cout << "Ingresa el legajo del alumno a buscar" << endl;
    cin >> legajoBuscado;

    int posicion = busquedaBinaria(alumnos, cant, legajoBuscado);

    if(posicion != -1 ){
        cout << "El alumno buscado fue encontrado " << endl; 
        cout << "Legajo: " << legajoBuscado << endl;
        cout << "Nombre: " << alumnos[posicion].nombre << endl;
        cout << "Nota final: " << alumnos[posicion].notaFinal << endl;
    } else
    {
        cout << "El usuario buscado no se encuentra inscripto" << endl;
    }
    
    return 0;
}