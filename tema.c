/*#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

int condition(int n)
{
    if(n<0||n>100)
    {
        return 0;
    }
    return 1;
}

void err(int condition,const char *fmt,...)
{
    if(!condition)
    {
        va_list va; 
        va_start(va,fmt); 
        fprintf(stderr,"eroare: ");
        vfprintf(stderr,fmt,va);
        va_end(va);
        fputc('\n',stderr);
        exit(EXIT_FAILURE);
    }
}

int main()
{
    int i,n;
    float x,y,e,min,max;
    printf("n=");scanf("%d",&n);
    err(condition(n),"n invalid: %d\n",n);
    printf("x=");scanf("%g",&x);
    printf("y=");scanf("%g",&y);
    if(x>=y)err(condition(n),"x=%g nu este mai mic decat y=%g\n",x,y);
    max=x;
    min=y;
for(i=0;i<n;i++){
printf("e=");scanf("%g",&e);
        if(e<x||e>y)err(condition(n),"element invalid: %g\n",e);
        if(e<min)min=e;
    if(e>max)max=e;
    }
    printf("min: %g, max: %g\n",min,max);
    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


double *allocVec(int n,...)
{
    va_list va;
    va_start(va,n);

    double *vector=(double*)malloc(n*sizeof(double));
    
    if(vector==NULL)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }
    vector[0]=va_arg(va,double);
    int i=1;
    while(i<3)
    {
        vector[i]=va_arg(va,double);
        i++;
    }
    va_end(va);
    return vector;
}

int main()
{
    int i=0;
    double *vector1=allocVec(3,7.2,-1,0);
    for(i=0;i<3;i++)
    {
        printf("vector[%d]=%.2g\n",i,vector1[i]);
    }
    free(vector1);

    return 0;
}*/

/*#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void absN(int n,...)
{
    va_list va;
    va_start(va,n);
    float *out1=va_arg(va,float *);
    float *out2=va_arg(va,float *);
    *out1=fabs(*out1);
    *out2=fabs(*out2);
    printf("x = %.2f\ny= %.2f\n", *out1,*out2);
    va_end(va);
}


int main()
{
    float x, y;
    printf("x = ");scanf("%f", &x);
    printf("y = "); scanf("%f", &y);
    absN(2, &x, &y);
    return 0;
}*/


/*Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));

#include <stdio.h>
#include <stdarg.h>


int crescator(int n, char tip,...)
{
    va_list va;
    va_start(va,tip);
    int numbers[n];
    double flnumbers[n];
    switch(tip)
    {
        case 'd':
            numbers[0]=va_arg(va,int);
            for(int i=1;i<n;i++)
            {
                numbers[i]=va_arg(va,int);
                if(numbers[i-1]>numbers[i])
                {
                    va_end(va);
                    return 0;
                }
            } 
            break;
        case 'f':
            flnumbers[0]=va_arg(va,double);
            for(int i=1;i<n;i++)
            {
                flnumbers[i]=va_arg(va,double);
                if(flnumbers[i-1]>flnumbers[i])
                {
                    va_end(va);
                    return 0;
                }
            } 
            break;
    }
    va_end(va);
    return 1;
}

int main()
{
    printf("%d\n",crescator(3,'d',1,7,4));
    return 0;
}*/