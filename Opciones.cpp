
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "Structures/ListaDobleCircular.cpp"
#include "Structures/Cola.cpp"
#include "Structures/ArbolBinarioBusqueda.cpp"
#include "Structures/Matriz.cpp"
//#include "Structures/ListaSimpleOrdenada.cpp"
//#include "Structures/ListaDoble.cpp"
#include "json.hpp"
#include <unistd.h>

using namespace std;
using json = nlohmann::json;


class Opciones_Programa{

    public:
        Opciones_Programa();
        void opcion_uno();
        void opcion_dos();
        void opcion_tres();
        void opcion_cuatro();
        string ruta;
        Lista_Doble_Circular *lcd;
        Arbol_Binario_Busqueda *abb;

        NodoArbol jugador1;
        NodoArbol jugador2;
        string nombre1;
        string nombre2;
}; 

Opciones_Programa::Opciones_Programa(){

    abb=new Arbol_Binario_Busqueda();
    lcd=new Lista_Doble_Circular();
 }

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_uno(){

    lcd=new Lista_Doble_Circular();

    cout<<"\nEscrita la ruta del archivo: ";
    cin>>ruta;

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
                lcd->Insertar(new NodoLCD(palabra["palabra"]));
               
            }

            
       // } //FIN DE CASILLAS
        
 
        
    } //FIN DE J2
    


    //} //FIN DEL ELSE


        reader.close();

}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_dos(){

    bool salida=false;
    char op;

        string nombre;
        //cout<<"Presione x para salir\n\n";
        cout<<" Ingrese el Nombre del Jugados: ";
        cin>>nombre;

        abb->Agregar(new NodoArbol(nombre.c_str()));



}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_tres(){

    jugador1=NULL;
    jugador2=NULL;
    nombre1="";
    nombre2="";
    
    cout<<">>>>>>>>>> Jugadores Dispobiles <<<<<<<<<<\n";
    cout<<"Escribe el Nombre de los 2 Jugadores para la partida:\n";
    abb->MostrarJugador();
    
    if(abb->recorrer()==0){

       juagador1=abb->ObtenerJugador();
        
    }else{ cout<<"\nUsuario escrito no esta en los mostrados anteriormente\n"; }






    


}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_cuatro(){


    bool salir=false;
    char opcion;

    do{
        cout<<"\n<--------------->[ REPORTES ]<--------------->\n\n";
        cout<<" [a] Diccionario de Palabras(LCD)\n";
        cout<<" [b] Fichas Disponibles en el Juego(COLA)\n";
        cout<<" [c] Usuarios Registrados(ARBOL)\n";
        cout<<" [d] Recorrido Inorden de Usuarios\n";
        cout<<" [e] Recorrido Preorden de Usuarios\n";
        cout<<" [f] Recorrido Posorden de Usuarios\n";
        cout<<" [g] Scoreboard  General del Juego(LSO)\n";
        cout<<" [h] Tablero del Juego(MATRIZ)\n";
        cout<<" [i] Scoreboard por Jugador(LSO)\n";
        cout<<" [j] Fichas por Jugador(LD)\n";
        cout<<" [k] Salir\n";
        cout<<"-----------------------------------------------\n";
        cout<<"Elija una opcion: ";
        cin>>opcion;

        switch (opcion){
        case 'a':
            cout<<"a\n";
            lcd->Graficar();
            break;

        case 'b':
            cout<<"b\n";
            break;

        case 'c':
            cout<<"c\n";
            abb->Graficar();
            break;

        case 'd':
            cout<<"d\n";
            break;

        case 'e':
            cout<<"e\n";
            break;

        case 'f':
            cout<<"f\n";
            break;
        
        case 'g':
            cout<<"g\n";
            break;

        case 'h':
            cout<<"h\n";
            break;

        case 'i':
            cout<<"i\n";
            break;

        case 'j':
            cout<<"j\n";
            break;

        case 'k':
            salir=true;
            break;


        default:
            cout<<"Opcion Incorrecta!!!!\n";
            break;
        }




    }while(salir!=true);




}

