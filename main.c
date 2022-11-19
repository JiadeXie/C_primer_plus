#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 20
#define COL 30

int main(void)
{
    int data[ROW][COL];
    int i, j;
    char file_in[30];
    char file_out[30];
    char convert[] = {' ', '.', '\'', '\"', '^', '*', '%', '$', '@', '#'};
    FILE *in, *out;

    printf("please enter data file name:\n");
    scanf("%s", file_in);
    if ((in = fopen(file_in, "r")) == NULL)
    {
        printf("cannot open %s file.\n", file_in);
        exit(EXIT_FAILURE);
    }
    printf("please enter graphic file name:\n");
    scanf("%s", file_out);
    if ((out = fopen(file_out, "w")) == NULL)
    {
        printf("cannot open %s file.\n", file_out);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            fscanf(in,"%d",&data[i][j]);
        }
    }
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%c",convert[data[i][j]]);
            fprintf(out,"%c",convert[data[i][j]]);
        }
        printf("\n");
        fprintf(out,"\n");
    }
    fclose(in);
    fclose(out);

    getchar();
    getchar();

    return 0;
}
