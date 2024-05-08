#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fin=fopen("fisier.txt", "r");
    if(fin==NULL)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }

    int n=3, i=0, j=0;
    int **a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            perror("-2");
            exit(EXIT_FAILURE);
        }
        for(j=0;j<n;j++)
        {
            fscanf(fin,"%d", &a[i][j]);
        }
    }

    printf("Matricea inainte de modificari:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    printf("Matricea dupa modificari:\n");

    for(i=0;i<n;i++)
    {
        while(j<n)
        {
            a[i][j++]=a[i][i];
        }
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }



    for(i=0;i<n;i++)
    {
        free(a[i]);
    }

    free(a);
    fclose(fin);
    return 0;
}