#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    double ar[50];
    double total=0.0;
    int count=0;

    FILE* fp;

    //FILE* fp1;
    //double ar1[50]={11.11,22.22,33.33,44.44,55.55,66.66,77.77,88.88,99.99,12.12,13.13,14.14,15.15,16.16,17.17,18.118};
    //fp1= fopen("data1.dat","wb");
    //fwrite(ar1, sizeof(double),16,fp1);


    if(argc<1||argc>2)
    {
        puts("argc error.\n");
        exit(EXIT_FAILURE);
    }
    if(argc==1)
    {
        printf("please enter a numbers,%d numbers entered\n",0);
        while (count<50&&(scanf("%lf",&ar[count]))==1)
        {
            total+=ar[count];
            printf("please enter a numbers,%d numbers entered\n",++count);
        }
        printf("average is %f\n",total/count);
        getchar();
        getchar();
        getchar();
        getchar();

        return 0;
    }
    if(argc==2&&(fp= fopen(argv[1],"rb"))==NULL)
    {
        printf("file name error.\n");
        exit(EXIT_FAILURE);
    }
    count= fread(ar,sizeof (double),50,fp);
    for (int i=0;i<count;i++) total+=ar[i];
    printf("average is %f\n",total/count);

    getchar();
    getchar();

    return 0;
}
