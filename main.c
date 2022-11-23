#include <stdio.h>
#include <string.h>
#define SEAT 12

struct client{
    char seat_number[15];
    int preorder;
    char xing[10];
    char ming[10];
};

//char* s_gets(char* st,int n);
void showmenu(void);
void snoes(struct client* c);
void sloes(struct client* c);
void salos(struct client* c);
void aactasa(struct client* c);
void dasa(struct client* c);


int main(void)
{
    char ch;
    struct client ar[12]=
            {
                    [0]="00000001",[1]="00000002",[2]="00000003",
                    [3]="00000004",[4]="00000005",[5]="00000006",
                    [6]="00000007",[7]="00000008",[8]="00000009",
                    [9]="00000010",[10]="00000011",[11]="00000012"
            };


    do
    {
        showmenu();
        ch=getchar();
        switch (ch)
        {
            case 'a':snoes(ar);break;
            case 'b':sloes(ar);break;
            case 'c':salos(ar);break;
            case 'd':aactasa(ar);break;
            case 'e':dasa(ar);break;
        }
        while (getchar()!='\n') continue;

    } while (ch!='f');

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

void showmenu(void)
{
    printf("To choose a function,enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
}

void snoes(struct client* c)
{
    int n=0;
    for (int i = 0; i < SEAT; ++i)  if(c[i].preorder==0) n++;
    printf("there are %d available seats.\n",n);
}

void sloes(struct client* c)
{
    for (int i = 0; i < SEAT; ++i) if(c[i].preorder==0)
        printf("seat %s is available.\n",c[i].seat_number);
}

void salos(struct client* c)
{
    struct client temp[SEAT+1];
    for (int i = 0; i < SEAT; ++i) temp[i]=c[i];
    for (int i=0;i<SEAT-1;i++)
    {
        for (int j = i+1; j <SEAT ; ++j)
        {
            if(strcmp(temp[i].xing,temp[j].xing)>0)
            {
                temp[SEAT]=temp[i];
                temp[i]=temp[j];
                temp[j]=temp[SEAT];
            }
        }
    }
    for (int i = 0; i < SEAT; ++i)
    {
        if(c[i].preorder==0) printf("seat:%s is available.\n",c[i].seat_number);
        if(c[i].preorder==1) printf("seat:%s has been ordered.\n",c[i].seat_number);
    }

}

void aactasa(struct client* c)
{
    int i;
    char x[10];
    char m[10];
    printf("please enter your xing and ming.\n");
    scanf("%s %s",x,m);
    for (i = 0; i < SEAT; ++i)
    {
        if(c[i].preorder==0) break;
    }
    if(i==12)
    {
        printf("there is no available seat.\n");
        return;
    }
    strcpy(c[i].xing,x);
    strcpy(c[i].ming,m);
    c[i].preorder=1;
    printf("assignment scceeded.\n");
    printf("Your seat number is %s\n",c[i].seat_number);
}

void dasa(struct client* c)
{
    int i;
    char sn[15];
    printf("please enter the seat number you want to delete.\n");
    scanf("%s",sn);
    for (i = 0; i < SEAT; ++i)
    {
        if(strcmp(sn,c[i].seat_number)!=0)
        {
            printf("seat number error.\n");
            return;
        } else break;
    }
    c[i].preorder=0;
    printf("deleted.\n");
}