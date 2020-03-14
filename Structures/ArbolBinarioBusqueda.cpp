/*#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <fstream>
#include <sstream>
#include <ctime>*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <stdbool.h>
#include <string>
#include <cstring>
#include <time.h>
#include <ctime>
#include <sstream>

using namespace std;


class NodoArbol{

    public:
        string Nombre_Judador;
        NodoArbol *left;
        NodoArbol *right;
        NodoArbol(string Nombre_Judador);
        NodoArbol();

};

NodoArbol::NodoArbol(){ }

NodoArbol::NodoArbol(string Nombre_Jugador){

    this->Nombre_Judador=Nombre_Jugador;
    this->left=NULL;
    this->right=NULL;
    
}

//********************************************************************************************


class Arbol_Binario_Busqueda{

    public:
        NodoArbol *root;
        string Nodo;
        string Enlaces;
        int resultado=0;


        Arbol_Binario_Busqueda();

        void Agregar(NodoArbol *Jugador);
        void Agregar_Recursivo(NodoArbol *current,NodoArbol *Jugador);
        void Inorder();
        void recursive_inorder(NodoArbol *current);
        void preorder();
        void recursive_preorder(NodoArbol *current);
        void posorder();
        void recursive_posorder(NodoArbol *current);
        int Buscar(string Jugador);

        string ArchivoGraficar();
        void Graficar();
        string r_inorder(NodoArbol *current);
        void graph_inorder();
        string r_preorder(NodoArbol *current);
        void graph_preorder();
        string r_posorder(NodoArbol *current);
        void graph_posorder();


};

Arbol_Binario_Busqueda::Arbol_Binario_Busqueda(){
    root=NULL;
}

void Arbol_Binario_Busqueda::Agregar(NodoArbol *Jugador){

    if(root==NULL){

        root=Jugador;
             // static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(actual)))->str();
        Nodo+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(Jugador)))->str();
        Nodo+="[label=\"<f0> |<f1>Nombre: ";
        Nodo+=static_cast<std::ostringstream*>(&(std::ostringstream()<<Jugador->Nombre_Judador.c_str()))->str();
        Nodo+=" |<f2> \" ]; \n";


    }else{

        Agregar_Recursivo(root,Jugador);
        //cout<<"raiz: "<<root->Nombre_Judador<<" ,actual: "<<Jugador->Nombre_Judador<<endl;
    }

}

void Arbol_Binario_Busqueda::Agregar_Recursivo(NodoArbol *current,NodoArbol *Jugador){

   resultado=strcmp(Jugador->Nombre_Judador.c_str(),current->Nombre_Judador.c_str());
   // cout<<"Resultado: "<<resultado<<" ";

    Nodo+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(Jugador)))->str();
    Nodo+="[label=\"<f0> |<f1>Nombre: ";
    Nodo+=static_cast<std::ostringstream*>(&(std::ostringstream()<<Jugador->Nombre_Judador.c_str()))->str();
    Nodo+=" |<f2>\" ]\n";


    if( resultado < 0 ){
       // cout<<"entro en izquierda \n";
        if(current->left != NULL){
            Agregar_Recursivo(current->left,Jugador);

        }else{
            current->left=Jugador;

            Enlaces+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str();
            Enlaces+=":f0";
            Enlaces+="->";
            Enlaces+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(Jugador)))->str();
            Enlaces+=":f1 [color=blue]\n";
        }

    }else if( resultado > 0 ){
            // cout<<"entro en derecha \n";
        if(current->right != NULL ){
            Agregar_Recursivo(current->right,Jugador);

        }else {
            current->right=Jugador;

            Enlaces+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str();
            Enlaces+=":f2";
            Enlaces+="->";
            Enlaces+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(Jugador)))->str();
            Enlaces+=":f1 [color=blue ]\n";
        }

    }

   

}


void Arbol_Binario_Busqueda::Graficar(){

    FILE* fichero;
    string cadena="";
    cadena+="digraph ArbolBB{\n";
    cadena+="subgraph cluster_1 {\n\n";
    cadena+="label= \"ARBOL_DE_JUGADORES \";\n";
    cadena+="labelloc=t;\n";
    cadena+="fontcolor=magenta4;\n";
    cadena+="fontsize=25;\n";
    cadena+="style=filled;\n";
    cadena+="fillcolor=limegreen;\n";
   // cadena+="node[shape=box, style=filled, fillcolor=goldenrod, label=<<TABLE border=\"0\" cellborder=\"0\"><TR><TD width=\"75\" height=\"75\" fixedsize=\"true\"><IMG SRC=\"ok.png\" scale=\"true\"/></TD><td><font point-size=\"20\">node</font></td></TR></TABLE>>]";
    cadena+="node[shape=record,height=0.5 style=filled fontcolor=black fillcolor=goldenrod ];\n\n";

   
    //fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Arbol_Jugadores.gv", "w");
    fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Arbol_Jugadores.dot", "w");

   fputs(cadena.c_str(),fichero);
    fputs("\n",fichero);
    fputs(Nodo.c_str(),fichero);
     //fputs(r_add1(root).c_str(),fichero);
    fputs("\n",fichero);
    fputs(Enlaces.c_str(),fichero);


    fputs("\n }\n\n }",fichero);
   // cadena+="digraph dot_image {\n";
    //cadena+="mario [image=\"C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/control.png\" width=\"100\" height=\"100\"  label=\" mario\"]";
   /* cadena+="node[shape=box, style=filled, fillcolor=white, color=blue, label=<<TABLE border=\"0\" cellborder=\"0\"><TR><TD width=\"75\" height=\"75\" fixedsize=\"true\"><IMG SRC=\"C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/control.png\" scale=\"true\"/></TD><td><font point-size=\"20\">node</font></td></TR></TABLE>>]";

   cadena+="name1";
   cadena+="->name2\n";
    cadena+="}\n";


    fputs(cadena.c_str(),fichero);*/
  


    fclose(fichero);

    //system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Arbol_Jugadores.gv");
    //system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Arbol_Jugadores.gv.png");
    system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Arbol_Jugadores.dot");
    system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Arbol_Jugadores.dot.png");
}

