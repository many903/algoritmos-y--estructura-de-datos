/*lograr que la lista me muestre el numero de amigos y salga de una lista entre 2 a 50
caracteres el valor mas alto y el mas bajo de la lista*/
#include <stdio.h>
#include <stdlib.h>


/*estructura de control*/
typedef struct Model{
    int lista [2];
}listas;
/*funciones*/
int arreglo(n);

int main()
{
    int n;
    scanf("%d",&n);
    arreglo(struct Model);
    compara();
}
/*declaramos el arreglo con el que se va a trabajar */
int arreglo(n){
    int i;
    for(i=0;i<n;i++)
        {
            p[i] = leer();
        }
    }
}

struct Model leer()
{
    struct Model listas;
    printf("lista: ");
    gets(listas.lista1);
    getchar(); /* lee enter */
    return (listas);
}