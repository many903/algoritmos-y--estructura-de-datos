/*Descripción
En las sesiones anteriores del Coding Rush, cada concursante obtuvo cierto puntaje. Los concursantes han estado spameando a Freddy diciéndole que necesitan saber sus puntos acumulados, ya que les da mucha flojera sumar los Scores en Omegaup y necesitan presumirlo a sus mamás lo antes posible.

Freddy tiene muchas cosas que hacer, y es por ello que necesita un programa que le ayude. Freddy te dará  Nombres y  puntajes. Tu deberás decirle los puntos de la persona que él te diga.

Entrada
Primera Linea: M , el número de concursantes

Siguientes M Lineas:N(i), el nombre del concursante i-esimo seguido por P(i1), los puntos del concursante i-esimo

Siguiente Linea: El nombre del concursante a buscar.

Salida
El Puntaje de la persona que te ha dicho Freddy.*/#include <stdio.h>
#include <string.h>
int main(void) { 
  int N, participante_buscar=0;   
  scanf("%i",&N);
  struct lista{
    char nombre_p[20];
    int puntos;
    }r_participantes[N];
  int i=0;
  while(i<N){
    scanf("%s",r_participantes[i].nombre_p);
    scanf("%d",&r_participantes[i].puntos);
    i++;
  }
  char buscar[10][20];
  scanf("%s",buscar[1]);
  i=0;
  while(i<N){
    if(strcmp(buscar[1],r_participantes[i].nombre_p)==0){
        participante_buscar=r_participantes[i].puntos;
        break;
        }
    i++;
       }
  
  printf("%d", participante_buscar);
  
  return 0;
}