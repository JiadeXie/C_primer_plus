#include <stdio.h>
int main(void)
{
    char ch,pre;
    int flag=0;
    printf("please enter context(# to quit):\n");
    while ((ch=getchar())!='#')
    {
        switch (ch)
        {
            case 'i':
                if(pre=='e')
                {
                    flag++;
                    pre=ch;
                    break;
                }
            default:pre=ch;
        }
    }
    printf("\nc=%d\ndone.",flag);
    return 0;

}
