#include<stdio.h>
#include<string.h>
#include"issuerecord.h"

int issuerecord_save(issuerecord_t *ir){
    FILE *fir;
    
    fir = fopen(ISSUERECORD_FILE, "ab");
    if(fir == NULL){
        return 0;
    }

    size_t recordwritten = fwrite(ir, RECSIZE_ISSUERECORD, 1, fir);

    fclose(fir);

    if(!recordwritten){
        return 0;
    }
    else{
        return 1;
    }
}

int get_max_issuerecord_id(){
    issuerecord_t issuerecord_buff;
    // int max_id = 0;

    FILE *fir;
    fir = fopen(ISSUERECORD_FILE, "rb");
    if(fir == NULL){
        return 0;  //error
    }

    fseek(fir, -RECSIZE_ISSUERECORD, SEEK_END);
    size_t recordread = fread(&issuerecord_buff, RECSIZE_ISSUERECORD, 1, fir);

    fclose(fir);

    if(!recordread){
        return 0;       //error
    }
    else{
        return issuerecord_buff.id;  
    }
}

int issuerecord_update(issuerecord_t *ir){
    int flag_update = 0;
    issuerecord_t ir_buff;
    
    FILE *fir;
    fir = fopen(ISSUERECORD_FILE, "rb+");
    if(fir = NULL){
        return 0;       //failed to update issuerecord.
    }

    while(fread(&ir_buff, RECSIZE_ISSUERECORD, 1, fir) > 0){
        if(ir_buff.id == ir->id){

            fseek(fir, -RECSIZE_ISSUERECORD, SEEK_CUR);
            fwrite(ir, RECSIZE_ISSUERECORD, 1, fir);
            
            flag_update = 1;
            break;
        }
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int issuerecord_find_by_id(int issuerecord_id, issuerecord_t *ir){
    int flag_search = 0;

    FILE *fir;
    fir = fopen(ISSUERECORD_FILE, "rb");
    if(fir == NULL){
        return 0;
    }

    while(fread(ir, RECSIZE_ISSUERECORD, 1, fir) > 0){
        if(issuerecord_id == ir->id){
            flag_search = 1;
            break;
        }
    }

    if(!flag_search){
        return 0;
    }
    else{
        return 1;
    }
}