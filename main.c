#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define BUFFSIZE 256

int main(int argc,char *argv[])
{
    FILE *fp;
    char ar[BUFFSIZE];
    char ch;
    int i=0;
    int count=0;

    if(argc<2)
    {
        printf("argc error.\n");
        exit(EXIT_FAILURE);
    }
    if(argc==2)
    {
        ch=argv[1][0];
        printf("please enter a string£º\n");
        fgets(ar,BUFFSIZE,stdin);
        while (ar[i]!='\0')
        {
            if(ar[i]==ch) count++;
            i++;
        }
        printf("In string \"%s\",there are %d %c.\n",ar,count,ch);
    }
    i=2;
    while (i<argc)
    {
        if((fp= fopen(argv[i],"r"))==NULL)
        {
            printf("cannot open file %s.\n",argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch= getc(fp))!=EOF)
        {
            if(ch==argv[1][0]) count++;
        }
        printf("In file \"%s\",there are %d %c.\n",argv[i],count,argv[1][0]);
        count=0;
        i++;
        fclose(fp);
    }

    getchar();
    getchar();
    return 0;
}