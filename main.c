#include <stdio.h>
#define BASESAL 10.0
#define BASETIME 40.0
#define BASERATE1 0.15
#define BASERATE2 0.20
#define BASERATE3 0.25


int main(void)
{
    float workTime,salary,tax;
    printf("please enter work time in a week:\n");
    scanf("%f",&workTime);
    if(workTime<=BASETIME) salary=workTime*BASESAL;
    if(workTime>BASETIME)
    {
        workTime=BASETIME+(workTime-BASETIME)*1.5;
        salary=workTime*BASESAL;
    }
    if(salary<=300.0)
    {
        tax=salary*BASERATE1;
        printf("salary=%.2f,tax=%.2f,sal after tax=%.2f",salary,tax,salary-tax);
    }
    if(salary>300.0&&salary<=450.0)
    {
        tax=300.0*BASERATE1+(salary-300.0)*BASERATE2;
        printf("salary=%.2f,tax=%.2f,sal after tax=%.2f",salary,tax,salary-tax);
    }
    if(salary>450.0)
    {
        tax=300.0*BASERATE1+150*BASERATE2+(salary-450.0)*BASERATE3;
        printf("salary=%.2f,tax=%.2f,sal after tax=%.2f",salary,tax,salary-tax);
    }

    return 0;

}
