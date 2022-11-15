#include "pe12-2a.h"


int main(void)
{
    //double* fuel;又是你呀，指针大哥。由于之前 double* fuel；是野指针并没有用变量来初始化，会导致它指向莫名其妙的地方，从而使程序崩溃。
    //double* dist;
    double* fuel=(double* )malloc(sizeof (double));
    double* dist=(double* )malloc(sizeof (double));


    int mode;
    int mode_pe12;



    printf("Enter 0 for metric mode,1 for US mode: \n");
    scanf("%d",&mode);
    while (mode>=0)
    {
        mode_pe12=set_mode(mode);
        printf("dist=%p\n",dist);
        printf("fuel=%p\n",fuel);
        get_info(mode_pe12,dist,fuel);
        show_info(mode_pe12,*dist,*fuel);
        printf("Enter 0 for metric mode,1 for US mode: \n");
        printf(" (-1 to quit): \n");
        scanf("%d",&mode);
    }
    printf("Done.\n");
    free(fuel);
    free(dist);
    getchar();
    getchar();
    return 0;
}