#ifndef PAYMENT_H
#define PAYMENT_H
#include "user.h"

struct payment {
    int id;                 // Payment ID
    int user_id;            // User ID
    float amount;           // Payment amount
    char payment_date[20];  // Payment date (string format or use a time_t variable)
    char type[10];          // Payment type ("fees" or "fine")
    char next_payment_due_date[20];  // Next payment due date (string format or use a time_t variable)
};

#endif // PAYMENT_H
