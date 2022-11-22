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
    int y,m,d,total;
    total=0;
    printf("please enter the year,month and day.\n");
    while(scanf("%d %d %d",&y,&m,&d)!=3||((m<1||m>12)||(d<1||d>31)) )
    {
        printf("entry error,please try again.\n");
        while (getchar()!='\n') continue;
    }
    printf("year=%d,month=%d,day=%d\n",y,m,d);

    for (int i = 0; i < m; ++i)
    {
        total+=year[i].days;
    }
    total+=d;
    printf("there are %d days from the beginning of %d to %d.%d.%d.\n",total,y,y,m,d);

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
