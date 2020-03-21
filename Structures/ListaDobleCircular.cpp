
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>//para abrir con comandos

#include <stdbool.h>
#include <fstream>
#include <sstream>

using namespace std;

class NodoLCD{

    public:
        string palabra;
        NodoLCD *next;
        NodoLCD *back;
        NodoLCD();
        NodoLCD(string palabra);

};

NodoLCD::NodoLCD(){

}

NodoLCD::NodoLCD(string palabra){

    this->palabra=palabra;
}

//*******************************************************************************************

class Lista_Doble_Circular{

    public:

        NodoLCD *first;
        NodoLCD *last;

        void Insertar(NodoLCD *palabra);
        bool Buscar(string palabra);
        void Mostrar();
        string ArchivoGrafica();
        void Graficar();

        Lista_Doble_Circular();

};

Lista_Doble_Circular::Lista_Doble_Circular(){
    
    this->first=NULL;
    this->last=NULL;

}

void Lista_Doble_Circular::Insertar(NodoLCD *palabra){

    if(first==NULL){
        first=palabra;
        first->next=NULL;
        first->back=NULL;
        last=first;
    }else{
        last->next=palabra;
        palabra->next=NULL;
        palabra->back=last;
        last=palabra;
       // palabra->next=first;
        }
}

void Lista_Doble_Circular::Mostrar(){

    NodoLCD *actual=new NodoLCD();
    actual=first;

    if(first!=NULL){

        while(actual!=NULL){
        cout<<"[ "<<actual->palabra<<" ]"<<"-->";
        actual=actual->next;
        }

    }else{
       // cout<<"La lista doble se encuentra vacia"<<endl;

    }

}

bool Lista_Doble_Circular::Buscar(string palabra){

    NodoLCD *actual=new NodoLCD();
    actual=first;
    bool encontrado=false;
    
    if(first!=NULL){

        while (actual!=NULL && encontrado!=true){

            if(actual->palabra==palabra){
              // cout<<"se encontro el dato: "<<actual->palabra;
               return encontrado=true; 
                
            }

            actual=actual->next;
        }

        if(!encontrado){
           // cout<<"El nodo no se encontro en la lista doble circular"<<endl;
         return encontrado;
        }
       
    }else{
        cout<<"La lista dodle circular se encuetra vacia"<<endl;

    }

   // return encontrado;
}


string Lista_Doble_Circular::ArchivoGrafica(){

    string cadena;
    NodoLCD *temporal=first;
    NodoLCD *actual=first;
    NodoLCD *uno=first;

    cadena+="digraph Lista_Doble{\n\n";
    cadena+="graph[ranksep= \"0.5\",nodesep= \"0.5\"];\n";
    cadena+="node[fontcolor=black shape=box style=filled fillcolor=deepskyblue3 fontsize=20];\n\n";
    cadena+="subgraph cluster_1 {\n\n";
    cadena+="fontname=algerian\n";
    cadena+="fontsize=25;\n";
    cadena+="label=\"Diccionario_de_Palabras\";\n";
    cadena+="fontcolor=black\n";
    cadena+="style=filled\n";
    cadena+="fillcolor=burlywood\n";
    cadena+="labelloc=t;";

    cadena+="{rank=same;\n";
    

    if(first!=NULL){

        while(temporal!=NULL){

            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temporal)))->str();
            cadena+="[label=\" ";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->palabra))->str();
            cadena+="\"];\n";

        temporal=temporal->next;
        }

    }else{
       // cout<<"La lista doble se encuentra vacia"<<endl;

    }

    cadena+="};\n\n";


        while(actual !=NULL){

          cadena+= static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(actual)))->str();

           if(actual->next != NULL)
          {

              cadena+="->\n";
          }

          actual=actual->next;

    }
    cadena+="[dir=both color=black];\n\n";
    //cadena+="->"+static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(uno)))->str();
    cadena+="\n"+static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(uno)))->str()+"->"+static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(last)))->str();;

    cadena+="\n";
    cadena+="[dir=both color=black];\n";
    cadena+="\n }\n\n}";

    return cadena;
}

void Lista_Doble_Circular::Graficar(){

   NodoLCD *aux=first;

   if(first!=NULL){

   FILE *fichero;

   fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/LCD_Diccionario.dot", "w");




   //fputs("digraph G {\ncolor=lightblue;\n", fichero);


   fputs(ArchivoGrafica().c_str(),fichero);
   fputs("\n",fichero);



   fclose(fichero);

  // printf("Proceso completado");
   cout<<endl;


   system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/LCD_Diccionario.dot");
   system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/LCD_Diccionario.dot.png");
 

   }

   else{

     cout<<"no se puede generar el diagrama"<<endl;

   }

}