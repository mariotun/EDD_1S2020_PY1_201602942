#include <iostream>
#include <string>
#include <stdio.h>
//#include <stdlib.h>//para abrir con comandos

#include <stdbool.h>
//#include <fstream>
//#include <sstream>

using namespace std;

class NodoLPE{
    public:
        int x;
        int y;
        NodoLPE *next;
        NodoLPE();
        NodoLPE(int x,int y);
};

NodoLPE::NodoLPE(){ }

NodoLPE::NodoLPE(int x,int y ){
    this->x=x;
    this->y=y;

}

//------------------------------------------------------------------------------------------------------------

class Lista_PE{
    public:
        NodoLPE *primero;
        NodoLPE *ultimo;
        Lista_PE();
        void Insertar(NodoLPE *pri);
        void Mostrar();
        bool Buscar(int x,int y);
};

Lista_PE::Lista_PE(){
    this->primero=NULL;
    this->ultimo=NULL;
}

void Lista_PE::Insertar(NodoLPE *pri){

    if(primero==NULL){
        primero=pri;
        primero->next=NULL;
        ultimo=primero;
    }else{
        ultimo->next=pri;
        pri->next=NULL;
        ultimo=pri;
    }
}


void Lista_PE::Mostrar(){

    NodoLPE *actual=new NodoLPE();
    actual=primero;

    if(primero!=NULL){

        while(actual!=NULL){
        cout<<"[ "<<actual->x<<","<<actual->y<<" ]"<<"-->";
        actual=actual->next;
        }

    }else{
       // cout<<"La lista doble se encuentra vacia"<<endl;

    }

}


bool Lista_PE::Buscar(int x,int y){
    NodoLPE *actual=new NodoLPE();
    actual=primero;
    bool encontrado=false;
    
    if(primero!=NULL){

        while (actual!=NULL && encontrado!=true){

            if( (actual->x==x) && (actual->y==y) ){
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
        cout<<"La lista dodle se encuetra vacia"<<endl;

    }
    
}
