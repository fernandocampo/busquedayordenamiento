/*
8. Facturación de Vendedores (PUP) Una empresa cuenta con 20 vendedores numerados
del 1 al 20. Se ingresan las ventas realizadas indicando el ID del vendedor y el importe,
finalizando la carga al ingresar el ID 0. Con esta información se debe:
●​ Mostrar un listado con la facturación total de cada uno de los 20 vendedores.
●​ Informar el número del vendedor que logró la mayor facturación acumulada.
*/

// si bien dice 20 , hacerlo de 1 a 4 para simplificar la carga

#include <iostream>
using namespace std;


void cargarVentas(float vTotales[]) {
    int idVendedor;
    float importe;

    do {
        cout << "Ingresar el ID del vendedor (1 a 4, o 0 para terminar): ";
        cin >> idVendedor;

        if (idVendedor != 0) {
            cout << "Ingresar el importe de la venta: ";
            cin >> importe;

            vTotales[idVendedor] += importe;
        }

    } while (idVendedor != 0);
}


void mostrarFacturacion(float vTotales[]) {
    cout << "\n--- FACTURACIÓN TOTAL DE VENDEDORES ---" << endl;
    for (int i = 1; i <= 4; i++) {
        cout << "Vendedor " << i << " - Facturacion Total: $" << vTotales[i] << endl;
    }
}


void mejorVendedor(float vTotales[]) {

    float maximoImporte = vTotales[1];
    int idMejorVendedor = 1;

    for (int i = 2; i <= 4; i++) {
        
        if (vTotales[i] > maximoImporte) {
            maximoImporte = vTotales[i];
            idMejorVendedor = i;
        }
    }

    cout << "El vendedor con mayor facturacion acumulada es el ID: " << idMejorVendedor << endl;
    cout << "Con un total de: $" << maximoImporte << endl;
}


int main () {

    float facturacionVendedores[5] = {0}; 

    cargarVentas(facturacionVendedores);
    
    mostrarFacturacion(facturacionVendedores);
    mejorVendedor(facturacionVendedores);
    
    return 0;
}