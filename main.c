#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* s_gets(char* st,int n);
int is_within(char*,char);
char* mystrncpy(char *,char *,int );


int main(void)
{
    char string1[101];
    char string2[51];
    int num;

    do {
        puts("please enter string1（回车 in a new line to quit:\n");
        fgets(string1,101,stdin);
        if(string1[0]=='\n') break;
        puts(string1);
        puts("please enter string2（回车 in a new line to quit:\n");
        fgets(string2,51,stdin);
        puts(string2);
        puts("please enter a number:\n");
        scanf("%d",&num);
        while (getchar()!='\n') continue;
        mystrncpy(string1,string2,num);
        puts(string1);

    } while (1);
    puts("Done\n");
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

int is_within(char* str,char ch)
{
    while (*str!=ch&&*str!='\0')
    {
        str++;
    }
    if(*str==ch) return 1;
    else return 0;
}

char* mystrncpy(char *str1,char *str2,int n)
{
    int c=0;
    char* pt1=str1;
    char* pt2=str2;
    while (*str2!='\0')
    {
        str2++;
        c++;
    }
    if(c<n)
    {
        int i= strlen(str1);
        str1[i-1]=' ';
        int j=0;
        while (pt2[j]!='\0')
        {
            pt1[i++]=pt2[j++];
        }
        str1[i]='\0';
    }
    if(c>=n)
    {
        int a= strlen(str1);
        str1[a-1]=' ';
        int b=0;
        while (b<n)
        {
            pt1[a++]=pt2[b++];
        }
    }
    return str1;
}
