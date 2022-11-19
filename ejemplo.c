

#include<stdio.h>
#include<stdlib.h>

typedef struct Molde{
    int dato;
    struct Molde *siguiente;
} Nodo;

/*********************/
Nodo *inicio = NULL;

void insertar(int x)
{
    Nodo *nuevo;
    nuevo = malloc(sizeof(n));
    nuevo->dato = x;
    if(inicio == NULL){
        inicio = nuevo;
        nuevo -> siguiente = NULL;
    }
    else{
        nuevo -> siguiente = inicio;
        inicio = nuevo;
    }
}

int main ()
{
    int n = scanf("cuantos juegan :%d", &n)
    insertar(n);
    printf("Dato de inicio(lls): %d\n",inicio->dato);
    return 0;
}