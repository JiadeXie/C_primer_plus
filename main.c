#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int btod(char * str);

int main(void)
{
    char* pbin=(char*)malloc(32*sizeof(char));
    printf("please enter a binary string:\n");
    scanf("%s",pbin);
    printf("%s=%d\n",pbin,btod(pbin));

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