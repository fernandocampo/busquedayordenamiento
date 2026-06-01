/*
10. Extremos de Duración en Películas Definir la estructura Pelicula con los campos
Código, Título y Duración en minutos. Cargar N películas en un vector y ordenarlas por su
duración de menor a mayor para:
●​ Informar el título de la película más corta y el título de la más larga.
●​ Mostrar el listado completo de películas ordenado por su tiempo de duración
*/

#include <iostream>
#include <string>
using namespace std;

struct Pelicula
{
    int codigo;
    string titulo;
    float duracion;
};


Pelicula obtenerPelicula () {
    Pelicula pelicula;
 
    cout << "ingresar el codigo de la pelicula" << endl;
    cin >> pelicula.codigo;

    cin.ignore(); 

    cout << "Ingresar nombre" << endl;
    getline(cin, pelicula.titulo); 

    cout << "ingresar duracion en min" << endl;
    cin >> pelicula.duracion;

    return pelicula;
}

void cargarPeliculas(Pelicula peliculas[], int cant) {
    for (int i = 0; i < cant; i++)
    {
        peliculas[i] = obtenerPelicula();
    }
    
}

void burbujeoMejorado (Pelicula peliculas[], int n) {
    int i = 0, j;
    Pelicula aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (peliculas[j].duracion > peliculas[j+1].duracion) {

                aux = peliculas[j];
                peliculas[j] = peliculas[j+1];
                peliculas[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}

void imprimir(Pelicula peliculas[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Posicicion " << i +1 << " Pelicula : " << peliculas[i].titulo << endl;
        cout << "Duracion en min "  << peliculas[i].duracion << endl;
    }
}


int main () {
    const int MAX_ELEMENTOS = 100;
    Pelicula peliculas[MAX_ELEMENTOS];
    int cant;

    cout << "Cuaatas peliculas vas a cargar? ";
    cin >> cant;

    cargarPeliculas(peliculas, cant);
    
    burbujeoMejorado(peliculas, cant); 
    
    cout << "Pelicula mas CORTA: " << peliculas[0].titulo 
         << " (" << peliculas[0].duracion << " min)" << endl;
         
    cout << "Pelicula mas LARGA: " << peliculas[cant - 1].titulo 
         << " (" << peliculas[cant - 1].duracion << " min)" << endl;


         cout << "\n--- LISTADO COMPLETO (De menor a mayor ) ---" << endl;
    imprimir(peliculas, cant);

    return 0;
}