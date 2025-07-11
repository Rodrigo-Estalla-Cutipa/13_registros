#include <iostream>
using namespace std;

struct empleado{
    string nombre;
    char sexo;
    float sueldo;
};

void imprime (empleado &c);

int main(){
    int n;
    float aux;
    empleado max, min;

    cout << "Ingrese la cantidad de trabajadores:" << endl;
    cin >> n;
    empleado pers[n];
    
    for(int i=0; i<n; i++){
        cout << "Empleado #" << i+1 << endl;
        cin.ignore();
        cout << "Ingrese el nombre: ";
        getline(cin,pers[i].nombre);
        cout << "Ingrese el sexo (M/F): ";
        cin >> pers[i].sexo;
        cout << "Ingrese sueldo: ";
        cin >> pers[i].sueldo;
        cout << "\n";
    }

    aux = pers[0].sueldo;
    for(int i=0; i<n; i++){
        if (aux < pers[i].sueldo){
            max = pers[i];
            aux = pers[i].sueldo;
        }
    }
    aux = pers[0].sueldo;
    for(int i=0; i<n; i++){
        if (aux > pers[i].sueldo){
            min = pers[i];
            aux = pers[i].sueldo;
        }
    }

    cout << "Empleado de MAYOR sueldo:" << endl;
    imprime (max);
    cout << "\n";
    cout << "Empleado de MENOR sueldo:" << endl;
    imprime (min);
    return 0;
}

void imprime (empleado &c){
    cout << "\tNombre: " << c.nombre << endl;
    cout << "\tSexo: " << c.sexo << endl;
    cout << "\tSueldo: " << c.sueldo << endl;
}