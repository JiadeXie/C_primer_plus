#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc,char* argv[])
{
    FILE* fp;
    char temp[MAX];

    if(argc!=3)
    {
        printf("argc error.\n");
        exit(EXIT_FAILURE);
    }
    if((fp= fopen(argv[2],"r"))==NULL)
    {
        printf("cannot open file %s.\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(temp,MAX,fp)!=NULL)
    {
        puts("enter loop\n");
        if((strstr(temp,argv[1]))!=NULL)
        {
            printf("%s",temp);
        }
    }

    printf("Done.\n");

    return 0;
}
