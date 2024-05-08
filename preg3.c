#include <stdio.h>
#include <stdlib.h>

int *detect(int *vector, int size)
{
    int i=0, index=0;
    int *v=(int*)malloc(size*sizeof(int));
    if(v==NULL)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<size;i++)
    {
        if(vector[i]>=0)
        {
            v[index++]=vector[i];
        }
    }
    return v;
}



int main()
{
    int n,i=0,count=0;

    printf("introdu un numar n:\n"); scanf("%d", &n);

    int *vect=(int*)malloc(n*sizeof(int));
    if(vect==NULL)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }
    for(;i<n;i++)
    {
        printf("vect[%d]=",i); scanf("%d", &vect[i]);
    }

    printf("avem urmatorul sir:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",vect[i]);
        if(vect[i]<0)
        {
            count--;
        }
    }
    printf("\n");

    int *vectmod=detect(vect, n);

    printf("avem urmatorul sir modificat:\n");
    for(i=0;i<n+count;i++)
    {
        printf("%d ",vectmod[i]);
    }

    free(vect);
    free(vectmod);
    return 0;
}