#include <iostream>
using namespace std;

struct atleta {
    string nombre;
    string pais;
    string disciplina;
    int medallas;
};

void imprime(atleta &a);

int main() {
    int n;
    string buscar;

    cout << "Ingrese la cantidad de atletas: " << endl;
    cin >> n;
    atleta atletas[n];

    for (int i = 0; i < n; i++) {
        cout << "Atleta #" << i + 1 << endl;
        cin.ignore();
        cout << "\tNombre: ";
        getline(cin, atletas[i].nombre);
        cout << "\tPais: ";
        getline(cin, atletas[i].pais);
        cout << "\tDisciplina: ";
        getline(cin, atletas[i].disciplina);
        cout << "\tNumero de medallas: ";
        cin >> atletas[i].medallas;
        cout << "\n";
    }

    cin.ignore();
    cout << "Ingrese el nombre del pais a buscar: ";
    getline(cin, buscar);

    int mayor = -1;
    int indiceMayor;
    bool existe = false;

    cout << "\nATLETAS DEL PAIS DE " << buscar << ":" << endl;

    for (int i = 0; i < n; i++) {
        if (atletas[i].pais == buscar) {
            imprime(atletas[i]);
            existe = true;
            if (atletas[i].medallas > mayor) {
                mayor = atletas[i].medallas;
                indiceMayor = i;
            }
        }
    }

    if (existe) {
        cout << "\nATLETA CON MAS MEDALLAS DE " << buscar << ":" << endl;
        imprime(atletas[indiceMayor]);
    } else {
        cout << "No se encontraron atletas de ese pais";
    }

    return 0;
}

void imprime(atleta &a) {
    cout << "\tNombre: " << a.nombre << endl;
    cout << "\tPais: " << a.pais << endl;
    cout << "\tDisciplina: " << a.disciplina << endl;
    cout << "\tMedallas: " << a.medallas << "\n" << endl;
}