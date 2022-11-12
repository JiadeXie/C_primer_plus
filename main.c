#include <stdio.h>
#include <string.h>
#define LISTSIZE 6
#define LIM 10
#define STOP "quit"
char* s_gets(char* st,int n);

int main(void)
{
    const char* list[LISTSIZE]=
            {"astronomy","astounding",
             "astrophysics","ostracize",
             "asterism","astrophobia"
            };
    int count=0;
    int i;
    for (i=0;i<LISTSIZE;i++)
        if (strncmp(list[i],"astro",5)==0)
        {
            printf("Found: %s\n",list[i]);
            count++;
        }
    printf("The list contained %d words beginnig"
           " with astro.\n",count);

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
        if(st[i]=='\n') st[i]='\0';
        else while (getchar()!='\n') continue;
    }

    return ret_val;
}


