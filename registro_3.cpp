#include <iostream>
using namespace std;

struct persona {
    string nom;
    int fn[3];
};

int comprobar(int, int, int);

int main (){
    int n, aux, mes;
    cout << "Ingrese la cantidad de personas:" << endl;
    cin >> n;
    persona lista[n];

    for (int i=0; i<n; i++){
        cout << "Persona #" << i+1 << ": " << endl;
        cout << "Ingrese el nombre: ";
        cin.ignore();
        getline(cin,lista[i].nom);
        cout << "Ingresa la fecha de nacimiento (dd mm aaaa): ";
        cin >> lista[i].fn[0] >> lista[i].fn[1] >> lista[i].fn[2];
        aux = comprobar(lista[i].fn[0], lista[i].fn[1], lista[i].fn[2]);
        while (aux == 0){
            cout << "FECHA INVALIDA" << endl << "Ingrese nuevamente la fecha (dd mm aaaa): ";
            cin >> lista[i].fn[0] >> lista[i].fn[1] >> lista[i].fn[2];
            aux = comprobar(lista[i].fn[0], lista[i].fn[1], lista[i].fn[2]);
        }
        cout << "\n";
    }
    
    do{
        cout <<"Ingrese un mes:" << endl;
        cin >> mes;
        if (mes>0){
            aux=0;
            cout << "Personas que celebran su cumpleanos ese mes:" << endl;
            for (int i=0; i<n; i++){
                if (mes == lista[i].fn[1]) {
                    cout << "\t" << lista[i].nom << endl;
                    aux=1;
                }
            }
            if (aux==0){
                cout << "\tNINGUNA" << endl;
            }
        } 
    } while (mes>0);

    cout << "FIN DEL PROGRAMA";
    return 0;
}

int comprobar(int d, int m, int a){
    int aux = 0;
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (d>0 && d<=31 && a>0 && a<2026){
                aux = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (d>0 && d<=30 && a>0 && a<2026){
                aux = 1;
            }
            break;
        case 2:
            if (a>0 && a<2026 && ((d>0 && d<=28) || (d == 29 && ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))))){
                aux = 1;
            }
            break;
        default:
            aux = 0;
            break;
    }
    return aux;
}