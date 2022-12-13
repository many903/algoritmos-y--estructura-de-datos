#include <stdio.h>
 
// Implementación iterativa del algoritmo de búsqueda binaria para devolver
// la posición de `target` en la array `nums` de tamaño `n`
int binarySearch(int nums[], int n, int target)
{
    // el espacio de búsqueda es nums[low…high]
    int low = 0, high = n - 1;
 
    // bucle hasta que se agote el espacio de búsqueda
    while (low <= high)
    {
        // encuentra el valor medio en el espacio de búsqueda y
        // lo compara con el objetivo
 
        int mid = (low + high)/2;    // puede ocurrir un desbordamiento
        // int mid = low + (high - low)/2;
        // int mid = high - (high - low)/2;
 
        // se encuentra el valor objetivo
        if (target == nums[mid]) {
            return mid;
        }
 
        // si el objetivo es menor que el elemento del medio, descartar todos los elementos
        // en el espacio de búsqueda correcto, incluido el elemento central
        else if (target < nums[mid]) {
            high = mid - 1;
        }
 
        // si el objetivo es más que el elemento del medio, descartar todos los elementos
        // en el espacio de búsqueda izquierdo, incluido el elemento central
        else {
            low = mid + 1;
        }
    }
 
    // el objetivo no existe en la array
    return -1;
}
 
int main(void)
{
    int nums[] = { 2, 5, 6, 8, 9, 10 };
    int target = 5;
 
    int n = sizeof(nums)/sizeof(nums[0]);
    int index = binarySearch(nums, n, target);
 
    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}
