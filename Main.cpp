#include <iostream>
#include <string>

using namespace std;

bool salir=false;
char opcion;

int main(){
    

    do{

        cout<<"\n\n---------------> SCRABBLE++ <---------------\n";
        cout<<"|                                          |\n";
        cout<<"|     (1)Lectura de Archivo                |\n";
        cout<<"|                                          |\n";
        cout<<"|     (2)Juego                             |\n";
        cout<<"|                                          |\n";
        cout<<"|     (3)Reportes                          |\n";
        cout<<"|                                          |\n";
        cout<<"|     (4)Salir                             |\n";
        cout<<"|                                          |\n";
        cout<<"--------------------------------------------\n";
         cout<<"Elija una opcion:";
        cin>>opcion;

        switch (opcion){

        case '1':
            cout<<"uno\n";

            break;

        case '2':
            cout<<"dos\n";

            break;

        case '3':
            cout<<"tres\n";
            break;

        case '4':
            cout<<"salir\n";
            salir=true;

            break;

        
        default:
            cout<<"Opcion Incorrecta!!!!\n";
            break;
        }



    
    
    }while(salir!= true);

    exit(1);

    return 0;
}