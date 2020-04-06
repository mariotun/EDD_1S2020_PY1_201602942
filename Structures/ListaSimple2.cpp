#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>//para abrir con comandos

#include <stdbool.h>
#include <fstream>
#include <sstream>

using namespace std;

class NodoLS2{

    public:
        string nombre;
        int puntos;
        NodoLS2 *next;
        //NodoLD *back;
        NodoLS2();
        NodoLS2(string nombre,int puntos);

};


NodoLS2::NodoLS2(){ }

NodoLS2::NodoLS2(string nombre,int puntos){
    this->nombre=nombre;
    this->puntos=puntos;
}

//*********************************************************************************************************************

class Lista_Simple2{

    public:

        NodoLS2 *first;
        NodoLS2 *last;

        void Insertar(NodoLS2 *ficha);
        bool Buscar(int ficha);
        void Mostrar();
        NodoLS2 *Eliminar(int letraficha);
        void Modificar(int palabra,int extras);
        string ArchivoGrafica();
        void Graficar();

        Lista_Simple2();

};

Lista_Simple2::Lista_Simple2(){
    
    this->first=NULL;
    this->last=NULL;

}

void Lista_Simple2::Insertar(NodoLS2 *palabra){

    if(first==NULL){
        first=palabra;
        first->next=NULL;
        //first->back=NULL;
        last=first;
    }else{
        last->next=palabra;
        palabra->next=NULL;
       // palabra->back=last;
        last=palabra;

         
       /* //if(first!=NULL){
		NodoLS *temp=first;
		//comparacion=strcmp(datos->palabra.c_str(),temp->sig->palabra.c_str());

     while(temp->next !=NULL && temp->next->puntos > palabra->puntos){

			temp=temp->next;
		}

		if(temp->next==NULL){//caso si va a ser el ultimo de la lista
			temp->next=palabra;

		}else if(temp->next != NULL){//caso si se va a ingresar en medio de la lista

			NodoLS*der=temp->next;
			temp->next=palabra;
			palabra->next=der;

		}
        cout<<"\bSe inserto en la lista de puntajes\n";*/




        }
}

void Lista_Simple2::Mostrar(){

    NodoLS2 *actual=new NodoLS2();
    actual=first;

    if(first!=NULL){

        while(actual!=NULL){
        cout<<"[ "<<actual->puntos<<" ]"<<"-->";
        actual=actual->next;
        }

    }else{
       // cout<<"La lista doble se encuentra vacia"<<endl;

    }

}

bool Lista_Simple2::Buscar(int palabra){

    NodoLS2 *actual=new NodoLS2();
    actual=first;
    bool encontrado=false;
    
    if(first!=NULL){

        while (actual!=NULL && encontrado!=true){

            if(actual->puntos==palabra){
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

   // return encontrado;
}


void Lista_Simple2::Modificar(int palabra,int extras){
    NodoLS2 *actual=new NodoLS2();
    actual=first;
    bool encontrado=false;
    
    if(first!=NULL){

        while (actual!=NULL && encontrado!=true){

            if(actual->puntos==palabra){
                actual->puntos=(actual->puntos*extras);
                encontrado=true;
            }

            actual=actual->next;
        }

        if(!encontrado){
            cout<<"El nodo no se encontro en la lista doble"<<endl;
         //return encontrado;
        }
       
    }else{
        cout<<"La lista dodle se encuetra vacia"<<endl;

    }

   // return encontrado;


}


NodoLS2 *Lista_Simple2::Eliminar(int letraficha){

    NodoLS2 *actual=new NodoLS2();
    actual=first;
    NodoLS2* anterior = new NodoLS2();
	anterior = NULL;
    bool encontrado=false;
    
    if(first!=NULL){

        while (actual!=NULL && encontrado!=true){

            if(actual->puntos==letraficha){
              
              if(actual==first){
                  first=first->next;
                  //first->back=NULL;

              }else if(actual==last){
                  anterior->next = NULL;
				  last = anterior;

              }else{
                  anterior->next = actual->next;
				  //actual->next->back = anterior;

              }
                encontrado=true; 
                return actual;
                
            }

            anterior = actual;
            actual=actual->next;
            
			
        }

        if(!encontrado){
           // cout<<"El nodo no se encontro en la lista doble circular"<<endl;
         return NULL;
        }
       
    }else{
        cout<<"La lista dodle se encuetra vacia"<<endl;

    }

   // return encontrado;


}


string Lista_Simple2::ArchivoGrafica(){

    string cadena;
    NodoLS2 *temporal=first;
    NodoLS2 *actual=first;
    NodoLS2 *uno=first;

    cadena+="digraph Lista_Doble{\n\n";
    cadena+="graph[ranksep= \"0.5\",nodesep= \"0.5\"];\n";
    cadena+="node[fontcolor=black shape=box style=filled fillcolor=tan2 fontsize=20];\n\n";
    cadena+="subgraph cluster_1 {\n\n";
    cadena+="fontname=algerian\n";
    cadena+="fontsize=25;\n";
    cadena+="label=\"Lista_Puntajes_Jugadores\";\n";
    cadena+="fontcolor=blue\n";
    cadena+="style=filled\n";
    cadena+="fillcolor=chartreuse3\n";
    cadena+="labelloc=t;";

    cadena+="{rank=same;\n";
    

    if(first!=NULL){

        while(temporal!=NULL){

            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temporal)))->str();
            cadena+="[label=\" ";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->nombre))->str();
            cadena+=" , ";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->puntos))->str();
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
   // cadena+="->"+static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(uno)))->str();

    cadena+="\n";
    cadena+="[dir=front color=black];\n";
    cadena+="\n }\n\n}";

    return cadena;
}

void Lista_Simple2::Graficar(){

   NodoLS2 *aux=first;

   if(first!=NULL){

   FILE *fichero;

   fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot", "w");




   //fputs("digraph G {\ncolor=lightblue;\n", fichero);


   fputs(ArchivoGrafica().c_str(),fichero);
   fputs("\n",fichero);



   fclose(fichero);

  // printf("Proceso completado");
   cout<<endl;


   system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot");
   system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot.png");
 

   }

   else{

     cout<<"no se puede generar el diagrama"<<endl;

   }

}