#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nombre[20];
    int ventas;
} Vendedor;


int comparar_vendedores(const void *a, const void *b) {
    Vendedor v1 = (Vendedor)a;
    Vendedor v2 = (Vendedor)b;

    return v2->ventas - v1->ventas;
}

int main() {

    int n, k;
    scanf("%d%d", &n, &k);


    Vendedor vendedores = (Vendedor)malloc(sizeof(Vendedor) * n);


    for (int i = 0; i < n; i++) {
        scanf("%s%d", vendedores[i].nombre, &vendedores[i].ventas);
    }


    qsort(vendedores, n, sizeof(Vendedor), comparar_vendedores);


    for (int i = 0; i < k; i++) {
        printf("%s %d\n", vendedores[i].nombre, vendedores[i].ventas);
    }
 return 0;
}