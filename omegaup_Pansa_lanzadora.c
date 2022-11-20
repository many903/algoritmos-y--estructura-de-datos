/*lograr que la lista me muestre el numero de amigos y salga de una lista entre 2 a 50
caracteres el valor mas alto y el mas bajo de la lista*/
#include <stdio.h>
#include <stdlib.h>


/*estructura nodo*/
typedef struct Model{
    int amigos
    int distancia 
    struct nodo * next;
}nodo;
/*funciones*/ 
nodo * incialista()
{
    return NULL;
}
nodo * crearnodo(int amigos, int distancia)
{
    nodo *aux = malloc(sizeof(amigos));
    
}
int main()
{
    nodo * lista = incialista();
    nodo * nuevo = crearnodo(/*datos que necesita el nodo para funcionar*/);
    lista = agragarPio(lista, nuevo);
}
