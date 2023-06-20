#include<stdio.h>
#include"book.h"
#include "copy.h"
#include"issuerecord.h"
#include"date.h"
#include"issuerecord_service.h"

void issue_copy(){
    int member_id;
    char isbn[ISBN_LENGTH] = {0};
    int issuerecord_id;
    
    printf("\nEnter member ID :");
    scanf("%d", &member_id);
    getchar();
    printf("\nEnter the ISBN of the book : ");
    scanf("%[^\n]", isbn);

    int flag_issued = issuerecord_add(isbn, member_id, &issuerecord_id);

    if(flag_issued == 1){
        printf("Book issued successfully.\n Your Issue ID is %d..!!", issuerecord_id);
    }
    else if(flag_issued == 0){
        printf("Book copy isn't available..!!");
    }
    else if(flag_issued == 0){
        printf("Error while saving issuerecord..!!");
    }
}

void return_copy(){
    int issuerecord_id;
    copy_t bc;

    printf("\nEnter the issuerecord ID");
    scanf("%d", &issuerecord_id);

    if(issuerecord_edit(issuerecord_id, &bc) == 1){
        printf("Issued book copy with %d has been returned", bc.copy_id);
    }
    else{
        printf("Failed to process your request..!!");
    }
}