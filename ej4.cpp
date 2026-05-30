/*
4. Control de Ventas Mensuales (PUP) Una empresa registra ventas durante los 31 días
de un mes. Por cada venta se ingresa el día (1 a 31) y el importe recaudado. Utilizando un
vector de 31 posiciones para acumular los datos según el día correspondiente, se solicita:
●​ Informar el total acumulado por cada jornada del mes.
●​ Indicar qué número de día registró la mayor venta.
●​ Listar los números de días que no registraron ninguna venta (aquellos que quedaron
en cero)
*/

#include <iostream>
using namespace std;

void cargarVentas(float ventas[]) {
    int dia;
    float vta = 0;

    cout << "=== Ingresa las ventas ===" << endl;
    for(int i = 0; i < 31; i++) {
        cout << "Dia (1 a 31): ";
        cin >> dia;
        cout << "Venta: $";
        cin >> vta;
        
        ventas[dia - 1] = ventas[dia - 1] + vta; 
    }
}
void informarTotales(float ventas[]) {
    cout << "\n--- TOTALES ACUMULADOS POR JORNADA ---" << endl;
    for (int i = 0; i < 31; i++) {
        cout << "Dia " << i + 1 << ": $" << ventas[i] << endl;
    }
}

void calcularMayorVenta(float ventas[], int& diaMayor, float& mayorImporte) {
    mayorImporte = ventas[0];
    diaMayor = 1;

    for (int i = 1; i < 31; i++) {
        if (ventas[i] > mayorImporte) {
            mayorImporte = ventas[i];
            diaMayor = i + 1;
        }
    }

    cout << "EL dia con mayor venta fue el dia " << diaMayor << " ($" << mayorImporte << ")" << endl;
}

void diasConCeroVentas (float ventas[]) {

    for (int i = 0; i < 31; i++)
    {
        if (ventas[i] == 0)
        {
            cout << "Dia con cero ventas " << i+1 << endl;
        }
        
    }
}

int main () {
    float ventas[31] = {0};
    int diaMayor;
    float mayorImporte;

    cargarVentas(ventas);
    informarTotales(ventas);
    calcularMayorVenta(ventas,diaMayor, mayorImporte);;
    diasConCeroVentas(ventas);

    return 0;
}