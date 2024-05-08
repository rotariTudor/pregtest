/*Subiectul 1: Să se imlementeze un program care gestionează un parc de automobile. Informaţiile relative la un
automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai putere între 1
și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile, datele sunt citite
de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou;
b) Ștergerea unui anumit automobil, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste de automobile;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
e) Ordonarea listei în funcție de anul fabricației, folosind qsort.
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    unsigned int cod:14;
    unsigned int locuri:4;
    unsigned int putere:9;
    char marca[15];
    char culoare[10];
    unsigned int anfabricatie:11;
}DATA;

#define MAX 64

int main()
{
    int max=MAX;
    DATA *data=(DATA*)malloc(max*sizeof(DATA)), *aux=NULL;
    if(data==NULL)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }
    int var, i=0, index=0, nrlocuri, stergcod;
    unsigned int cod, locuri, putere, anfabricatie;

    char marca[15], culoare[10];

    
    while(1)
    {
        printf("Pentru a introduce un automobil nou apasa 1.\n");
        printf("Pentru a sterge un automobil, apasa 2.\n");
        printf("Pentru a afisa lista tuturor masinilor, apasa 3.\n");
        printf("Pentru a afisa lista de automobile cu un anumit numar de locuri, apasa 4.\n");
        printf("Pentru a iesi, apasa 10.\n");

        scanf("%d", &var);
        switch(var)
        {
            case 1:
                printf("Introdu codul automobilului:\n"); scanf("%d", &cod);
                data[i].cod=cod;

                printf("Introdu nr de locuri a automobilului:\n"); scanf("%d", &locuri);
                data[i].locuri=locuri;

                printf("Introdu puterea masinii, in cai putere:\n"); scanf("%d", &putere);
                data[i].putere=putere;

                printf("Introdu marca masinii:\n"); scanf("%14s", marca);
                strcpy(data[i].marca, marca);

                printf("Introdu culoarea masinii:\n"); scanf("%9s", culoare);
                strcpy(data[i].culoare, culoare);

                printf("Introdu anul de fabricatie(Intre 1800 si 2017):\n"); scanf("%d", &anfabricatie);
                data[i].anfabricatie=anfabricatie;

                i++;
                if(i>=max)
                {
                    max+=max;
                    aux=(DATA*)realloc(data, max*sizeof(DATA));
                    if(aux==NULL)
                    {
                        perror("-2");
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        data=aux;
                    }
                }
                break;

            case 2:
                /*printf("introdu codul pentru a sterge masina:\n"); scanf("%d", &stergcod);
                for(index=0;index<i;index++)
                {
                    if(data[i].cod==stergcod)
                    {
                        for(index=0;index<i;index++)
                        {
                            data[index].cod=data[index+1].cod;
                            data[index].locuri=data[index+1].locuri;
                            data[index].putere=data[index+1].putere;
                            strcpy(data[index].marca, data[index+1].marca);
                            strcpy(data[index].culoare, data[index+1].culoare);
                            data[index].anfabricatie=data[index+1].anfabricatie;
                        }
                        i--;
                    }
                }*/
                break;

            case 3:
                for(index=0;index<i;index++)
                {
                    printf("-----------------------------\n**Codul:%d**\n\n**Locuri:%d**\n\n**Puterea:%d**\n\n**Marca:%s**\n\n**Culoarea:%s**\n\n**Anul de fabricatie:%d**\n\n", data[index].cod, data[index].locuri, data[index].putere, data[index].marca, data[index].culoare, data[index].anfabricatie);
                    printf("\n");printf("\n");
                }
                break;

            case 4:
                printf("introdu nr de locuri:\n"); scanf("%d", &nrlocuri);
                for(index=0;index<i;index++)
                {
                    if(data[index].locuri==nrlocuri)
                    {
                        printf("-----------------------------\n**Codul:%d**\n\n**Locuri:%d**\n\n**Puterea:%d**\n\n**Marca:%s**\n\n**Culoarea:%s**\n\n**Anul de fabricatie:%d**\n\n", data[index].cod, data[index].locuri, data[index].putere, data[index].marca, data[index].culoare, data[index].anfabricatie);
                        printf("\n");printf("\n");
                    }
                }
                break;

            case 10:
                free(data);
                return 0;

            default:
                free(data);
                return 0;
        }
    }
    free(data);
    return 0;
}