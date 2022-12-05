/*librerias*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*estructuras*/
typedef struct Model
{
    char accion[10]; /*accion a realizar*/
    int valor;/*valor que va a tomar*/
}accval;

typedef struct nodo{
    accval *dato;
    struct nodo *siguiente;
}Nodo;

typedef struct pila {
    Nodo *tope;
    int total; /*cuantos vamos? */
}Pila;
/*definicion de funcion*/
accval* crearaccion(char accion[10], int valor);
Nodo* crearNodo(accval *accval);
Nodo* crearPlia();
int estaVacia(pila *plia);
void Introduce(Pila *pila,Nodo *nodo);
void imprimir(Pila *pila);
int suma(Pila *pila);
void pop (Pila *pila);
/*main*/
int main(){
    Pita *p;
    Coche *c1;
    Nodo *n;
    p=crearPila();
    av1=crearaccion("AGREGAR",2);
    n=crearNodo(av1);
    Introduce(p,n);// ingresa el primer nodo
    imprimir(p);
    pop(p);
    imprimir(p);
    return 0;
}
/*funciones */
/*1 si esta  vacia----0 si no esta vacia*/
int estaVacia(Pila *plia){
    if (Pila->total==0){
        return 1;
    } else {
        return 0;
    }
}
accval* crearAccion(char accion[10], int valor){
    accval *aux = malloc(sizeof(accval));
    strcpy(aux->accion, accion);
    aux->valor = valor;
    return aux;
}

Nodo* crearNodo(accval *accval){
    Nodo *aux= malloc(sizeof(accval));
    aux->dato=accval;
    aux->siguiente = NULL;
    return(aux);
}
Nodo* crearPlia(){
    Pila *aux=malloc(sizeof(accval))
    aux->tope=NULL;
    aux->total=0;
}
void Introduce(Pila *pila,Nodo *aux){
    if(estaVacia(pila)==1){
        Pila->tope=aux;
    } else {
        aux->siguiente=pila->tope;
        pila->tope=aux;
    }
    pila->total++;

}
void imprimir(Pila *pila){
    Nodo *aux=pila->tope;
    accval *A;
    while (aux!=NULL) {
        A= aux->dato;
        printf("%s %d \n",A->accion, A->valor);
        aux=aux->siguiente;
    }
}
int suma(Pila *pila){
    Nodo *aux=pila->tope;
    accval *A;
    while (aux!=NULL) {
        A= aux->dato;
        aux=aux->siguiente;
        aux2=aux->anterior;
        if((pila->accion)=="agregar"){
            aux->dato=aux->anterior->valor+aux->valor;
            pop(p);
        }
    }   

}
void pop (Pila *pila){
Nodo *aux=NULL;

if ( !estaVacia(pila)){
    aux=pila->tope;
    pila->tope=pila->tope->siguiente;
    }
return aux;
}