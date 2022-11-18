#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(void)
{
    FILE *in, *out;
    int ch;
    char name1[LEN];
    char name2[LEN];
    int count = 0;

    printf("please enter the file name:\n");
    fgets(name1,LEN,stdin);
    name1[strlen(name1)-1]='\0';

    if((in=fopen(name1,"r"))==NULL)
    {
        fprintf(stderr,"I couldn't open the file \"%s\"\n",name1);
        exit(EXIT_FAILURE);
    }
    strncpy(name2,name1,LEN-5);
    name2[LEN-5]='\0';
    strcat(name2,".red");
    if((out=fopen(name2,"w"))==NULL)
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    while ((ch= getc(in))!=EOF)
        if(count++%3==0) putc(ch,out);
    if(fclose(in)!=0|| fclose(out)!=0)
        fprintf(stderr,"Error in closing files\n");

    return 0;
}