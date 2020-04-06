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

class NodoLSO{

    public:
        string Nombre_Jugador;
        int Puntaje;
        NodoLSO *next;
        NodoLSO();
        NodoLSO(int Puntaje);
        NodoLSO(string Nombre,int Puntaje);

};

NodoLSO::NodoLSO(){ }

NodoLSO::NodoLSO(int Puntaje){
    this->Puntaje=Puntaje;
}

NodoLSO::NodoLSO(string Nombre,int Puntaje){
    this->Nombre_Jugador=Nombre;
    this->Puntaje=Puntaje;
}

//***************************************************************************************************

class Lista_Simple_Ordenada{

    public:
        NodoLSO *first;
        NodoLSO *last;
        Lista_Simple_Ordenada(int oc);
        void Insertar(NodoLSO *datos);
		void Buscar(string palabra);
        string ArchivoGraficaP(int op);
        void GraficarP(int opc);
        void SALUDO();
        void Mostrar();
       // string ArchivoGraficaNP();
       // void GraficarNP();
};

Lista_Simple_Ordenada::Lista_Simple_Ordenada(int oc){

    if(oc==1){
        
    this->first=NULL;
    this->last=NULL;
    NodoLSO *temp=new NodoLSO(5000);
    first=temp;

    }else if(oc==2){

    this->first=NULL;
    this->last=NULL;
    NodoLSO *temp=new NodoLSO("",5000);
    first=temp;

    }

}

void Lista_Simple_Ordenada::SALUDO(){ cout<<"\nHola,soy la lista de los puntajes\n"; }

void Lista_Simple_Ordenada::Insertar(NodoLSO *datos){

    int comparacion;
    

	if(first->next==NULL){
		first->next=datos;	
        cout<<"\nEra el unico y se Inserto\n";
	
	}else{
        cout<<"\n"<<first->next->Puntaje<<endl;
        //if(first!=NULL){
		NodoLSO *temp=first;
		//comparacion=strcmp(datos->palabra.c_str(),temp->sig->palabra.c_str());

     while(temp->next !=NULL && temp->next->Puntaje > datos->Puntaje){

			temp=temp->next;
		}

		if(temp->next==NULL){//caso si va a ser el ultimo de la lista
			temp->next=datos;

		}else if(temp->next != NULL){//caso si se va a ingresar en medio de la lista

			NodoLSO*der=temp->next;
			temp->next=datos;
			datos->next=der;

		}
        cout<<"\bSe inserto en la lista de puntajes\n";

        //}

	}
    

    }

    void Lista_Simple_Ordenada::Mostrar(){
        cout<<"\n"<<first->Puntaje<<" , "<<first->next->Puntaje<<endl;
       //if(first!=NULL){
        //NodoLSO *aux;
        //aux=first->next;
        NodoLSO *aux=first;

        while(aux->next!=NULL){
            cout<<"[ "<<aux->Puntaje<<" ]-->";
            aux=aux->next;
        }


        //}else{ cout<<"SE ENCUENTAR VACIA LA LISTA SIMPLE";}
    }




string Lista_Simple_Ordenada::ArchivoGraficaP(int op){
cout<<"primero";
    if(first!=NULL){
cout<<"segundo";
    NodoLSO *temporal=first->next;
	NodoLSO *actual=first->next;
	string cadena,titulo;
    int cont=1;
	


    if( (first!=NULL) && (op==1) ){
cout<<"tercero";
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

        while (temporal!=NULL) {

            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temporal)))->str();
            cadena+="[label=\" ";
            cadena+="Juego "+to_string(cont)+"\\n";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->Puntaje))->str()+"pts.";
            cadena+="\"];\n";

            temporal=temporal->next;
            cont++;
        }


    }else if( (first!=NULL) && (op==2) ){
cout<<"cuarto";
        cadena+="digraph Lista_Simple_General{\n\n";
        cadena+="subgraph cluster_2{\n\n";
        cadena+="fontname=algerian;\n";
        cadena+="fontsize=25;\n";
        cadena+="style=filled;\n";
        cadena+="fillcolor=steelblue2;\n";
        cadena+="label=\"Puntaje_General_de_Jugadores\";\n";
        cadena+="\n labelloc=t; \n";
        cadena+="node[margin=0.25 style=filled fillcolor=orange shape=box];\n";
        cadena+="{rank=same;\n";

            while (temporal!=NULL) {

            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temporal)))->str();
            cadena+="[label=\" ";
            cadena+="Jugador: ";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->Nombre_Jugador))->str()+"\n";
            cadena+="Puntaje: ";
            cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temporal->Puntaje))->str()+"pts.\n";
            cadena+="\"];\n";

            temporal=temporal->next;
            cont++;
        }


    }else{
        cout<<"La Lista Simple se encuentra vacia"<<endl;
    }

    cadena+="};\n\n";

    while(actual !=NULL){

          cadena+= static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(actual)))->str();

           if(actual->next != NULL)
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

void Lista_Simple_Ordenada::GraficarP(int opc){
 
    if(opc==1){

        NodoLSO *aux=first;

        if(first!=NULL){

        FILE *fichero;
        fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot", "w");

        fputs(ArchivoGraficaP(opc).c_str(),fichero);
        fputs("\n",fichero);

        fclose(fichero);

        cout<<endl;

        system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot");
        system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_Usuario.dot.png");

        }
    
    }else if(opc==2){

        NodoLSO *aux=first;

        if(first!=NULL){

        FILE *fichero2;
        fichero2 = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_General.dot", "w");

        fputs(ArchivoGraficaP(opc).c_str(),fichero2);
        fputs("\n",fichero2);

        fclose(fichero2);

        cout<<endl;

        system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_General.dot");
        system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Score_Board_General.dot.png");

        }

   }

   else{

     cout<<"no se puede generar el diagrama"<<endl;

   }

}

