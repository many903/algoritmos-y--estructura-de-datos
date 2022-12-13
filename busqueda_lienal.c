#include <stdio.h>
void funcion(int[], int, int);
void funcion(int arreglo[], int tam, int busca){
  int i, contador = 0;
  for(i = 0; i < 10; i++){
    if(arreglo[i] == busca){
      printf("Numero encontrado en indice %d\n", i);
      break;//para que no siga buscando si ya lo encontro
    }
    else{
      contador++;//por cada busqueda sin exito suma 1 a contador
    }
  }//fin for
  if (contador == 10)
    printf("Numero no encontrado\n");
}//fin funcion
int main(void){
  int  num, x, arreglo[10];
  printf("Ingresa un numero: ");
  scanf("%d", &num);
  printf("LISTA DE NUMEROS\n");
  for(x = 0; x < 10; x++){
    arreglo[x] = x * 2;
    printf("%d ",arreglo[x]);
  }
  printf("\n\n");
 funcion(arreglo,10, num);
return 0;
}