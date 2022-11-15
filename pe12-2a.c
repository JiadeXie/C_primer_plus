#include "pe12-2a.h"

int set_mode(int mode)
{
    int mode_pe12;
    while (mode<-1||mode>1)
    {
        printf("Invalid mode specified.\n");
        scanf("%d",&mode);
    }
    if(mode==1)
    {
        mode_pe12=mode;
        printf("Mode 1(US) used.\n");
        return mode_pe12;
    }
    if(mode==0)
    {
        mode_pe12=mode;
        printf("Mode 0(EU) used.\n");
        return mode_pe12;
    }
}

void get_info(int mode,double* dis,double* fue)
{
    double di,fu;
    printf("dis=%p\n",dis);
    printf("fue=%p\n",fue);
    if(mode==0)
    {
        printf("Enter distance traveled in kilometers:\n");
        scanf("%lf",&di);
        printf("di=%f\n",di);
        printf("Enter fuel consumed in liters:\n");
        scanf("%lf",&fu);
        printf("fu=%f\n",fu);
        *dis=di;
        printf("dist=%f\n",*dis);
        *fue=fu;
        printf("fuel=%f\n",*fue);
    }
    if(mode==1)
    {
        printf("Enter distance traveled in miles:\n");
        scanf("%lf",&di);
        printf("Enter fuel consumed in gallons:\n");
        scanf("%lf",&fu);
        *dis=di;
        *fue=fu;
        printf("dist=%f\n",*dis);
        printf("fuel=%f\n",*fue);
    }
}

void show_info(int mode,double dist,double fuel)
{
    printf("dist=%f\n",dist);
    printf("fuel=%f\n",fuel);

    if(mode==0) printf("Fuel consumption is %.2f liters per 100km.\n",(fuel/dist)*100.0);
    if(mode==1) printf("Fuel consumption is %.2f miles per gallon.\n",dist/fuel);

}