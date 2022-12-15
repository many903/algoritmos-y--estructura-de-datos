/*debo regresar el costo total del viaje y la suma del costo de los vuelos de los paises */
#include <string.h>
#include <stdio.h>

typedef struct vuelo{
    char origen[25];
    char destino[25];
    int costo;
}Vuelo;  

int main() {
    int vuelos, paises;/*vuelos y el numero de paises a visitar*/
    scanf("%i", &vuelos);
    int vuelosR=(vuelos-1);

    for(int i = 0; i < vuelosR; i++){
        scanf("%d", &Vuelo.origen[i]);
        scanf("%d", &Vuelo.destino[i]);
        scanf("%i", &Vuelo.costo[i]);
    }
    return 0;
}