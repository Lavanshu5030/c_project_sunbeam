#ifndef __PAYMENT_DAL_H
#define __PAYMENT_DAL_H

#include"payment.h"

int payment_save(payment_t *p);
int get_max_pay_id();

#endif