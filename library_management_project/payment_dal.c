#include<stdio.h>
#include"payment.h"

int payment_save(payment_t *p){
    payment_t p_buff;
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