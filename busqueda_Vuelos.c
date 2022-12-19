#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);


    struct Vuelo
    {
      char origen[4];
      char destino[4];
      int costos;
    }vuelos[n];


    for (int i = 0; i < n; i++)
    {
      scanf("%s %s %d", vuelos[i].origen, vuelos[i].destino, &vuelos[i].costos);
    }


    char paises[m][4];


    for (int i = 0; i < m; i++)
    {
       scanf("%s", paises[i]);
    }

    int costos = 0;


    for (int i = 0; i < m; i++)
    {
       for (int j = 0; j < n; j++)
       {
           if (strcmp(paises[i], vuelos[j].origen) == 0 && strcmp(paises[i + 1], vuelos[j].destino) == 0)
           {
               costos += vuelos[j].costos;
               break;
           }
       }
    }

    printf("%d\n", costos);
    return 0;
}