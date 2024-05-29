#include<stdio.h>

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
    pmonth = NULL;
    pday = NULL;
    /* type the date to get the yearday */
    printf("enter year:");
    scanf("%d", &year);
    printf("enter month:");
    scanf("%d", &month);
    printf("enter day:");
    scanf("%d", &day);
    yearday = day_of_year(year, month, day);
    printf("In year %d, it is the %d.day\n\n", year, yearday);
    /* type the yearday to get the date*/
    printf("enter year:");
    scanf("%d", &year);
    printf("enter days of year:");
    scanf("%d", &yearday);
    month_day(year, yearday, pmonth, pday);
    printf("the %d. day of year %d is %d. month and %d day", yearday, year, *pmonth, *pday);

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