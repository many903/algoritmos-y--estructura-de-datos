/*Descripción
En las sesiones anteriores del Coding Rush, cada concursante obtuvo cierto puntaje. Los concursantes han estado spameando a Freddy diciéndole que necesitan saber sus puntos acumulados, ya que les da mucha flojera sumar los Scores en Omegaup y necesitan presumirlo a sus mamás lo antes posible.

Freddy tiene muchas cosas que hacer, y es por ello que necesita un programa que le ayude. Freddy te dará  Nombres y  puntajes. Tu deberás decirle los puntos de la persona que él te diga.

Entrada
Primera Linea: M , el número de concursantes

Siguientes M Lineas:N(i), el nombre del concursante i-esimo seguido por P(i1), los puntos del concursante i-esimo

Siguiente Linea: El nombre del concursante a buscar.

Salida
El Puntaje de la persona que te ha dicho Freddy.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
#define MAX 100      
 
typedef struct snodoa{
    int Nombre;//M
    int Puntos;//p
    struct snodoa *izq, *der;
}tnodoa;
 
typedef tnodoa *tpunteroa;
 
/*funciones*/
void insertarArbol (tpunteroa *raiz, int dato);
tpunteroa buscar (tpunteroa raiz, int dato);
void participantes (tpunteroa *raiz, int *dato);
 
 
int main (){
 
    tpunteroa raiz;
    int dato, esCompleto=1, aux;
    P = NULL; //P = particiopantes 
    scanf ("%d",&i);
    participantes (tpunteroa *raiz, int *dato);
    busca(tpunteroa *raiz, int dato);

system ("PAUSE");
return 0;
}
 
//ARBOL-BUSCAR//
tpunteroa buscar (tpunteroa raiz, int dato){
    if (raiz == NULL){
        return NULL;
    }else{
        if (dato == raiz->nombre){
            return raiz-> valor;
        }else{
            if (dato == raiz->nombre){
                return buscar (raiz->izq, dato);
            }else{
                return buscar (raiz->der, dato);
            }
        }
    }
}
/*participantes*/
void participantes (tpunteroa *raiz, int dato){
    if (*raiz == NULL){
        scanf ("%d",&P);
    }else{
        for(i=0; i<P; i++){
            (scanf ("%c", &dato));
            while(a==0){
                if( isdigit(dato) ) 
                {
                    (*raiz)->valor = dato;
                }
                else 
                {
                    (*raiz)->nombre = dato;
                }
            }
        }
    }
}