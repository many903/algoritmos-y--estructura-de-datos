#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

typedef struct Model 
{
     int matricula[35];
     char nombre[35];
     char calif[35];
     char UEA[35];
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
    char matricula[35];
    listas eq;
    printf("nombre del Modeluego que deseas eliminar: ");
    gets(matricula);
    for(i=0;i<n;i++)
    {
        if (strcmp(matricula,q[i].matricula) == 0) //iguales
            return(i);
    }
    return(-1);
}

listas busca(struct Model q[MAX], int n )
{
    int i;
    char matricula[35];
    listas eq;
    printf("nombre del Modeluego que deseas buscar: ");
    scanf("%s",matricula);
    for(i=0;i<n;i++)
    {
        if ( strcmp(matricula,q[i].matricula) == 0) //iguales
            return(q[i]);
    }
}

listas modificar(struct Model q[MAX],int n,int menu_contacto())
{
    int opcion,i;
	char matricula1[35];
	char nombre1[35];
	char calif1[20];
	char UEA1[7];
    listas eq;
	printf("nombre del Modeluego que deseas editar: ");
    scanf("%s",matricula1); 
     do
     {
        opcion= menu_contacto();  
        //Aqui van las funciones 
        switch(opcion)
        {
            case 1:     
            	    printf("Introduce el nombre correcto: ");
			        gets(nombre1);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(matricula1,q[i].matricula) == 0){
                          strcpy(q[i].nombre,nombre1);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 2: 
			        printf("Introduce la clasificacion correcta: ");
			        gets(calif1); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(matricula1,q[i].matricula) == 0){
                          strcpy(q[i].calif,calif1);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 3: 
			        printf("Introduce el UEA correcto: ");
			        gets(UEA1);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(matricula1,q[i].matricula) == 0){
                          strcpy(q[i].UEA,UEA1);
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
     printf("\t   matricula  nombre   calif     UEA   \n");
     for(i=0; i<n; i++)
     {
         desplegar(q[i]);
     }
}

void desplegar(struct Model q)
{
    printf("\n%15s %7s %6s %9s %9s\n",
           q.nombre,q.nombre,q.calif,q.UEA);
}

struct Model leer()
{
    struct Model listas;
    printf("matricula: ");
    gets(listas.matricula);
    printf("nombre: ");
    gets(listas.nombre);
    printf("calif: ");
    gets(listas.calif);
    printf("UEA: ");
    gets(listas.UEA);
    getchar(); /* lee enter */
    return (listas);
}

int menu()
{
    int opc;
    printf("\n =========================================== \n");
    printf("\n                  💻  ALUMNADO  💻 \n");
    printf("1. Lectura de datos\n");
    printf("2. leer desde el archivo\n");
    printf("3. Escritura de datos al archivo\n");
    printf("4. imprime la lista\n");
    printf("5. Consulta a un alumno por matricula \n");
    printf("6. Modifica los datos de un alumno \n");
    printf("7. Alta de un nuevo alumno \n");
    printf("8. Baja de un alumno \n");
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
    printf("1. nombre\n");
    printf("2. calif\n");
    printf("3. UEA\n");
    printf("0. Terminar\n");
    printf("Selecciona opciÃ³n: \n");
    scanf("%d",&opci);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opci);
}