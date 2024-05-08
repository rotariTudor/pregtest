#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nume[12];
    int nota;
}Student;


int comparare(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;

    if ((*studentA).nota != (*studentB).nota) 
    {
        return studentB->nota - studentA->nota;
    }

    else 
    {
        return strcmp(studentA->nume, studentB->nume);
    }
}

int main()
{
    int n, i;
    printf("introdu n:\n"); scanf("%d", &n);
    Student *student=(Student*)malloc(n*sizeof(Student));
    for(i=0;i<n;i++)
    {
        printf("introdu numele studentului:\n"); scanf("%11s", student[i].nume);
        printf("introdu nota studentului:\n"); scanf("%d", &student[i].nota);
    }


    printf("Numele studentilor inainte de qsort:\n");
    for(i=0;i<n;i++)
    {
        printf("%s - %d\n", student[i].nume, student[i].nota);
    }

    qsort(student, n, sizeof(Student),comparare);

    printf("Numele studentilor inainte de qsort:\n");
    for(i=0;i<n;i++)
    {
        printf("%s - %d\n", student[i].nume, student[i].nota);
    }

    free(student);
    return 0;
}