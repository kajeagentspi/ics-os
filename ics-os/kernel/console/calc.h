// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*
    This function prints the help message
*/
void calchelp()
{
    printf("\nOptions: --add (-a), --mul (-m), --sub (-s), --div (-d), --pow (-p), --mod (-M), --help, --version\n");
    printf("Usage: calc -add 1 2\n");
    printf("NOTE: only add and multiply can have an infinite argument\n\n");
}
/*
    This function prints the version message
*/
void calcversion()
{
    printf("Version 1.0\n");
    printf("Made by Jake Tagnepis and PA Ganayo\n");
}
int calc(char *args)
{
    int argInd;
    int argc = 0;
    char *params = strtok(args, " ");
    char *argv[256];
    while (params != NULL)
    {
        argv[argc++] = params;
        params = strtok(NULL, " ");
    }
    if (strcmp(argv[1], "--help") == 0)
    {
        calchelp();
        return 1;
    }
    if (strcmp(argv[1], "--version") == 0)
    {
        calcversion();
        return 1;
    }

    if (argc < 3)
    {
        calchelp();
        return 1;
    }
    else
    {

        if (strcmp(argv[1], "--add") == 0 || strcmp(argv[1], "-a") == 0)
        {
            int sum = 0;
            int temp;
            for (argInd = 2; argInd < argc; argInd++)
            {
                temp = atoi(argv[argInd]);
                sum += temp;
            }

            printf("Sum: %d\n", sum);
        }
        if (strcmp(argv[1], "--mul") == 0 || strcmp(argv[1], "-m") == 0)
        {
            int prod = 1;
            int temp;
            for (argInd = 2; argInd < argc; argInd++)
            {
                temp = atoi(argv[argInd]);
                prod *= temp;
            }

            printf("Product: %d\n", prod);
        }
        if (strcmp(argv[1], "--sub") == 0 || strcmp(argv[1], "-s") == 0)
        {
            if (argc > 4)
            {
                printf("Needs two argument only\n");
                return 1;
            }
            else if (argc < 4)
            {
                printf("Invalid argument\n");
                return 1;
            }
            else
            {
                int difference = atoi(argv[2]) - atoi(argv[3]);

                printf("Difference: %d\n", difference);
            }
        }
        if (strcmp(argv[1], "--div") == 0 || strcmp(argv[1], "-d") == 0)
        {
            if (argc > 4)
            {
                printf("Needs two argument only\n");
                return 1;
            }
            else if (argc < 4)
            {
                printf("Invalid argument\n");
                return 1;
            }
            else if (strcmp(argv[3], "0") == 0)
            {
                printf("Cannot divide by zero\n");
                return 1;
            }
            else
            {
                int quotient = atoi(argv[2]) / atoi(argv[3]);

                printf("Quotient: %d\n", quotient);
            }
        }
        if (strcmp(argv[1], "--pow") == 0 || strcmp(argv[1], "-p") == 0)
        {
            if (argc > 4)
            {
                printf("Needs two argument only\n");
                return 1;
            }
            else if (argc < 4)
            {
                printf("Invalid argument\n");
                return 1;
            }
            else
            {
                int temp1 = atoi(argv[2]);
                int temp2 = atoi(argv[3]);
                int count;
                int power = 1;

                for (count = 0; count < temp2; count++)
                {
                    power *= temp1;
                }

                printf("Power: %d\n", power);
            }
        }
        if (strcmp(argv[1], "--mod") == 0 || strcmp(argv[1], "-M") == 0)
        {
            if (argc > 4)
            {
                printf("Needs two argument only\n");
                return 1;
            }
            else if (argc < 4)
            {
                printf("Invalid argument\n");
                return 1;
            }
            else if (strcmp(argv[3], "0") == 0)
            {
                printf("Cannot divide by zero\n");
                return 1;
            }
            else
            {
                int modulo = atoi(argv[2]) % atoi(argv[3]);

                printf("Modulo: %d\n", modulo);
            }
        }
    }
    return 0;
}
