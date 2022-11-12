#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void ToUpper(char*);
int PunctCount(const char*);

int main(int argc,char* argv[])
{
    int count;
    printf("The command line has %d arguments:\n",argc);
    for (count=0;count<argc;count++) printf("%d: %s\n",count,argv[count]);
    printf("\n");

    return 0;
}
