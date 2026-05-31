/*

7. Biblioteca por Código Una biblioteca registra N libros almacenando su código
identificador y su título. Tras finalizar la carga, el sistema debe ordenar el catálogo por
código de libro para:
●​ Solicitar al usuario un código para consultar.
●​ Informar el título del libro correspondiente o indicar si el código es inexistente.

*/

#include <iostream>
using namespace std;

struct Libro
{
    int codigo;
    string titulo;
};


Libro obtenerLibro () {

    Libro libro;
 
        cout << "ingresar el codigo del libro" << endl;
        cin >> libro.codigo;

        cout << "Ingresar titulo del libro" << endl;
        cin >> libro.titulo;
        
        return libro;

}

void cargarLibros (Libro libros[], int cant) {
    for (int i = 0; i < cant; i++)
    {
        libros[i] = obtenerLibro();
    }
    
}

void burbujeoMejorado (Libro libros[], int n) {
    int i = 0, j;
    Libro aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (libros[j].codigo > libros[j+1].codigo) {

                aux = libros[j];
                libros[j] = libros[j+1];
                libros[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}


int busquedaBinaria (Libro libros[], int cant, int codigoBuscado) {
    int inicio = 0;
    int fin = cant - 1;

    while (fin >= inicio) { 
        int mitad = inicio + (fin - inicio) / 2;

        if (libros[mitad].codigo == codigoBuscado) {
            return mitad;
        }

        if (libros[mitad].codigo > codigoBuscado) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }
    
    return -1;
}

int main () {

    int cant;
    
    cout << "Ingresar la cantidad de libros a ingresar" << endl;
    cin >> cant;

    Libro libros[cant];

    cargarLibros(libros, cant);
    burbujeoMejorado(libros, cant);

    int codigoBuscado;

    cout << "Ingresa el codigo del libro a buscar" << endl;
    cin >> codigoBuscado;

    int posicion = busquedaBinaria(libros, cant, codigoBuscado);

    if(posicion != -1 ){
        cout << "El codigo de libro fue encontrado " << endl; 
        cout << "Codigo buscado es: " << codigoBuscado << endl;
        cout << "Titulo: " << libros[posicion].titulo << endl;
    } else
    {
        cout << "El codigo buscado es inexistente" << endl;
    }
    
    return 0;
}