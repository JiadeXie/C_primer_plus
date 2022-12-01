#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2);

int main(void)
{
    int xie[]={1,2,3,4,5,6,7,8,9,10};
    qsort(xie,10, sizeof(int),cmp);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d\t",xie[i]);
    }

    puts("Done!\n");
    getchar();
    getchar();
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    const int* a1=(const int *)p1;
    const int* a2=(const int *)p2;
    if(*a1>*a2) return -1;
    else if(*a1==*a2) return 0;
    else return 1;
}