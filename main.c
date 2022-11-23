#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
char* s_gets(char* st,int n);
void zmsx(struct book*,int);
void jgsx(struct book*,int);

int main(void)
{
    struct book library[MAXBKS];
    int count=0;
    int index;

    printf("please enter the book title.\n");
    printf("press [enter] at the start of a line to stop.\n");
    while (count<MAXBKS&& s_gets(library[count].title,MAXTITL)!=NULL&&library[count].title[0]!='\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author,MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f",&library[count++].value);
        while (getchar()!='\n') continue;
        if(count<MAXBKS) printf("Enter the next title.\n");
    }
    if(count>0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
        }
        putchar('\n');
        printf("zmsx:\n\n");
        zmsx(library,count);//书名升序输出
        printf("jgsx:\n\n");
        jgsx(library,count);//价格升序输出
    }
    else printf("no books? too bad.\n");
    printf("Done.\n");

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

void zmsx(struct book* b,int n)
{
    struct book temp[n+1];
    for (int i = 0; i < n; ++i)  temp[i]=b[i];
    for (int i = 0; i < n-1; ++i)
    {
        for (int j=i+1;j<n;++j)
        {
            if((strcmp(temp[i].title,temp[j].title))>0)
            {
                temp[n]=temp[i];
                temp[i]=temp[j];
                temp[j]=temp[n];
            }
        }
    }
    for (int k= 0; k < n; k++)  printf("%s by %s: $%.2f\n",temp[k].title,temp[k].author,temp[k].value);

}


void jgsx(struct book* b,int n)
{
    struct book temp[n+1];
    for (int i = 0; i < n; ++i)  temp[i]=b[i];
    for (int i = 0; i < n-1; ++i)
    {
        for (int j=i+1;j<n;++j)
        {
            if(temp[i].value>temp[j].value)
            {
                temp[n]=temp[i];
                temp[i]=temp[j];
                temp[j]=temp[n];
            }
        }
    }
    for (int k= 0; k < n; k++)  printf("%s by %s: $%.2f\n",temp[k].title,temp[k].author,temp[k].value);
}
