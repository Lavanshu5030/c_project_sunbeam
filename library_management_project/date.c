#include <stdio.h>
#include <time.h>
#include"date.h"

struct tm d1;
struct tm d2; 
date_t date1, date2;
//date should be adjusted like below.
// year - 1900
// month (0 - 11)
// day of the month (1 - 31)

int is_leap_year(int year) {
    year += 1900;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}

int days_in_month(int month, int year) {
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysInMonth[month];

    if (month == 1 && is_leap_year(year))
        days++;

    return days;
}

void convert(date_t *date, struct tm *d){
    d->tm_year = date->year -1900;
    d->tm_mon = date->month - 1;
    d->tm_mday = date->day;
}


int date_diff(date_t date1, date_t date2 ){
    
    struct tm d1, d2;
    convert(&date1, &d1);
    convert(&date2, &d2);

    time_t time1 = mktime(&d1);
    time_t time2 = mktime(&d2);

    double diff_in_seconds = difftime(time1, time2);
    int diff_in_days = (int)(diff_in_seconds / (24 * 3600));

    return diff_in_days;
}

void adddays(date_t i_date, int days_to_add, date_t *d_date ) {
    
    struct tm d1;
    convert(&i_date, &d1);
    // convert(&d_date, &d2);
    
    d1.tm_mday += days_to_add;

    while (d1.tm_mday > days_in_month(d1.tm_mon, d1.tm_year)) {
        d1.tm_mday -= days_in_month(d1.tm_mon, d1.tm_year);
        d1.tm_mon++;

        if (d1.tm_mon > 11) {
            d1.tm_mon = 0;
            d1.tm_year++;
        }
    }
    d_date->year = d1.tm_year + 1900;
    d_date->month = d1.tm_mon + 1;
    d_date->day = d1.tm_mday;

}

void current_date(date_t *date){
    struct tm *d;
    time_t current_time;
    
    current_time = time(NULL);
    d = localtime(&current_time);

    date->year = d->tm_year + 1900;
    date->month = d->tm_mon + 1;
    date->day = d->tm_mday;

}