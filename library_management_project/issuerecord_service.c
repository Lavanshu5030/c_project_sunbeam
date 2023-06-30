#include<stdio.h>
#include<string.h>
#include"issuerecord.h"
#include"issuerecord_dal.h"
#include"book.h"
#include"book_dal.h"
#include"book_service.h"
#include"date.h"
#include"payment_service.h"
#include"user_service.h"

//This function add new issuerecord in ISSUERECORD_FILE. This returns "1" if issuerecord saved successfully, returns "0" if book not found, returns "-2" if member is unpaid and returns "-1" if got error while saving record.
int issuerecord_add(char isbn[ISBN_LENGTH], int member_id, int *issuerecord_id){
    
    issuerecord_t ir;
    copy_t bc;

    int paid = ispaid_user(member_id);
    if(paid == 0){
        return -2;
    }

    if(ispaid_user(member_id) == 0){
        return -2;
    }


    if(book_copy_avail_id(isbn, &bc) == 1){

        ir.id = get_max_issuerecord_id() + 1;           //automatically gets last record's id.
        
        ir.book_copy_id = bc.copy_id;                        //assigns available book copy id.
        if(book_copy_change_status(ir.book_copy_id, 0, &bc) == 0){
            return -1;                                  //failed to save issuerecord.
        }
        
        ir.member_id = member_id;                       //user inputed member id.
        ir.fine_amount = 0;                             // no fine_amount while issueing book.
        current_date(&ir.issue_date);                    //assings current date to ir.issue_date.
        adddays(ir.issue_date, 7, &ir.return_due_date); //assign ir.return_due_date.
        
        ir.return_date.day = 0;                         //no return date while issueing book.
        ir.return_date.month = 0;                       //no return date while issueing book.
        ir.return_date.year = 0;                        //no return date while issueing book.

        
        if(issuerecord_save(&ir) == 1){
            *issuerecord_id = ir.id;
            return 1;
        }
        else{
            return -1;      //failed to save issuerecord.
        }

    }
    else{
        return 0;           //Book_copy not available
    }

}

int issuerecord_edit(int issuerecord_id, copy_t *bc, float *amount){
    
    int flag_edit = 0;
    issuerecord_t ir;
    int fine_amount;

    if(issuerecord_find_by_id(issuerecord_id, &ir) == 1){
        
        current_date(&ir.return_date);
        
        if(datecmp(ir.return_date, ir.return_due_date ) == 1){
            fine_amount = date_diff(ir.return_date, ir.return_due_date) * 5;
            ir.fine_amount = *amount = fine_amount;
        }
        else{
            ir.fine_amount = *amount = 0;
        }
 
        if(issuerecord_update(&ir) == 1 && book_copy_change_status(ir.book_copy_id, 1, bc) == 1 && payment_add_fine(ir.fine_amount, ir.member_id) == 1){
            flag_edit = 1;
        }
    }

    if(!flag_edit){
        return 0;
    }
    else{
        return 1;
    }

}