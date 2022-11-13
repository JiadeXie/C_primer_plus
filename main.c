#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* s_gets(char* st,int n);
void order(char *);

int main(void)
{
    char str[101];
    do
    {
        puts("please enter a string(input 回车 in a new line to quit):\n");
        fgets(str,101,stdin);
        if(str[0]=='\n') break;
        puts(str);
        order(str);
        puts(str);
    } while (1);

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

void order(char *str)
{
    int n= strlen(str);
    char cpy[n];
    int i=0;
    n=n-1;//下标减一时，指向'\n'

    strncpy(cpy,str,n);
    while (n>=0)
    {
        str[i++]=cpy[--n];//n先减一，指向尾字母
    }

}