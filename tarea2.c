*/

// LIBRERIAS QUE SE USARON 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

//DEFINIR LA ESTRUCTURA DEL POBLEMA

typedef struct persona 
{
     char nombre[35];
     char edad[3];
     char UEA[35];
     char facebook[35];
     char telefono[11];
} per;

//FUNCIONES QUE SE APLICARAN EN EL PROGRMA

int menu_contacto();

per leer();

void leeTeclado(per p[MAX], int n);

void leeDatos(per p[MAX], int n);

void escribeDatos(per p[MAX],int n);

void despliegaDatos(struct persona q[MAX], int n);

void desplegar(struct persona q);

per busca(struct persona q[MAX], int n);

void alta(per p[MAX], int *n);

per modificar(struct persona q[MAX],int n,int menu_contacto());

int busca_elint(struct persona q[MAX], int n );

void baja(per q[MAX], int n);

//FUNCIONES PRINCIPALES DEL PROGRMA

int main ( )
{
        per p[MAX];
        int n,i,opcion;
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
            default: printf("Opci贸n invalida %d\n", opcion);
        }
    } while (opcion != 0);
        return 0;
}
//FUNCION BAJA

void baja(per q[MAX], int n)
{
	int i,a;
    a=busca_elint(q,n);
    per eq;
    for(i=a;i<n;i++){
    	q[i]=q[i+1];
    }
	n=n-1;		
}
//FUNCION BUSCA_ELIMINA

int busca_elint(struct persona q[MAX], int n )
{
    int i;
    char nombre[35];
    per eq;
    printf("Nombre del contacto que deseas eliminar: ");
    gets(nombre);
    for(i=0;i<n;i++)
    {
        if (strcmp(nombre,q[i].nombre) == 0) //iguales
            return(i);
    }
    return(-1);
}
//Funcion BUSCA

per busca(struct persona q[MAX], int n )
{
    int i;
    char nombre[35];
    per eq;
    printf("Nombre del contacto que deseas buscar: ");
    gets(nombre);
    for(i=0;i<n;i++)
    {
        if ( strcmp(nombre,q[i].nombre) == 0) //iguales
            return(q[i]);
    }
}

//FUNCION MODIFICA

per modificar(struct persona q[MAX],int n,int menu_contacto())
{
    int opcion,i;
	char nombre[35];
	char edades[5];
	char lugar[20];
	char face[7];
	char cel[10];
    per eq;
	printf("Nombre del contacto que deseas editar: ");
    gets(nombre); 
     do
     {
        opcion= menu_contacto();  
        //Aqui se a dar las funciones 
        switch(opcion)
        {
            case 1:     
            	    printf("Introduce edad nueva: ");
			        gets(edades);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(nombre,q[i].nombre) == 0){
                          strcpy(q[i].edad,edades);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 2: 
			        printf("Introduce el nuevo lugar: ");
			        gets(lugar); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(nombre,q[i].nombre) == 0){
                          strcpy(q[i].direccion,lugar);
                      	  return(q[i]);
					  }
                    }
                    break;
            case 3: 
			        printf("Dame tu face jajaja: ");
			        gets(face);
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(nombre,q[i].nombre) == 0){
                          strcpy(q[i].facebook,face);
                      	  return(q[i]);
					  }
                    }
                break;
            case 4: 
			        printf("Introduce tu numero nuevo: ");
			        gets(cel); 
			        for(i=0;i<n;i++)
                    {
                      if (strcmp(nombre,q[i].nombre) == 0){
                          strcpy(q[i].telefono,cel);
                      	  return(q[i]);
					  }
                    }
                break;
            default: printf("Opci贸n invalida %d\n", opcion);
        }
    } while (opcion != 0);
}
//FUNCION DAR DE ALTA EN UN PROGRAMA 

void alta(per p[MAX], int *n)
{
    p[*n] = leer();
    (*n)++;
}
//LEE EL TECLADO

void leeTeclado(per p[MAX], int n)
{
    int i;
    for(i=0;i<n;i++)
        {
            p[i] = leer();
        }
}
//LEE UNA ESTRUCT Y ALMACENA EL ARREGLO

void leeDatos(per p[MAX], int n)
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

void escribeDatos(per p[MAX],int n)
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

void despliegaDatos(struct persona q[MAX], int n)
{
     int i;
     printf("\t   NOMBRE  EDAD   DIRRECCION     FACEBOOK    TELEFONO\n");
     for(i=0; i<n; i++)
     {
         desplegar(q[i]);
     }
}
//DESPLIEGA LOS DATOS EN LAS PARTES DE LA ESTRUCTURA 

void desplegar(struct persona q)
{
    printf("\n%15s %7s %6s %25s %18s\n",
           q.nombre,q.edad,q.direccion,q.facebook,q.telefono);
}
//PIDE Y LEE LOS DATOS PRINCIPALES DEL PROGRAMA
struct persona leer()
{
    struct persona per;
    printf("Nombre: ");
    gets(per.nombre);
    printf("Edad: ");
    gets(per.edad);
    printf("Direccion: ");
    gets(per.direccion);
    printf("Facebook: ");
    gets(per.facebook);
    printf("Telefono: ");
    gets(per.telefono);
    getchar(); /* lee enter */
    return (per);
}
//SE INSERTA EL MENU DE PROGRAMA PROGRAMA PRINCIPAL

int menu()
{
    int opc;
    printf("\nCONTACTO \n");
    printf("1. Lectura de datos\n");
    printf("2. Lectura de per desde archivo\n");
    printf("3. Escritura de per a un archivo\n");
    printf("4. Consulta de personas disponibles\n");
    printf("5. Busca un contacto\n");
    printf("6. Modifica info de contacto\n");
    printf("7. Alta de un nuevo contacto\n");
    printf("8. Baja de un contacto ya no disponible\n");
    printf("0. Terminar\n");
    printf("Selecciona opci贸n: \n");
    scanf("%d",&opc);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opc);
}
//INSERTA EL MENU DE LA OPCION MODIFICACION

int menu_contacto(){
    int opci;
    printf("\nElije el la opcion a editar\n");
    printf("1. Edad\n");
    printf("2. Lugar\n");
    printf("3. Face\n");
    printf("4. Telefono\n");
    printf("0. Terminar\n");
    printf("Selecciona opci贸n: \n");
    scanf("%d",&opci);
    //printf("OPC: %d", opc);
    //fflush(stdin);
    getchar();
    return (opci);
}