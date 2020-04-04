
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
//#include <stdlib.h>//para el random

#include "Structures/ListaDobleCircular.cpp"
#include "Structures/Cola.cpp"
#include "Structures/ArbolBinarioBusqueda.cpp"
#include "Structures/Matriz.cpp"
#include "LPosEspeciales.cpp"
//#include "Structures/ListaSimpleOrdenada.cpp"
//#include "Structures/ListaDoble.cpp"
#include "json.hpp"
#include <unistd.h>

using namespace std;
using json = nlohmann::json;


class Opciones_Programa{

    public:
        Opciones_Programa();
        void opcion_uno();
        void opcion_dos();
        void opcion_tres();
        void opcion_cuatro();
        int ValidarNombre(string nombre);
        void fichas(Cola *cl);
        void HTML(string nom1,string nom2,int pt1,int pt2); 
        void TURNOS(NodoArbol *jug1,NodoArbol *jug2,int pt1,int pt2);

        string ruta;
        Lista_Doble_Circular *lcd;
        Arbol_Binario_Busqueda *abb;
        Cola *cl;
        Matrizz *mt;
        Lista_PE *lpeDobles;
        Lista_PE *lpeTriples;

        NodoArbol *jugador1;
        NodoArbol *jugador2;
        char nombre1[0];
        char nombre2[0];
        int entrada,entrada2;
        int *psnx;
        int *psny;
        string *fichaeliminar;
        int cantLetras=0;
        int dimensionMatriz;
        int abrirHTML=0;
        

}; 

Opciones_Programa::Opciones_Programa(){

    abb=new Arbol_Binario_Busqueda();
    lcd=new Lista_Doble_Circular();
    //cl=new Cola();
    //lpe=new Lista_PE();
    
 }

 //------------------------------------------------------------------------------------------------------------------------

 void Opciones_Programa::TURNOS(NodoArbol *jug1,NodoArbol *jug2,int pt1,int pt2){

    mt=new Matrizz();
    bool salir=false;
    bool salir2=false;

    char opcion;
    char opcion2;
    char letra;

    NodoArbol *nombreJ;
    int puntosGeneral;
    int tur1=1;
    int tur2=0;
    abrirHTML=0;
    //int *psnx;
    //int *psny;

    int puntaje1=0;
    int puntaje2=0;
    

while(salir2!=true){

    opcion2;
    int contt=0;
    string palabraa;
    int verificar=0;
    psnx=new int[30];
    psny=new int[30];
    fichaeliminar=new string[10];
    int posFielim=0;
    cantLetras=0;
    puntosGeneral=0;
    //nombreJ=NULL;

    cout<<"\n1.-Salir Del Juego\n";
    cout<<"\n2.-Iniciar Turno\n";
    cin>>opcion2;

    switch(opcion2){

        case '1':
            //jug1->scoreboard->Insertar(new NodoLSO(puntaje1));
            //jug2->scoreboard->Insertar(new NodoLSO(puntaje2));
            salir2=true;
        break;

        case '2':
        
        if(tur1==1){
            //cout<<"-----*turno1\n";
            nombreJ=jug1;
           // puntosGeneral=puntaje1;
           // puntaje1=puntosGeneral;

            //tur2=2;
            tur1=2;
        }else if(tur1==2){
            //cout<<"-----*turno2\n";
            nombreJ=jug2;
            //puntosGeneral=puntaje2;
            //puntaje2=puntosGeneral;
            tur1=1;
            //tur2=0;
        }
        

    do{
        //x=0;
        //y=0;
        
        bool xb=true,yb=true,lb=true;
        bool letficha=true;
        
        //string palabraa;
        salir=false;
        string lt;
        opcion;
        letra;
        
        string x,y;
        string ltr;
        
        
        cout<<"\n\n----------> Creacion de una Matriz <----------\n\n";
        cout<<" JUGADOR: "<<nombreJ->Nombre_Judador<<endl<<endl;
        cout<<"     1.Insertar\n\n";
        cout<<"     2.Ver Tablero\n\n";
        cout<<"     3.Fichas Disponibles\n\n";
        cout<<"     4.Validar y Terminar Turno\n\n";
        cin>>opcion;
        switch(opcion){

            case '1'://**************************************************************************
                verificar++;
                
                cout<<"Posicion X: ";
                cin>>x;
                cout<<"\nPosicion Y: ";
                cin>>y;
                cout<<"\nDato: "; 
                cin>>letra;

               // cout<<"------>letra:"<<letra<<endl;

                 for(int i=0;i<x.length();i++){

                    if( !( (x[i]>=48 && x[i]<=57) ) ){
                        cout<<"x malo\n";
                        xb=false;
                    }

                }

                for(int i=0;i<y.length();i++){

                    if( !( (y[i]>=48 && y[i]<=57) ) ){
                        cout<<"y malo\n";
                        yb=false;
                    }

                }
                //cout<<"------>letra:"<<letra<<endl;
               
                    if(  !( (letra>=65 && letra<=90) || (letra>=97 && letra<=122) )  ){
                        cout<<"letra malo\n";
                        lb=false;
                    }

                    ltr;
                    if( (nombreJ->fichas->Buscar(ltr+=letra)==true) ){
                            cout<<"es su ficha\n";
                            //ltr;
                            fichaeliminar[posFielim]=ltr;
                            cout<<"mi fichas para eliminar es:"<<fichaeliminar[posFielim];
                            posFielim++;

                    }else if((nombreJ->fichas->Buscar(ltr+=letra)==false)){ cout<<"NO es su ficha\n"; letficha=false;}

                
                
        if( (letficha==true) && (xb==true) && (yb==true) && (lb==true) && (stoi(x)<=dimensionMatriz) && (stoi(y)<=dimensionMatriz) ){
                    palabraa+=letra; 
                    psnx[contt]=stoi(x);
                    psny[contt]=stoi(y);   
                    
                    if( lpeDobles->Buscar(stoi(x),stoi(y))==true ){
                        mt->add(stoi(x),stoi(y),lt+letra,"tomato2");
                    }else if( lpeTriples->Buscar(stoi(x),stoi(y))==true){
                        mt->add(stoi(x),stoi(y),lt+letra,"slateblue3");
                    }else{
                        mt->add(stoi(x),stoi(y),lt+letra);
                    }
                    contt++;
                    cantLetras++;
                    cout<<"se ingreso la ficha\n";

                }else{
                    cout<<"NO se ingreso.Posiciones fuera de rango o No se tiene esa ficha\n";
                    cout<<"Rango de Posiciones de ser Menor o Igual a: "<<dimensionMatriz<<endl;  

                }
                
               // cout<<"------>letra:"<<letra<<endl;

            break;

            case '2'://**************************************************************************
                mt->Graficar();
                HTML(jug1->Nombre_Judador,jug2->Nombre_Judador,puntaje1,puntaje2);
            break;

            case '3'://**************************************************************************
                nombreJ->fichas->Mostrar();

            break;

            case '4'://**************************************************************************

                if(verificar>=3){
                bool respuesta=lcd->Buscar(palabraa);

                if(respuesta==false){
                    cout<<"\nPalabra no encontrada en el Diccionario, Se quitara del Tablero!!\n";
                    

                    //for(int z=0;z<cantLetras;z++){
                    for(int z=0;z<posFielim;z++){

                        //if( (psnx[z]!=0) && (psny[z]!=0) ){
                            cout<<"px:"<<psnx[z]<<",py:"<<psny[z]<<endl;
                        mt->Eliminar(psnx[z],psny[z]);
                        //}
                    }

                }else if(respuesta==true ){
                    for(int z=0;z<posFielim;z++){
                        cout<<"FichaEliminar:"<<fichaeliminar[z];
                       puntosGeneral+=nombreJ->fichas->Eliminar(fichaeliminar[z])->puntos;//PARA ELIMINAR LAS FICHAS EN LA LD DEL JUGADOR
                        
                        //if( (psnx[z]!=0) && (psny[z]!=0) ){
                           // cout<<"Bpx:"<<psnx[z]<<",Bpy:"<<psny[z]<<endl;
                        //mt->Eliminar(psnx[z],psny[z]);
                        //}
                    }

                    if(tur1==2){
                        puntaje1+=puntosGeneral;
                    }else if(tur1==1){
                        puntaje2+=puntosGeneral;
                    }

                    cout<<"\nPUNTAJE:"<<puntosGeneral<<endl;

                    cout<<"\n¡¡¡ Se acepto la palabra !!!\n";

                }

                }else{ cout<<"\n No se han ingresado por lomenos 3 letras\n"; }


                salir=true;


            break;

            default://**************************************************************************
                cout<<"\n!!!!!Opcion Incorrecta\n";
            break;
        }

        


    }while(salir!= true);

        break;

        default:
        cout<<"\nERROR al elegir la opcion\n";
        break;

        }//cierre del switch
        
    }//cierre del primer while



 }//cierre del metodo


//------------------------------------------------------------------------------------------------------------------------

int Opciones_Programa::ValidarNombre(string nombre){

    for(int i=0;i<nombre.length();i++){

        if( !( (nombre[i]>=65 && nombre[i]<=90) || (nombre[i]>=97 && nombre[i]<=122) ) ){
            return 0;
        }

    }

    return 1;

}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::fichas(Cola *cl){

          //cl=new Cola();
          int alfabeto=1;
          int r=0;
          int a=1,b=1,c=1,d=1,e=1,f=1,g=1,h=1,i=1,j=1,l=1,m=1,n=1;
          int nn=1,o=1,p=1,q=1,r2=1,s=1,t=1,u=1,v=1,x=1,y=1,z=1;

    while (alfabeto<=95){

        r=rand() % 25 + 1;

        //fichas(random);
        //alfabeto++;
        
if(r==1 && a<=12){  
    //cout<<"---->\n";
    cl->Insertar(new NodoCola("a",1));
    alfabeto++;
    a++;

}else if(r==2 && e<=12){
    cl->Insertar(new NodoCola("e",1));
    alfabeto++;
    e++;

}
else if(r==3 && o<=9){
    cl->Insertar(new NodoCola("o",1));
    alfabeto++;
    o++;
    
}
else if(r==4 && i<=6){
    cl->Insertar(new NodoCola("i",1));
    alfabeto++;
    i++;
  
}
else if(r==5 && s<=6){
    cl->Insertar(new NodoCola("s",1));
    alfabeto++;
    s++;
    
}
else if(r==6 && n<=5){
    cl->Insertar(new NodoCola("n",1));
    alfabeto++;
    n++;
    
}
else if(r==7 && l<=4){
    cl->Insertar(new NodoCola("l",1));
    alfabeto++;
    l++;
    
}
else if(r==8 && r2<=5){
    cl->Insertar(new NodoCola("r",1));
    alfabeto++;
    r2++;
    
}
else if(r==9 && u<=5){
    cl->Insertar(new NodoCola("u",1));
    alfabeto++;
    u++;
    
}
else if(r==10 && t<=4){
    cl->Insertar(new NodoCola("t",1));
    alfabeto++;
    t++;
    
}else if(r==11 && d<=5){
    cl->Insertar(new NodoCola("d",2));
    alfabeto++;
    d++;

}
else if(r==12 && g<=2){
    cl->Insertar(new NodoCola("g",2));
    alfabeto++;
    g++;
    
}
else if(r==13 && c<=4){
    cl->Insertar(new NodoCola("c",3));
    alfabeto++;
    c++;
    
}
else if(r==14 && b<=2){
    cl->Insertar(new NodoCola("b",3));
    alfabeto++;
    b++;
    
}
else if(r==15 && m<=2){
    cl->Insertar(new NodoCola("m",3));
    alfabeto++;
    m++;
    
}
else if(r==16 && p<=2){
    cl->Insertar(new NodoCola("p",3));
    alfabeto++;
    p++;
    
}
else if(r==17 && h<=2){
    cl->Insertar(new NodoCola("h",4));
    alfabeto++;
    h++;
    
}
else if(r==18 && f<=1){
    cl->Insertar(new NodoCola("f",4));
    alfabeto++;
    f++;
    
}
else if(r==19 && v<=1){
    cl->Insertar(new NodoCola("v",4));
    alfabeto++;
    v++;
    
}else if(r==20 && y<=1){
    cl->Insertar(new NodoCola("y",4));
    alfabeto++;
    y++;

}
else if(r==21 && q<=1){
    cl->Insertar(new NodoCola("q",5));
    alfabeto++;
    q++;
    
}
else if(r==22 && j<=1){
    cl->Insertar(new NodoCola("j",8));
    alfabeto++;
    j++;
    
}
else if(r==23 && nn<=1){
    cl->Insertar(new NodoCola("ñ",8));
    alfabeto++;
    nn++;
    
}
else if(r==24 && x<=1){
    cl->Insertar(new NodoCola("x",8));
    alfabeto++;
    x++;
    
}
else if(r==25 && z<=1){
    cl->Insertar(new NodoCola("z",10));
    alfabeto++;
    z++;
    
}



    }//FIN DEL WHILE

cout<<"\nYA SE INGRESARON TODAS LAS FICHAS\n";
cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<" d:"<<d<<" e:"<<e<<" f:"<<f<<" g:"<<g<<" h:"<<h<<" i:"<<i<<" j:"<<j<<endl;
cout<<"l:"<<l<<" m:"<<m<<" n:"<<n<<" ñ:"<<nn<<" o:"<<o<<" p:"<<p<<" q:"<<q<<" r:"<<r2<<" s:"<<s<<" t:"<<t<<" u:"<<u<<endl;
cout<<"v:"<<v<<" x:"<<x<<" y:"<<y<<" z:"<<z<<endl;



}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_uno(){

    /*lcd=new Lista_Doble_Circular();//para guardar las palabras
    lpeDobles=new Lista_PE();//para guardar los posiciones Dobles
    lpeTriples=new Lista_PE();//para guardar los posiciones Triples*/

    cout<<"\nEscrita la ruta del archivo: ";
    cin>>ruta;

    json j2;
 //string filename = "C:/Users/HP/Desktop/EDD/Proyecto1/entrada.json";
 string filename=ruta;
 /*dimensionMatriz=0;
 int x,y;*/

 ifstream reader(filename);
  if (reader.fail()){
        cout << "El archivo no existe, verifique que la ruta y el archivo exista." << endl << endl;
    }else{
        
        lcd=new Lista_Doble_Circular();//para guardar las palabras
        lpeDobles=new Lista_PE();//para guardar los posiciones Dobles
        lpeTriples=new Lista_PE();//para guardar los posiciones Triples

    
        dimensionMatriz=0;
        int x,y;

     reader>>j2;


    //for (int i = 0; i < j2.size(); i++){ //INICION DE J2

        dimensionMatriz = j2["dimension"];
        cout<<"\n\nDimensioM:"<<dimensionMatriz<<endl;

        json casillas=j2["casillas"];
        
        //for (int j = 0; j < casillas.size(); j++){ //INICIO DE CASILLAS
            
           // cout<<"casillas: "<<j<<endl;
            json dobles=casillas["dobles"];
            for (int y = 0; y < dobles.size(); y++){
                json coordenadas1=dobles[y];
                //cout<<coordenadas1["x"]<<" , "<<coordenadas1["y"]<<endl;
                lpeDobles->Insertar(new NodoLPE(coordenadas1["x"],coordenadas1["y"]));
            }
            lpeDobles->Mostrar();

            json triples=casillas["triples"];
            for (int x = 0; x < triples.size(); x++){
                json coordenadas2=triples[x];
                //cout<<coordenadas2["x"]<<" , "<<coordenadas2["y"]<<endl;
                lpeTriples->Insertar(new NodoLPE(coordenadas2["x"],coordenadas2["y"]));
            }
            lpeTriples->Mostrar();

            json diccionario=j2["diccionario"];
            //json palabra=diccionario["palabra"];
            for(int p=0 ; p<diccionario.size();p++){
                json palabra=diccionario[p];
                //cout<<"palabra: "<<palabra["palabra"]<<endl;
                lcd->Insertar(new NodoLCD(palabra["palabra"]));
               
            }

            
       // } //FIN DE CASILLAS
        
 
        
    } //FIN DE J2
    


    //} //FIN DEL ELSE


        reader.close();

}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_dos(){

    bool salida=false;
    char op;

        //char nombre[20];
        string nombre;
        //cout<<"Presione x para salir\n\n";
        cout<<" Ingrese el Nombre del Jugador(solo letras): ";
        cin>>nombre;



        if( ValidarNombre(nombre)==1){

        abb->Agregar(new NodoArbol(nombre.c_str()));
        entrada++;

        }else{
            cout<<"\nNombre incorrecto,debe ser solo con letras\n";
        }

}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_tres(){

    if(entrada >= 2){
        entrada2++;
    jugador1=NULL;
    jugador2=NULL;
    nombre1;
    nombre2;
   // int random=0;
    bool sa=false;
    bool sa2=false;
    //string fichax,fichax2;
    NodoCola *fichax,*fichax2;
    int vec[2];
    char jue;
    
    
    do{
        
       
    cout<<"\n---------- Jugadores Disponibles ----------\n";
    abb->MostrarJugador();
    cout<<"Elija el primer jugador para la partida:\n";
    cin>>nombre1;
    vec[0]=atoi(nombre1);
    cout<<"Elija el segundo jugador para la partida:\n";
    cin>>nombre2;
    vec[1]=atoi(nombre2);

    //int n1=static_cast<int>(nombre1);
    //int n2=static_cast<int>(nombre2);
   // cout<<"n1: "<<vec[0]<<endl;
   // cout<<" n2: "<<vec[1]<<endl;
    
    if(abb->ObtenerJugador( vec[0] )!=NULL && abb->ObtenerJugador( vec[1] )!=NULL){
       
        jugador1=abb->ObtenerJugador( vec[0] );
        jugador2=abb->ObtenerJugador( vec[1] );
        sa=true;
        cout<<"J1: "<<jugador1->Nombre_Judador<<endl;
        cout<<"J2: "<<jugador2->Nombre_Judador<<endl;

    }else{ cout<<"\nError al elegir alguno de los jugadores,verifique nuevamente\n"; }   
    
    }while(sa!=true);

    //TOCA HACER EL RANDOM PARA METER LAS FICHAS
    cl=new Cola();
    fichas(cl);

   /* cout<<"fic:"<<cl->Eliminar()<<endl;
    cout<<"fic:"<<cl->Eliminar()<<endl;
    cout<<"fic:"<<cl->Eliminar()<<endl;
    cout<<"fic:"<<cl->Eliminar()<<endl;
    cout<<"fic:"<<cl->Eliminar()<<endl;
    cout<<"fic:"<<cl->Eliminar()<<endl;
    cout<<"fic:"<<cl->Eliminar()<<endl;*/

    for (int i = 0; i < 7; i++) {
     
        if( (fichax=cl->Eliminar())!=NULL){
            jugador1->fichas->Insertar(new NodoLD(fichax->ficha,fichax->puntos));
            cout<<fichax->ficha;
        }else{ cout<<"\nSe acabaron las fichas"; }
    }
    cout<<endl;
    for (int j = 0;  j< 7; j++) {
     
        if( (fichax2=cl->Eliminar())!=NULL){
            jugador2->fichas->Insertar(new NodoLD(fichax2->ficha,fichax2->puntos));
            cout<<fichax2->ficha;
        }else{ cout<<"\nSe acabaron las fichas"; }
    }
    
        
        TURNOS(jugador1,jugador2,5,5);
    
    /*do{//PARA LOS TURNOS DE CADA JUGADOR

    cout<<"(1)Salir\n (2)Ver Tablero\n";

    cin>>jue;
    switch(jue){
        case '1':
        sa2=true;
        break;

        case '2':
            //HTML("MARIOT","SANDYG",100,100);
        break;


    }
        

    }while(sa2!=true);*/




    cout<<"estoy fuera\n";

    }else{ cout<<"\nPor lo menos debe de haber ingresado dos Jugadores para elegirlos\n"; }


}

//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::opcion_cuatro(){


    bool salir=false;
    char opcion;

    do{
        cout<<"\n<--------------->[ REPORTES ]<--------------->\n\n";
        cout<<" [a] Diccionario de Palabras(LCD)\n";
        cout<<" [b] Fichas Disponibles en el Juego(COLA)\n";
        cout<<" [c] Usuarios Registrados(ARBOL)\n";
        cout<<" [d] Recorrido Inorden de Usuarios\n";
        cout<<" [e] Recorrido Preorden de Usuarios\n";
        cout<<" [f] Recorrido Posorden de Usuarios\n";
        cout<<" [g] Scoreboard  General del Juego(LSO)\n";
        cout<<" [h] Tablero del Juego(MATRIZ)\n";
        cout<<" [i] Scoreboard por Jugador(LSO)\n";
        cout<<" [j] Fichas por Jugador(LD)\n";
        cout<<" [k] Salir\n";
        cout<<"-----------------------------------------------\n";
        cout<<"Elija una opcion: ";
        cin>>opcion;

        switch (opcion){
        case 'a':
            cout<<"a\n";
            lcd->Graficar();
            break;

        case 'b':
            cout<<"b\n";
            cl->Graficar();
            break;

        case 'c':
            cout<<"c\n";
            abb->Graficar();
            break;

        case 'd':
            cout<<"d\n";
            abb->graph_inorder();
            break;

        case 'e':
            cout<<"e\n";
            abb->graph_preorder();
            break;

        case 'f':
            cout<<"f\n";
            abb->graph_posorder();
            break;
        
        case 'g':
            cout<<"g\n";
            break;

        case 'h':
            cout<<"h\n";
            
            break;

        case 'i':
            cout<<"i\n";


            
            break;

        case 'j':
            
            if(entrada2 >= 1){
            cout<<"i\n";
            char opcc;
            cout<<"(1)Jugador1 (2)Jugador2 \n";
            cin>>opcc;
            switch(opcc){
                case '1':
                jugador1->fichas->Graficar();
                break;

                case '2':
                jugador2->fichas->Graficar();
                break;

                defautl:

                break;
            }

            }else{ cout<<"\nError,Por lo menos se requiere haber iniciado una partida\n"; }

            break;

        case 'k':
            salir=true;
            break;


        default:
            cout<<"Opcion Incorrecta!!!!\n";
            break;
        }




    }while(salir!=true);




}



//------------------------------------------------------------------------------------------------------------------------

void Opciones_Programa::HTML(string nom1,string nom2,int pt1,int pt2){

    string cadena;
    abrirHTML++;

    cadena+="<!DOCTYPE html>\n";
    cadena+="<html>\n";
    cadena+=" <head>\n";
    cadena+="  <meta charset=\"utf-8\">\n";
    cadena+="  <title>SCRABBLE++</title>\n";
    cadena+=" </head>\n";
    cadena+="   <body background=\"C:/Users/HP/Desktop/EDD/Proyecto1/fondo5.jpg\">\n";
    cadena+=" <table border=5 align=\"center\" color=black >\n\n";
    cadena+=" <tr border=\"blue\">\n";
    cadena+="  <th><strong> <font size=5.5 style=\"background-color:black;\" color=white>TABLERO DEL JUEGO</font> </strong></th>\n";
    cadena+="  <th><strong> <font size=5.5 style=\"background-color:black;\" color=white>JUGADOR</font> </strong></th>\n";
    cadena+="  <th><strong> <font size=5.5 style=\"background-color:black;\" color=white>PUNTUACION</font> </strong></th>\n";
    cadena+=" </tr>\n\n";
    cadena+=" <tr>\n";
    cadena+="  <td rowspan=\"2\">  <img src=\" C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/Table_Juego.dot.png\" alt=\"No se puede mostar el Tablero del Juego\" width=\"\"100\"\" height=\"\"100\"\" /> </td>\n";
    cadena+="  <td align=\"center\"> <font size=6 style=\"background-color:yellow;\" color=black>"+ nom1 +"</font> </td>\n";
    cadena+="  <td align=\"center\"> <font size=6 style=\"background-color:orange;\" color=black>"+ to_string(pt1) +"</font> </td>\n";
    cadena+=" </tr>\n\n";
    cadena+=" <tr>\n";
    cadena+="  <td align=\"center\"> <font size=6 style=\"background-color:yellow;\" color=black>"+ nom2 +"</font> </td>\n";
    cadena+="  <td align=\"center\"> <font size=6 style=\"background-color:orange;\" color=black>"+ to_string(pt2) +"</font> </td>\n";
    cadena+=" </tr>\n\n";
    cadena+=" </table>\n";
    //cadena+=" </div>\n";
    cadena+="   </body>\n";
    cadena+="</html>\n";

    FILE *fichero;
    fichero = fopen("C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/TableroJ.html", "w");
    fputs(cadena.c_str(),fichero);
    fputs("\n",fichero);
    fclose(fichero);

    if(abrirHTML==1){
   system("cmd.exe /C start C:/Users/HP/Desktop/EDD/Proyecto1/Graficas/TableroJ.html");
    }

}