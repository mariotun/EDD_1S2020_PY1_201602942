#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "Opciones.cpp"
//#include"LPosEspeciales.cpp"
//#include "Structures/ListaDobleCircular.cpp"
//#include "Structures/Cola.cpp"
//#include "Structures/ArbolBinarioBusqueda.cpp"
//#include "Structures/Matriz.cpp"
/*#include "Structures/ListaSimpleOrdenada.cpp"
#include "Structures/ListaDoble.cpp"

#include "json.hpp"
#include <unistd.h>*/


using namespace std;
//using json = nlohmann::json;

bool salir=false;
bool salir2=false;

char opcion;
char opcion2;
char letra;
//void Leer_Json(string ruta);
Opciones_Programa *op=new Opciones_Programa();
//string ruta;

string x,y;



int main(){

    /*Matrizz *mt=new Matrizz();
    mt->add(1,3,"m");
    mt->add(2,3,"a");
    mt->add(6,7,"r","purple");
    mt->add(8,2,"i");
    mt->add(0,0,"X","white");
    mt->add(0,8,"y","white");
    mt->add(3,0,"z","white");
    mt->add(5,1,"o","green2");
    mt->add(6,1,"g");
    mt->Graficar();*/

    

   do{

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

    exit(1);

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
    mt->add(6,7,"r");
    mt->add(8,2,"i");
    mt->add(5,1,"o");
    mt->add(6,1,"g");
    mt->add(2,2,"u");
    mt->add(8,3,"a2");
    mt->add(2,7,"t");
    mt->add(2,10,"e");
    mt->add(3,4,"z");
    mt->add(4,5,"x");
    mt->add(9,11,"bb");
    mt->add(10,6,"uu");

    mt->Eliminar(2,2);
    mt->Eliminar(2,7);
    mt->Eliminar(8,3);
    mt->Eliminar(1,3);
    mt->Eliminar(3,4);
    mt->Eliminar(10,6);
    mt->Eliminar(6,7);
    mt->Eliminar(9,11);
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


    /*Cola *cl=new Cola();
    cl->Insertar(new NodoCola("M",5));
    cl->Insertar(new NodoCola("F",2));
    cl->Insertar(new NodoCola("S",3));
    cl->Insertar(new NodoCola("Q",4));
    cl->Insertar(new NodoCola("h",4));
    
    NodoCola *elim=cl->Eliminar();
    NodoCola *elim2=cl->Eliminar();
    
    cout<<"ficha:"<<elim->ficha<<" ,pts:"<<elim->puntos<<endl;
    cout<<"ficha:"<<elim2->ficha<<" ,pts:"<<elim2->puntos<<endl;
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

    /*string cadena="raul";
int suma=0;
    for(int x=0;x<cadena.length();x++){B


        //cadena[x];
        suma=suma+cadena[x];
    }
    cout<<suma;*/

/*Matrizz *mt=new Matrizz();

while(salir2!=true){

    opcion2;
    cout<<"\n1.-Salir Del Juego\n";
    cout<<"\n2.-Iniciar Turno\n";
    cin>>opcion2;

    switch(opcion2){

        case '1':
            salir2=true;
        break;

        case '2':

    do{
        //x=0;
        //y=0;
        
        bool xb=true,yb=true,lb=true;
        salir=false;
        string lt;
        opcion;
        letra;

        cout<<"\n\n----------> Creacion de una Matriz <----------\n\n";
        cout<<"     1.Insertar\n\n";
        cout<<"     2.Graficar\n\n";
        cout<<"     3.Validar y Terminar Turno\n\n";
        cin>>opcion;
        switch(opcion){

            case '1':
                cout<<"Posicion X: ";
                cin>>x;
                cout<<"\nPosicion Y: ";
                cin>>y;
                cout<<"\nDato: "; 
                cin>>letra;

                cout<<"------>letra:"<<letra<<endl;

                 for(int i=0;i<x.length();i++){

                    if( !( (x[i]>=48 && x[i]<=57) ) ){
                        cout<<"x malo\n";
                        xb=false;
                    }

                }

                for(int i=0;i<y.length();i++){

                    if( !( (y[i]>=48 && y[i]<=57) ) ){
                        cout<<"y malo\n";
                        yb=false;
                    }

                }
                cout<<"------>letra:"<<letra<<endl;
               
                    if(  !( (letra>=65 && letra<=90) || (letra>=97 && letra<=122) )  ){
                        cout<<"letra malo\n";
                        lb=false;
                    }

                //cout<<xb<<" , "<<yb<<" , "<<lb<<endl;
                cout<<"------>letra:"<<letra<<endl;
                
                if(xb==true && yb==true && lb==true){
                    mt->add(stoi(x),stoi(y),lt+letra);
                    cout<<"se ingreso\n";

                }else{
                    cout<<"no se ingreso\n";    
                }
                
                cout<<"------>letra:"<<letra<<endl;

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

        


    }while(salir!= true);

        break;

        default:
        cout<<"\nERROR al elegir la opcion\n";
        break;

        }//cierre del switch
        
    }*/