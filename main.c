#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int btoi(char*);
void itob(int,char*);
int openbits(int);
int checkbit(int,int);
int rotate_l(int,int);

int main(void)
{
    char ch[CHAR_BIT* sizeof(int)+1];
    int n,m,k;
    printf("please enter two number:\n");
    scanf("%d %d",&n,&m);
    itob(n,ch);
    k= rotate_l(n,m);
    printf("before rotate_l,n=%d=%s\n",n, ch);
    itob(k,ch);
    printf("after rotate_l,n=%d=%s\n",n, ch);

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
    //printf("%d=%s\n",n,b);
}

int openbits(int n)
{
    int c=0;
    const static int  size=CHAR_BIT*sizeof(int);
    char temp[size+1];
    for (int i = size-1; i >=0; i--)
    {
        temp[i]=(01&n)+48;
        n>>=1;
    }
    temp[size]='\0';
    for (int i = 0; i < size; ++i)
    {
        if(temp[i]==49) c++;
    }
    printf("%s\n",temp);
    return c;
}

int checkbit(int a,int b)
{
    int temp= pow(2,b-1);
    if(temp==(a&temp)) return 1;
    else return 0;
}

int rotate_l(int a,int length)
{
    const static int size=CHAR_BIT* sizeof(int);
    for (int i = 0; i < length; ++i)
    {
        if((a&(1<<size-1)))//先读取将要被移出的数据，即把最高位设置为1，并与n进行与操作，
        {                  //若结果为1，则移位，并在左侧置1；若结果为零，则直接移位。
            a<<=1;
            a|=1;
        } else a<<=1;
    }
    return a;
}