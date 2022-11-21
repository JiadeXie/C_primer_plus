#include <stdio.h>
#include <string.h>
#define NLEN 30

struct namect{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

char* s_gets(char* st,int n);
void getinfo(struct namect* pst);
void makeinfo(struct namect* pst);
void showinfo(const struct namect* pst);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    getchar();
    getchar();
    return 0;
}

void getinfo(struct namect* pst)
{
    printf("please enter your first name.\n");
    s_gets(pst->fname,NLEN);
    printf("please enter your last name.\n");
    s_gets(pst->lname,NLEN);
}

void makeinfo(struct namect* pst)
{
    pst->letters= strlen(pst->fname)+ strlen(pst->lname);
}

void showinfo(const struct namect* pst)
{
    printf("%s %s,your name contains %d letters.\n",
           pst->fname,pst->lname,pst->letters);
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