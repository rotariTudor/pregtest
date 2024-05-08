#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

int suma(int n,...)
{
    va_list va;
    int suma=0;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        suma+=va_arg(va,int);
    }
    va_end(va);
    return suma;
}

double maxim(double x,...)
{
    va_list va;
    double max=x,y;
    va_start(va,x);
    do
    {
        y=va_arg(va,double);
        if(y>max)
        {
            max=y;
        }
    }while((y-0)>0.001);
    va_end(va);
    return max;
}

double maxN(int n,...)
{
    va_list va;
    va_start(va,n);
    double max=va_arg(va,double);
    while(--n)
    {
        double e=va_arg(va,double);
        if(max<e){max=e;}
    }
    va_end(va);
    return max;
}

double *impart(int n, ...) {
    va_list va;
    int i = 0;
    va_start(va, n);
    int divisor = n; 
    double *v = (double*)malloc(n * sizeof(double));
    if (!v) {
        exit(EXIT_FAILURE);
    }
    while (n--) {
        int g = va_arg(va, int);
        v[i] = (double)g / divisor;
        i++;
    }
    va_end(va);
    return v;
}

int *prim(int n, ...) {
    va_list va;
    va_start(va, n);
    int *v = (int*)malloc(n * sizeof(int));
    if (!v) {
        exit(EXIT_FAILURE);
    }
    int index=0;
    int count=0;
    while(n--)
    {
        int variabila=va_arg(va,int);
        for(int i=1;i*i<=variabila;i++)
        {
            if(variabila%i==0)
            {
                count++;
            }
        }
        if(count==1)
        {
            v[index]=variabila;
            index++;
        }
        count=0;
    }
    va_end(va);
    return v;
}

float *allocVec(int n,...)
{
    double *v=(double*)malloc(n*sizeof(double));
    va_list(va);
    va_start(va,n);
    int index=0;
    while(n--)
    {
        v[index]=va_arg(va,double);
        index++;
    }
    return v;
}

int main(int argc,char *argv[])
{
    //printf("%d\n",suma(3,1,2,3));
    //printf("%.2f\n",maxim(7.1,3.3,8.0,0.0));
        //printf("%g\n",maxN(3,8.0,0.0,5.0));
    //asta de mai sus, sau de mai jos e corect
        //printf("%g\n",maxN(3,(double)8,0.0,(double)5));
    /*double *v=impart(4,44,10,9,5);
    for(int i=0;i<4;i++)
    {
        printf("%.3g\n",v[i]);
    }*//*
    int *v1=prim(5,44,17,9,5,11);
    for(int i=0;i<5;i++)
    {
        printf("%d\n",v1[i]);
    }*/
    //free(v);
    //free(v1);
    double *vector=allocVec(3,7.2,-1,0);
    for(int i=0;i<3;i++)
    {
        printf("vector[%d]=%.2f\n",i,vector[i]);
    }
    free(vector);
    return 0;
}