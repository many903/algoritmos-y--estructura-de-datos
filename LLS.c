/*archivo de trabajo para clase */
/*lista ligada simple*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    }
    else
    {   nuevo-> siguiente = inicio;
        inicio =nuevo;
    }
}

//recorre la lista y deebuelve su longitud 
int recorrer()
{   nodo *aux = inicio;
    int longitud = 0;

    printf("\n Inicio del recorrido\n");
    if (aux!=NULL)
    {   while (aux->siguiente != NULL)
        {   printf("%d, aux->dato");
            aux = aux->siguiente;
            longitud++;
        }
        longitud++;
        printf("%d,aux->dato");
    }

    return longitud;
}

/*devueleve la posición en que se encuentra un valor, 0 -1en orto caso*/
int buscaDato(int valor)
{   nodo *aux = inicio;
    int pocion = 1;
    
    printf("\n Inicio de la busqueda: \n");
    while((aux != NULL) && (aux->data != valor))
    {   aux = aux->siguiente;
        posición++;
    };
    if (aux != NULL)
        return posición;
    else
        return-1;
}

/*devueleve el apuntador al nodo que esta en una posición particuliar */
nodo *buscaNodo(int pos)
{
    int i = 1;
    nodo *aux 
    while(i < pos && aux != NULL){
        aux = aux->siguiente;
        i++;
    }
    return aux;
}

//recorrido recursivo de la lista 
void visita (nodo *actual)
{
    if(actual != NULL)
    {
        printf("%d", actual->dato);
        
    } 
}
void interccambio (int i, int j)
{
    
}

void buruja ()
{
    for (i=1;i<n-1;i++){
      for(j=0;j<n-1;j++)
        {
          intercambia();
        }
      }
}
    
void cartas ()
{
    for(i=1;i<n-1;i++){
      aux=a(i);
      j=i-1;
      do(j>=0 && j>aux){
        
      }
    }
}
