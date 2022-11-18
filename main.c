#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
#define BUFFSIZE 256

int main(void)
{
    FILE *fp1,*fp2;
    char ar1[LEN];
    char ar2[LEN];
    char* temp1=(char*) malloc(BUFFSIZE*sizeof(char));
    char* temp2=(char*) malloc(BUFFSIZE*sizeof(char));

    printf("Please enter the first file name:\n");
    fgets(ar1,LEN,stdin);
    ar1[strlen(ar1)-1]='\0';
    printf("%s\n",ar1);
    printf("Please enter the second file name:\n");
    fgets(ar2,LEN,stdin);
    ar2[strlen(ar2)-1]='\0';
    printf("%s\n",ar2);
    if((fp1=fopen(ar1,"r+"))==NULL)
    {
        printf("cannot open the first file.\n");
        exit(EXIT_FAILURE);
    }
    if((fp2=fopen(ar2,"r+"))==NULL)
    {
        printf("cannot open second file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(temp1,BUFFSIZE,fp1)!=NULL)
    {
        if(fgets(temp2,BUFFSIZE,fp2)!=NULL)
        {
            fputs(temp1,stdout);
            fputs(temp2,stdout);
        } else
        {
            fputs(temp1,stdout);
        }
    }
    while (fgets(temp2,BUFFSIZE,fp2)!=NULL)  fputs(temp2,stdout);
    printf("Print the combine line.\n");
    rewind(fp1);
    rewind(fp2);
    int i=1;
    while (fgets(temp1,BUFFSIZE,fp1)!=NULL)
    {
        if(fgets(temp2,BUFFSIZE,fp2)!=NULL)
        {
            printf("line no.%d :",i);
            while (*temp1!='\n') putchar(*temp1++);
            putchar('+');
            printf("%s",temp2);
            i++;
        } else
        {
            printf("line no.%d : %s",i++,temp1);
        }
    }
    while (fgets(temp2,BUFFSIZE,fp2)!=NULL)
    {
        printf("line no.%d : %s", i++,temp2);
    }
    fclose(fp1);
    fclose(fp2);
    getchar();
    getchar();
    return 0;
}