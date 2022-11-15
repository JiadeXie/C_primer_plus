#include <stdlib.h>
#include <stdio.h>
int* make_array(int elem,int val)
{
    int* ar=(int*)malloc(elem*sizeof(int));
    for (int i = 0; i < elem; ++i)
    {
        ar[i]=val;
    }
    return ar;
}

void show_array(const int ar[],int n)
{
    for (int i = 0; i < n; ++i)
    {
        if(i!=0&&i%8==0) putchar('\n');
        printf("%-5d",ar[i]);
    }
    putchar('\n');
}