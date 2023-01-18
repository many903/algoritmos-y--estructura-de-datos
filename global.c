#include <stdio.h>
#include <stdlib.h>

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

void crear(){     
  estudiente *s;
  FILE *fp;
  int n, i, j;
  printf("cuantos estudiantes tendra en clase:  ");
  scanf("%d",&n);

  s = (estudiente*)calloc(n, sizeof(estudiente));

  for (i = 0; i<n; i++){
    s[i].total = 0;
    s[i].per = 0;
    printf("ingrese la matricula:   ");
    scanf("%d",&s[i]);
    fflush(stdin);
    printf("ingrese el nombre del estudiante: ");
    scanf("%s",s[i].nombre);
    for(j=0; j< 3; j++){
        printf("ingrese el codigo de la UEA");
        scanf("%d",&s[i].sub[j].mark);
        s[i].total+= s[i].sub[j].mark;
    }
    s[i].per = s[i].total / 3.0;
  }
}

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
