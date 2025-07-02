#include<iostream>
using namespace std;
#include "contactos.h"
#include "imprime_modifica.h"

int main(){
    int n, op;
    char salir;
    string nom, user, domain;
    char sex;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;

    int modificar;

    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Modificar un contacto"<<endl;
        cout<<"3. Mostrar contactos"<<endl;
        cout<<"0. Salir"<<endl;
        cout<< endl;
        cout<<"Elige una opcion: "; cin>>op;
        cout<<endl;

        switch(op){
            case 1:
                cout<<"Ingrese los datos de un usuario:"<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio):"<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);

                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i+1<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                cout<<"QUE CONTACTO DESEA MODIFICAR?: "; cin >> modificar;
                modificaContacto(lista[modificar-1]);
                break;
            case 3:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i+1<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 0:
                cout<<"Esta seguro de salir? (S/N): "; cin >> salir;
                if (salir == 'N'){
                    op = 3;
                }
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);

    return 0;
}