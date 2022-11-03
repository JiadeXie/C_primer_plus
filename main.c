#include <stdio.h>
#define SAL1 8.75
#define SAL2 9.33
#define SAL3 10.00
#define SAL4 11.20
#define BASETIME 40.0
#define RATEBASE1 300.0
#define RATEBASE2 450.0
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void)
{
    void showsal(double,double);
    int flag;
    double time;
    printf("**********************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr\t\t\t2) $9.33/hr\n");
    printf("3) $10.00/hr\t\t\t4) $11.20/hr\n");
    printf("5) quit\n");
    printf("**********************************************************************\n");
    scanf("%d",&flag);
    while (!(flag==5))
    {
        printf("please enter work time:\n");
        scanf("%lf",&time);
        switch (flag)
        {
            case 1:showsal(SAL1,time);break;
            case 2:showsal(SAL2,time);break;
            case 3:showsal(SAL3,time);break;
            case 4:showsal(SAL4,time);break;
            default:printf("Enter the right number.\n");break;
        }
        printf("**********************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("1) $8.75/hr\t\t\t2) $9.33/hr\n");
        printf("3) $10.00/hr\t\t\t4) $11.20/hr\n");
        printf("5) quit\n");
        printf("**********************************************************************\n");
        scanf("%d",&flag);

    }
    printf("Done.\n");
    return 0;
}

void showsal(double sal,double wtime)
{
    double allSalary,tax,netSalary;
    if(wtime>BASETIME) wtime=BASETIME+(wtime-BASETIME)*1.5;
    allSalary=wtime*sal;
    if(allSalary<=RATEBASE1)
    {
        tax=allSalary*RATE1;
        netSalary=allSalary-tax;
        printf("allSalary=%.2lf,tax=%.2lf,netSalary=%.2lf.\n",allSalary,tax,netSalary);
    }
    if(allSalary>RATEBASE1&&allSalary<=RATEBASE2)
    {
        tax=RATEBASE1*RATE1+(allSalary-RATEBASE1)*RATE2;
        netSalary=allSalary-tax;
        printf("allSalary=%.2lf,tax=%.2lf,netSalary=%.2lf.\n",allSalary,tax,netSalary);
    }
    if(allSalary>RATEBASE2)
    {
        tax=RATEBASE1*RATE1+(RATEBASE2-RATEBASE1)*RATE2+(allSalary-RATEBASE2)*RATE3;
        netSalary=allSalary-tax;
        printf("allSalary=%.2lf,tax=%.2lf,netSalary=%.2lf.\n",allSalary,tax,netSalary);
    }
}








