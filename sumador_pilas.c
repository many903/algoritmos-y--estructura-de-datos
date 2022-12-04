#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int numero;
    struct nodo *siguiente;

};

void agregar(int numero);
void eliminar();
int imprimirUltimo();

struct nodo *superior = NULL;

void agregar(int numero)
{
    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
    nuevoNodo -> numero = numero;
    nuevoNodo -> siguiente = superior;
    superior = nuevoNodo;


}

void eliminar()
{
    if(superior != NULL)
    {
        struct nodo *temporal = superior;
        superior = superior->siguiente;
        free(temporal);

    }

}


int imprimirUltimo()
{
  if (superior == NULL)
    return -1;
  return superior -> numero;
} 

int main()
{
    int eleccion;
    int numero;

    while (eleccion != -1)
    {
        
    //printf("1-Insertar en la pila \n2-Eliminar de la pila \n3-impimir el ultimo\n");
    scanf("%d",&eleccion);

    switch(eleccion)
    {
        case 1:
        scanf("%d",&numero);
        agregar(numero);
        break;

        case 2:
        eliminar();
        break;

        case 3:
        printf("%d\n", imprimirUltimo());
        break;

    }



    }
    

}