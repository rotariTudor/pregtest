#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*int data[10];*/
    int data[1000000];
    for(int i=0;i<1000000;i++)
    {
        data[i]=1000000000+i;
    }
    FILE *file=fopen("file.bin","wb");
    if(!file)
    {
        perror("-1");
        exit(EXIT_FAILURE);
    }
    fwrite(data,sizeof(data),1,file);
    //fread(data,sizeof(data),1,file);

    fclose(file);
    return 0;
}