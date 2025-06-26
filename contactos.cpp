#include<iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

void modificaContacto(contactoEmail &);

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
          
void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}