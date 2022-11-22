#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 81
char* s_gets(char* st,int n);

typedef struct lens{
    float foclen;
    float fstop;
    char brand[30];
}LENS;



int main(void)
{
    LENS arr[10]={[3]={600.0,3.0,"Xeon"}};

    arr[2].foclen=500.0;
    arr[2].fstop=2.0;
    strcpy(arr[2].brand,"Rema");

    for (int i = 2; i <=3; ++i) {
        printf("arr[%d].foclen=%f,arr[%d].fstop=%f,arr[%d].brand=%s.\n",
               i,arr[i].foclen,i,arr[i].fstop,i,arr[i].brand);
    }

    puts("Bye!");

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
