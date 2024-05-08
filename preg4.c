#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    float float_a = *((float*)a);
    float float_b = *((float*)b);
    if(float_a<float_b)
    {
        return -1;
    }
    if(float_a>float_b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int n, i;
    printf("introdu n:\n"); scanf("%d", &n);

    float *v=(float*)malloc(n*sizeof(float));
    if(v==NULL)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<n;i++)
    {
        printf("v[%d]=", i); scanf("%f", &v[i]);
    }

    printf("vectorul initial:\n");

    for(i=0;i<n;i++)
    {
        printf("v[%d]=%f\n", i,v[i]);
    }

    qsort(v, n, sizeof(float), compare);

    printf("vectorul modificiat:\n");

    for(i=0;i<n;i++)
    {
        printf("v[%d]=%f\n", i,v[i]);
    }

    float x;
    printf("introdu numarul pe care il cauti:\n"); scanf("%f", &x);

    float *found = (float*)bsearch(&x, v, n, sizeof(float), compare);

    if(found)
    {
        printf("Este!!\n");
    }
    else
    {
        printf("Nu-i\n");
    }

    free(v);
    return 0;
}