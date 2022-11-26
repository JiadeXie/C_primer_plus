#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int btoi(char*);
void itob(int,char*);
int openbits(int);
int checkbit(int,int);
int rotate_l(int,int);

struct word{
    unsigned int word_id:8;
    unsigned int word_size:7;
    unsigned int duiqi:2;
    unsigned int jiacu:1;
    unsigned int xieti:1;
    unsigned int underline:1;
};
struct word sample={1,12,0,0,0,0};
const char w_dq[][7]={"left","middle","right"};
const char on_off[][4]={"off","on"};

void show(void);
void change_id(void);
void change_size(void);
void change_duiqi(void);
void change_jiacu(void);
void change_xieti(void);
void chang_underline(void);

int main(void)
{
    char ch;

    do
    {
        show();
        ch=getchar();
        switch (ch)
        {
            case 'f':change_id();break;
            case 's':change_size();break;
            case 'a':change_duiqi();break;
            case 'b':change_jiacu();break;
            case 'i':change_xieti();break;
            case 'u':chang_underline();break;
            case 'q':break;
            default :printf("entry error,please try again.\n");break;
        }
        while (getchar()!='\n') continue;
    }while(ch!='q');

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

void show(void)
{
    printf("ID SIZE ALIGNMENT  B   I   U\n");
    printf("%-2d %-2d   %-10s%-3s %-3s %-3s\n",
           sample.word_id,sample.word_size,w_dq[sample.duiqi],
           on_off[sample.jiacu],on_off[sample.xieti],on_off[sample.underline]);

    printf("f)change font\ts)change size\ta)change alignment\n");
    printf("b)toggle bold\ti)toggle italic\tu)toggle underline\n");
    printf("q)quit\n");
}

void change_size(void)
{
    unsigned int size;
    printf("enter font size(0-127):\n");
    scanf("%d",&size);
    if(size<0||size>127)
    {
        printf("entry error,program exits.\n");
        exit(EXIT_FAILURE);
    }
    sample.word_size=size;
}

void change_duiqi(void)
{
    while (getchar()!='\n') continue;
    char ch;
    printf("Select alignment:\n");
    printf("l)left   \tm)middle\tr)right\n");
    ch=getchar();
    if(ch=='l') sample.duiqi=0;
    else if(ch=='m') sample.duiqi=1;
    else if(ch=='r') sample.duiqi=2;
    else
    {
        printf("entry error,program exits.\n");
        exit(EXIT_FAILURE);
    }
}

void change_xieti(void)
{
    if(sample.xieti==1) sample.xieti=0;
    else if(sample.xieti==0) sample.xieti=1;
}

void change_jiacu(void)
{
    if(sample.jiacu==1) sample.jiacu=0;
    else if(sample.jiacu==0) sample.jiacu=1;
}

void chang_underline(void)
{
    if(sample.underline==1) sample.underline=0;
    else if(sample.underline==0) sample.underline=1;
}

void change_id(void)
{
    unsigned int temp;
    printf("please enter font(0-255):\n");
    scanf("%d",&temp);
    if(temp<0||temp>255)
    {
        printf("entry error,program exits.\n");
        exit(EXIT_FAILURE);
    }
    sample.word_id=temp;
}