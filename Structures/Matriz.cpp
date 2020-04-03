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

class NodoMatriz{

    public:
        int x;
        int y;
        string letra;
        string colorf;
        int tipo_casilla;
        NodoMatriz *up;
        NodoMatriz *down;
        NodoMatriz *left;
        NodoMatriz *right;
        NodoMatriz();
        NodoMatriz(int x,int y,string letra);
        NodoMatriz(int x,int y,string letra,string colorf);
        
};

NodoMatriz::NodoMatriz(){   }

NodoMatriz::NodoMatriz(int x,int y,string letra){
    this->x=x;
    this->y=y;
    this->letra=letra;
    this->colorf="tan2";
    this->up=NULL;
    this->down=NULL;
    this->left=NULL;
    this->right=NULL;
}

NodoMatriz::NodoMatriz(int x,int y,string letra,string colorf){
    this->x=x;
    this->y=y;
    this->letra=letra;
    this->colorf=colorf;
    this->up=NULL;
    this->down=NULL;
    this->left=NULL;
    this->right=NULL;
}


//************************************************************************************

class Matrizz{

    public:
        NodoMatriz *head;
        NodoMatriz *primero;
        NodoMatriz *ultimo;
        string cadenasdex;
        string enlacesx;
        string cadenasdey;
        string enlacesy;
        Matrizz();
        void add(int x,int y,string letra);
        void add(int x,int y,string letra,string color);
        void add_x(NodoMatriz *new_node,int x);
        void add_y(NodoMatriz *new_node,int y);
        void add_Node(int x,int y,string letra);
        void add_headerx(int x);//para crear cabeceras en x
        void add_headery(int y);//para crear cabeceras en y
        void Delete(int x,int y);
        void Eliminar(int x,int y);
        void EliminarColumna(int x,int y);
        void EliminarFila(int x,int y);
        int search(int x,int y);
        void print_nodos_x();
        void print_nodos_y();
        string  write_file();
        void Graficar();

       // NodoMatriz *temp=head->right;
       // NodoMatriz *te=temp;
       // NodoMatriz *enlace=temp;//puntero para recorrer los enlaces

};

Matrizz::Matrizz(){
    NodoMatriz *temp=new NodoMatriz(-1,-1,"");
    head=temp;
}

void Matrizz::add(int x,int y,string letra){

    add_headerx(x);
    add_headery(y);
    NodoMatriz *new_node=new NodoMatriz(x,y,letra);
    add_x(new_node,x);
    add_y(new_node,y);

}

void Matrizz::add(int x,int y,string letra,string color){

    add_headerx(x);
    add_headery(y);
    NodoMatriz *new_node=new NodoMatriz(x,y,letra,color);
    add_x(new_node,x);
    add_y(new_node,y);

}

void Matrizz::add_x(NodoMatriz *new_nodo,int x){

    NodoMatriz *temp=head;
   
    while(temp->x != x){
        temp=temp->right;
   }

    if(temp->down == NULL){
        temp->down=new_nodo;
        new_nodo->up=temp;
        


    }else{

        NodoMatriz *tempo=temp;

        while(tempo->down != NULL && tempo->down->y < new_nodo->y){
            tempo=tempo->down;
        }

        if(tempo->down==NULL){//por si el dato se ingresa de ultimo
            tempo->down=new_nodo;
            new_nodo->up=tempo;
            

        }

       else if(tempo->down != NULL && tempo->down->y != new_nodo->y){
            NodoMatriz *der=tempo->down;
            tempo->down=new_nodo;
            new_nodo->up=tempo;
            new_nodo->down=der;
            der->up=new_nodo;

        }

    }//donde termina el else principal

}

void Matrizz::add_y(NodoMatriz *new_nodo,int y){

    NodoMatriz *temp=head;

    while(temp->y != y){
        temp=temp->down;

    }
    if(temp->right==NULL){
        temp->right=new_nodo;
        new_nodo->left=temp;

    }

    else{

    NodoMatriz *tempo=temp;

    while(tempo->right != NULL && tempo->right->x < new_nodo->x){
        tempo=tempo->right;
    }

    if(tempo->right==NULL){
        tempo->right=new_nodo;
        new_nodo->left=tempo;

    }

   else if(tempo->right!= NULL && tempo->right->x != new_nodo->x){
        NodoMatriz *der=tempo->right;
        tempo->right=new_nodo;
        new_nodo->left=tempo;
        new_nodo->right=der;
        der->left=new_nodo;

    }

    }//donde termina el else principal

}

void Matrizz::add_headerx(int x){

    if(head->right==NULL){
        NodoMatriz *temp=new NodoMatriz(x,0,"");
        head->right=temp;
        temp->left=head;

    }else{

   NodoMatriz *temp=head;

   while(temp->right != NULL && temp->right->x < x){//recorrido para ingresar ordenado
        temp=temp->right;

   }

   if(temp->right==NULL){
       NodoMatriz *n_temp=new NodoMatriz(x,0,"");
       temp->right=n_temp;
       n_temp->left=temp; //caso si se ingresa de ultimo

   }else if(temp->right != NULL && temp->right->x != x) {
       NodoMatriz *new_temp=new NodoMatriz(x,0,"");
       NodoMatriz *der=temp->right;
       temp->right=new_temp;
       new_temp->left=temp;
       new_temp->right=der;
       der->left=new_temp;

   }

    }

}

void Matrizz::add_headery(int y){

         if(head->down==NULL){
         NodoMatriz *temp=new NodoMatriz(0,y,"");
         head->down=temp;
         temp->up=head;

        }else{

         NodoMatriz *temp=head;

         while(temp->down != NULL && temp->down->y < y){
                temp=temp->down;
         }

         if(temp->down==NULL){
             NodoMatriz *new_temp=new NodoMatriz(0,y,"");
             temp->down=new_temp;
             new_temp->up=temp;

         }else if(temp->down != NULL && temp->down->y != y){
             NodoMatriz *new_temp=new NodoMatriz(0,y,"");
             NodoMatriz *der=temp->down;
             temp->down=new_temp;
             new_temp->up=temp;
             new_temp->down=der;
             der->up=new_temp;

         }

     }

}

void  Matrizz::Eliminar(int x,int y){
    EliminarColumna(x,y);
    EliminarFila(x,y);

}


void Matrizz::EliminarColumna(int x,int y){

    NodoMatriz* actual ;//= new NodoMatriz();
	actual = head;
	NodoMatriz* anterior;// = new NodoMatriz();
	anterior=NULL;
	
    bool encontrado = false;
	int nodoBuscado = 0;
    int cant=0;
	//cout << " Ingrese el dato del Nodo a Buscar para Eliminar: ";
	//cin >> nodoBuscado;
    
	if(head!=NULL){

        while(actual->x != x){
         actual=actual->right;
        }

        if(actual->down == NULL){
         //temp->down=new_nodo;
         //new_nodo->up=temp;
       cout<<"no hay nada en esa columna"<<endl;
        }else{

            NodoMatriz *otro=actual->down;
            //cout<<"PRIMERO:"<<otro->letra<<endl;
           // anterior=actual;
            NodoMatriz *elim,*elim2,*elim3;
            //otro->down != NULL && encontrado!=true
         while(otro!= NULL && encontrado!=true){
                cant++;

                if(otro->y==y){
                    //cout<<"----->se encontro: "<<otro->letra<<endl;

                    if(otro->down==NULL && otro->up==actual){//por si es el unico en la columna
                    //cout<<"soy en unico en la columna\n";

                    if(actual->right==NULL){//pregunto si es una cabecera del final
                        elim=actual->left;
                        elim->right=NULL;
                        actual->left=NULL;


                     // elim2=otro->left;
                     // elim2->right=NULL;

                    }else if(actual->left!=NULL && actual->right!=NULL){//por si la cabecera esta en medio
                       
                        elim=actual->left;
                        elim2=actual->right;
                        elim->right=elim2;
                        elim2->left=elim;

                        //actual->left=NULL;
                        //actual->right=NULL;
                      }

                    

                    encontrado=true;

                    }else if(otro->down!=NULL && otro->up==actual){//por si es el primero y no es el unico
                    //cout<<"soy el primero y no soy el unico\n";

                    //elim=otro->up;
                    //elim->down=otro->down;
                    elim=otro->down;
                    elim->up=actual;
                    actual->down=elim;

                   // otro->left->right=otro->right;



                    encontrado=true;


                    }else if(otro->down!=NULL && otro->up!=actual){//por si es el de en medio
                    //cout<<"soy el de enmedio\n"<<otro->up->letra<<" - "<<otro->down->letra;

                   
                   /* elim=otro->up;
                    elim2=otro->down;

                    otro->up=elim3;
                    otro->down=elim3;

                    elim->down=elim2;*/

                    elim=otro;
                    elim->up->down=elim->down;
                    elim->down->up=elim->up;
                    //elim->left->right=elim->right;
                    
                    //elim->down=NULL;SE ELIMINO EL ULTIMO
                    //elim=NULL;
                

                    encontrado=true;

                    }else{//por si es el ultimo
                    //cout<<"soy en ultimo\n";
                    
                    elim=otro;
                    elim->up->down=NULL;
                    otro->up=NULL;
                    
                    encontrado=true;


                    }

                } 
               
            anterior= otro;
            //cout<<"anterior:"<<anterior->letra<<endl;
			otro=otro->down;
            //cout<<"otro:"<<otro->letra<<endl;

		}//FIN DEL WHILE
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		
        }
		
     }//FIN DEL ESLSE DEL SEGUNDO IF

    }//FIN DEL PRIMER IF EN EL METODO
    else{ cout << "\n La listas se encuentra Vacia\n\n"; }
		
}

void Matrizz::EliminarFila(int x,int y){

    NodoMatriz* actual =new NodoMatriz();
	actual = head;
	
    bool encontrado = false;
	
    int cant=0;
	
	if(head!=NULL){

        while(actual->y != y){
         actual=actual->down;
        }

        if(actual->right == NULL){
         
       cout<<"no hay nada en esa fila"<<endl;
        }else{

            NodoMatriz *otro=new NodoMatriz();
            otro=actual->right;
            //cout<<"PRIMERO:"<<otro->letra<<endl;
           
            NodoMatriz *elim,*elim2,*elim3;
            
         while(otro!= NULL && encontrado!=true){
                cant++;

                if(otro->x==x){
                    //cout<<"----->se encontro: "<<otro->letra<<endl;

                    if(otro->right==NULL && otro->left==actual){//por si es el unico en la fila
                   // cout<<"soy el unico en la fila\n";
                       
                       //otro->left=NULL;//para desenlazar el nodo en si
                       //actual->right=NULL;

                    if(actual->down==NULL){//pregunto si es una lateral que esta de ultimo
                       //cout<<"soy la ultima latera\n";
                        elim=actual->up;
                        elim->down=NULL;
                       actual->up=NULL;


                      //elim2=otro->up;
                      //elim2->down=NULL;

                    }else if(actual->up!=NULL && actual->down!=NULL){//por si una lateral se encuentra en medio
                        //cout<<"soy una lateral en medio\n";
                        //cout<<"up:"<<actual->up->y<<" down:"<<actual->down->y;
                        elim=new NodoMatriz();
                        elim2=new NodoMatriz();
                       // elim3=new NodoMatriz();
                        
                       // cout<<"actual:"<<actual->y<<endl;
                        elim=actual->up;
                        //cout<<"up:"<<elim->y;
                        elim2=actual->down;
                        //cout<<" ,down:"<<elim2->y;
                        elim->down=elim2;
                        elim2->up=elim;

                        //actual->up=elim3;
                        //actual->down=elim3;
                        
                        
                        //actual=NULL;
                        //delete(actual);

                         //elim3->up=NULL;
                         //elim3->down=NULL;

                        //actual->up=NULL;
                        //actual->down=NULL;
                        //actual=NULL;

                    }

                    

                    encontrado=true;

                    }else if(otro->right!=NULL && otro->left==actual){//por si es el primero y no es el unico
                    //cout<<"soy el primero y no soy el unico\n";

                    elim=otro->right;
                    elim->left=actual;
                    actual->right=elim;

                    encontrado=true;


                    }else if(otro->right!=NULL && otro->left!=actual){//por si es el de en medio
                   // cout<<"soy el de enmedio\n"<<otro->left->letra<<" - "<<otro->right->letra;

                    elim=otro;
                    elim->left->right=elim->right;
                    elim->right->left=elim->left;
                   
                    encontrado=true;

                    }else{//por si es el ultimo
                    //cout<<"soy en ultimo\n";
                    
                    elim=otro;
                    elim->left->right=NULL;
                    otro->left=NULL;
                    
                    encontrado=true;


                    }

                } 
                // anterior= otro;
            //cout<<"anterior:"<<anterior->letra<<endl;
			otro=otro->right;
            //cout<<"otro:"<<otro->letra<<endl;

		}//FIN DEL WHILE
		
		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		
        }
		
     }//FIN DEL ESLSE DEL SEGUNDO IF

    }//FIN DEL PRIMER IF EN EL METODO
    else{ cout << "\n La listas se encuentra Vacia\n\n"; }


}


void Matrizz::Delete(int x,int y){
    cout<<"---->entro a delete\n";
    NodoMatriz *temp=head;
    NodoMatriz *aux=NULL;
     bool encontrado=false;
     int cant=0;
     //Node *temp;

     while(temp->x != x){
         temp=temp->right;
    }

     if(temp->down == NULL){
         //temp->down=new_nodo;
         //new_nodo->up=temp;
       cout<<"no hay nada en esa columna"<<endl;
     }else{

         NodoMatriz *otro=temp;
         NodoMatriz *elim,*elim2;
         NodoMatriz *elim3,*elim4;

    while(otro->down != NULL && encontrado!=true){
        cant++;
       if(otro->down->y == y ){
            cout<<"el dato se encontro y es: "<<otro->down->letra<<" con cant= "<<cant<<endl;

            if(cant==1 && temp->left!=head){
                cout<<"solo uno"<<temp->x<<"\n";
                elim=temp->left;
                elim->right=NULL;
                temp->left=NULL;
                elim2=otro->down->left;
                elim2->right=NULL;
                encontrado=true;
            }else{
                
                if(otro->down->down==NULL){
                    cout<<"ultimo\n";

                    //cout<<"elim:"<<elim->down->up->letra;
                    elim2=new NodoMatriz();
                    elim2=NULL;
                    otro->down->up->down=elim2;
                    
                    //elim=otro->down;
                    //elim->up=elim2;
                    //elim->left=elim2;
                    
                    //delete(elim2);
                    //elim3=otro->down->left;
                    //elim3->right=NULL;
                    

                    encontrado=true;

                }else{
                        cout<<"no entro\n";
                }

            }

            /*if(otro->down == NULL){//eliminar si este nodo es el ultimo

               /* aux->down=NULL;
                otro->down=aux;
                aux=otro->up;

                cout<<"eliminno si es el ultimo";

            }

            encontrado=true;*/



        }

        //otro->down=otro->down->down;
        otro=otro->down;
       
    }

     }//cierre del else principal


}

void Matrizz::print_nodos_x(){

    if(head!=NULL && head->right!=NULL && head->down!=NULL){

     NodoMatriz *temp=head->right;
     cadenasdex="";
     enlacesx="";
    // ls2=new ListaS();//inicializar una nueva lista simple para linealizar por columna

     while(temp->right != NULL){

     cout<<temp->x;
     cout<<"-->";
     enlacesx+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temp->right)))->str();
     enlacesx+="->";

     if(temp->down != NULL){
        // cout<<temp->down->g;
        NodoMatriz *te=temp;
        NodoMatriz *enlace=temp;//puntero para recorrer los enlaces

       // cadenasdex+="node[shape=box height=0.5 style=filled fontcolor=black fillcolor= tan2]\n";
         while(te->down != NULL){

             //cout<<te->down->r<<","<<te->down->g<<","<<te->down->b;

    //ls2->InsertarLS(new NodeLS(te->down->x,te->down->y,te->down->r,te->down->g,te->down->b));

             //cout<<"-->";
              //te=te->down;
              //enlace=enlace->down;
             cadenasdex+="node[shape=box height=0.5 style=filled fontcolor=black fillcolor=";
             cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<te->down->colorf.c_str()))->str()+"]\n";
             cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(te->down)))->str();
             cadenasdex+="[label=\"";
             cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<te->down->letra.c_str()))->str();
             cadenasdex+="\" style=radial,group=";
             cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<te->down->x))->str();
             cadenasdex+="];\n";

             enlacesx+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(enlace->down)))->str();




             te=te->down;
            enlace=enlace->down;

            if(enlace->down != NULL ){
               enlacesx+="->";
            }


         }
        enlacesx+="[dir=both]\n";


     }


    cout<<"\n";
     temp=temp->right;

     }

 //todo lo que esta abajo es pata imprimir el ultimo nodo

     cout<<temp->x;

     cout<<"-->";
     if(temp->down != NULL){
         //cout<<temp->down->g;

         enlacesx+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temp->right)))->str();
         enlacesx+="->";

         NodoMatriz *te=temp;
         NodoMatriz *enlace=temp;

          while(te->down != NULL){
              //cout<<te->down->r<<","<<te->down->g<<","<<te->down->b;

    // ls2->InsertarLS(new NodeLS(te->down->x,te->down->y,te->down->r,te->down->g,te->down->b));

              //cout<<"-->";

              cadenasdex+="node[shape=box height=0.5 style=filled fontcolor=black fillcolor=";  
              cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<te->down->colorf.c_str()))->str()+"]\n";
              cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(te->down)))->str();
              cadenasdex+="[label=\"";
              cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<te->down->letra.c_str()))->str();
              cadenasdex+="\" style=radial,group=";
              cadenasdex+=static_cast<std::ostringstream*>(&(std::ostringstream()<<te->down->x))->str();
              cadenasdex+="];\n";

              enlacesx+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(te->down)))->str();
             // enlacesx+="->";

              te=te->down;
              enlace=enlace->down;

              if(enlace->down != NULL ){
                 enlacesx+="->";
              }


          }

    enlacesx+="[dir=both]";

     }

     cout<<"\n";


    }else{ cout<<"NO SE PUEDEN MOSTRAR LOS NODOS X\n"; }

}

void Matrizz::print_nodos_y(){

    if(head!=NULL && head->right!=NULL && head->down!=NULL){

     NodoMatriz *temp=head->down;
     cadenasdey="";
     enlacesy="";
     //ls=new ListaS();//inicializar una nueva lista simple para linealizar por fila

     while(temp->down != NULL){

     cout<<temp->y;
     cout<<"-->";

     enlacesy+="{rank=same;";
     enlacesy+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temp->down+1)))->str();
     enlacesy+="->";

     if(temp->right != NULL){

         NodoMatriz *tey=temp;
         NodoMatriz *enlacey=temp;//puntero para hacer o recorrer los enlaces horizontalmente

          while(tey->right != NULL){
             // cout<<tey->right->r<<","<<tey->right->g<<","<<tey->right->b;


     // ls->InsertarLS(new NodeLS(tey->right->x,tey->right->y,tey->right->r,tey->right->g,tey->right->b));//linealizacion por FILA


        //cout<<"-->";


              cadenasdey+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(tey->right)))->str();
              cadenasdey+="[label=\"";
              cadenasdey+=static_cast<std::ostringstream*>(&(std::ostringstream()<<tey->right->letra.c_str()))->str();
             // cadenasdey+="\" style=radial,group=";
             // cadenasdey+=static_cast<std::ostringstream*>(&(std::ostringstream()<<tey->right->y))->str();
              cadenasdey+="\"];\n";

              enlacesy+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(enlacey->right)))->str();



              tey=tey->right;//este ya estaba originalmente para imprimir los enlaces en consola
              enlacey=enlacey->right;

              if(enlacey->right != NULL){
                  enlacesy+="->";
              }


          }
          enlacesy+="[dir=both] } \n";


     }
    cout<<"\n";
     temp=temp->down;

     }

 //*********************** todo lo de abajo es para imprimir el ultimo nodo **************************
     cout<<temp->y;

     cout<<"-->";
     if(temp->right != NULL){
        // cout<<temp->right->g;

         enlacesy+="{rank=same;";
         enlacesy+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temp->down+1)))->str();
         enlacesy+="->";


         NodoMatriz *tey=temp;
         NodoMatriz *enlacey=temp;

          while(tey->right != NULL){
             // cout<<tey->right->r<<","<<tey->right->g<<","<<tey->right->b;


         // ls->InsertarLS(new NodeLS(tey->right->x,tey->right->y,tey->right->r,tey->right->g,tey->right->b));//linealizacion por FILA


              //cout<<"-->";


              cadenasdey+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(tey->right)))->str();
              cadenasdey+="[label=\"";
              cadenasdey+=static_cast<std::ostringstream*>(&(std::ostringstream()<<tey->right->letra.c_str()))->str();
              cadenasdey+="\"";
              //cadenasdey+="\" style=radial,group=";
              // cadenasdey+=static_cast<std::ostringstream*>(&(std::ostringstream()<<tey->right->y))->str();
              cadenasdey+="];\n";

              enlacesy+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(tey->right)))->str();



              tey=tey->right;//ya estaba originalmente
              enlacey=enlacey->right;


              if(enlacey->right != NULL){
                  enlacesy+="->";
              }

          }
          enlacesy+="[dir=both] }";

     }

     cout<<"\n";


    }else{ enlacesy+="\n\n}\n"; cout<<"NO SE PUEDE MOSTRAR NODOS Y\n"; }

}

string Matrizz::write_file(){

         string cadena=" ";

     cadena+="digraph ";
     cadena+="tablero";
     cadena+="{ \n\n";
     
     cadena+="graph[ranksep= \"0.5\",nodesep= \"0.5\"];\n";

     cadena+="subgraph cluster_1 {\n\n";
     
     cadena+="fontname=algerian\n";
     cadena+="label= \"Matriz de Letras \";\n ";
     cadena+="labelloc=t;\n";
     cadena+="fontcolor=blue4;\n";
     cadena+="fontsize=25;\n";
     cadena+="style=filled;\n";
     cadena+="fillcolor=steelblue2;\n\n";

     //cadena+="graph[ranksep= \"0.5\",nodesep= \"0.5\"];\n";
     cadena+="node [shape=box fillcolor=chartreuse3];\n";
     cadena+="mt[label= \"Matrix\" style=radial group=0]\n";

     cadena+="{rank=same;\n";

      //cadena2+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(tem->primero)))->str();
      //cadena2+=  static_cast<std::ostringstream*>(&(std::ostringstream()<<insercion->dato))->str();
if(head!=NULL && head->right!=NULL  && head->down!=NULL){

     NodoMatriz *temp=head;
     NodoMatriz *enlase=head;
     NodoMatriz *temp2=head;
     NodoMatriz *enlase2=head;

        

     while(temp->right != NULL){

         temp=temp->right;
         cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temp->right)))->str();
         cadena+="[label= \"";
         cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temp->x))->str();
         cadena+=" \" style=radial,group=";
         cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temp->x))->str();
         cadena+="]\n";


    // temp=temp->right;

     }

    cadena+="mt->";

    while(enlase->right != NULL){
        enlase=enlase->right;
        cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(enlase->right)))->str();

        if(enlase->right!=NULL){
        cadena+="->";
        }
    }
    cadena+="[dir=both];";
    cadena+="};\n\n";


//Es para imprimir las columnas de la matriz

    while (temp2->down != NULL){

        temp2=temp2->down;
        cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(temp2->down+1)))->str();
        cadena+="[label= \"";
        cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temp2->y))->str();
        cadena+=" \" style=radial,group=0";
        //cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<temp2->y))->str();
        cadena+="]\n";

    }

       cadena+="mt->";
       while(enlase2->down != NULL){
           enlase2=enlase2->down;
           cadena+=static_cast<std::ostringstream*>(&(std::ostringstream()<<reinterpret_cast<int64_t>(enlase2->down+1)))->str();

           if(enlase2->down!=NULL){
           cadena+="->";
           }
       }
       cadena+="[dir=both];";

        }else{cout<<"NO SE PUEDE GRAFICAR PORQUE NO HAY NADA\n"; }


     return cadena;


}

void Matrizz::Graficar(){

    print_nodos_y();
    //mt->print_allheaders();
    print_nodos_x();

   // string path="Graphics/"+nombreCarpeta+"/"+nombre+".dot";


    FILE* fichero;
    //fichero = fopen("Graphics/Matrix.dot", "w");
    //fichero = fopen("/home/mario/Escritorio/EDD_2S/Proyecto1_EDD_2S/Graphics/Matrix.dot", "w");

    fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Table_Juego.dot", "w");



    fputs(write_file().c_str(),fichero);

    fputs("\n\n",fichero);
    fputs(cadenasdex.c_str(),fichero);
    fputs("\n\n",fichero);
    fputs(enlacesx.c_str(),fichero);

    fputs("\n\n",fichero);
    fputs(cadenasdey.c_str(),fichero);
    fputs("\n\n",fichero);
    fputs(enlacesy.c_str(),fichero);


    fputs("\n }\n\n}",fichero);
    fclose(fichero);

    system("dot -Tpng  -O C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Table_Juego.dot");
    //system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Table_Juego.dot.png");
    //NO LO VAMOS ABRIR AUTOMATICAMENTE, PORQUE ESTA EL HTML VASICO


}