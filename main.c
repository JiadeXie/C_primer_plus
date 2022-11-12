#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LIMIT 81
void ToUpper(char*);
int PunctCount(const char*);

int main(int argc,char* argv[])
{
    int i,times;

    if(argc<2||(times=atoi(argv[1]))<1)  printf("Usage: %s positive-number\n",argv[0]);
    else
    {
        for (i=0;i<times;i++) puts("Hello,good looking!");
    }

    return 0;
}
