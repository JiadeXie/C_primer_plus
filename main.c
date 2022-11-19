#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(void)
{
    FILE *fp;
    char ar[MAX];
    char temp[MAX];
    int num;

    printf("please enter a file name.\n");
    fgets(ar,MAX,stdin);
    ar[strlen(ar)-1]='\0';
    if((fp=fopen(ar,"r"))==NULL)
    {
        printf("cannot open file %s.\n",ar);
        exit(EXIT_FAILURE);
    }
    do
    {
        printf("please enter the location(输入负数或字母退出).\n");
        if((scanf("%d",&num))==0||num<0) break;
        fseek(fp,num,SEEK_SET);
        fgets(temp,MAX,fp);
        printf("%s",temp);

    } while (1);
    printf("Done.\n");

    return 0;
}
