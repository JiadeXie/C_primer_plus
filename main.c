#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 81
char* s_gets1(char* st,int n);

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
        {"December","Dec",31,12}
};

int main(void)
{
    char n[10];
    int m=0;
    int days=0;

    printf("please enter month(输入回车退出).\n");
    while ((s_gets1(n,10))!=NULL&&n[0]!='\0')
    {
        while (strcmp(n,year[m].name)!=0&&m<12) m++;
        if(m>=12)
        {
            printf("entry error,please try again.\n");
        } else
        {
            for (int i = 0; i <=m ; ++i)
            {
                days+=year[i].days;
            }
            printf("there are %d days from 1 to %d month.\n",days,year[m].number);
        }
        days=0;
        m=0;
    }

    puts("Bye!");

    getchar();
    getchar();
    return 0;
}

char* s_gets1(char *st,int n)
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
    st[0]= toupper(st[0]);
    while (*(++st)!='\0') *st= tolower(*st);
    return ret_val;
}
