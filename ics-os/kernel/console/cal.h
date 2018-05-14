// #include "../../sdk/dexsdk.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*
    This function prints the help message
*/
void calhelp()
{
    printf("Usage: cal [month year|year]\n");
}

/*
    This function prints the version message
*/
void calversion()
{
    printf("Version 1.0\n");
    printf("Made by Jake Tagnepis and PA Ganayo\n");
}

int getWeekDayIndex(int day, int month, int year)
{

    int tomohiko[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + tomohiko[month - 1] + day) % 7;
}

int getNumberOfDays(int monthNo, int year)
{
    switch (monthNo)
    {
    // January
    case 0:
        return 31;
    // February
    case 1:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return 29;
        else
            return 28;
    // March
    case 2:
        return 31;
    // April
    case 3:
        return 30;
    // May
    case 4:
        return 31;
    // June
    case 5:
        return 30;
    // July
    case 6:
        return 31;
    // August
    case 7:
        return 31;
    // September
    case 8:
        return 30;
    // October
    case 9:
        return 31;
    // November
    case 10:
        return 30;
    // December
    case 11:
        return 31;
    }
}

char *getMonthName(int monthNo)
{
    switch (monthNo)
    {
    case 0:
        return "----------January----------";
    case 1:
        return "----------February---------";
    case 2:
        return "----------March------------";
    case 3:
        return "----------April------------";
    case 4:
        return "----------May--------------";
    case 5:
        return "----------June-------------";
    case 6:
        return "----------July-------------";
    case 7:
        return "----------August-----------";
    case 8:
        return "----------September--------";
    case 9:
        return "----------October----------";
    case 10:
        return "----------November---------";
    case 11:
        return "----------December---------";
    }
}

void printMonth(int monthNo, int year)
{
    int day, i;
    int dayCount = getNumberOfDays(monthNo - 1, year);
    char *monthName = getMonthName(monthNo - 1);
    printf("%s\n", monthName);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int spaces = getWeekDayIndex(1, monthNo, year);
    for (int i = 0; i < spaces; i++)
    {
        printf("    ");
    }
    for (day = 1; day < dayCount + 1; day++)
    {
        printf("%02d  ", day);
        if (getWeekDayIndex(day, monthNo, year) == 6)
            printf("\n");
    }
    printf("\n");
}
int cal(char *args)
{
    int argc = 0;
    char *params = strtok(args, " ");
    char *argv[256];
    while (params != NULL)
    {
        argv[argc++] = params;
        params = strtok(NULL, " ");
    }
    int month;
    int year;
    if (argc == 3)
    {
        month = atoi(argv[1]);
        year = atoi(argv[2]);
        if (month == 0 || year == 0)
        {
            calhelp();
            return 1;
        }
        printMonth(month, year);
    }
    else if (argc == 2)
    {
        if (strcmp("--help", argv[1]) == 0)
        {
            calhelp();
            return 0;
        }
        else if (strcmp("--version", argv[1]) == 0)
        {
            calversion();
            return 0;
        }
        year = atoi(argv[1]);
        if (year == 0)
        {
            calhelp();
            return 1;
        }
        for (month = 1; month < 13; month++)
        {
            printMonth(month, year);
            getch();
        }
    }
    else
    {
        year = 2018;
        for (month = 1; month < 13; month++)
        {
            printMonth(month, year);
            getch();
        }
    }
}
