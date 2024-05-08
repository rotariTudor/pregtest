#include <stdio.h>
#include <math.h>

double f1(double x)
{
    return ((x-4)/(x+4));
}

double f2(double x)
{
    return (x*10);
}

double f3(double x)
{
    return (x*x+x+1);
}

double f4(double x)
{
    return (2*x*x+x);
}

void tabelare(int a, int b, int n, double(*fct)(double))
{
    float p=(b-a)/n;
    for(float i=a;i<=b;i+=p)
    {
        double rez=0;
        rez=fct(i);
        printf("%.3g\t", rez);
    }
    printf("\n");
}

int main(void)
{
    int a=0, b=0, n=0;
    double(*fct[4])(double);
    fct[0]=f1;
    fct[1]=f2;
    fct[2]=f3;
    fct[3]=f4;
    printf("Introduceti inceputul intervalului:");
    scanf("%d", &a);
    printf("introduceti sfarsitul intervalului:");
    scanf("%d", &b);
    printf("Cate masuratori sa se faca:");
    scanf("%d", &n);
    printf("fct[0]= ");
    tabelare(a,b,n,fct[0]);
    printf("fct[1]= ");
    tabelare(a,b,n,fct[1]);
    printf("fct[2]= ");
    tabelare(a,b,n,fct[2]);
    printf("fct[3]= ");
    tabelare(a,b,n,fct[3]);
    return 0;
}