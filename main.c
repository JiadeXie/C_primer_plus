#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct fullname
{
    char name[15];
    char midname[10];
    char xing[10];
};
struct secnumber
{
    char number[20];
    struct fullname name;
};
char* s_gets(char* st,int n);
void qqq(struct secnumber* num,int n);

int main(void)
{
    int n=5;
    struct secnumber ar[5]=
    {
            {"302039823",{"Dribble","","Flossie"}},
            {"302039824",{"Dribblf","","Flossif"}},
            {"302039825",{"Dribblg","Mddf","Flossig"}},
            {"302039826",{"Dribblh","","Flossih"}},
            {"302039827",{"Dribbli","Mddh","Flossii"}},
    };
    printf("%S\n",ar[1].name.midname);
    qqq(ar,n);


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

void qqq(struct secnumber *num, int n){
               for (int i = 0; i < n; ++i)
               {
                        if(strlen(num[i].name.midname)>0) printf("%s, %s %c. -- %s\n",
                                                      num[i].name.name,num[i].name.xing,num[i].name.midname[0],num[i].number);
                        else printf("%s, %s -- %s\n",
                                     num[i].name.name,num[i].name.xing,num[i].number);

                }
}
