#include <stdio.h>
#include <stdlib.h>


typedef struct producto inventario;
{   char nombre[25];
    char fecha[20];
    char proveedor [30];
    int existencia;
    int codigo;
    float precio_venta;
    struct producto *siguiente;
};
typedef struct producto inventario;

inventro *inicio = NULL;

void insertar (char nombre[25], char fecha[20], char proveedor[30], int existencia, int codigo, float precio_venta)
{
    inventario *nuevo;
    nuevo = malloc(sizeof (inventario));
    nuevo -> nombre, nombre;
    nuevo -> fecha, fecha;
    nuevo -> proveedor, proveedor;
    nuevo -> existencia, existencia;
    nuevo -> codigo,codigo;
    nuevo -> precio_venta, precio_venta;
    inventario *anterior;
    inventario *actual;
    
    if (inicio == NULL)
    {   inicio = nuevo;
        nuevo -> siguiente = NULL;
}
else 
{
    anterior = NULL;
    actual = inicio;
    while (actual != NULL)
    {
        anterior = actual;
        actual= actual -> siguiente;
    }
    anterior -> siguiente = nuevo;
    nuevo -> siguiente = NULL;
    
    }
}

int main () {
    insertar("Chocolate", "26/10/22", "Suiza", 5,3,14.00);
    
    printf("Nombre %s\n", inicio->Nombre);
    printf("fecha %s\n", inicio->fecha);
    printf("proveedor%s\n", inicio->proveedor);
    printf("existencia %d\n", inicio->existencia);
    printf ("codigo %d\n", inicio->codigo);
    printf ("precio_venta %f\n", inicio->precio_venta);
    return 0;
    
    //Creamos un producto y lo inicializamos
    
}