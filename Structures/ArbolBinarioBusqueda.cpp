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

#include "ListaSimpleOrdenada.cpp"
#include "ListaDoble.cpp"


using namespace std;


class NodoArbol{

    public:
        string Nombre_Judador;
        Lista_Simple_Ordenada *scoreboard;
        Lista_Doble *fichas;
        NodoArbol *left;
        NodoArbol *right;
        NodoArbol(string Nombre_Judador);
        NodoArbol();

};

NodoArbol::NodoArbol(){ }

NodoArbol::NodoArbol(string Nombre_Jugador){

    this->Nombre_Judador=Nombre_Jugador;
    this->scoreboard=new Lista_Simple_Ordenada(1);
    this->fichas=new Lista_Doble();
    this->left=NULL;
    this->right=NULL;
    
}

//********************************************************************************************


class Arbol_Binario_Busqueda{

    public:
        NodoArbol *root;
        string Nodo;
        string Enlaces;
        string flechas;
        string flechas2;
        string flechas3;
        int resultado=0;
        int res;
        NodoArbol *jugador;

        Arbol_Binario_Busqueda();

        void Agregar(NodoArbol *Jugador);
        void Agregar_Recursivo(NodoArbol *current,NodoArbol *Jugador);
        void Inorder();
        void recursive_inorder(NodoArbol *current);
        void preorder();
        void recursive_preorder(NodoArbol *current);
        void posorder();
        void recursive_posorder(NodoArbol *current);

        int Buscar(NodoArbol *current,string nombre);//--> PARA QUE NO SE INGRESE REPETIDO EL JUGADOR
        int recorrer(string nombre);//--> PARA QUE NO SE INGRESE REPETIDO EL JUGADOR
        
        void MostrarJugador();//--* PARA MOSTRAR JUGADORES A ELEGIR
        void MostrarJ(NodoArbol *mj);//--* PARA MOSTRAR  JUGADORES A ELEGIR
        
        NodoArbol JugadorObtenido(NodoArbol *current,string nombre);//<> PARA INTERACTUAR CON EL JUGADOR
        NodoArbol ObtenerJugador(string nombre);//<> PARA INTERACTUAR CON EL JUGADOR
        
        void MostarMejoresPuntajes();//ES PARA EL SCOREBOARD GENERAL

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
        
        if(recorrer(Jugador->Nombre_Judador.c_str())==0){

        Agregar_Recursivo(root,Jugador);
        
        }else{ cout<<"\nUsuario ya existente,escriba otro nombre\n"; }
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


int Arbol_Binario_Busqueda::recorrer(string nombre){
    res=0;
    int respueta=0;
    int valor=0;

    valor=Buscar(root,nombre);
    //cout<<"valor: "<<valor<<endl;

    if(valor==1){
       return  respueta=1;
    }else {
       return  respueta=0;
    }

    //return respueta;
}

int Arbol_Binario_Busqueda::Buscar(NodoArbol *current,string nombre){

    //int res=0;

    if(current->left != NULL){
        Buscar(current->left,nombre);
    }
    
   // cout<<"(*)"<<current->Nombre_Judador<<endl;
    if( strcmp(current->Nombre_Judador.c_str(),nombre.c_str()) == 0 ){ 
        //int res=0;
        //cout<<"se encontro: "<<current->Nombre_Judador;
        res=1;
        //return (res);
        
    }

    if(current->right != NULL){
        Buscar(current->right,nombre);
    }


    return (res);

}


void Arbol_Binario_Busqueda::MostrarJugador(){

    MostrarJ(root);
}

void Arbol_Binario_Busqueda::MostrarJ(NodoArbol *mj){

    if(mj->left != NULL){
        MostrarJ(mj->left);
    }

        cout<<"(*) "<<mj->Nombre_Judador<<"\n";
    

    if(mj->right != NULL){
        MostrarJ(mj->right);
    }


}

NodoArbol Arbol_Binario_Busqueda::ObtenerJugador(string nombre){

    jugador=NULL;
    return ( JugadorObtenido(root,nombre) );
}

NodoArbol Arbol_Binario_Busqueda::JugadorObtenido(NodoArbol *current,string nombre ){

    if(current->left != NULL){
        JugadorObtenido(current->left,nombre);
    }
   
    if( strcmp(current->Nombre_Judador.c_str(),nombre.c_str()) == 0 ){ 
        
        jugador=current;
        
    }

    if(current->right != NULL){
        JugadorObtenido(current->right,nombre);
    }

    return (jugador);

}


void Arbol_Binario_Busqueda::Graficar(){

    if(root != NULL){

    FILE* fichero;
    string cadena="";
    cadena+="digraph ArbolBB{\n";
    cadena+="subgraph cluster_1 {\n\n";
    cadena+="label= \"ARBOL_DE_JUGADORES \";\n";
    cadena+="labelloc=t;\n";
    cadena+="fontcolor=magenta4;\n";
    cadena+="fontname=algerian\n";
    cadena+="fontsize=25;\n";
    cadena+="style=filled;\n";
    cadena+="fillcolor=limegreen;\n";
   // cadena+="node[shape=box, style=filled, fillcolor=goldenrod, label=<<TABLE border=\"0\" cellborder=\"0\"><TR><TD width=\"75\" height=\"75\" fixedsize=\"true\"><IMG SRC=\"ok.png\" scale=\"true\"/></TD><td><font point-size=\"20\">node</font></td></TR></TABLE>>]";
    cadena+="node[shape=record,height=0.5 style=filled fontcolor=black fillcolor=goldenrod fontsize=20 ];\n\n";

   
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

    }else{
        cout<<"\nNO se puede generar la grafica de usuarios\n";    
    }
}


string Arbol_Binario_Busqueda::r_inorder(NodoArbol *current){

    string texto="";
    

    if (current->left != NULL){
        texto+= r_inorder(current->left);
    }

    texto+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str();
    texto+="[label=\"Nombre: ";
    texto+=static_cast<std::ostringstream*>(&(std::ostringstream()<<current->Nombre_Judador))->str();
    texto+=" \" ];\n";

    flechas+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str()+ " -> ";

    if (current->right != NULL){
        texto+= r_inorder(current->right);
    }
    return texto;

}

string Arbol_Binario_Busqueda::r_preorder(NodoArbol *current){

    string texto="";
    
    texto+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str();
    texto+="[label=\"Nombre: ";
    texto+=static_cast<std::ostringstream*>(&(std::ostringstream()<<current->Nombre_Judador))->str();
    texto+=" \" ];\n";

    flechas2+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str()+ " -> ";

    if (current->left != NULL){
        texto+= r_preorder(current->left);
    }

    if (current->right != NULL){
        texto+= r_preorder(current->right);
    }
    return texto;

}

string Arbol_Binario_Busqueda::r_posorder(NodoArbol *current){

    string texto="";
    

    if (current->left != NULL){
        texto+= r_posorder(current->left);
    }

    if (current->right != NULL){
        texto+= r_posorder(current->right);
    }

    texto+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str();
    texto+="[label=\"Nombre: ";
    texto+=static_cast<std::ostringstream*>(&(std::ostringstream()<<current->Nombre_Judador))->str();
    texto+=" \" ];\n";

    flechas3+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(current)))->str()+ " -> ";


    return texto;

}

void Arbol_Binario_Busqueda::graph_inorder(){

    FILE* fichero_inorder;

    fichero_inorder = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Inorden.dot", "w");

     fputs("digraph Inorder_Traversal{\n\n",fichero_inorder);
     fputs("graph[ranksep= \"0.5\",nodesep= \"0.5\"];",fichero_inorder);
     fputs("subgraph cluster_3{\n\n",fichero_inorder);
     fputs("label=\"Recorrido Inorden\";\n",fichero_inorder);
     fputs("labelloc=t;\n",fichero_inorder);
     fputs("fontcolor=magenta4;\n",fichero_inorder);
     fputs("fontname=algerian;\n",fichero_inorder);
     fputs("fontsize=25;\n",fichero_inorder);
     fputs("style=filled;\n",fichero_inorder);
     fputs("fillcolor=limegreen;\n\n",fichero_inorder);
     
     fputs("node[margin=0.3 shape=box style=filled fontcolor=black fillcolor=goldenrod fontsize=20];\n",fichero_inorder);
     fputs("{rank=same;\n\n",fichero_inorder);

    fputs(r_inorder(root).c_str(),fichero_inorder);

    fputs("};\n",fichero_inorder);
    string fl=flechas.erase(flechas.find_last_of('-'));
    fputs(fl.c_str(),fichero_inorder);

    fputs("\n\n[color=blue ];\n",fichero_inorder);
    fputs("}\n\n}",fichero_inorder);

    fclose(fichero_inorder);

    system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Inorden.dot");
    system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Inorden.dot.png");


}

void Arbol_Binario_Busqueda::graph_preorder(){

    FILE* fichero_Preorder;

    fichero_Preorder = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Preorden.dot", "w");

     fputs("digraph Preorden_Traversal{\n\n",fichero_Preorder);
     fputs("graph[ranksep= \"0.5\",nodesep= \"0.5\"];",fichero_Preorder);
     fputs("subgraph cluster_4{\n\n",fichero_Preorder);
     fputs("label=\"Recorrido Preorden\";\n",fichero_Preorder);
     fputs("labelloc=t;\n",fichero_Preorder);
     fputs("fontcolor=magenta4;\n",fichero_Preorder);
     fputs("fontname=algerian;\n",fichero_Preorder);
     fputs("fontsize=25;\n",fichero_Preorder);
     fputs("style=filled;\n",fichero_Preorder);
     fputs("fillcolor=limegreen;\n\n",fichero_Preorder);
     
     fputs("node[margin=0.3 shape=box style=filled fontcolor=black fillcolor=goldenrod fontsize=20];\n",fichero_Preorder);
     fputs("{rank=same;\n\n",fichero_Preorder);

    fputs(r_preorder(root).c_str(),fichero_Preorder);

    fputs("};\n",fichero_Preorder);
    string fl=flechas2.erase(flechas2.find_last_of('-'));
    fputs(fl.c_str(),fichero_Preorder);

    fputs("\n\n[color=blue ];\n",fichero_Preorder);
    fputs("}\n\n}",fichero_Preorder);

    fclose(fichero_Preorder);

    system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Preorden.dot");
    system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Preorden.dot.png");


}

void Arbol_Binario_Busqueda::graph_posorder(){

    FILE* fichero_Posorder;

    fichero_Posorder = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Posorden.dot", "w");

     fputs("digraph Posorder_Traversal{\n\n",fichero_Posorder);
     fputs("graph[ranksep= \"0.5\",nodesep= \"0.5\"];",fichero_Posorder);
     fputs("subgraph cluster_5{\n\n",fichero_Posorder);
     fputs("label=\"Recorrido Posorden\";\n",fichero_Posorder);
     fputs("labelloc=t;\n",fichero_Posorder);
     fputs("fontcolor=magenta4;\n",fichero_Posorder);
     fputs("fontname=algerian;\n",fichero_Posorder);
     fputs("fontsize=25;\n",fichero_Posorder);
     fputs("style=filled;\n",fichero_Posorder);
     fputs("fillcolor=limegreen;\n\n",fichero_Posorder);
     
     fputs("node[margin=0.3 shape=box style=filled fontcolor=black fillcolor=goldenrod fontsize=20];\n",fichero_Posorder);
     fputs("{rank=same;\n\n",fichero_Posorder);

    fputs(r_posorder(root).c_str(),fichero_Posorder);

    fputs("};\n",fichero_Posorder);
    string fl=flechas3.erase(flechas3.find_last_of('-'));
    fputs(fl.c_str(),fichero_Posorder);

    fputs("\n\n[color=blue ];\n",fichero_Posorder);
    fputs("}\n\n}",fichero_Posorder);

    fclose(fichero_Posorder);

    system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Posorden.dot");
    system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Recorrido_Posorden.dot.png");


}