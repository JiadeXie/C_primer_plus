#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE* source,FILE* dest);
char* s_gets(char* st,int n);

int main(int argc,char* argv[])
{
    FILE *fa,*fs;
    int files;
    int i=1;
    //char file_app[SLEN];
    //char file_src[SLEN];
    int ch;

    //puts("Enter name of destination file:\n");
    //s_gets(file_app,SLEN);
    if((fa= fopen(argv[1],"a+"))==NULL)
    {
        fprintf(stderr,"Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)
    {
        fputs("Can't create output buffer\n",stderr);
        exit(EXIT_FAILURE);
    }
    files=argc-2;
    //puts("Enter name of first source file (empty line to quit):");
    //while (s_gets(file_src,SLEN)&&file_src[0]!='\0')
    //{
    while(i<=files)
    {
    if ((fs = fopen(argv[i+1], "r")) == NULL) fprintf(stderr, "Can't open %s\n", argv[i+1]);
    else if (fs == fa) fputs("Can't append file to itself\n", stderr);
    else {
        if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
            fputs("Can't create input buffer\n", stderr);
            continue;
        }
        append(fs, fa);
        if (ferror(fs) != 0) fprintf(stderr, "Error in reading file %s.\n", argv[i+1]);
        if (ferror(fa) != 0) fprintf(stderr, "Error in writing file %s.\n", argv[1]);
        fclose(fs);
        //files++;
        printf("File %s appended.\n", argv[i+1]);
        i++;
        //puts("Next file (empty line to quit):");
        }
    }
    //}
    printf("Done appending. %d files appened.\n",files);
    rewind(fa);
    printf("%s contents:\n",argv[1]);
    while ((ch= getc(fa))!=EOF) putchar(ch);
    putchar('\n');
    puts("Done displaying.\n");
    fclose(fa);

    return 0;
}

void append(FILE *source,FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes= fread(temp,sizeof (char),BUFSIZE,source))>0)
        fwrite(temp,sizeof (char),bytes,dest);
}

char* s_gets(char* st,int n)
{
    char* ret_val;
    char* find;

    ret_val= fgets(st,n,stdin);
    if(ret_val)
    {
        find= strchr(st,'\n');
        if(find) *find='\0';
        else
            while (getchar()!='\n') continue;
    }
    return ret_val;
}