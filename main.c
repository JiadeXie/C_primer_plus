#include <stdio.h>
int main(void)
{
    double da=100.0,de=100;
    int year=0;
    do
    {
    da=da+100.0*0.1;//计算单利
    de=de+de*0.05;//计算复利
    year++;
    }while(da-de>=0);
    printf("da=%.2lf,de=%.2lf,year=%d",da,de,year);

    return 0;
}
