#ifndef __ISSUERECORD_H
#define __ISSUERECORD_H

#include"date.h"
#include<time.h>

#define ISSUERECORD_FILE "issuerecord.db"
#define RECSIZE_ISSUERECORD sizeof(issuerecord_t)

typedef struct issuerecord
{
    int id;
    int book_copy_id;
    int member_id;
    int fine_amount;
    date_t issue_date;
    date_t return_due_date;
    date_t return_date;

}issuerecord_t;


#endif