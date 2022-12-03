#ifndef pila_h
#define pila_h

#iclude <stdio.h>
#iclude <stdlib.h>
/*


*/
typedef char* pila;

typedef struct nodo {
    struct nodo *next;
}Nodo;

typedefstruct pila {
    Nodo* cabeza;
}Pila;

Nodo* CrearNodo(int n);
void destruirNodo(Nodo* nodo);
void consume ();

int main(){

}
Nodo* crearNodo(int n){
    Nodo* nodo=(Nodo*)malloc(sizeof(Nodo));
    nodo-> n = n;
    nodo-> next = NULL;
    return nodo;
}

void destruirNodo(Nodo* nodo){
    nodo-> next = NULL;
    free(nodo);
}
void Apilar(Pila* pila, n){
    Nodo* nodo= crearNodo(n);
    nodo-> next = pila->cabeza;
    piola->cabeza = nodo;
}
 void consimir (){
    if (pila -> cabeza!=NULL){
        nod
    }
 }