#include <stdio.h>
#include "payment_service.h"
#include "payment_dal.h"
#include "date.h"

void take_payment(){
    int member_id;
    printf("\nEnter the member ID : ");
    scanf("%d", &member_id);

    int flag_pay = payment_add_fees(member_id);

    if(flag_pay == 1){
        printf("\nPayment done successfully..!!\n Member with member ID : %d is now paid member", member_id);
    }
    else if(flag_pay == 2){
        printf("\nMember is already submitted the fees for this month.");
    }
    else{
        printf("\nFailed to process your request..!!\nTry again later.");
    }
}

void print_payment(){
    int payment_id;
    payment_t p;
    char *paytype;


    printf("\nEnter the payment id : ");
    scanf("%d", &payment_id);
    
    int pay = payment_search_by_id(payment_id, &p);

    if(p.type == 0)
        paytype = "Fine";
    else if(p.type == 1)
        paytype = "Fees";

    if(pay == 1){
        printf("\nPayment ID : %d\nMember ID : %d\nAmount : %.2f\nPayment type : %s\nTransaction time : %02d-%02d-%04d\nNext Payment Due Date : %02d-%02d-%04d" , p.id , p.member_id, p.amount, paytype, p.transaction_time.day, p.transaction_time.month, p.transaction_time.year, p.nextpayment_duedate.day, p.nextpayment_duedate.month, p.nextpayment_duedate.year);
    }
    else{
        printf("Record not found ..!!");
    }
}

void fine_fees_report(){
    int total_fees = 0;
    int total_fine = 0;
    date_t init_date, final_date;

    printf("\nEnter the date range (dd-mm-yyyy) :");
    printf("\nFrom :");
    scanf("%d%*c%d%*c%d", &init_date.day, &init_date.month, &init_date.year);
    printf("To :");
    scanf("%d%*c%d%*c%d", &final_date.day, &final_date.month, &final_date.year);

    if(payment_report(init_date, final_date, &total_fees, &total_fine) == 1){
        printf("\nFees/Fine Report");
        printf("\nTotal Fees : %d", total_fees);
        printf("\nTotal Fine : %d", total_fine);
    }
    else{
        printf("\nFailed to proceed your request");
    }
}