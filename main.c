#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* s_gets(char* st,int n);
char* cmp(char*,char);


int main(int argc,char* argv[])
{
    char string[51];
    char* pt;
    char ch;
    int size=51;
    do {
        puts("please enter a string(»Ø³µ to quit):\n");
        s_gets(string, size);
        if(string[0]=='\0') break;
        puts("your string is ");
        puts(string);
        printf("please enter a character:\n");
        ch=getchar();
        while (getchar()!='\n') continue;
        pt = cmp(string, ch);
        if(pt==NULL) puts("not found");
        else if(*pt)printf("*pt=%c\n",*pt);
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
void TOLOWER(char* try)
{
    int i=1;
    toupper(try[0]);
    while (try[i]!='\0')
    {
        try[i]=tolower(try[i]);
        i++;
    }
}

char* cmp(char* str,char ch)
{
    while (*str!=ch&&*str!='\0')
    {
        str++;
    }
    if(*str==ch) return str;
    else return NULL;
}