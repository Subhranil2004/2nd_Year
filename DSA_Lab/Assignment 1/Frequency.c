// Find the frequency of a character in a file

#include <stdio.h>
#include <stdlib.h>
int frequency(FILE *, char);
int main()
{
    FILE *fptr;
    char fpath[100];
    char ch;
    printf("Enter the relative filepath : ");
    scanf("%s", fpath);
    fptr = fopen(fpath, "r");
    if (fptr == NULL)
    {
        printf("File can't be opened. Exiting...");
        exit(0);
    }

    printf("Enter the character : ");
    ch = getchar();
    while (ch == ' ' || ch == '\n' || ch == '\t')
        ch = getchar();
    printf("The frequency of character \'%c\' = %d.\n", ch, frequency(fptr, ch));
    fclose(fptr);
    return 0;
}
int frequency(FILE *fp, char ch)
{
    char readch;
    int freq = 0;
    readch = fgetc(fp);
    while (readch != EOF)
    {
        if (ch == readch)
            freq++;
        readch = fgetc(fp);
    }
    return freq;
}