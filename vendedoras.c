#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar el nombre y las ventas de cada vendedor
typedef struct {
    char nombre[20];
    int ventas;
} Vendedor;

// Función que compara dos vendedores según sus ventas
int comparar_vendedores(const void *a, const void *b) {
    Vendedor v1 = (Vendedor)a;
    Vendedor v2 = (Vendedor)b;

    return v2->ventas - v1->ventas;
}

int main() {
    // Leer n y k
    int n, k;
    scanf("%d%d", &n, &k);

    // Crear un arreglo para almacenar los vendedores
    Vendedor vendedores = (Vendedor)malloc(sizeof(Vendedor) * n);

    // Leer las ventas de cada vendedor y agregarlas al arreglo
    for (int i = 0; i < n; i++) {
        scanf("%s%d", vendedores[i].nombre, &vendedores[i].ventas);
    }

    // Ordenar el arreglo en orden descendente según las ventas de cada vendedor
    qsort(vendedores, n, sizeof(Vendedor), comparar_vendedores);

    // Imprimir los k mejores vendedores con sus ventas respectivas
    for (int i = 0; i < k; i++) {
        printf("%s %d\n", vendedores[i].nombre, vendedores[i].ventas);
    }

   

    return 0;
}