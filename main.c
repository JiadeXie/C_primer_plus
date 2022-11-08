#include <stdio.h>
void to_base_n(unsigned long n,unsigned base);

int main(void)
{
    unsigned long number;
    unsigned b;
    printf("Enter an integer and base£¨2~10£© (q to quit):\n");
    while (scanf("%lu %u",&number,&b)==2)
    {
        if(b<2||b>10)
        {
            printf("·¶Î§´íÎó,baseµÄ·¶Î§Îª2~10,ÇëÖØÐÂÊäÈë\n");
            continue;
        }
        printf("Binary equivalent: ");
        to_base_n(number,b);
        putchar('\n');
        printf("Enter an integer £¨q to quit):\n");
    }
    printf("Done.\n");

    return 0;

}

void to_base_n(unsigned long n,unsigned base)
{
    int r;
    r=(int)n%base;
    if(n>=2) to_base_n(n/base,base);
    printf("%d",r);
    return;
}




