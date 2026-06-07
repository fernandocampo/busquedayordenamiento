/*

Una empresa comercial desea registrar información de sus vendedores.

De cada vendedor se conoce:
Número de legajo.
Nombre y apellido.
Sucursal.
Cantidad de ventas realizadas durante el mes.
Bono

El bono se calcula de la siguiente manera:
Si realizó 50 o más ventas, recibe un bono de $15.000 por cada venta que supera las 50.
En caso contrario, no recibe bono.

Se pide desarrollar un programa utilizando estructuras, funciones y procedimientos que permita:

Definir una estructura vendedor.
Cargar los datos de los vendedores en un vector. La carga finalizará cuando el usuario responda "N" o "n" 
Calcular El bono de cada vendedor durante la carga.
Mostrar el listado completo de vendedores.
Ordenar el vector por número de legajo en forma descendente, de manera que el vendedor con mayor número de legajo quede en la primera posición.
Mostrar el listado ordenado.
Buscar el vendedor mediante número de legajo utilizando el método de búsqueda más eficiente para este caso.
Informar todos los datos del vendedor encontrado. Si no existe, mostrar un mensaje adecuado.

*/

#include <iostream>
using namespace std;

struct Vendedor
{
    int legajo;
    string nombre;
    string apellido;
    int sucursal;
    int cantVentas;
    float bono;
};

void cargarVendedores(Vendedor vendedores[], int& cantVend) {
    char continuar;
    cantVend = 0;

    int CANT_VENTAS_BONO = 50;
    float BONO_UNITARIO = 15000;

    do {
        cout << "\n--- Cargar Vendedor " << cantVend + 1 << " ---" << endl;
        cout << "Ingresa el legajo del vendedor: ";
        cin >> vendedores[cantVend].legajo;

        cin.ignore();

        cout << "Ingresa el nombre del vendedor: ";
        cin >> vendedores[cantVend].nombre;

        cout << "Ingresa el apellido del vendedor: ";
        cin >> vendedores[cantVend].apellido;

        cout << "Ingresa la sucursal del vendedor: ";
        cin >> vendedores[cantVend].sucursal;

        cout << "Ingresa la cant de ventas realizadas durante el mes: ";
        cin >> vendedores[cantVend].cantVentas;

        vendedores[cantVend].bono = 0;

        if (vendedores[cantVend].cantVentas >= CANT_VENTAS_BONO) {
            vendedores[cantVend].bono = (vendedores[cantVend].cantVentas - CANT_VENTAS_BONO) * BONO_UNITARIO;
        } 

        cantVend++;

        cout << "Queres cargar otro vendedor? (S/N): ";
        cin >> continuar;

    } while (continuar != 'N' && continuar != 'n');
}

void imprimir(Vendedor vendedores[], int cantVend) {
    for (int i = 0; i < cantVend; i++)
    {
        cout << "\nVendedor " << i + 1 << " - Legajo: " << vendedores[i].legajo << endl;
        cout << "Nombre: "  << vendedores[i].nombre << endl;
        cout << "Apellido: " << vendedores[i].apellido << endl;
        cout << "Sucursal: " << vendedores[i].sucursal << endl; 
        cout << "Cantidad de Ventas: " << vendedores[i].cantVentas << endl;
        cout << "Bono: $" << vendedores[i].bono << endl;
        cout << "-----------------------------------" << endl;
    }
}

void burbujeoMejoradoDesc (Vendedor vendedores[], int cantVend) {
    int i = 0, j;
    Vendedor vendedorAux; 
    bool ordenado = false;

    while (i < cantVend && !ordenado) {
        ordenado = true;

        for (j = 0; j < cantVend - i - 1; j++) {
            if (vendedores[j].legajo < vendedores[j+1].legajo) {
                vendedorAux = vendedores[j];
                vendedores[j] = vendedores[j+1];
                vendedores[j+1] = vendedorAux;
                ordenado = false;
            }
        }
        i++;
    }
}

void burbujeoMejoradoAsc (Vendedor vendedores[], int cantVend) {
    int i = 0, j;
    Vendedor vendedorAux; 
    bool ordenado = false;

    while (i < cantVend && !ordenado) {
        ordenado = true;
        for (j = 0; j < cantVend - i - 1; j++) {
            if (vendedores[j].legajo > vendedores[j+1].legajo) {
                vendedorAux = vendedores[j];
                vendedores[j] = vendedores[j+1];
                vendedores[j+1] = vendedorAux;
                ordenado = false;
            }
        }
        i++;
    }
}

int busquedaBinaria (Vendedor vendedores[], int cantVend, int legajoBuscado) {
    int inicio = 0;
    int fin = cantVend - 1;

    while (inicio <= fin) { 
        int mitad = inicio + (fin - inicio) / 2;

        if (vendedores[mitad].legajo == legajoBuscado) {
            return mitad;
        }

        if (vendedores[mitad].legajo > legajoBuscado) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }
    
    return -1;
}

void analisisVendedorBuscado(Vendedor vendedores[], int cantVend) {
    int legajoBuscado;
    
    cout << "\nIngresa el numero de legajo del vendedor que queres buscar: ";
    cin >> legajoBuscado;

    int posicion = busquedaBinaria(vendedores, cantVend, legajoBuscado);
    
    if (posicion != -1)
    {
        cout << "\n[Vendedor Encontrado]" << endl;
        cout << "Legajo: " << vendedores[posicion].legajo << endl;
        cout << "Nombre: " << vendedores[posicion].nombre << endl;
        cout << "Apellido " << vendedores[posicion].apellido << endl;
        cout << "Sucursal: " << vendedores[posicion].sucursal << endl;
        cout << "Cantidad de Ventas: " << vendedores[posicion].cantVentas << endl;
        cout << "Bono: $" << vendedores[posicion].bono << endl;
    } else
    {
        cout << "El vendedor con el legajo " << legajoBuscado << " no esta registrado." << endl;
    }
}

int main () {
    const int MAX_ELEMENTOS = 1000;
    Vendedor vendedores[MAX_ELEMENTOS];
    int cantVend = 0;

    cargarVendedores(vendedores, cantVend);
    
    cout << "\n=== Listado de vendedores cargados ===" << endl;
    imprimir(vendedores, cantVend);

    burbujeoMejoradoDesc(vendedores, cantVend); 
    
    cout << "\n=== Listado de vendedores ordenado DESC x Legajo ===" << endl;
    imprimir(vendedores, cantVend);

    //ordeno pero asc para despues poder usar la busqu binaria
    burbujeoMejoradoAsc(vendedores, cantVend);

    analisisVendedorBuscado(vendedores, cantVend);
    
    return 0;
}