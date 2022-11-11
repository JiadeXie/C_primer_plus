#include <stdio.h>
#define STLEN 10

int main(void)
{
    char words[STLEN];
    int i;

    puts("Enter strings (empty line to quit):");
    while (fgets(words,STLEN,stdin)!=NULL && words[0]!='\n')
    {
        i=0;
        while (words[i]!='\n'&&words[i]!='\0') i++;
        if(words[i]=='\n')  words[i]='\0';//当输入的字符串较短时
        else//当输入的字符串超出数组长度时
            while (getchar()!='\n') continue;
        puts(words);
    }
    puts("Done.");

    return 0;
}
