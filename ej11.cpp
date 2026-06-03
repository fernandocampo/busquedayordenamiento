/*
11. Ranking de Productividad Industrial Una fábrica registra la actividad de sus
máquinas. De cada una se ingresa el código identificador, el nombre del operario a cargo y
la cantidad de piezas producidas durante el turno. Una vez cargados los datos de las N
máquinas, se solicita:
●​ Ordenar el listado de mayor a menor según la producción de piezas.
●​ Mostrar los códigos de las tres máquinas que lideran el ranking de productividad.
●​ Permitir al usuario ingresar el nombre de un operario para buscarlo en el sistema e
informar cuántas piezas produjo su máquina.
*/

#include <iostream>
#include <string>
using namespace std;

struct Maquina
{
    int codigo;
    string nombreOperario;
    int cantidadProducida;
};


Maquina obtenerMaquina () {
    Maquina maquina;
 
    cout << "ingresar el codigo de la maquina" << endl;
    cin >> maquina.codigo;

    cin.ignore(); 

    cout << "Ingresar nombre del operario" << endl;
    getline(cin, maquina.nombreOperario); 

    cout << "ingresar la cantidad producida" << endl;
    cin >> maquina.cantidadProducida;

    return maquina;
}

void cargarMaquinas(Maquina maquinas[], int &cant) {
    cout << "Cuaatas maquinas vas a cargar? ";
    cin >> cant;
    
    for (int i = 0; i < cant; i++)
    {
        maquinas[i] = obtenerMaquina();
    }
    
}

void burbujeoMejoradoDesc (Maquina maquinas[], int n) {
    int i = 0, j;
    Maquina aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (maquinas[j].cantidadProducida < maquinas[j+1].cantidadProducida) {

                aux = maquinas[j];
                maquinas[j] = maquinas[j+1];
                maquinas[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}


void burbujeoMejoradoAsc (Maquina maquinas[], int n) {
    int i = 0, j;
    Maquina aux; 
    bool ordenado = false;

    while (i < n && !ordenado) {
        ordenado = true;

        for (j = 0; j < n - i - 1; j++) {
            if (maquinas[j].nombreOperario > maquinas[j+1].nombreOperario) {

                aux = maquinas[j];
                maquinas[j] = maquinas[j+1];
                maquinas[j+1] = aux;
                ordenado = false;

            }
        }
        i++;
    }
}


int busquedaBinaria (Maquina maquinas[], int n, string operarioBuscado) {
    int inicio = 0;
    int fin = n - 1;

    while (fin >= inicio) { 
        int mitad = inicio + (fin - inicio) / 2;

        if (maquinas[mitad].nombreOperario == operarioBuscado) {
            return mitad;
        }

        if (maquinas[mitad].nombreOperario > operarioBuscado) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }
    
    return -1;
}


void imprimirRanking(Maquina maquinas[], int n) {
    
    cout << "Top 3 maquinas x produccion" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Posicicion " << i +1 << " Maquina : " << maquinas[i].codigo << endl;
        cout << "Cantidad Producida: "  << maquinas[i].cantidadProducida << endl;
    }
}

void analisisEmpleadoBuscado(Maquina maquinas[], int n) {

    string operarioBuscado;
    
    cout << "Ingresa el nombre del operario que queres buscar" << endl;
    cin >> operarioBuscado;

    int posicion = busquedaBinaria(maquinas, n, operarioBuscado);
    
    if (posicion != -1)
    {
        cout << "Se encontro el operario " << endl;
        cout << "El operario " << maquinas[posicion].nombreOperario << "de la maquina " << maquinas[posicion].codigo << endl;
        cout << "Produjo " << maquinas[posicion].cantidadProducida << endl;
    } else
    {
        cout << "El operario " << operarioBuscado << "no esta registrado " << endl;
    }
    
}


int main () {
    const int MAX_ELEMENTOS = 100;
    Maquina maquinas[MAX_ELEMENTOS];
    int cant;

    cargarMaquinas(maquinas, cant);

    burbujeoMejoradoDesc(maquinas, cant); 
    imprimirRanking(maquinas, cant);


    burbujeoMejoradoAsc(maquinas, cant);
    analisisEmpleadoBuscado(maquinas, cant);
    
    return 0;
}