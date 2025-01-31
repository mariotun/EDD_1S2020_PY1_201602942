#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>//para abrir con comandos

#include <stdbool.h>
#include <fstream>
#include <sstream>

using namespace std;

class NodoLD{

    public:
        string ficha;
        int puntos;
        NodoLD *next;
        NodoLD *back;
        NodoLD();
        NodoLD(string palabra,int puntos);

};


NodoLD::NodoLD(){ }

NodoLD::NodoLD(string ficha,int puntos){

    this->ficha=ficha;
    this->puntos=puntos;
}

//*********************************************************************************************************************

class Lista_Doble{

    public:

        NodoLD *first;
        NodoLD *last;

        void Insertar(NodoLD *ficha);
        bool Buscar(string ficha);
        void Mostrar();
        NodoLD *Eliminar(string letraficha);
        NodoLD *Eliminar2();
        void Modificar(string palabra,int extras);
        string ArchivoGrafica();
        void Graficar();

        Lista_Doble();

};

Lista_Doble::Lista_Doble(){
    
    this->first=NULL;
    this->last=NULL;

}

void Lista_Doble::Insertar(NodoLD *palabra){

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
        }
}

void Lista_Doble::Mostrar(){

    NodoLD *actual=new NodoLD();
    actual=first;

    if(first!=NULL){

        while(actual!=NULL){
        cout<<"[ "<<actual->ficha<<" ]"<<"-->";
        actual=actual->next;
        }

    }else{
       // cout<<"La lista doble se encuentra vacia"<<endl;

    }

}

bool Lista_Doble::Buscar(string palabra){

    NodoLD *actual=new NodoLD();
    actual=first;
    bool encontrado=false;
    
    if(first!=NULL){

        while (actual!=NULL && encontrado!=true){

            if(actual->ficha==palabra){
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


void Lista_Doble::Modificar(string palabra,int extras){
    NodoLD *actual=new NodoLD();
    actual=first;
    bool encontrado=false;
    
    if(first!=NULL){

        while (actual!=NULL && encontrado!=true){

            if(actual->ficha==palabra){
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


NodoLD *Lista_Doble::Eliminar(string letraficha){

    NodoLD *actual=new NodoLD();
    actual=first;
    NodoLD* anterior = new NodoLD();
	anterior = NULL;
    bool encontrado=false;
    
    if(first!=NULL){

        while (actual!=NULL && encontrado!=true){

            if(actual->ficha==letraficha){
              
              if(actual==first){
                  first=first->next;
                  first->back=NULL;

              }else if(actual==last){
                  anterior->next = NULL;
				  last = anterior;

              }else{
                  anterior->next = actual->next;
				  actual->next->back = anterior;

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


NodoLD *Lista_Doble::Eliminar2(){

    NodoLD *actual=new NodoLD();
    actual=first;
    NodoLD* anterior = new NodoLD();
	anterior = NULL;
    bool encontrado=false;
    
    if(first!=NULL){

        if(first==last){
            //cout<<"son los ultimos";
            anterior=last;
            first=NULL;
            last=NULL;
            return (anterior);

        }else{
        anterior=last;
        last=last->back;
        last->next=NULL;

        return (anterior);
        }

    }else{
        cout<<"La lista dodle se encuetra vacia"<<endl;
        return NULL;
    }

}



string Lista_Doble::ArchivoGrafica(){

    string cadena;
    NodoLD *temporal=first;
    NodoLD *actual=first;
    NodoLD *uno=first;

    cadena+="digraph Lista_Doble{\n\n";
    cadena+="graph[ranksep= \"0.5\",nodesep= \"0.5\"];\n";
    cadena+="node[fontcolor=black shape=box style=filled fillcolor=tan2 fontsize=20];\n\n";
    cadena+="subgraph cluster_1 {\n\n";
    cadena+="fontname=algerian\n";
    cadena+="fontsize=25;\n";
    cadena+="label=\"Lista_Fichas_Disponibles\";\n";
    cadena+="fontcolor=blue\n";
    cadena+="style=filled\n";
    cadena+="fillcolor=chartreuse3\n";
    cadena+="labelloc=t;";

    cadena+="{rank=same;\n";
    

    if(first!=NULL){

        while(temporal!=NULL){

            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temporal)))->str();
            cadena+="[label=\" ";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->ficha))->str();
            cadena+="\"];\n";

        temporal=temporal->next;
        }

    /*}else{
       // cout<<"La lista doble se encuentra vacia"<<endl;

    }*/

    cadena+="};\n\n";


        while(actual !=NULL){

          cadena+= static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(actual)))->str();

           if(actual->next != NULL)
          {

              cadena+="->\n";
          }

          actual=actual->next;

    }

    cadena+="\n";
    cadena+="[dir=both  color=black];\n";
    cadena+="\n }\n\n}";
   // cadena+="->"+static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(uno)))->str();
    }else{
       // cout<<"La lista doble se encuentra vacia"<<endl;
        cadena+="Lista_de_Fichas_Vacia";
        cadena+=" } ";
        cadena+=" }; \n}";

    }

   

    return cadena;
}

void Lista_Doble::Graficar(){

   NodoLD *aux=first;

   //if(first!=NULL){

   FILE *fichero;

   fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/LD_Fichas_Jugador.dot", "w");




   //fputs("digraph G {\ncolor=lightblue;\n", fichero);


   fputs(ArchivoGrafica().c_str(),fichero);
   fputs("\n",fichero);



   fclose(fichero);

  // printf("Proceso completado");
   cout<<endl;


   system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/LD_Fichas_Jugador.dot");
   system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/LD_Fichas_Jugador.dot.png");
 

   //}else{
     //cout<<"no se puede generar el diagrama"<<endl;
   //}

}