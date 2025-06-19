#include <iostream>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12], salario;
};

int main(){
    EMP EMPLEADOS[100];
    int n, num_mayor;
    float aux;
    string nom_mayor;

    cout << "Ingrese el numero de empleados:" << endl;
    cin >> n;
    float suma[n];

    for (int i = 0; i < n; i++){
        cout << "Numero del empleado: ";
        cin >> EMPLEADOS[i].num;
        cout << "Ingrese el nombre del empleado: ";
        cin >> EMPLEADOS[i].nom;
        for (int j = 0; j < 12; j++){
            cout << "Venta del Mes Nro " << j + 1 << ": ";
            cin >> EMPLEADOS[i].ven[j];
            suma[i] = suma[i] + EMPLEADOS[i].ven[j];
        }
        cout << "Ingrese el salario bruto de este empleado: ";
        cin >> EMPLEADOS[i].salario;
        cout << "\n";
    }
    
    aux = suma[0];
    for (int i=0; i<n; i++){
        if (suma[i] >= aux){
            aux = suma[i];
            num_mayor = i+1;
            nom_mayor = EMPLEADOS[i].nom;
        }
    }

    for (int i=0; i<n; i++){
        if (suma[i] > 100) {
            EMPLEADOS[i].salario = EMPLEADOS[i].salario * 110/100;
        }
    }

    cout << "LISTA COMPLETA:" << endl;
    for (int i = 0; i < n; i++){
        cout << "Empleado Nro: " << EMPLEADOS[i].num << endl;
        cout << EMPLEADOS[i].nom << endl;
        cout << "Salario Neto: " << EMPLEADOS[i].salario << endl;
        cout << "\n";
    }

    cout << "EMPLEADO CON MAYORES VENTAS A NIVEL ANUAL:" << endl;
    cout << "Numero: " << num_mayor << endl;
    cout << "Nombre: " << nom_mayor << endl << "\n";

    cout << "EMPLEADOS CON VENTAS INFERIORES A 30 UNIDADES EN DICIEMBRE:" << endl;
    for (int i=0; i<n; i++){
        if (EMPLEADOS[i].ven[11] < 30) {
            cout << "Empleado Nro: " << EMPLEADOS[i].num << endl;
            cout << EMPLEADOS[i].nom << endl << "\n";
        }
    }

    return 0;
}