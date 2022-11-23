/*Desarrolla un programa para administrar una LLS de enteros, sobre la que podamos 
ejecutar las 5 operaciones básicas descritas en la unidad 3. Luego, desde un módulo
"main()" debemos ofrecer al usuario la posibilidad de ejecutar cualquiera de las 
instrucciones soportadas. Para la operación 2, puedes tomar el mismo código del ciclo
de recorrido que propusimos en la Tarea 3. 
Manuel Enrique Garcia Neve 2193077979*/


//no se si estoy bien aun me falta 

#include <stdio.h>
#include <stdlib.h>

typedef struct Molde 
{   int dato;
    struct Molde *siguiente;
}   Nodo;

Nodo *inicio = NULL;

void insertar ( int x)
{
    Nodo *nuevo;
    nuevo = malloc(sizeof(Nodo));
    nuevo-> dato = x;
    if (inicio == NULL)
    {   inicio = nuevo;
        nuevo -> siguiente =NULL;
    }
    else 
    { nuevo ->siguiente = inicio;
      inicio = nuevo;
    }  
}

int main()
{
    insertar(4);
    printf("Dato en inicio : %d\n" ,inicio->dato) ;
    
    return 0;
}   
    