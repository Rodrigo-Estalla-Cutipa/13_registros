#include <iostream>
using namespace std;

struct EMP
{
    int num;
    string nom;
    float ven[12], salario;
};

int main()
{
    EMP EMPLEADOS[100];
    int n;

    cout << "Ingrese el numero de empleados:" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Numero del empleado: ";
        cin >> EMPLEADOS[i].num;
        cout << "Ingrese el nombre del empleado: ";
        cin >> EMPLEADOS[i].nom;
        for (int j = 0; j < 12; j++)
        {
            cout << "Venta Nro " << j + 1 << ": ";
            cin >> EMPLEADOS[i].ven[j];
        }
        cout << "Ingrese el salario bruto de este empleado: ";
        cin >> EMPLEADOS[i].salario;
        cout << "\n";
    }

    cout << "LISTA COMPLETA:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Numero del empleado: " << EMPLEADOS[i].num << endl;
        cout << EMPLEADOS[i].nom << endl;
        for (int j = 0; j < 12; j++)
        {
            cout << "Venta Nro " << j + 1 << ": " << EMPLEADOS[i].ven[j] << endl;
        }
        cout << "Salario Neto: " << EMPLEADOS[i].salario << endl;
        cout << "\n";
    }

    return 0;
}