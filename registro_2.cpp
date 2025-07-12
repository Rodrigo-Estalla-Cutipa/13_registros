#include <iostream>
using namespace std;

struct persona{
    string nombre;
    int DNI;
    int edad;
};

void imprime (persona &c);

int main(){
    int n, aux=0;
    float s;

    cout << "Ingrese la cantidad de personas:" << endl;
    cin >> n;
    persona pers[n];
    
    for(int i=0; i<n; i++){
        cout << "Persona #" << i+1 << endl;
        cin.ignore();
        cout << "Ingrese el nombre: ";
        getline(cin,pers[i].nombre);
        cout << "Ingrese el DNI: ";
        cin >> pers[i].DNI;
        cout << "Ingrese la edad: ";
        cin >> pers[i].edad;
        cout << "\n";
    }

    for(int i=0; i<n; i++){
        if (50 < pers[i].edad){
            aux++;
        }
        s = s + pers[i].edad;
    }

    cout << "Cantidad de personas mayores de 50: " << aux << endl;
    cout << "Promedio de edades: " << s/n << endl;
    cout << "Personas Ingresadas:" << endl;
    for (int i=0; i<n; i++){
        cout << "Persona #" << i+1 << endl;
        imprime (pers[i]);
    }
    return 0;
}

void imprime (persona &c){
    cout << "\tNombre: " << c.nombre << endl;
    cout << "\tDNI: " << c.DNI << endl;
    cout << "\tEdad: " << c.edad << endl;
}