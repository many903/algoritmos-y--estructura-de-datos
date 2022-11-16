/******************************************************************************
Hacer un programa en el que se defina un arreglo de 5 elementos. Los valores del arreglo
y la potencia x se deben pedir al usuario. Define la función potenciaArreglo(), la cual 
recibe un arreglo por referencia y un exponente por valor. La función debe elevar cada 
elemento del arreglo a la potencia dada y dejar el nuevo valor en la posición que le 
corresponde en el arreglo. En pantalla se debe mostrar el arreglo original y el arreglo
elevado a la potencia dada.
creado por Many903.
UEA: Algoritmos y estructura de datos.
Univecidad Autonoma Mertopolitan Unidad lerma.
*******************************************************************************/

#include <stdio.h>

int potenciaArreglo(int arreglo, int arreglo2);
int leerArreglo(int arreglo);

int main()
{
    /*declacracion de variables */
    int arreglo[5];
    int arreglo2[5];
    int potencia;
    /*uso de la funcion para leer el arreglo dado por el usuario*/
    leerArreglo(arreglo);
    
    /*multiplicacion del arreglo por la potencia*/
    potenciaArreglo(arreglo,arreglo2);
    
    /*imprime los arreglos*/
    printf("el arreglo original es: %d",arreglo);
    printf("el arreglo original es: %d",arreglo2);
    return 0;
}

int potenciaArreglo(int arreglo, int arreglo2)/*hace la multiplicacion del arreglo por la potencia*/
{
    for (int i = 0; i < 4; i++)
        arreglo2[i] = arreglo[i]*potencia;
    return arreglo2;
}   

int leerArreglo(int arreglo1)/* me permite leer el arreglo1 entregado por el usiario*/
{
    for (int l = 0; l < 4; l++)
        arreglo[i] = scanf("por favor escribe un numero del 0 al 9");
    
    return arreglo;
}