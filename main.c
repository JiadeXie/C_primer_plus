#include <stdio.h>
#include <string.h>
char* s_gets(char* st,int n);
#define LEN 20
const char* msgs[5]=
        {
        "     Thank you for the wonderful evening, ",
        "You certainly prove that a ",
        "is a special kind of guy. We must get together",
        " and a delicious ",
        " and have a few laughs"
        };
struct names
{
    char first[LEN];
    char last[LEN];
};
struct guy
{
    struct names handles;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2]=
            {       {
                    {"Ewen","Villard"},
                    "grilled salmon",
                    "personality coach",
                    68112.00
                    },
                    {
                    {"Rodney","Swillbelly"},
                    "tripe",
                    "tabloid editor",
                    432400.00
                    }
            };
    struct guy* him;

    printf("address #1: %p #2: %p\n",&fellow[0],&fellow[1]);
    him=&fellow[0];
    printf("pointer #1: %p #2: %p\n",him,him+1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n",him->income,(*him).income);
    him++;
    printf("him->favfood is %s: him->handle.last is %s\n",him->favfood,him->handles.last);

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