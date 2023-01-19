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

void crear();
void imprimir();
void append();
void noofrec();
void buscar();
void guardar();
void elimina_registro();
void sort_by_total_on_screen();
void sort_by_total_in_file();
void sort_by_name_on_screen();

int main(){
    int ch;                                 // Escoge (choice)
    do{
        printf("\n[ 1 ] - crear");         // Crea el registro
        printf("\n[ 2 ] - imprimir");        // Muestra en pantalla
        printf("\n[ 3 ] - APPEND");         // Añade o anexa
        printf("\n[ 4 ] - numnero de registros");  // Te dice el numero de registro total.
        printf("\n[ 5 ] - buscar");
        printf("\n[ 6 ] - guardar");
        printf("\n[ 7 ] - DELETE");
        printf("\n[ 8 ] - SORT BY TOTAL DESC - ON SCREEN");
        printf("\n[ 9 ] - SORT BY TOTAL DESC - IN DILE");
        printf("\n[ 10 ] - SOR BY NAME ON SCREEN");
        printf("\n[ 0 ] - EXIT");           //Salir

        printf("\n - INGRESA TU NUMERO A ELEGIR:  ");
        scanf("%d", &ch);

        switch(ch){

            case 1:
                crear();
            break;

            case 2:
                imprimir();
            break;

            case 3:
                append();
            break;

            case 4:
                noofrec();      // Dice el numero de registros
            break;

            case 5:
                buscar();       // Busca
            break;

            case 6:
                guardar();
            break;

            case 7:
                elimina_registro(); //Eliminar registro.
            break;

            case 8:
                sort_by_total_on_screen();
            break;

            case 9:
                sort_by_total_in_file();
            break;

            case 10:
                sort_by_name_on_screen();
            break;
        }
    }
    while(ch!=0);
    return 0;
}
void crear(){
    student *s;
    FILE *fp;

    int n, i, j;            // n -> numero de estudiantes, i -> estudiante, j -> Por materia
    printf("\nCuantos estudiantes quieres ingresar?: ");
    scanf("%d",&n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt", "w");        // Registrará a los estudiantes en un archivo txt.

    for(i=0;i<n;i++){
        s[i].total = 0;
        s[i].per = 0;
        printf("\nIngresa la matricula: ");
        scanf("%d", &s[i]);

        fflush(stdin);                                      // Escribe el contenido de secuencia en el archivo.

        printf("Ingresa el Nombre del estudiante: ");
        scanf("%[^\n]s", s[i].name);

        for(j=0;j<2;j++){
            printf("Ingresa la Calificacion de la UEA%d : ",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 2.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);

}

void imprimir(){
    student s1;
    FILE *fp;
    int j;
    fp = fopen("mystudents.txt","r");            //Leemos el registro de estudiantes en el archivo guardado

    while(fread(&s1,sizeof(student),1,fp)){
        printf("\n%-5d%-20s",s1.rno,s1.name);
        for(j=0;j<2;j++){
            printf("%4d",s1.sub[j].mark);
        }
        printf("%5d%7.2f",s1.total,s1.per);
    }

    fclose(fp);                                         // Cerramos el archivo

}

void append(){
    student *s;
    FILE *fp;

    int n, i, j;            // n -> numero de estudiantes, i -> estudiante, j -> Por materia
    printf("\nCuantos estudiantes quieres ingresar?: ");
    scanf("%d",&n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt", "a");        // Registrará a los estudiantes en un archivo txt.

    for(i=0;i<n;i++){
        s[i].total = 0;
        s[i].per = 0;
        printf("\nIngresa la matricula: ");
        scanf("%d", &s[i]);

        fflush(stdin);                                      // Escribe el contenido de secuencia en el archivo.

        printf("Ingresa el Nombre del estudiante: ");
        scanf("%[^\n]s", s[i].name);

        for(j=0;j<2;j++){
            printf("Ingresa la Calificacion de la UEA%d : ",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 2.0;
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);

}

void noofrec(){
    student s1;
    FILE *fp;
    fp = fopen("mystudents.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);

    printf("\n\nLos numeros de registro son: %d",n);

    fclose(fp);
}

void buscar(){                                   // Buscaremos por matrícula
    student s1;
    FILE *fp;
    int j, rno,found=0;

    fp = fopen("mystudents.txt","r");            //Leemos el registro de estudiantes en el archivo guardado

    printf("Ingrese la matricula para buscar: ");
    scanf("%d",&rno);

    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rno == rno){
            found=1;
            printf("\n%-5d%-20s",s1.rno,s1.name);
            for(j=0;j<2;j++){
                printf("%4d",s1.sub[j].mark);
            }
            printf("%5d%7.2f",s1.total,s1.per);
        }

        if(!found)
            printf("\nMatricula no encontrada!");


        fclose(fp);                                         // Cerramos el archivo

    }
}

void guardar(){                                   // Buscaremos por matrícula
    student s1;
    FILE *fp, *fp1;
    int j, rno,found=0;

    fp = fopen("mystudents.txt","r");            //Leemos el registro de estudiantes en el archivo guardado
    fp1 = fopen("temp.txt", "w");

    printf("Ingrese la matricula para actualizar: ");
    scanf("%d",&rno);

    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rno == rno){
            s1.total=0;
            s1.per=0;
            found=1;
            printf("\nIngresa la nueva matricula: ");
            scanf("%d", &s1);

            fflush(stdin);                                      // Escribe el contenido de secuencia en el archivo.

            printf("Ingresa el nuevo Nombre del estudiante: ");
            scanf("%[^\n]s", s1.name);

            for(j=0;j<2;j++){
                printf("Ingresa la Calificacion de la UEA%d : ",j+1);
                scanf("%d",&s1.sub[j].mark);
                s1.total += s1.sub[j].mark;
            }
            s1.per = s1.total / 2.0;

            }
            fwrite(&s1,sizeof(student),1,fp1);               // Actualizará la lista



    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("mystudents.txt", "w");

        while(fread(&s1,sizeof(student),1,fp1)){
            fwrite(&s1,sizeof(student),1,fp);
        }

        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nMatricula no encontrada!");


    fclose(fp);                                         // Cerramos el archivo

}

void elimina_registro(){                                   // Buscaremos por matrícula
    student s1;
    FILE *fp, *fp1;
    int j, rno,found=0;

    fp = fopen("mystudents.txt","r");            //Leemos el registro de estudiantes en el archivo guardado
    fp1 = fopen("temp.txt", "w");

    printf("Ingrese la matricula para eliminar: ");
    scanf("%d",&rno);

    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rno == rno){
            found=1;
        }
        else
            fwrite(&s1,sizeof(student),1,fp1);               // Actualizará la lista

    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("mystudents.txt", "w");

        while(fread(&s1,sizeof(student),1,fp1)){
            fwrite(&s1,sizeof(student),1,fp);
        }

        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nMatricula no encontrada!");


    fclose(fp);                                         // Cerramos el archivo

}

void sort_by_total_on_screen(){
    student *s, s1;
    FILE *fp;
    int i,j;
    fp = fopen("mystudents.txt", "r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (student*)calloc(n,sizeof(student));

    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(student),1,fp);

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s[i].total <s[j].total){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

     for(i=0;i<n;i++){
        printf("\n%-5d%-20s",s[i].rno,s[i].name);
        for(j=0;j<2;j++){
            printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].per);
    }
}

void sort_by_total_in_file(){
    student *s, s1;
    FILE *fp;
    int i,j;
    fp = fopen("mystudents.txt", "r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (student*)calloc(n,sizeof(student));

    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(student),1,fp);

    fclose(fp);

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s[i].total <s[j].total){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    fp = fopen("mystudents.txt", "w");

     for(i=0;i<n;i++){
        printf("\n%-5d%-20s",s[i].rno,s[i].name);
        for(j=0;j<2;j++){
            printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].per);
        fwrite(&s[i],sizeof(student),1,fp);
    }

}

void sort_by_name_on_screen(){
    student *s, s1;
    FILE *fp;
    int i,j;
    fp = fopen("mystudents.txt", "r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(student);
    s = (student*)calloc(n,sizeof(student));

    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(student),1,fp);

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(s[i].name,s[j].name)>0){
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
     for(i=0;i<n;i++){
        printf("\n%-5d%-20s",s[i].rno,s[i].name);
        for(j=0;j<2;j++){
            printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].per);
    }
}
