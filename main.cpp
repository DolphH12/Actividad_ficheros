#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    //Este es el primer taller de ficheros
    int clave, opcion, Bclave, Nclave;
    char nombre[30];
    ofstream Guardar;
    ifstream Leer;
    ofstream Temp;
    Guardar.open("Fichero.txt",ios::app);
    while(true){

        cout << "1. Guardar Registro" << endl;
        cout << "2. Leer Registros" << endl;
        cout << "3. Buscar Registro" << endl;
        cout << "4. Eliminar Registro" << endl;
        cout << "5. Modificar Registro" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese un nombre" << endl;
                cin >> nombre;
                cout << "Ingrese Clave" << endl;
                cin >> clave;
                Guardar << nombre << " " << clave << endl;
                //_sleep(3500);
                system("CLS");
                break;
            }
            case 2: {
                Leer.open("Fichero.txt");
                Leer>>nombre;
                while (!Leer.eof()) {
                    Leer >> clave;
                    cout << "Nombre: " << nombre << endl;
                    cout << "Clave:  " << clave <<endl;
                    cout << endl;
                    Leer >> nombre;
                }
                Leer.close();
                //_sleep(3500);
                system("CLS");
                break;
            }
            case 3: {
                Leer.open("Fichero.txt");
                Leer>>nombre;
                bool encontrado = false;
                cout << "Ingrese clave a buscar"<<endl;
                cin >> Bclave;
                while (!Leer.eof()) {
                    Leer >> clave;
                    if(clave == Bclave){
                        encontrado = true;
                        cout << "Nombre: "<<nombre<<endl;
                        cout << "Clave:  "<<clave<<endl;
                        cout << endl;
                    }
                    Leer >> nombre;
                }
                if(!encontrado){
                    cout << "El registro no existe" << endl;
                }
                Leer.close();
                //_sleep(3500);
                system("CLS");
                break;

            }
            case 4: {
                Leer.open("Fichero.txt");
                Temp.open("Temp.txt");
                Leer>>nombre;
                bool encontrado = false;
                cout << "Ingrese clave a eliminar"<<endl;
                cin >> Bclave;
                while (!Leer.eof()) {
                    Leer >> clave;
                    if(clave == Bclave){
                        encontrado = true;
                        cout << "Nombre: "<<nombre<<endl;
                        cout << "Clave:  "<<clave<<endl;
                        cout << endl;
                        cout << "Eliminado"<<endl;
                    }else {
                        Temp << nombre <<" "<<clave<<endl;
                    }
                    Leer >> nombre;
                }
                if(!encontrado){
                    cout << "El registro no existe" << endl;
                }
                Leer.close();
                Temp.close();
                Guardar.close();
                remove("Fichero.txt");
                rename("Temp.txt", "Fichero.txt");
                Guardar.open("Fichero.txt",ios::app);
                //_sleep(3500);
                system("CLS");
                break;

            }
            case 5: {
                Leer.open("Fichero.txt");
                Temp.open("Temp.txt");
                Leer>>nombre;
                bool encontrado = false;
                cout << "Ingrese clave del registro a modificar"<<endl;
                cin >> Bclave;
                while (!Leer.eof()) {
                    Leer >> clave;
                    if(clave == Bclave){
                        encontrado = true;
                        cout << "Nombre: "<<nombre<<endl;
                        cout << "Clave:  "<<clave<<endl;
                        cout << endl;
                        cout << "Ingrese nueva Clave"<<endl;
                        cin >> Nclave;
                        Temp << nombre <<" "<<Nclave<<endl;
                        cout << "MODIFICADO" << endl;

                    }else {
                        Temp << nombre <<" "<<clave<<endl;
                    }
                    Leer >> nombre;
                }
                if(!encontrado){
                    cout << "El registro no existe" << endl;
                }
                Leer.close();
                Temp.close();
                Guardar.close();
                remove("Fichero.txt");
                rename("Temp.txt", "Fichero.txt");
                Guardar.open("Fichero.txt",ios::app);
                //_sleep(3500);
                system("CLS");
                break;

            }
        }

    }
    return 0;
}









