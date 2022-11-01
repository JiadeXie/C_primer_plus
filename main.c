#include <stdio.h>
int main(void)
{
    int a,k,i,j;
    char ch,cd;
    printf("please enter a char:");
    scanf("%c",&ch);
    i=ch-65+1; //计算行数
    j=i-1;//计算单侧空格数量
    for (a=0;a<i;)
    {
        for (k=0;k<j;k++) printf(" ");
        for(cd='A';cd<=65+a;cd++) printf("%c",cd);
        for (cd-=2;cd>='A';cd--) printf("%c",cd);
        printf(" \n");
        j--;
        a++;
    }

    return 0;
}
