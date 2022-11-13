#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 40
#define ANSWER "Grant"
void TOLOWER(char* try);

char* s_gets(char* st,int n);

int main(int argc,char* argv[])
{
    int i=1;
    char try[SIZE];
    puts("Who is buried in Grant's tomb?");
    s_gets(try,SIZE);
    try[0]=toupper(try[0]);
    TOLOWER(try);

    while (strcmp(try,ANSWER)!=0)
    {
        puts("No,that's wrong.Try again.");
        s_gets(try,SIZE);
        try[0]=toupper(try[0]);
        TOLOWER(try);
    }


    puts("That's right!\n");

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