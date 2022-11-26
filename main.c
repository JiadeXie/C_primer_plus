#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int btoi(char*);
void itob(int,char*);

int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        printf("argument error.\n");
        exit(EXIT_FAILURE);
    }

    int n;
    int n1;
    char str[CHAR_BIT* sizeof(int)+1];

    n=btoi(argv[1]);
    printf("~%d=",n);
    n=~n;
    itob(n,str);

    n=btoi(argv[2]);
    printf("~%d=",n);
    n=~n;
    itob(n,str);

    n= btoi(argv[1]);
    n1= btoi(argv[2]);
    printf("%d&%d=",n,n1);
    n=n&n1;
    itob(n,str);

    n= btoi(argv[1]);
    n1= btoi(argv[2]);
    printf("%d|%d=",n,n1);
    n=n|n1;
    itob(n,str);

    n= btoi(argv[1]);
    n1= btoi(argv[2]);
    printf("%d^%d=",n,n1);
    n=n^n1;
    itob(n,str);

    puts("Done!\n");
    getchar();
    getchar();
    return 0;
}

int btod(char * str)
{
    char* p=str;
    int bitc;
    int n=0;
    bitc= strlen(str);
    while (*p!='\0')
    {
        bitc--;
        if(*p=='1') n+=pow(2,bitc);
        p++;
    }
    return n;
}

int btoi(char* str)
{
    int bitc= strlen(str);
    int n=0;
    while(*str!='\0')
    {
        bitc--;
        if(*str!='0'&&*str!='1')
        {
            printf("enter error,please enter binary string.\n");
            exit(EXIT_FAILURE);
        }
        else if(*str=='1')  n+= pow(2,bitc);
        str++;
    }
    return n;
}

void itob(int n,char * b)
{
    int i;
    int copy=n;
    const static int size=CHAR_BIT* sizeof(int);
    for (i=size-1;i>=0;i--)
    {
        b[i] = (1 & copy) + 48;
        copy>>=1;
    }
    b[size]='\0';
    printf("%d=%s\n",n,b);
    return ;
}