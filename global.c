#include <stdio.h>

typedef struct alumno {
    int rno;
    char nombre;
    struct sujeto{
        int calif;
        char UEA;
        int mark;
    }sub[3];
    int total;
    float per;
} estudiente;

void crear(){}
void impresion(){}
void append(){}


int main(){
    int ch;
    do{
        printf("\n==================================================================");
        printf("\n1.-CREAR");
        printf("\n1.-DISPLAY");
        printf("\n1.-APPEND");
        printf("\n1.-EXIT");

        printf("\nIngresa la opcion deceada:   ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                crear();
            break;
            case 2:
                impresion();
            break;
            case 3:
                append();
            break;
        }
    }while (ch!=0);
    return 0;
}