// LIBRERIAS QUE SE USARON 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

//DEFINIR LA ESTRUCTURA DEL POBLEMA

typedef struct estudiante 
{
     char nombre[35];
     char matricula[30];
     char UEA[35];
     char calificacion[35];
} est;

//FUNCIONES QUE SE APLICARAN EN EL PROGRMA

int menu_alumno();

est leer();

void leeTeclado(est p[MAX], int n);

void leeDatos(est p[MAX], int n);

void escribeDatos(est p[MAX],int n);

void despliegaDatos(struct estudiante q[MAX], int n);

void desplegar(struct estudiante q);

est busca(struct estudiante q[MAX], int n);

void alta(est p[MAX], int *n);

est modificar(struct estudiante q[MAX],int n,int menu_alumno());

int busca_elint(struct estudiante q[MAX], int n );

void baja(est q[MAX], int n);

//FUNCIONES PRINCIPALES DEL PROGRMA

int main ( )
{
        est p[MAX];
        int n,i,opcion;
        scanf("%d",&n);    
    do{
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
			case 6: desplegar(modificar(p,n,menu_alumno));
			        break;
            case 7: alta(p,&n);
                    break;
            case 8: baja(p,n);
                    break;
            default: printf("Opci贸n invalida %d\n", opcion);
        }
    } while (opcion != 0);
        return 0;
}
//FUNCION BAJA

void baja(est q[MAX], int n)
{
	int i,a;
    a=busca_elint(q,n);
    est eq;
    for(i=a;i<n;i++){
    	q[i]=q[i+1];
    }
	n=n-1;		
}
//FUNCION BUSCA_ELIMINA

int busca_elint(struct estudiante q[MAX], int n )
{
    int i;
    char nombre[35];
    est eq;
    printf("Nombre del alumno que deseas eliminar: ");
    gets(nombre);
    for(i=0;i<n;i++)
    {
        if (strcmp(nombre,q[i].nombre) == 0) //iguales
            return(i);
    }
    return(-1);
}
//Funcion BUSCA

est busca(struct estudiante q[MAX], int n )
{
    int i;
    char nombre[35];
    est eq;
    printf("Nombre del alumno que deseas buscar: ");
    gets(nombre);
    for(i=0;i<n;i++)
    {
        if ( strcmp(nombre,q[i].nombre) == 0) //iguales
            return(q[i]);
    }
}

//FUNCION MODIFICA

est modificar(struct estudiante q[MAX],int n,int menu_alumno())
{
    int opcion,i;
	char nombre[35];
    int matricula[15];
    char UEA[35];
    char calificacion[35];
    est eq;
	printf("Nombre del alumno que deseas editar: ");
    gets(nombre); 
     do
     {
        opcion= menu_alumno();  
        //Aqui se a dar las funciones 
        switch(opcion)
        {
            case 1:     
            	    printf("Introduce matricula nueva: ");
			        gets(matricula);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(nombre,q[i].nombre) == 0){
                          strcpy(q[i].matricula,matricula);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 2: 
			        printf("calificacion: ");
			        gets(calificacion);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(nombre,q[i].nombre) == 0){
                          strcpy(q[i].calificacion,calificacion);
                      	  return(q[i]);
					  }
                    }
                break;
            case 3: 
			        printf("corrije el nombre: ");
			        gets(nombre); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(nombre,q[i].nombre) == 0){
                          strcpy(q[i].nombre,nombre);
                      	  return(q[i]);
					  }
                    }
                break;
            default: printf("Opci贸n invalida %d\n", opcion);
        }
    } while (opcion != 0);
}
//FUNCION DAR DE ALTA EN UN PROGRAMA 

void alta(est p[MAX], int *n)
{
    p[*n] = leer();
    (*n)++;
}
//LEE EL TECLADO

void leeTeclado(est p[MAX], int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            p[i] = leer();
        }
}
//LEE UNA ESTRUCT Y ALMACENA EL ARREGLO

void leeDatos(est p[MAX], int n)
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
//ESCRIBE UNA ESTRUCTURA Y ALMACENA EL ARREGLO

void escribeDatos(est p[MAX],int n)
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
//FUNCION DESPLIEGA LOS DATOS

void despliegaDatos(struct estudiante q[MAX], int n)
{
     int i;
     printf("\t   NOMBRE  matricula UEA calificacion\n");
     for(i=0; i<n; i++)
     {
         desplegar(q[i]);
     }
}
//DESPLIEGA LOS DATOS EN LAS PARTES DE LA ESTRUCTURA 

void desplegar(struct estudiante q)
{
    printf("\n%15s %15d %6s %25s\n",
           q.nombre,q.matricula,q.UEA,q.calificacion);
}
//PIDE Y LEE LOS DATOS PRINCIPALES DEL PROGRAMA
struct estudiante leer()
{
    struct estudiante est;
    printf("Nombre: ");
    gets(est.nombre);
    printf("matricula: ");
    gets(est.matricula);
    printf("UEA: ");
    gets(est.UEA);
    printf("calificacion: ");
    gets(est.calificacion);
    getchar(); /* lee enter */
    return (est);
}
//SE INSERTA EL MENU DE PROGRAMA PROGRAMA PRINCIPAL

int menu()
{
    int opc;
    printf("\n =========================================== \n");
    printf("\n                  💻  ALUMNADO  💻 \n");
    printf("1. Lectura de datos\n");
    printf("2. Lectura de este desde archivo\n");
    printf("3. Escritura de este a un archivo\n");
    printf("4. Consulta de estudiantes insctrito en la uea\n");
    printf("5. Busca un alumno\n");
    printf("6. Modifica info de alumno\n");
    printf("7. Alta de un nuevo alumno\n");
    printf("8. Baja de un alumno ya no insctrito en la uea\n");
    printf("0. Terminar\n");
    printf("Selecciona opción: \n");
    scanf("%d",&opc);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opc);
}
//INSERTA EL MENU DE LA OPCION MODIFICACION

int menu_alumno(){
    int opci;
    printf("\nElije el la opcion a editar\n");
    printf("1. matricula\n");
    printf("2. calificacion \n");
    printf("3. nombre\n");
    printf("0. Terminar\n");
    printf("Selecciona opción: \n");
    scanf("%d",&opci);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opci);
}