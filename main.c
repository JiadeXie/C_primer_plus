#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int getnumber(FILE*);

int main(int argc,char* argv[])
{
    FILE *fp;
    int count;
    char words[MAX];

    if((fp=fopen("wordy","a+"))==NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    count= getnumber(fp);
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#')) fprintf(fp,"%d.%s\n",++count,words);

    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s",words)==1) puts(words);
    puts("Done!");
    if(fclose(fp)!=0) fprintf(stderr,"Error closing file\n");

    return 0;
}

int getnumber(FILE* fp)
{
    int i=0;
    char temp[MAX];
    if(fgets(temp,MAX,fp)!=NULL) i++;
    return i;
}