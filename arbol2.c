#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int informacion;
    struct nodo *derecha, *izq;
};

struct nodo *origen = NULL;

void insert(int x) {
    struct nodo *new;
    new = malloc (sizeof(struct nodo));
    new -> informacion =x;
    new -> izq=NULL;
    new -> derecha= NULL;
    if (origen ==NULL)
        origen = new;
    else {
        struct nodo *ult, *reco;
        reco= origen;
        while(reco != NULL) {
            ult = reco;
            if (x<reco -> informacion)
                reco = reco -> izq;
            else
                reco= reco ->derecha;
        }
        if (x<ult -> informacion)
            ult -> izq = new;
        else
            ult -> derecha = new;
    }
}



void  print (struct nodo *reco) {
    if (reco != NULL){
        print(reco -> izq);
        printf("%i ", reco -> informacion);
        print(reco -> derecha);
    }
}


int counting(struct nodo *origen) {
  if (origen == NULL) {
    return 0;
  }
  if (origen->izq == NULL && origen->derecha == NULL) {
    return 1;
  }
  return counting(origen->izq) + counting(origen->derecha);
}


void printLeaf(struct nodo *origen) {
  if (origen == NULL) {
    return;
  }
  if (origen->izq == NULL && origen->derecha == NULL) {
    printf("%d ", origen->informacion);
  }
  printLeaf(origen->izq);
  printLeaf(origen->derecha);
}



int main ()  {
    int f,p;
    scanf ("%i",&f);
    for (int i=0; i<f;i++)  {
        scanf("%i",&p);
        insert(p);
    }
    printf("%d\n",counting(origen));
    printLeaf(origen);
    return 0;
}