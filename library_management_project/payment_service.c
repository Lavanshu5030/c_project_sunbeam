#include <stdio.h>
#include "payment.h"
#include "payment_dal.h"
#include "user_service.h"
#include "date.h"

int payment_add_fine(float amount, int member_id){
    payment_t p;

    p.id = get_max_pay_id();
    p.member_id = member_id;
    p.type = fine;
    p.amount = amount;
    current_date(&p.transaction_time);
    p.nextpayment_duedate.day = 0;
    p.nextpayment_duedate.month = 0;
    p.nextpayment_duedate.year = 0;

    if(payment_save(&p) == 1){
        return 1;       //payment done successfully
    }
    else{
        return 0;       //payment failed
    }
}

int payment_add_fees(int member_id){
    payment_t p;
    
    if(ispaid_user(member_id) == 1){
        return 2;       //if member is already a paid user.
    }

    p.id = get_max_pay_id() + 1;
    p.member_id = member_id;
    p.type = fees;
    p.amount = 100;
    current_date(&p.transaction_time);
    adddays(p.transaction_time, 30, &p.nextpayment_duedate);

    if(payment_save(&p) == 1 && update_due_date(p.member_id, p.nextpayment_duedate)){
        return 1;       //payment done successfully
    }
    else{
        return 0;       //payment failed
    }
   
}

int payment_report(date_t init_date, date_t final_date, int *total_fees, int *total_fine){
    if(total_payment(init_date, final_date, total_fees, total_fine) == 1){
        return 1;   //successfully executed
    }
    else{
        return 0;   //failed to proceed the request
    }
}