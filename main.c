#include <stdio.h>
void inputf(double ar[],int col);
double rowave(double ar[],int col);
double allave(double ar[][5],int row);
double maximum(double ar[][5],int row);
void printans(double a,double b,double c,double d,double e);

int main(void)
{
    double a[3][5];
    double rave1,rave2,rave3,aave,max;

    for (int i = 0; i < 3; ++i)
    {
        printf("please enter 5 numbers:\n");
        inputf(a[i],5);
    }
    printf("array:\n");
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%.2f  ",a[i][j]);
        }
        putchar('\n');
    }
    rave1= rowave(a[0],5);
    rave2= rowave(a[1],5);
    rave3= rowave(a[2],5);
    aave= allave(a,3);
    max= maximum(a,3);
    printans(rave1,rave2,rave3,aave,max);

    return 0;

}

void inputf(double ar[],int col)
{
    for (int i = 0; i < col; ++i)
    {
        scanf("%lf",&ar[i]);
    }
    while (getchar()!='\n') continue;

}

double rowave(double ar[],int col)
{
    double total=0.0;
    for (int i = 0; i < col; ++i)
    {
        total+=ar[i];
    }
    return total/5.0;
}

double allave(double ar[][5],int row)
{
    double total=0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            total+=ar[i][j];
        }
    }
    return total/15.0;

}

double maximum(double ar[][5],int row)
{
    double max=ar[0][0];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if(max<ar[i][j]) max=ar[i][j];
        }
    }
    return max;
}

void printans(double a,double b,double c,double d,double e)
{
    printf("rave1=%.2f,rave2=%.2f,rave3=%.2f\nall average=%.2f,maximum=%.2f\n",
           a,b,c,d,e);
}
