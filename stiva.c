#include <stdio.h>

#define MAX 100
int top=-1;
int stack[MAX];

void push(int item)
{
    if(top==MAX-1)
    {
        printf("stiva e plina\n");
        return;
    }
    stack[++top]=item;
}

int pop()
{
    if(top==-1)
    {
        printf("stiva e goala\n");
        return 0;
    }
    return stack[top--];
}

void display()
{
    if(top==-1)
    {
        printf("stiva e goala\n");
        return;
    }
    printf("elementele sunt: ");
    for(int i=top;i>=0;i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("elem scos: %d\n", pop());
    display();
    return 0;
}