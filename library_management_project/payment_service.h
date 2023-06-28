#ifndef __PAYMENT_SERVICE_H
#define __PAYMENT_SERVICE_H
#include "date.h"

int payment_add_fine(float amount, int member_id);
int payment_add_fees(int member_id);
int payment_report(date_t init_date, date_t final_date, int *total_fees, int *total_fine);

#endif