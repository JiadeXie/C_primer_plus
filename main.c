#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 81
char* s_gets(char* st,int n);

typedef struct {
    char name[10];
    char shorname[4];
    int days;
    int number;
}MONTH;

MONTH year[12]={
        {"January","Jan",31,1},
        {"February","Feb",28,2},
        {"March","Mar",31,3},
        {"April","Apr",30,4},
        {"May","May",31,5},
        {"June","Jun",30,6},
        {"July","Jul",31,7},
        {"August","Aug",31,8},
        {"September","Sep",30,9},
        {"October","Oct",31,10},
        {"November","Nov",30,11},
        {"Decenber","Dec",31,12}
};

int main(void)
{
    int n;
    int days;
    printf("please enter a number(q to quit).\n");
    while ((scanf("%d",&n))==1&&(n>=1&&n<=12))
    {
        for (int i=0;i<n;i++)
        {
            days+=year[i].days;
        }
        printf("there are %d days from 1 to %d month.\n",days,n);
        printf("please enter a number(q to quit).\n");
    }
    puts("Bye!");

    getchar();
    getchar();
    return 0;
}

char* s_gets(char *st,int n)
{
    char* ret_val;
    char* find;

    ret_val= fgets(st,n,stdin);
    if(ret_val)
    {
        find= strchr(st,'\n');
        if(find) *find='\0';
        else while (getchar()!='\n') continue;
    }
    return ret_val;
}
