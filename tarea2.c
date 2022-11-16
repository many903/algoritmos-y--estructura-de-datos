/*librerias y veriables globales*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

/*estructura de control*/
typedef struct Molde
{   
    float lista[35]
} lista ;

/*declaracion de funciones dependientes de lista p[MAX]*/
void full(lista p[MAX]); /* falta */
void elementos(lista p[MAX]);
void insertar(lista p[MAX]);
void remover(lista p[MAX]);
void leeteclado(lista p[MAX]);
void lee()

/*funcion main*/
int main()
{
    lista p [MAX];
    int i, n, opcion;
    scanf ("%d",&n);
    do
    {
        pocion = menu();
        switch(opcion)
        {
            case 1: leeteclado(p);
                break;
                
            case 2: full();
                break;
                
            case 3: elementos();
                break;
            
            case 4: insertar();
                break;
            
            case 5: remover();
                break;
            default: printf("OpciÃ³n invalida %d\n", opcion);
        }
    }while (opcion != 0);
        return 0;
}
/*definir cada una de las funciones y como deven funcionar*/

/*dar debaja un elemento de la lista*/
void remover(lista p[MAX], int n)
{
	int i,a;
    a=busca_conint(q,n);
    lista eq;
    for(i=a;i<n;i++){
    	q[i]=q[i+1];
    }
	n=n-1;		
}
/*insertar un elemento de la lista */
void insertar(lista p[MAX], int *n)
{
    p[*n] = leer();
    (*n)++;
}

/*entrega los datos de la lista */
void despliegaDatos(struct Molde q[MAX], int n)
{
     int i;
     printf("\t lista\n");
     for(i=0; i<n; i++)
     {
         desplegar(q[i]);
     }
}

/*lee los datos desde el teclado del usuario*/
void leeteclado(Gamer p[MAX], int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            p[i] = leer();
        }
}

/*crea una estructuraque me opermite leer */
struct leer()
{
    struct Molde;
    printf("inserta un numero o caracter:");
    gets(Molde.lista)
}

/*menu*/
int menu()
{
    int opc;
    printf("\n edicion de una lista \n");
    printf("1. Lectura de datos\n");
    printf("2. verificar si la lista esta llena\n");
    printf("3. elementos de un archivo\n");
    printf("4. Consulta de un videojuego disponibles\n");
    printf("5. Busca un videojuego\n");
    printf("0. Terminar\n");
    printf("Selecciona una opción: \n");
    scanf("%d",&opc);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opc);
}
void full(){
    for (int i=0; i<30; i++){
        if (i =<0){
            printf("1");
        
        }
        else: printf("0");
    }
}
