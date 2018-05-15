// #include "../../sdk/dexsdk.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*
    This function prints the help message
*/
void cathelp()
{
    printf("Usage: cat.exe filename\n");
}
/*
    This function prints the version message
*/
void catversion()
{
    printf("Version 1.0\n");
    printf("Made by Jake Tagnepis and PA Ganayo\n");
}
int cat(char *args)
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
    char *buffer;
    if (argc != 2)
    {
        cathelp();
        return 1;
    }
    if (strcmp(argv[2], "--help") == 0)
    {
        cathelp();
        return 0;
    }
    else if (strcmp(argv[2], "--version") == 0)
    {
        catversion();
        return 0;
    }
    fseek(fp, 0, SEEK_SET);
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = (char *)malloc(fsize);
    fread(buffer, fsize, 1, fp);
    fclose(fp);
    printf("%s\n", buffer);
    return 0;
}