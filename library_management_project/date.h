#ifndef __DATE_H
#define __DATE_H

#include<time.h>

typedef struct date
{
    int day;
    int month;
    int year;
}date_t;

int date_diff(date_t date1, date_t date2);  //return difference between two  dates in number of days
void adddays(date_t i_date, int days_to_add,date_t *d_date );
void current_date(date_t *date);
int datecmp(date_t final, date_t init);

#endif