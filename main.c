//turn temperatures in s or k
#include <stdio.h>

int main(void)
{
    void temperatures(double);
    double h;
    int c;

    printf("please enter temperatures in h(q to quit):\n");
    c=scanf("%lf",&h);
    while(c==1)
    {
        temperatures(h);
        printf("please enter temperatures in h(q to quit):\n");
        c=scanf("%lf",&h);
    }

    return 0;
}

void temperatures(double t)
{
    const double  F_TO_C=32.0,C_TO_K=273.16;
    double s,k;
    s=5.0/9.0*(t-F_TO_C);
    k=s+C_TO_K;
    printf("%.2f is %.2f or %.2f\n",t,s,k);
}