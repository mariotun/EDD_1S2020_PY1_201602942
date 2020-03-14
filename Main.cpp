#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
//#include <json/json.h>
#include "Structures/ListaDobleCircular.cpp"
#include "Structures/Cola.cpp"
#include "Structures/ArbolBinarioBusqueda.cpp"
#include "Structures/Matriz.cpp"
#include "Structures/ListaSimpleOrdenada.cpp"

using namespace std;

//bool salir=false;
//char op;
//void Leer_Json(string ruta);

int main(int argc, char *argv[]){


/*string cadena="raul";
int suma=0;
    for(int x=0;x<cadena.length();x++){

        //cadena[x];
        suma=suma+cadena[x];
    }
    cout<<suma;*/

    Lista_Simple_Ordenada *lso=new Lista_Simple_Ordenada(1);
    Lista_Simple_Ordenada *lso2=new Lista_Simple_Ordenada(2);
    
    lso->Insertar(new NodoLSO(3));
    lso->Insertar(new NodoLSO(4));
    lso->Insertar(new NodoLSO(1));
    lso->Insertar(new NodoLSO(7));
    lso->Insertar(new NodoLSO(8));
    lso->Insertar(new NodoLSO(2));
    lso->Insertar(new NodoLSO(10));
    lso->GraficarP(1);
    
    lso2->Insertar(new NodoLSO("mario",30));
    lso2->Insertar(new NodoLSO("raul",40));
    lso2->Insertar(new NodoLSO("sofia",10));
    lso2->Insertar(new NodoLSO("nico",70));
    lso2->Insertar(new NodoLSO("alejandra",80));
    lso2->Insertar(new NodoLSO("daniel",20));
    lso2->Insertar(new NodoLSO("carla",10));
    lso2->GraficarP(2);






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

  /*Matrizz *mt=new Matrizz();
    mt->add(1,3,"m");
    mt->add(2,3,"a");
    mt->add(3,3,"r");
    mt->add(4,3,"i");
    mt->add(5,3,"o");
    mt->add(2,1,"g");
    mt->add(2,2,"u");
    mt->add(2,3,"a");
    mt->add(2,4,"t");
    mt->add(2,5,"e");
    mt->add(5,2,"c");
    mt->add(5,3,"o");
    mt->add(5,4,"m");
    mt->add(5,5,"i");
    mt->add(5,6,"d");
    mt->add(5,7,"a");
    mt->add(2,5,"jajaj");
    mt->add(3,5,"m");
    mt->add(4,5,"p");
    mt->add(5,5,"i");
    mt->add(6,5,"r");
    mt->add(7,5,"e");
    mt->add(7,1,"s");
    mt->add(7,2,"o");
    mt->add(7,3,"l");
    mt->Graficar();*/



    /*Arbol_Binario_Busqueda *abb=new Arbol_Binario_Busqueda();
    abb->Agregar(new NodoArbol("mario"));
    abb->Agregar(new NodoArbol("alejandra"));
    abb->Agregar(new NodoArbol("nicolas"));
    abb->Agregar(new NodoArbol("carlos"));
    abb->Agregar(new NodoArbol("zaina"));
    abb->Agregar(new NodoArbol("xiomara"));
    abb->Agregar(new NodoArbol("raul"));
    abb->Graficar();*/


    /*Cola *cl=new Cola();
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
    cl->Graficar();*/
    

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