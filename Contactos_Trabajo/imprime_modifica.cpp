#include <iostream>
using namespace std;
#include "imprime_modifica.h"

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}

void modificaContacto(contactoEmail &cambio){
    string n, user, domain;
    char s;
    int e;
    correo email;

    n = cambio.nom;
    s = cambio.sex;
    e = cambio.edad;

    email = cambio.email;
    user = email.user;
    domain = email.domain;

    char aux;

    cout << "Modificar nombre? (S/N): ";
    cin >> aux;
    if (aux == 'S'){
        cin.ignore();
        cout << "\tIngrese nombre: ";
        getline(cin,n);
    }
    cout << "Modificar sexo? (S/N): ";
    cin >> aux;
    if (aux == 'S'){
        cout << "\tIngrese sexo (M/F): ";
        cin >> s;
    }
    cout << "Modificar edad? (S/N): ";
    cin >> aux;
    if (aux == 'S'){
        cout << "\tIngrese edad: ";
        cin >> e;
    }
    cout << "Modificar correo? (S/N): ";
    cin >> aux;
    if (aux == 'S'){
        cout<<"Ingrese el correo electronico (usuario@dominio):"<<endl;
        cout<<"\tIngrese el usuario: "; cin>>user;
        cout<<"\tIngrese el dominio: "; cin>>domain;
    }

    leerCorreo(email,user,domain);
    leerContacto(cambio,n,s,e,email);

    cout << endl << "HA INGRESADO LA SIGUIENTE INFORMACION:" << endl;
    imprimeContacto(cambio);
    cout << endl << "Es correcta esta informacion? (S/N): ";
    cin >> aux;
    if (aux == 'N') {
        modificaContacto(cambio);
    } else {
        system("pause");
    }
}