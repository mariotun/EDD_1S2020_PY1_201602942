#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

//#include "Opciones.cpp"

//#include "Structures/ListaDobleCircular.cpp"
//#include "Structures/Cola.cpp"
//#include "Structures/ArbolBinarioBusqueda.cpp"
#include "Structures/Matriz.cpp"
/*#include "Structures/ListaSimpleOrdenada.cpp"
#include "Structures/ListaDoble.cpp"

#include "json.hpp"
#include <unistd.h>*/


using namespace std;
//using json = nlohmann::json;

bool salir=false;
char opcion;
//void Leer_Json(string ruta);
//Opciones_Programa *op=new Opciones_Programa();
//string ruta;

   int x,y;
string letra;

int main(){

/*string cadena="raul";
int suma=0;
    for(int x=0;x<cadena.length();x++){B


        //cadena[x];
        suma=suma+cadena[x];
    }
    cout<<suma;*/

  
  Matrizz *mt=new Matrizz();
    mt->add(1,3,"m");
    mt->add(2,3,"a");
    mt->add(3,4,"r");
    mt->add(4,2,"i");
    mt->add(5,1,"o");
    mt->add(3,1,"g");
    mt->add(2,2,"u");
    mt->add(4,3,"a2");
    mt->add(2,4,"t");
    mt->add(2,5,"e");
    mt->Eliminar(4,3);
    mt->Eliminar(2,5);
    //mt->Eliminar(2,2);
    mt->Eliminar(2,3);
    mt->Eliminar(2,4);
    mt->Eliminar(5,1);
    //mt->Delete(4,3);

   // mt->Delete(2,5);
  //  mt->Delete(5,1);
    mt->Graficar();





   /* do{
        x=0;
        y=0;
        letra="";

        cout<<"\n\n----------> Creacion de una Matriz <----------\n\n";
        cout<<"     1.Insertar\n\n";
        cout<<"     2.Graficar\n\n";
        cout<<"     3.Salir\n\n";
        cin>>opcion;
        switch(opcion){

            case '1':
                cout<<"Posicion X: ";
                cin>>x;
                cout<<"\nPosicion Y: ";
                cin>>y;
                cout<<"\nDato: ";
                cin>>letra;
                mt->add(x,y,letra.c_str());

            break;

            case '2':
                mt->Graficar();
            break;

            case '3':
                salir=true;
            break;

            default:
                cout<<"\n!!!!!Opcion Incorrecta\n";
            break;
        }

        


    }while(salir!= true);*/
   

  /* do{

        cout<<"\n\n---------------> SCRABBLE++ <---------------\n";
        cout<<"|                                          |\n";
        cout<<"|     (1) Lectura de Archivo               |\n";
        cout<<"|                                          |\n";
        cout<<"|     (2) Ingresar Jugadores               |\n";
        cout<<"|                                          |\n";
        cout<<"|     (3) Jugar                            |\n";
        cout<<"|                                          |\n";
        cout<<"|     (4) Reportes                         |\n";
        cout<<"|                                          |\n";
        cout<<"|     (5) Salir                            |\n";
        cout<<"|                                          |\n";
        cout<<"--------------------------------------------\n";
        cout<<"Elija una opcion:";
        cin>>opcion;

        switch (opcion){

        case '1':
            //cout<<"\nEscrita la ruta del archivo: ";
            //cin>>ruta;
            op->opcion_uno();
            //Leer_Json(ruta);
           
            break;
        
        case '2':
            op->opcion_dos();
            break;

        case '3':
            cout<<"tres\n";
            //try{
            op->opcion_tres();
            //}catch(int e){ cout<<"\nError al elegir!!\n"<<e;}
            break;

        case '4':
            cout<<"cuatro\n";
            op->opcion_cuatro();
            break;

        case '5':
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

/*
void Leer_Json(string ruta){

 json j2;
 //string filename = "C:/Users/HP/Desktop/EDD/Proyecto1/entrada.json";
 string filename=ruta;
 int dimension;
 int x,y;

 ifstream reader(filename);
  if (reader.fail()){
        cout << "El archivo no existe, verifique que la ruta y el archivo exista." << endl << endl;
    }else{
        
     reader>>j2;


    //for (int i = 0; i < j2.size(); i++){ //INICION DE J2

        dimension = j2["dimension"];
        cout<<"\n\nDimensioM:"<<dimension<<endl;

        json casillas=j2["casillas"];
        
        //for (int j = 0; j < casillas.size(); j++){ //INICIO DE CASILLAS
            
           // cout<<"casillas: "<<j<<endl;
            json dobles=casillas["dobles"];
            for (int y = 0; y < dobles.size(); y++){
                json coordenadas1=dobles[y];
                cout<<coordenadas1["x"]<<" , "<<coordenadas1["y"]<<endl;
            }
            

            json triples=casillas["triples"];
            for (int x = 0; x < triples.size(); x++){
                json coordenadas2=triples[x];
                cout<<coordenadas2["x"]<<" , "<<coordenadas2["y"]<<endl;
            }
        

            json diccionario=j2["diccionario"];
            //json palabra=diccionario["palabra"];
            for(int p=0 ; p<diccionario.size();p++){
                json palabra=diccionario[p];
                cout<<"palabra: "<<palabra["palabra"]<<endl;
               
            }

            
       // } //FIN DE CASILLAS
        
 
        
    } //FIN DE J2
    


    //} //FIN DEL ELSE


        reader.close();



}
*/
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




 /* Arbol_Binario_Busqueda *abb=new Arbol_Binario_Busqueda();
    abb->Agregar(new NodoArbol("mario"));
    abb->Agregar(new NodoArbol("alejandra"));
    abb->Agregar(new NodoArbol("nicolas"));
    abb->Agregar(new NodoArbol("carlos"));
    abb->Agregar(new NodoArbol("zaina"));
    abb->Agregar(new NodoArbol("xiomara"));
    abb->Agregar(new NodoArbol("raul"));
    cout<<"\nRespuesta: "<<abb->recorrer("xiomar");
    cout<<"\nRespuesta: "<<abb->recorrer("carlo");
    cout<<"\nRespuesta: "<<abb->recorrer("zain");
    //abb->Graficar();
    abb->graph_inorder();
    abb->graph_preorder();
    abb->graph_posorder();*/


    /*  Cola *cl=new Cola();
    cl->Insertar(new NodoCola("M",5));
    cl->Insertar(new NodoCola("F",2));
    cl->Insertar(new NodoCola("S",3));
    cl->Insertar(new NodoCola("Q",4));
    cout<<"f:"<<cl->Eliminar()<<endl;
    cout<<"f:"<<cl->Eliminar()<<endl;
    cout<<"f:"<<cl->Eliminar()<<endl;
    cout<<"f:"<<cl->Eliminar()<<endl;
    cout<<"f:"<<cl->Eliminar()<<endl;
    cl->Graficar();*/
    

   /*Lista_Doble_Circular *lcd=new Lista_Doble_Circular();
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

        /*Lista_Doble *ld=new Lista_Doble();
    ld->Insertar(new NodoLD("r"));
    ld->Insertar(new NodoLD("h"));
    ld->Insertar(new NodoLD("p"));
    ld->Insertar(new NodoLD("a"));
    ld->Insertar(new NodoLD("k"));
    ld->Insertar(new NodoLD("o"));
    ld->Insertar(new NodoLD("m"));
    ld->Insertar(new NodoLD("s"));
    ld->Insertar(new NodoLD("e"));
    ld->Insertar(new NodoLD("j"));
    ld->Insertar(new NodoLD("o"));
    ld->Insertar(new NodoLD("b"));
    ld->Graficar();*/

  /*Lista_Simple_Ordenada *lso=new Lista_Simple_Ordenada(1);
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
    lso2->GraficarP(2);*/