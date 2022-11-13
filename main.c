#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* s_gets(char* st,int n);
void input(char *);

int main(void)
{
    char str[101];
    input(str);

    return 0;
}

char* s_gets(char* st,int n)
{
    char* ret_val;
    int i=0;

    ret_val= fgets(st,n,stdin);
    if(ret_val)
    {
        while (st[i]!='\n'&&st[i]!='\0') i++;
        if(st[i]=='\n')  st[i]='\0';
        else while (getchar()!='\n') continue;
    }

    return ret_val;
}

void input(char *str)
{
    char s[101];
    char *pt=str;
    int i=0;
    do {
        printf("please input a string(input ¿Õ¸ñ in a new line to quit):\n");
        fgets(str,101,stdin);
        if(str[0]=='\n') break;
        while (*str!='\0')
        {
            if(*str!=' ')
            {
                s[i++]=*str;
                str++;
            }
            else str++;
        }
        s[i]='\0';
        strcpy(pt,s);
        puts(pt);

    }while(1);
}