#include <stdio.h>
#include <string.h>
#include <limits.h>//提供CHAR_BIT的定义，CHAR_BIT表示每字节的位数
char* itobs(int,char*);
void show_bstr(const char*);
int invert_end(int num,int bits);

int main(void)
{
    char bin_str[CHAR_BIT* sizeof(int)+1];
    int number;

    puts("Enter integers and see them in binary.\n");
    puts("Non-numeric input terminates program.");
    while (scanf("%d",&number)==1)
    {
        itobs(number,bin_str);
        printf("%d is\n",number);
        show_bstr(bin_str);
        putchar('\n');
        number= invert_end(number,4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number,bin_str));
        putchar('\n');
    }

    puts("Done!\n");
    getchar();
    getchar();
    return 0;
}

char* itobs(int n,char* ps)
{
    int i;
    const static int size=CHAR_BIT* sizeof(int);
    for (i=size-1;i>=0;i--,n>>=1)  ps[i]=(01&n)+'0';
    ps[size]='\0';

    return ps;
}

void show_bstr(const char* str)//4位一组现实二进制字符串
{
    int i=0;
    while(str[i])
    {
        putchar(str[i]);
        if(++i%4==0&&str[i])
            putchar(' ');
    }
}

int invert_end(int num,int bits)
{
    int mask=0;
    int bitval=1;

    while (bits-- >0)
    {
        mask|=bitval;
        bitval<<=1;
    }
    return num^mask;
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



