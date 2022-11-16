#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

typedef struct Model 
{
     char lista1[35];
     char lista2[35];
     char lista3[35];
     char lista4[35];
     char lista5[11];
} listas;

int menu_contacto();

listas leer();

void leeTeclado(listas p[MAX], int n);

void leeDatos(listas p[MAX], int n);

void escribeDatos(listas p[MAX],int n);

void despliegaDatos(struct Model q[MAX], int n);

void desplegar(struct Model q);

listas busca(struct Model q[MAX], int n);

void alta(listas p[MAX], int *n);

listas modificar(struct Model q[MAX],int n,int menu_contacto());

int busca_elint(struct Model p[MAX], int n );

void baja(listas q[MAX], int n);


int main ( )
{
        listas p[MAX];
        int n,i, opcion;
        scanf("%d",&n);    
    do
    {
        opcion = menu();   
        switch(opcion)
        {
            case 1: leeTeclado(p,n);
                    break;
            case 2: leeDatos(p,n);
                    break;
            case 3: escribeDatos(p,n);
                    break;
            case 4: despliegaDatos(p,n);
                    break;
            case 5: desplegar(busca(p,n));
			        break;
			case 6: desplegar(modificar(p,n,menu_contacto));
			        break;
            case 7: alta(p,&n);
                    break;
            case 8: baja(p,n);
                    break;
            default: printf("OpciÃ³n invalida %d\n", opcion);
        }
    } while (opcion != 0);
        return 0;
}

void baja(listas q[MAX], int n)
{
	int i,a;
    a=busca_conint(q,n);
    listas eq;
    for(i=a;i<n;i++){
    	q[i]=q[i+1];
    }
	n=n-1;		
}

int busca_conint(struct Model q[MAX], int n )
{
    int i;
    char lista1[35];
    listas eq;
    printf("lista2 del Modeluego que deseas eliminar: ");
    gets(lista1);
    for(i=0;i<n;i++)
    {
        if (strcmp(lista1,q[i].lista1) == 0) //iguales
            return(i);
    }
    return(-1);
}

listas busca(struct Model q[MAX], int n )
{
    int i;
    char lista1[35];
    listas eq;
    printf("lista2 del Modeluego que deseas buscar: ");
    scanf("%s",lista1);
    for(i=0;i<n;i++)
    {
        if ( strcmp(lista1,q[i].lista1) == 0) //iguales
            return(q[i]);
    }
}

listas modificar(struct Model q[MAX],int n,int menu_contacto())
{
    int opcion,i;
	char lista11[35];
	char lista21[35];
	char lista31[20];
	char lista41[7];
	char lista51[10];
    listas eq;
	printf("lista2 del Modeluego que deseas editar: ");
    scanf("%s",lista11); 
     do
     {
        opcion= menu_contacto();  
        //Aqui van las funciones 
        switch(opcion)
        {
            case 1:     
            	    printf("Introduce el lista2 correcto: ");
			        gets(lista21);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(lista11,q[i].lista1) == 0){
                          strcpy(q[i].lista2,lista21);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 2: 
			        printf("Introduce la clasificacion correcta: ");
			        gets(lista31); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(lista11,q[i].lista1) == 0){
                          strcpy(q[i].lista3,lista31);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 3: 
			        printf("Introduce el lista4 correcto: ");
			        gets(lista41);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(lista11,q[i].lista1) == 0){
                          strcpy(q[i].lista4,lista41);
                      	  return(q[i]);
					  }
                    }
                break;
            case 4: 
			        printf("Introduce el lista5 que hay para el Modeluego : ");
			        gets(lista51); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(lista11,q[i].lista1) == 0){
                          strcpy(q[i].lista5,lista51);
                      	  return(q[i]);
					  }
                    }
                break;
            default: printf("OpciÃ³n invalida %d\n", opcion);
        }
    } while (opcion != 0);
}

void alta(listas p[MAX], int *n)
{
    p[*n] = leer();
    (*n)++;
}

void leeTeclado(listas p[MAX], int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            p[i] = leer();
        }
}

void leeDatos(listas p[MAX], int n)
{
    FILE * fp;
    int tam, i;
    fp = fopen("datos", "rb");
    if (fp == NULL)
    {
        printf("error al abrir el archivo\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        tam = fread(&p[i],sizeof(p[i]),1,fp);
        if (tam > 0) printf("registro leido\n");
    }
}

void escribeDatos(listas p[MAX],int n)
{
    FILE * fp;
    int tam, i;
    fp = fopen("datos", "wb");
    if (fp == NULL)
    {
        printf("error al abrir el archivo\n");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        tam = fwrite(&p[i],sizeof(p[i]),1,fp);
        if (tam > 0) printf("registro escrito\n");
    }
}

void despliegaDatos(struct Model q[MAX], int n)
{
     int i;
     printf("\t   lista1  lista2   lista3     lista4    lista5\n");
     for(i=0; i<n; i++)
     {
         desplegar(q[i]);
     }
}

void desplegar(struct Model q)
{
    printf("\n%15s %7s %6s %9s %9s\n",
           q.lista2,q.lista2,q.lista3,q.lista4,q.lista5);
}

struct Model leer()
{
    struct Model listas;
    printf("lista1: ");
    gets(listas.lista1);
    printf("lista2: ");
    gets(listas.lista2);
    printf("lista3: ");
    gets(listas.lista3);
    printf("lista4: ");
    gets(listas.lista4);
    printf("lista5: ");
    gets(listas.lista5);
    getchar(); /* lee enter */
    return (listas);
}

int menu()
{
    int opc;
    printf("\n listas \n");
    printf("1. Lectura de datos\n");
    printf("2. verificar si la lista esta llena\n");
    printf("3. Escritura de Modeluego a un archivo\n");
    printf("4. Consulta de un Modeluego disponibles\n");
    printf("5. Busca en una lista\n");
    printf("6. Modifica una lista \n");
    printf("7. Alta de un nuevo lugar en la lista\n");
    printf("8. Baja de un lugar en la lista \n");
    printf("0. Terminar\n");
    printf("Selecciona opciÃ³n: \n");
    scanf("%d",&opc);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opc);
}

int menu_contacto(){
    int opci;
    printf("\nElije el la opcion a editar\n");
    printf("1. lista2\n");
    printf("2. lista3\n");
    printf("3. lista4\n");
    printf("4. lista5\n");
    printf("0. Terminar\n");
    printf("Selecciona opciÃ³n: \n");
    scanf("%d",&opci);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opci);
}