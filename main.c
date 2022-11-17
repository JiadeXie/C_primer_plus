#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int ch;
    char file[30];
    FILE *fp;
    unsigned long count=0;

    printf("please enter the file name.\n");
    fgets(file,30,stdin);
    count=strlen(file);
    file[count-1]='\0';
    count=0;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("Can't open %s\n",file);
        exit(EXIT_FAILURE);
    }
    while ((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    putchar('\n');
    printf("File %s has %lu characters\n",file,count);
    getchar();
    getchar();

    return 0;
}