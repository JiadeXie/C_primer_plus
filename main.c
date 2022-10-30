//running.c -- A useful program for runners
#define SIXTY 60
#include <stdio.h>

int main(void)
{
    int min;

    printf("please enter the minutes or 0 to quit:\n");
    scanf("%d",&min);
    while(min>0)
    {
        printf("%d is %d hour and %d minutes\n",min,min/SIXTY,min%SIXTY);
        printf("please enter the minutes or 0 to quit:\n");
        scanf("%d",&min);
    }
    
    return 0;
}