/*tarea 3 parte 2*/
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Molde
{
    int dato;
    struct Molde *siguiente;
} Nodo;

/*varible global "inicio de lista" */
Nodo *inicio = NULL;

/*incertar el valor al inicio de la lista --- modifica la funcion incertar */
void insertar(int x)
{   
    Nodo*nuevo;
    nuevo = malloc(sizeof(Nodo));
    nuevo->dato = x;
    Nodo*anterior;
    Nodo*actual;

    if (inicio == NULL)
    {
        inicio = nuevo;
        nuevo = nuevo -> siguiente= NULL;
    }
    else
    {   
        anterior = NULL;
        actual = inicio;
        while (actual != NULL)
        {   
            anterior = actual;
            actual = actual -> siguiente;
        }
    anterior -> siguiente = NULL;
    }
}

void recorrido()
{   Nodo*aux= inicio;
    int longitud=0;

    printf("\nInicio del recorrido\n\n");
    if (aux ->siguiente != NULL) {
        while (aux -> siguiente != NULL){

            printf("%d",aux -> siguiente);
            aux = aux ->siguiente;
            longitud++;
        }
        longitud++;
    }
    printf("Fin del recorrido\n longitud=%d\n\n", longitud);
}

int main()
{
    insertar(4);
    recorrido();
    printf("Dato de en inicio: %d\n",inicio->dato);
}