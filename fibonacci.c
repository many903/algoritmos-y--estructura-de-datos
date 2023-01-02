

#include<stdio.h>
#include<stdlib.h>

typedef struct Molde{
    int dato;
    struct Molde *siguiente;
} Nodo;

/*********************/
Nodo *inicio = NULL;

void insertar(int x)
{
    Nodo *nuevo;
    nuevo = malloc(sizeof(n));
    nuevo->dato = x;
    if(inicio == NULL){
        inicio = nuevo;
        nuevo -> siguiente = NULL;
    }
    else{
        nuevo -> siguiente = inicio;
        inicio = nuevo;
    }
}
int fibonacci1(n){
    numIter++;
    if (n<2){
        //Caso trivial
        return n;
    } else {
        //Descomponemos problema n en 2 subproblemas n-1 y n-2
        let [p1, p2] = [n-1, n-2];
        //1 llamada por cada subproblema
        let s1 = fibonacci1(p1);
        let s2 = fibonacci1(p2);
        //Combinamos soluciones parciales
        result = s1+s2
        return result;
    }
}

int main ()
{
    int n = scanf("cuantos juegan :%d", &n)
    insertar(n);
    printf("Dato de inicio(lls): %d\n",inicio->dato);
    fibonacci(n);
    printf ("dato de fibonacci:%d\n",fibonacci->result);
    return 0;
}