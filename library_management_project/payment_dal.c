#include <stdio.h>
#include "payment.h"
#include "date.h"

int payment_save(payment_t *p){

    FILE *fp;

    fp = fopen(PAYMENT_FILE,"ab");
    if(fp == NULL){
        return 0;
    }

    size_t recordwritten = fwrite(p, RECSIZE_PAYMENT, 1, fp);

    fclose(fp);

    if(!recordwritten){
        return 0;
    }
    else{
        return 1;
    }
}

int get_max_pay_id(){
    payment_t p_buff;
    FILE *fp;

    fp = fopen(PAYMENT_FILE, "rb");
    if(fp == NULL){
        return 0;
    }

    fseek(fp, -RECSIZE_PAYMENT, SEEK_END);
    fread(&p_buff, RECSIZE_PAYMENT, 1, fp);
    
    fclose(fp);

    return p_buff.id;
}

int payment_search_by_id(int payment_id, payment_t *p){
    int flag_found = 0;  //flag
    FILE *fp;
    
    fp = fopen(PAYMENT_FILE , "rb");
    if(fp == NULL){
        return 0;
    }

    while ( fread(p, RECSIZE_PAYMENT, 1, fp) > 0){
        if(p->id == payment_id){            
            flag_found = 1;
            break;
        }
    }

    fclose(fp);

    if(!flag_found){
        return 0;
    }
    else{
        return 1;
    }
}

int payment_total(date_t init_date, date_t final_date, int *total_fees, int *total_fine){
    payment_t p_buff;
    int flag = 0;
    FILE *fp;

    fp = fopen(PAYMENT_FILE, "rb");
    if(fp == NULL){
        return -1;  //error while opening file.
    }

    while(fread(&p_buff, RECSIZE_PAYMENT, 1, fp) > 0){
        
        int cmp_l = datecmp(init_date, p_buff.transaction_time);
        int cmp_g = datecmp(final_date, p_buff.transaction_time);

        // checks record's transaction is in between init_date and final_date.      
        if((cmp_l == 0 || cmp_l == 2) && (cmp_g == 1 || cmp_g == 2)){
            if(p_buff.type == fees){
                *total_fees += p_buff.amount;
            }
            else if(p_buff.type == fine){
                *total_fine += p_buff.amount;
            }
            flag = 1;
        }
        else{
            break;
        }
    }

    if(flag == 1)
        return 1;   //successfuly executed.
    else
        return 0;
}