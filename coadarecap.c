#include <stdio.h>
/*
#define MAX_SIZE 100
int front = -1;
int rear = -1;

int queue[MAX_SIZE];

void enqueue(int item)
{
    if(rear==MAX_SIZE-1)
    {
        printf("Coada este plina\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    queue[++rear]=item;
}

int dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Coada este goala\n");
        return -1;
    }
    return queue[front++];
}

void display()
{
    if(front==-1||front>rear)
    {
        printf("Coada este goala\n");
        return;
    }
    printf("Elementele din coada sunt:");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("ELEM extras: %d\n", dequeue());
    display();
    return 0;
}*/

#define MAX_SIZE 100
int front =-1, rear=-1;
int queue[MAX_SIZE];

void enqueue(int item)
{   
    if(rear==MAX_SIZE-1)
    {
        printf("stiva este plina\n");
    }
    if(front==-1)
    {
        front = 0;
    }
    queue[++rear]=item;
}

int dequeue()
{
    if(front==-1||front>rear)
    {
        printf("coada e goala\n");
        return -1;
    }
    return queue[front++];
}  

void display()
{
    if(front==-1||front>rear)
    {
        printf("coada e goala\n");
        return;
    }
    printf("Elementele sunt:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}