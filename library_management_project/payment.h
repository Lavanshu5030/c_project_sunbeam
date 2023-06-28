#ifndef __PAYMENT_H
#define __PAYMENT_H

#include<stdio.h>
#include"date.h"

#define PAYMENT_FILE    "payment.db"
#define RECSIZE_PAYMENT sizeof(payment_t)

enum payment_type {fine, fees};

typedef struct payment{
    int id;
    int member_id;
    float amount;
    enum payment_type type;
    date_t transaction_time;
    date_t nextpayment_duedate;
}payment_t;

#endif
