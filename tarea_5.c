/*lista doblemente ligada */
#include <stdio.h>
#include <stdlib.h>

//Estructura del nodo
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
} NODO;


NODO *CrearNodo(int dato);
int InsertarInicio(NODO **inicio, int dato);
int InsertarFinal(NODO **inicio, int dato);
void ImprimirLista(NODO *inicio);
int EliminarNodo(NODO **inicio, int dato);


int main()
{
    NODO *inicio = NULL;

    InsertarInicio(&inicio, 1);
    InsertarInicio(&inicio, 2);
    InsertarFinal(&inicio, 3);
    InsertarFinal(&inicio, 4);
    EliminarNodo(&inicio, 4);
    ImprimirLista(inicio);
    system("pause>nul");

    return 0;
}

//Función para eliminar un nodo de la lista
int EliminarNodo(NODO **inicio, int dato)
{
    NODO *actual = *inicio, *ant = NULL, *sig = NULL;

    while(actual != NULL)
    {
        if(actual->dato == dato)
        {
            if( actual == *inicio)
            {
                *inicio = actual->siguiente;
                if( actual->siguiente != NULL)
                    actual->siguiente->anterior = NULL;
            }
            else if( actual->siguiente == NULL)
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                ant->siguiente = NULL;
            }
            else
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                sig = actual->siguiente;
                actual->siguiente = NULL;
                ant->siguiente = sig;
                sig->anterior = ant;
            }
            free(actual);
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

//Función para insertar al final de la lista
int InsertarFinal(NODO **inicio, int dato)
{
    NODO *nuevo = NULL, *nAux = *inicio;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        while(nAux->siguiente != NULL){ nAux = nAux->siguiente;}
        nuevo->anterior = nAux;
        nAux->siguiente = nuevo;
        return 1;
    }
    return 0;
}

//Función para imprimir la lista
void ImprimirLista(NODO *inicio)
{
    NODO *nAux = inicio;

    while(nAux != NULL)
    {
        printf("%d ", nAux->dato);
        nAux = nAux->siguiente;
    }
}

//Función para insertar al inicio de la lista
int InsertarInicio(NODO **inicio, int dato)
{
    NODO *nuevo = NULL;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *inicio;
        nuevo->anterior = NULL;
        if( *inicio != NULL)
            (*inicio)->anterior = nuevo;
        *inicio = nuevo;
        return 1;
    }
    return 0;
}

//Función para crear un nuevo nodo
NODO *CrearNodo(int dato)
{
    NODO* nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));
    if( nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}
