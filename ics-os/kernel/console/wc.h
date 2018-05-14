// #include "../../sdk/dexsdk.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*
    This function gets the character count, line count, word count and the max line length
*/
void getCount(char *buffer, int fsize, int *chars, int *lines, int *words, int *maxLine)
{
    int i;
    char delimiter[] = " \t\r\n\v\f";
    char *token;
    int startLine = 0;
    int endLine = 0;
    int lineLength = 0;
    for (i = 0; i < fsize; i++)
    {
        if (buffer[i] == '\n')
        {
            endLine = i - 1;
            lineLength = endLine - startLine;
            startLine = i + 1;
            (*lines)++;
            if (*maxLine < lineLength)
            {
                *maxLine = lineLength;
            }
        }

        (*chars)++;
    }
    endLine = i;
    lineLength = endLine - startLine;
    if (*maxLine < lineLength)
    {
        *maxLine = lineLength;
    }
    token = strtok(buffer, delimiter);
    while (token != NULL)
    {
        (*words)++;
        token = strtok(NULL, delimiter);
    }
}
/*
    This function prints the help message
*/
void wchelp()
{
    printf("Usage: wc.exe filename [option]\n");
}
/*
    This function prints the version message
*/
void wcversion()
{
    printf("Version 1.0\n");
    printf("Made by Jake Tagnepis and PA Ganayo\n");
}
int wc(char *args)
{
    int argc = 0;
    char *params = strtok(args, " ");
    char *argv[256];
    while (params != NULL)
    {
        argv[argc++] = params;
        params = strtok(NULL, " ");
    }
    file_PCB *fp;
    int fsize;
    int chars = 0;
    int lines = 0;
    int words = 0;
    int maxline = 0;
    char *buffer;
    if (argc < 2 || argc > 3)
    {
        wchelp();
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0)
    {
        wchelp();
        return 0;
    }
    else if (strcmp(argv[1], "--version") == 0)
    {
        wcversion();
        return 0;
    }
    else if ((fp = openfilex(argv[1], FILE_READ)) == NULL)
    {
        printf("File not found.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_SET);
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = (char *)malloc(fsize);
    fread(buffer, fsize, 1, fp);
    fclose(fp);
    getCount(buffer, fsize, &chars, &lines, &words, &maxline);
    if (strcmp(argv[2], "-c") == 0 || strcmp(argv[2], "--bytes") == 0)
    {
        printf("%i %s\n", fsize, argv[1]);
        return 0;
    }
    else if (strcmp(argv[2], "-m") == 0 || strcmp(argv[2], "--chars") == 0)
    {
        printf("%i %s\n", chars, argv[1]);
        return 0;
    }
    else if (strcmp(argv[2], "-l") == 0 || strcmp(argv[2], "--lines") == 0)
    {
        printf("%i %s\n", lines, argv[1]);
        return 0;
    }
    else if (strcmp(argv[2], "-L") == 0 || strcmp(argv[2], "--max-line-length") == 0)
    {
        printf("%i %s\n", maxline, argv[1]);
        return 0;
    }
    else if (strcmp(argv[2], "-w") == 0 || strcmp(argv[2], "--words") == 0)
    {
        printf("%i %s\n", words, argv[1]);
        return 0;
    }
    else
    {
        printf(" %i %i %i %s\n", lines, words, chars, argv[1]);
        return 0;
    }
}