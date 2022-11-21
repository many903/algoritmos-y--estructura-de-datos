/*tarea 3  ejrcicio 1*/
#include <stdio.h>
#include <stdlib.h>
 
typedef struct molde
{
    int dato;
    struct Molde *siguiente;
} Nodo;

/*varible global "inicio de lista" */
nodo *inicio = NULL;

/*incertar el valor al inicio de la lista */
void insertar(int valor)
{   nodo*nuevo;
    nuevo =  malloc(sizeof(nodo));
    nuevo -> dato = valor;
    if(valor == NULL) {
        inicio = nuevo;
        nuevo -> siguiente = NULL;
    }
    else{
        nuevo -> siguiente = inicio;
        inicio = nuevo;
    }
}
int main()
{
    insertar
    printf("Dato de en inicio: %d\n",inicio->dato);
}