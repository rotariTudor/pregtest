#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int top=0;
int stack[MAX];


void push(int n)
{
    if(top>=MAX)
    {
        printf("stiva e plina\n");
        exit(EXIT_FAILURE);
    }
    stack[top++]=n;
}

void display()
{
    if(top==0)
    {
        printf("stiva este goala\n");
        exit(EXIT_FAILURE);
    }
    printf("elementele din stiva sunt:\n");
    for(int i=top-1;i>=0;i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int pop()
{
    if(top==0)
    {
        printf("stiva e goala\n");
        return -1;
    }
    return stack[--top];
}

int main(void)
{
    int size=0;
    printf("introdu un nr n:\n");
    scanf("%d", &size);

    printf("introdu nr-ele:\n");
    int v[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d", &v[i]);
        push(v[i]);
    }
    display();

    printf("%d\n", pop());
    printf("%d\n", pop());
}