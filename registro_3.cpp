#include <iostream>
using namespace std;

struct persona {
    string nom;
    int fn[3];
};

int main (){
    int n, aux=0, mes=1;
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