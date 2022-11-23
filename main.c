#include <stdio.h>
#include <string.h>
#define CSIZE 4
struct name{
    char ming[20];
    char xing[10];
};
struct student{
    struct name n;
    double grade[3];
    double average;
};
//char* s_gets(char* st,int n);
double average(double a,double b,double c);
void ppp(struct student*,int);


int main(void)
{
    char m[20];
    char x[10];
    int seek;
    int count=0;
    double class_ave;
    struct student st[CSIZE]=
            {
                    [0]={"san","zhang"},
                    [1]={"si","li"},
                    [2]={"wu","wang"},
                    [3]={"liu","zhao"}
            };

    do
    {
        seek=0;
        printf("please enter your Ãû,ĞÕ(ÊäÈë#ÍË³ö)\n");
        scanf("%s",m);
        if(m[0]=='#') break;
        scanf("%s",x);
        while ((strcmp(x,st[seek].n.xing)!=0)&&(strcmp(m,st[seek].n.ming)!=0)&&seek<4) seek++;
        if(seek>=4)
        {
            seek=0;
            printf("entry error,please try again.\n");
            continue;
        } else
        {
            printf("please enter class_1,class_2,class_3 score.\n");
            scanf("%lf %lf %lf",&st[seek].grade[0],&st[seek].grade[1],&st[seek].grade[2]);
        }
        count++;
    } while (count!=CSIZE);
    for (int i = 0; i < CSIZE; ++i)
    {
        st[i].average=average(st[i].grade[0],st[i].grade[1],st[i].grade[2]);
    }
    ppp(st,CSIZE);
    class_ave=(st[0].average+st[1].average+st[2].average+st[3].average)/4.0;
    printf("class_average=%.2f\n",class_ave);
    puts("Done!\n");

    getchar();
    getchar();
    return 0;
}

char* s_gets(char *st,int n)
{
    char* ret_val;
    char* find;

    ret_val= fgets(st,n,stdin);
    if(ret_val)
    {
        find= strchr(st,'\n');
        if(find) *find='\0';
        else while (getchar()!='\n') continue;
    }
    return ret_val;
}

double average(double a,double b,double c)
{
    return (a+b+c)/3.0;
}

void ppp(struct student* st,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s %s: class_1=%.2f,class_2=%.2f,class_3=%.2f,average=%.2f\n",
              st[i].n.ming,st[i].n.xing,st[i].grade[0],st[i].grade[1],st[i].grade[2],st[i].average);
    }
}