#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
//#include <json/json.h>
#include "Structures/ListaDobleCircular.cpp"
#include "Structures/Cola.cpp"

using namespace std;

bool salir=false;
char opcion;
void Leer_Json(string ruta);

int main(){

    Cola *cl=new Cola();
    cl->Insertar(new NodoCola("M",5));
    cl->Insertar(new NodoCola("F",2));
    cl->Insertar(new NodoCola("S",3));
    cl->Insertar(new NodoCola("Q",4));
    cl->Insertar(new NodoCola("L",8));
    cl->Insertar(new NodoCola("Y",1));
    cl->Insertar(new NodoCola("T",6));
    cl->Insertar(new NodoCola("P",6));
    cl->Insertar(new NodoCola("R",6));
    cl->Eliminar();
    cl->Eliminar();
    cl->Graficar();
    

   /* Lista_Doble_Circular *lcd=new Lista_Doble_Circular();
     lcd->Insertar(new NodoLCD("mario"));
     lcd->Insertar(new NodoLCD("guate"));
     lcd->Insertar(new NodoLCD("comida"));
     lcd->Insertar(new NodoLCD("luz"));
     lcd->Insertar(new NodoLCD("mundo"));
     lcd->Insertar(new NodoLCD("edd"));
     lcd->Insertar(new NodoLCD("osos"));
     lcd->Graficar();


     lcd->Mostrar();
     cout<<"* "+lcd->Buscar("hola");
     cout<<"* "+lcd->Buscar("sandy");
     cout<<"* "+lcd->Buscar("edd");
     cout<<"* "+lcd->Buscar("luz");


      if(lcd->Buscar("sandy")==false){
         cout<<"FALSE";
     }*/

     

    

  /*  do{

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

    exit(1);*/

    return 0;
}


void Leer_Json(string ruta){







}