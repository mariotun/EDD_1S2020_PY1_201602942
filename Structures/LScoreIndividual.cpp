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

class NodoLSOIn{

    public:
        //string Nombre_Jugador;
        int Puntaje;
        NodoLSOIn *next;
        NodoLSOIn();
        NodoLSOIn(int Puntaje);
       

};

NodoLSOIn::NodoLSOIn(){ }

NodoLSOIn::NodoLSOIn(int Puntaje){
    this->Puntaje=Puntaje;
}


//***************************************************************************************************

class Lista_Simple_Ordenada_In{

    public:
        NodoLSOIn *first;
        NodoLSOIn *last;
        Lista_Simple_Ordenada_In();
        void Insertar(NodoLSOIn *datos);
		void Buscar(string palabra);
        string ArchivoGraficaP();
        void GraficarP();
        void SALUDO();
        void Mostrar();
       // string ArchivoGraficaNP();
       // void GraficarNP();
};

Lista_Simple_Ordenada_In::Lista_Simple_Ordenada_In(){
    this->first=NULL;
    this->last=NULL;
    
}

void Lista_Simple_Ordenada_In::SALUDO(){ cout<<"\nHola,soy la lista de los puntajes\n"; }

void Lista_Simple_Ordenada_In::Insertar(NodoLSOIn *datos){

    int comparacion;
   

	if(first==NULL){
        NodoLSOIn *temp;
        temp->Puntaje=5000;
        first=temp;
		first->next=datos;	
        cout<<"\nEra el unico y se Inserto\n";
	
	}else{
        //cout<<"\n"<<first->next->Puntaje<<endl;
        //if(first!=NULL){
		NodoLSOIn *temp=first;
		//comparacion=strcmp(datos->palabra.c_str(),temp->sig->palabra.c_str());

     while(temp->next !=NULL && temp->next->Puntaje > datos->Puntaje){

			temp=temp->next;
		}

		if(temp->next==NULL){//caso si va a ser el ultimo de la lista
			temp->next=datos;

		}else if(temp->next != NULL){//caso si se va a ingresar en medio de la lista

			NodoLSOIn*der=temp->next;
			temp->next=datos;
			datos->next=der;

		}
        cout<<"\bSe inserto en la lista de puntajes\n";

        //}

	}
    

    }

    void Lista_Simple_Ordenada_In::Mostrar(){
        NodoLSOIn *pru=new NodoLSOIn();
        pru=first;
        cout<<"\n"<<pru->Puntaje<<" , "<<pru->next->Puntaje<<endl;
       //if(first!=NULL){
        //NodoLSO *aux;
        //aux=first->next;
        NodoLSOIn *aux=new NodoLSOIn();
        aux=first->next;
        //cout<<"\n++++"<<aux->Puntaje;
        //cout<<"\n++++"<<aux->next->Puntaje;
        //cout<<"\n++++"<<aux->next->next->Puntaje;
    int cont=1;
        while( aux!=NULL){
            cout<<"[ "<<aux->Puntaje<<" ]-->";
           aux=aux->next;
           cont++;
        }


        //}else{ cout<<"SE ENCUENTAR VACIA LA LISTA SIMPLE";}
    }




string Lista_Simple_Ordenada_In::ArchivoGraficaP(){

    if(first!=NULL){

    NodoLSOIn *temporal=first->next;
	NodoLSOIn *actual=first->next;
	string cadena,titulo;
    int cont=1;
	

        cadena+="digraph Lista_Simple{\n\n";
        cadena+="subgraph cluster_1{\n\n";
        cadena+="fontname=algerian;\n";
        cadena+="fontsize=25;\n";
        cadena+="style=filled;\n";
        cadena+="fillcolor=steelblue2;\n";
        cadena+="label=\"Puntaje_de_Juegos\";\n";
        cadena+="\n labelloc=t; \n";
        cadena+="node[margin=0.25 style=filled fillcolor=orange shape=box];\n";
        cadena+="{rank=same;\n";

        while (temporal->Puntaje!=0) {

            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temporal)))->str();
            cadena+="[label=\" ";
            cadena+="Juego "+to_string(cont)+"\\n";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->Puntaje))->str()+"pts.";
            cadena+="\"];\n";

            temporal=temporal->next;
            cont++;
        }


    cadena+="};\n\n";

    while(actual->Puntaje !=0){

          cadena+= static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(actual)))->str();

           if(actual->next->Puntaje != 0)
          {

              cadena+="->";
          }

          actual=actual->next;

    }
    cadena+="\n";
    cadena+="[dir=front color=darkgreen];\n";
    cadena+="\n }\n\n}";

    return cadena;

    }else{ cout<<"\nNo hay puntos acumulados en este momento\n";}

}

void Lista_Simple_Ordenada_In::GraficarP(){
 
   if(first!=NULL){

        NodoLSOIn *aux=first;

        

        FILE *fichero;
        fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot", "w");

        fputs(ArchivoGraficaP().c_str(),fichero);
        fputs("\n",fichero);

        fclose(fichero);

        cout<<endl;

        system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot");
        system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot.png");

        }else{

     cout<<"no se puede generar el diagrama"<<endl;

   }

}
