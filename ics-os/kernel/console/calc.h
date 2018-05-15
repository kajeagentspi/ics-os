// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*
    This function prints the help message
*/
void calchelp()
{
    printf("\nOptions: --add (-a), --mul (-m), --sub (-s), --div (-d), --pow (-p), --help, --version\n");
    printf("Usage: calc.exe -add 1 2\n");
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
int main(int argc, char *argv[])
{
    int argInd;

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
            float sum = 0;
            float temp;
            for (argInd = 2; argInd < argc; argInd++)
            {
                temp = atof(argv[argInd]);
                sum += temp;
            }
            int intpart = (int)sum;
            float decpart = sum - intpart;
            if (decpart == 0)
                printf("Sum: %d\n", (int)sum);
            else
                printf("Sum: %f\n", sum);
        }
        if (strcmp(argv[1], "--mul") == 0 || strcmp(argv[1], "-m") == 0)
        {
            float prod = 1;
            float temp;
            for (argInd = 2; argInd < argc; argInd++)
            {
                temp = atof(argv[argInd]);
                prod *= temp;
            }
            int intpart = (int)prod;
            float decpart = prod - intpart;
            if (decpart == 0)
                printf("Product: %d\n", (int)prod);
            else
                printf("Product: %f\n", prod);
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
                float difference = atof(argv[2]) - atof(argv[3]);
                int intpart = (int)difference;
                float decpart = difference - intpart;
                if (decpart == 0)
                    printf("Difference: %d\n", (int)difference);
                else
                    printf("Difference: %f\n", difference);
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
                float quotient = atof(argv[2]) / atof(argv[3]);
                int intpart = (int)quotient;
                float decpart = quotient - intpart;
                if (decpart == 0)
                    printf("Quotient: %d\n", (int)quotient);
                else
                    printf("Quotient: %f\n", quotient);
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
                float temp1 = atof(argv[2]);
                float temp2 = atof(argv[3]);
                int checkerInt = (int)temp2;
                float checkerFloat = temp2 - checkerInt;
                int count;
                float power = 1;
                if (checkerFloat != 0)
                {
                    printf("Invalid 2nd argument\n");
                    return 1;
                }
                for (count = 0; count < (int)temp2; count++)
                {
                    power *= temp1;
                }
                int intpart = (int)power;
                float decpart = power - intpart;
                if (decpart == 0)
                    printf("Power: %d\n", (int)power);
                else
                    printf("Power: %f\n", power);
            }
        }
    }
    return 0;
}
