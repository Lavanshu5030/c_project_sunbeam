#ifndef __PAYMENT_DAL_H
#define __PAYMENT_DAL_H

#include"payment.h"

int payment_save(payment_t *p);
int get_max_pay_id();
int payment_search_by_id(int payment_id, payment_t *p);
int total_payment(date_t init_date, date_t final_date, int *total_fees, int *total_fine);

#endif