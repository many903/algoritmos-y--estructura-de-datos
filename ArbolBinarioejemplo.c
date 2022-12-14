#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
#define MAX 100
 
typedef struct snodoa{
    int valor;
    struct snodoa *izq, *der;
}tnodoa;
 
typedef tnodoa *tpunteroa;
 
void insertarArbol (tpunteroa *raiz, int dato);
void imprimirArbol (tpunteroa raiz);
void borrarArbol (tpunteroa *raiz);
tpunteroa buscar (tpunteroa raiz, int dato);
int esHoja (tpunteroa raiz);
int alturaArbolNodo (tpunteroa raiz, int dato);
void alturaArbol (tpunteroa raiz, int *altura);
void auxAltura (tpunteroa raiz, int a, int *altura);
 
//Dato en 0: No es un ArbolCompleto - Dato en 1: Si, es un ArbolCompleto
void arbolCompleto (tpunteroa *raiz, int *dato);
 
 
int main (){
 
    tpunteroa raiz;
    int dato, esCompleto=1, aux;
    raiz = NULL;
 
    /*
        Insertamos valores creando el siguiente Arbol:
                
                       4
                      / \
                     1   6
                        / \
                       5   9   
    */
 
    insertarArbol (&raiz, 4);
    insertarArbol (&raiz, 1);
    insertarArbol (&raiz, 6);
    insertarArbol (&raiz, 9);
    insertarArbol (&raiz, 5);
 
    //Imprimimos el Arbol en orden
    printf ("Arbol impreso: ");
    imprimirArbol (raiz);
 
    //Verificamos si es o no un Arbol Completo
    printf ("\n\nEs un Arbol completo?");
    arbolCompleto (&raiz, &esCompleto);
    if (esCompleto == 1)
        printf ("\n-Si. Es un Arbol Completo\n");
    else
        printf ("\nNo. No es un Arbol Completo\n");
 
    //Buscamos la Altura del Nodo con valor 6 en el Arbol
    aux = alturaArbolNodo (raiz, 6);
    printf ("\nLa Altura del Nodo 6 es: %d\n", aux);
 
    //Verificamos si el Nodo pasado como parametro es Hoja o no
    printf ("El Nodo: %d ", *(&raiz->valor));
    if (esHoja (raiz)){
       printf ("Es hoja\n\n");
    }else{
       printf ("No es hoja\n\n");      
    }
     
    //Buscamos el Nodo con valor 1 en el Arbol, y verificamos si es Hoja o no
    printf ("El Nodo con valor 1 ");
    if (esHoja (buscar(raiz, 1))){
       printf ("Es hoja\n\n");           
    }else{
       printf ("No es hoja\n\n");      
    }
 
    //Obtenemos la Altura del Arbol
    alturaArbol (raiz, &aux);
    printf ("La Altura del Arbol es: %d\n\n", aux);
 
    //Borramos el Arbol
    borrarArbol (&raiz);
    printf ("El Arbol fue borrado correctamente\n\n");
 
 
system ("PAUSE");
return 0;
}
 
//ARBOL-INSERTAR//
void insertarArbol (tpunteroa *raiz, int dato){
    if (*raiz == NULL){
        *raiz = malloc(sizeof(tnodoa));
        (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    }else{
        if (dato <= (*raiz)->valor){
            insertarArbol (&(*raiz)->izq, dato);
        }else{
            insertarArbol (&(*raiz)->der, dato);
        }
    }
}
 
//ARBOL-IMPRIMIR//
void imprimirArbol (tpunteroa raiz){
    if (raiz != NULL){
        imprimirArbol (raiz->izq);
        printf ("%d, ", raiz->valor);
        imprimirArbol (raiz->der);
    }
}
 
//ARBOL-BORRAR//
void borrarArbol (tpunteroa *raiz){
    if (*raiz != NULL){
        borrarArbol (&(*raiz)->izq);
        borrarArbol (&(*raiz)->der);
        free (*raiz);
        *raiz = NULL;
    }
}
 
//ARBOL-BUSCAR//
tpunteroa buscar (tpunteroa raiz, int dato){
    if (raiz == NULL){
        return NULL;
    }else{
        if (dato == raiz->valor){
            return raiz;
        }else{
            if (dato < raiz->valor){
                return buscar (raiz->izq, dato);
            }else{
                return buscar (raiz->der, dato);
            }
        }
    }
}
 
//ARBOL-COMPLETO//
//Dato en 0: No es - Dato en 1: Si, es
void arbolCompleto (tpunteroa *raiz, int *dato){
    if ((*raiz)->izq != NULL)
        arbolCompleto (&(*raiz)->izq, dato);
    if ((*raiz)->der != NULL)
        arbolCompleto (&(*raiz)->der, dato);
    if ((*dato) == 0)
        return;
    if ((*raiz)->der == NULL && (*raiz)->izq != NULL)
        *dato = 0;
    if ((*raiz)->der != NULL && (*raiz)->izq == NULL)
        *dato = 0;
}

//ARBOL-ALTURANODO//
int alturaArbolNodo (tpunteroa raiz, int dato){
    int altura=0;
    tpunteroa actual=raiz;
    while (actual!=NULL){
        if (dato == actual->valor){           
            return altura;
        }else{
            altura++;
            if (dato < actual->valor){               
                actual=actual->izq;
            }else{
                if (dato > actual->valor){               
                    actual=actual->der;
                }
            }
        }
    }
printf("\nNo existe ese valor en el nodo.\n");
return 0;
}

//ARBOL-ESHOJA?//
//Devuelve 1 si es Hoja, 0 si no lo es
int esHoja(tpunteroa raiz){
    if (!raiz->der && !raiz->izq)
       return 1;
    else
        return 0; 
}

//ARBOL-ALTURA//
void alturaArbol (tpunteroa raiz, int *altura){
    *altura=0;
    auxAltura(raiz, 0, altura);
}
 
void auxAltura (tpunteroa raiz, int a, int *altura){
    if(raiz->izq){
        auxAltura(raiz->izq, a+1, altura);
    }
    if(raiz->der){
        auxAltura(raiz->der, a+1, altura);
    }
    if(esHoja(raiz) && a>*altura){
        *altura=a;
    }
}