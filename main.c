#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81


int main(int argc,char* argv[])
{
    FILE *fs,*fd;
    static char temp[BUFSIZE];
    int bytes;

    if(argc!=3)
    {
        printf("argc error.\n");
        exit(EXIT_FAILURE);
    }
    if((fs= fopen(argv[1],"rb"))==NULL)
    {
        printf("can not open %s file,\n ",argv[1]);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
    {
        printf("Can't create input buffer\n",stderr);
        exit(EXIT_FAILURE);
    }
    if((fd= fopen(argv[2],"ab+"))==NULL)
    {
        printf("can not open %s file,\n ",argv[2]);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fd,NULL,_IOFBF,BUFSIZE)!=0)
    {
        printf("Can't create output buffer\n",stderr);
        exit(EXIT_FAILURE);
    }
    while ((bytes= fread(temp,sizeof (char),BUFSIZE,fs))>0)
        fwrite(temp,sizeof (char),bytes,fd);
    printf("Copy done.\n");
    printf("Destination file content:\n");
    rewind(fd);
    while ((bytes= fread(temp,sizeof (char),BUFSIZE,fd))>0)
        fputs(temp,stdout);
    putchar('\n');

    return 0;
}
