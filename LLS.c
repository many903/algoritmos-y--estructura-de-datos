/*lista ligada simple*/
#include <stdio.h>
#include <stdlib.h>

/*declaracion de la estructura de base*/
typedef struct Mode
{   int dato;
    struct Mode *siguiente;
}   nodo;

/*variable global*/
nodo *inicio = NULL;

/*insertar un valor de incio a la lista*/
void insertar(int valor)
{   nodo *nuevo;
    nuevo = malloc(sizeof(nodo));
    nuevo->dato = valor;
    if(inicio = NULL)
    {   inicio =nuevo;
        nuevo-> siguiente = NULL;
        }}
