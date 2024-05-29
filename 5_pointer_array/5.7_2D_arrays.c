#include<stdio.h>
#include<stdlib.h>

/* leap year */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day);

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int year, month, day;
    int yearday;
    int *pmonth, *pday;
    pmonth = (int *)malloc(sizeof(int *));
    pday = (int *)malloc(sizeof(int *));
    /* type the date to get the yearday */
    printf("year:");
    scanf("%d", &year);
    printf("month:");
    scanf("%d", &month);
    printf("day:");
    scanf("%d", &day);
    yearday = day_of_year(year, month, day);
    printf("already the %d.day of %d\n\n", yearday, year);
    /* type the yearday to get the date*/
    printf("year:");
    scanf("%d", &year);
    printf("days of year:");
    scanf("%d", &yearday);
    month_day(year, yearday, pmonth, pday);
    printf("%d days of %d: %4d-%02d-%02d\n", yearday, year, year, *pmonth, *pday);
    free(pmonth);
    free(pday);

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int leap;
    int yearday;
    int i;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    yearday = day;

    for(i=1; i<month; i++){
        yearday += daytab[leap][i];
    }

    return yearday;
}

void month_day(int year, int yearday, int *pm, int *pd)
{
    int leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 ==0;
    int i;

    for (i=1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    *pm = i;
    *pd = yearday;
    
}