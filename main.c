#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 4096
#define SLEN 81


int main(void)
{
    int i=0;
    FILE *fp;
    char ar[SLEN];
    char temp[BUFSIZE];
    char ch;

    printf("please enter the file name.\n");
    fgets(ar,SLEN,stdin);
    ar[strlen(ar)-1]='\0';
    printf("%s\n",ar);
    if ((fp=fopen(ar,"r"))==NULL)
    {
        printf("fp1 can not open %s file.\n",ar);
        exit(EXIT_FAILURE);
    }
    while (!feof(fp)) temp[i++]=fgetc(fp);
    fclose(fp);
    i=0;
    if ((fp=fopen(ar,"w+"))==NULL)
    {
        printf("fp2 can not open %s file.\n",ar);
        exit(EXIT_FAILURE);
    }
    while (temp[i]!='\0')
    {
        temp[i]= toupper(temp[i]);
        //putchar(temp[i]);
        fputc(temp[i],fp);
        i++;
    }
    rewind(fp);
    while ((ch=getc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);

    getchar();
    getchar();
    return 0;
}

