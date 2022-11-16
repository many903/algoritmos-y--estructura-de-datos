/* apuntadore.c    
   uso de operadores & y *(indireccion)
 */
#include <stdio.h>

int main()
(
    int x=5;
    int *apx;
    apx = &x;

    printf ("El valor de x es: %d\nEl valor de *apx es: %d\n", x, *apx);
    printf ("La direccion de x es: %p\nBl valor de apx es: %p\n", &X, apx);
    printf ("Sizeof x: %d bytes\n", sizeof (x));
    return 0;
)







