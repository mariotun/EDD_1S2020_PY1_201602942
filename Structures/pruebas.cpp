#include "nodo.h"

Nodo::Nodo(char letra, int punteo)
{
    this->letra=letra;
    this->punteo=punteo;
    this->siguiente= nullptr;
}

char Nodo::getLetra()
{
    return this->letra;
}

int Nodo::getPunteo()
{
    return  this->punteo;
}

Nodo *Nodo::getSiguiente()
{
    return  this->siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente)
{
    this->siguiente= siguiente;
}

unsigned long Nodo::getID() const
{
    return (unsigned long)this;
}

string Nodo::getCodigoDOT()
{
    //Color
    string fillcolor;
    switch (this->punteo) {
    case 1:
        fillcolor= "blue";
        break;
    case 2:
        fillcolor= "red";
        break;
    case 3:
        fillcolor= "pink";
        break;
    default:
        fillcolor= "lime";
    }
    char codigo_dot[256];
    sprintf(codigo_dot, "%lu [label=\"%c\", style=filled, fillcolor=%s];\r\n\t", getID(), std::toupper(this->letra), fillcolor.c_str());
    return string(codigo_dot);
}

string Nodo::getFlechaSiguienteCodigoDOT()
{
    if (this->getSiguiente() != nullptr){
        char codigo_dot[256];
        sprintf(codigo_dot, "%lu -> %lu;\r\n\t", getID(), this->siguiente->getID());
        return string(codigo_dot);
    }
    return  "";
}
