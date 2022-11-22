/*tarea 3  ejrcicio 1*/
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Molde
{
    
    int dato;
    struct Molde *siguiente;
} Nodo;

/*varible global "inicio de lista" */
Nodo *inicio = NULL;

/*incertar el valor al inicio de la lista */
void insertar(int valor)
{   Nodo*nuevo;
    nuevo =  malloc(sizeof(Nodo));
    nuevo -> dato = valor;
    if(valor = NULL) {
        inicio = nuevo;
        nuevo -> siguiente = NULL;
    }
    else{
        nuevo -> siguiente = inicio;
        inicio = nuevo;
    }
}

void recorrido()
{   Nodo*aux= inicio;
    int longitud=0;

    printf("\nInicio del recorrido\n\n");
    if (aux ->siguiente != NULL) {
        while (aux -> siguiente != NULL){

            printf("%d\n");
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