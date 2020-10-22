#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int clave, opcion, Bclave;
    char nombre[30];
    ofstream Guardar;
    ifstream Leer;
    Guardar.open("Fichero.txt",ios::app);
    while(true){

        cout << "1. Guardar Registro" << endl;
        cout << "2. Leer Registro" << endl;
        cout << "3. Buscar Registro" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese un nombre" << endl;
                cin >> nombre;
                cout << "Ingrese Clave" << endl;
                cin >> clave;
                Guardar << nombre << " " << clave << endl;
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

            }
        }

    }
    return 0;
}









