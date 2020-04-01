
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <fstream>
#include <sstream>

using namespace std;

class NodoCola{
    
    public:
        string ficha;
        int puntos;
        NodoCola *next; 
        NodoCola *back;
        NodoCola();
        NodoCola(string ficha,int puntos);
  
};

NodoCola::NodoCola() {  }

NodoCola::NodoCola(string ficha,int puntos){
    this->ficha=ficha;
    this->puntos=puntos;
}

//**************************************************************************************************

class Cola{

    public:

        NodoCola *first;
        NodoCola *last;

        void Insertar(NodoCola *ficha);
        bool Buscar(string ficha);
        //string Eliminar();
        NodoCola *Eliminar();
        void elimina();
        void Desplegar();
        string ArchivoGrafica();
        void Graficar();

        NodoCola *ficha;

};

void Cola::Insertar(NodoCola *ficha){

	if(last==NULL){
		last=ficha;
		last->next=NULL;
        last->back=NULL;//------->(*)
		first=last;
      
	}else{
		//first->next=ficha;
        
        ficha->next=first;
        first->back=ficha;//------>(*)
        first=ficha;
        //last=ficha;
		//ficha->next=NULL;
		
	}
	
}

bool Cola::Buscar(string ficha){

    NodoCola *actual=first;
	bool encontrado = false;

	if(first != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->ficha == ficha){
				cout << "\n Nodo con el dato ( " << actual->ficha<< " ) Encontrado";
				return encontrado = true;
			}
			
			actual=actual->next;
		}
		if(!encontrado){

            return encontrado;
			//cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}


void Cola::elimina(){

     NodoCola *aux;
     //aux->next=NULL;
     NodoCola *inicio;
     //string fi="";
     //ficha=NULL;

     if(last != NULL){

         if(last==first){
             //fi=first->ficha;
             //ficha=first;
             cout<<"solo hay uno";
             last=NULL;
             first=NULL;
             
             //delete(first);
         }else{
             /*cout<<"\nlast:"<<last->ficha;
            // cout<<"\nnext:"<<last->next->ficha;
             cout<<"\nback:"<<last->back->ficha;
             cout<<"\nback-back:"<<last->back->back->ficha;*/
         
         last=last->back;
         last->next=NULL;
         

         }

         //return fi;
        // return ficha;

     }else{
         //return "w";
          //return NULL;
         cout<<"No existe Nodo para eliminar";
     }


}

 NodoCola *Cola::Eliminar(){

    NodoCola *aux;
     //aux->next=NULL;
     NodoCola *inicio;
     //string fi="";
     //ficha=NULL;

     if(last != NULL){

         if(last==first){
             //fi=first->ficha;
             //ficha=first;
             cout<<"solo hay uno";
             aux=last;
             last=NULL;
             first=NULL;
             
             return aux;
             //delete(first);
         }else{
             /*cout<<"\nlast:"<<last->ficha;
            // cout<<"\nnext:"<<last->next->ficha;
             cout<<"\nback:"<<last->back->ficha;
             cout<<"\nback-back:"<<last->back->back->ficha;*/
         aux=last;
         last=last->back;
         last->next=NULL;
         

         }

         //return fi;
         return aux;

     }else{
         //return "w";
          return NULL;
         cout<<"No existe Nodo para eliminar";
     }

   
   }

   string  Cola::ArchivoGrafica(){

       string cadena;
       NodoCola *aux=first;

    cadena+="digraph pila {\n";
    cadena+="label=""Cola_Fichas"";\n";
    cadena+="labelloc=t;\n";
    cadena+="node [margin=0.3 fontcolor=black  shape=record style=filled fillcolor=orange  color=black];\n";
    //cadena+="{rank=same;";

     cadena+="\n";
     cadena+="struct1[\n";
     cadena+="label=\"{";
     cadena+="\n";
     cadena+="^salida";

      if(first!=NULL){

         while(aux!=NULL){

            cadena+="|";
            cadena+="Ficha: ";
            cadena+= static_cast<std::ostringstream*>(&(std::ostringstream() << aux->ficha))->str();
            cadena+="\\l";
            cadena+="\n Valor: ";
            cadena+= static_cast<std::ostringstream*>(&(std::ostringstream() << aux->puntos))->str()+" pts.";
            cadena+="\\l";
            cadena+="\n";

            aux=aux->next;


         }

         cadena+="}\" \n";
         cadena+="];\n";
         cadena+="}";

     }else{
        cadena+="\n |Cola de Fichas Vacia";
        cadena+=" } \"";
        cadena+=" \n]; \n}";
        // cout<<"NO se puede graficar,Pila Vacia"<<endl;
     }

    return cadena;

   }

   void Cola::Graficar(){

  //if(first!=NULL){

    FILE *fichero;
    //fichero = fopen("/home/mario/Escritorio/Practica#1/Graficas.dot", "wt");
    fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Cola_Fichas.dot", "w");


    fputs(ArchivoGrafica().c_str(),fichero);
    fputs("\n",fichero);

    fclose(fichero);

    cout<<endl;


   system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Cola_Fichas.dot");
   system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Cola_Fichas.dot.png");
 
  //}else{ cout<<"\nNO se puede generar el diagrama de las fichas\n"; }


   }
