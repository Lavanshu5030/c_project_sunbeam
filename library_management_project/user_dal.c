#include <stdio.h> // Tier-1
#include <stdlib.h>
#include <string.h>
#include "user_dal.h"
#include "user_service.h"
#include "user_control.h"
#include"user.h"

int user_save(user_t *u) {
    FILE *file = fopen("user.db", "ab");  // Open the file in binary write mode

    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    fwrite(u, sizeof(user_t), 1, file);  // Write the user structure to the file

    fclose(file);  // Close the file

    return 1;
}

user_t* find_user_by_id(int *id) {
    FILE *file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    user_t *user = (user_t* )malloc(sizeof(user_t));
    if (user == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return NULL;
    }

    while (fread(user, sizeof(user_t), 1, file) == 1) {
        if (user->id == *id) {
            fclose(file);
            return user;
        }
    }
  

    fclose(file);
    free(user);
    printf("Record Not Found"); // Do not print in this file
    return NULL;
}

user_t* find_user_by_email(char* email) {
    FILE* file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    user_t temp_user;
    while (fread(&temp_user, sizeof(user_t), 1, file) == 1) {
        if (strcmp(temp_user.email, email) == 0) {
            fclose(file);
            user_t* user = (user_t*) malloc(sizeof(user_t));
            if (user == NULL) {
                printf("Error allocating memory.\n");
                return NULL;
            }
            *user = temp_user; // Copy the data to the allocated memory
            return user;
        }
    }

    fclose(file);
    printf("Record not found.\n");// Do not print in this file
    return NULL;
}

int user_get_max_id() {
    FILE* file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1; // Return -1 to indicate an error
    }

    int max_id = -1; // Initialize with a value that is lower than any possible ID

    user_t temp_user;
    while (fread(&temp_user, sizeof(user_t), 1, file) == 1) {
        if (temp_user.id > max_id) {
            max_id = temp_user.id;
        }
    }

    fclose(file);

    if (max_id == -1) {
        printf("No records found.\n");
    }

    return max_id;
}

int user_update(user_t *u){
    
    user_t user_buff;
    
    int updated = 0;    //flag

    FILE *fu;
    fu = fopen("user.db", "rb+");
    if(fu == NULL){
        return 0;
    }

    while( fread(&user_buff, sizeof(user_t) , 1, fu) > 0 ) {
        
        // if id is matching or not
        if(u->id == user_buff.id){
            
            //copies date to the respective fields
            strcpy(user_buff.email, u->email);
            strcpy(user_buff.phone, u->phone);
            strcpy(user_buff.password, u->password);
            user_buff.nextpayment_duedate = u->nextpayment_duedate;
          
            fseek(fu, -sizeof(user_t), SEEK_CUR);  // move file fpos to one record back
            fwrite(&user_buff, sizeof(user_t), 1, fu);    // update changes into the file
            
            updated = 1;
            break;
        }
    }
    fclose(fu);

    if(!updated){
        return 0;
    }
    else{
        return 1;
    }
}





