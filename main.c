#include <stdio.h>
#include <stdlib.h>
int* make_array(int elem,int val);
void show_array(const int ar[],int n);

int main(void)
{
    int* pa;
    int size;
    int value;

    printf("Enter the number of elements: \n");
    while (scanf("%d",&size)==1&&size>0)
    {
        printf("Enter the initialization value: \n");
        scanf("%d",&value);
        pa= make_array(size,value);
        if(pa)
        {
            show_array(pa,size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): \n");
    }
    printf("Done.\n");

    return 0;
}