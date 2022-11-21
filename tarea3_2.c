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
{   nodo*aux= inicio;
    int longitud=0;

    print("\nInicio del recorrido\n\n");
    if (aux ->siguiente != NULL) {
        while (aux -> siguiente != NULL){

            printf("%d",nodo*aux -> siguiente);
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