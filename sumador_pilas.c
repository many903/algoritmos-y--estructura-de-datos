#include <stdio.h>

int main(void)
{

  int P[100000];

  int n,ii=0,i=0;

  char a[]={'A','G','R','E','G','A'};

  char c[]={'C','O','N','S','U','M','E'};

  char im[]={'I','M','P','R','I','M','E'};

  char e[8];

  scanf("%i",&n);

  while(ii<n)
  {
      while(i<=n && ii<n)
        {
          scanf("%s",&e);

          if(e[1]==a[1])
          {
            scanf("%i",&P[i]);
            i+=1;
          }
          if(e[1]==c[1])
          {
            P[i-2]=P[i-2]+P[i-1];
            P[i-1]=NULL;
            i-=1;
          }
          if(e[1]==im[1])
          {
            printf("%i\n",P[i-1]);
          }
          ii+=1;
        }
  } return 0;
}