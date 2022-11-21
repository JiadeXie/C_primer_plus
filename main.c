#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;

    printf("Enter test score: ");
    scanf("%d",&score);
    if(score>=84)
    {
        readfirst=(struct book){"Crime and Punishment","Fyodor Dostoyevsky",11.25};
    }
    else readfirst=(struct book){"Mr.Bouncy's Nice Hat","Fred Winsome",5.99};
    printf("Your assigned reading:\n");
    printf("%s by %s: $%.2f\n",readfirst.title,readfirst.author,readfirst.value);

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