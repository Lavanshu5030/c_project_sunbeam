#include <stdio.h> // Tier-2
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // To use 'R_OK'
#include "user_service.h"
#include "user_control.h"
#include "user_dal.h"
#include "user.h"
#include "date.h"

int user_authenticate(char* email, char* password,user_t *u) {
    FILE* file = fopen("user.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0; // Return 0 to indicate authentication failure
    }

    user_t temp_user;
    while (fread(&temp_user, sizeof(user_t), 1, file) == 1) {
        if (strcmp(temp_user.email, email) == 0 && strcmp(temp_user.password, password) == 0) {
            fclose(file);
            return 1; // Return 1 to indicate authentication success
        }
    }

    fclose(file);
    return 0; // Return 0 to indicate authentication failure
}

int member_register(user_t* user) {
    int max_id = user_get_max_id();
    int new_id = max_id + 1;


    user_t new_user;
    new_user.id = new_id;
    new_user.role = member;
    
    user_accept(&new_user);
    strcpy(new_user.email, user->email);
    strcpy(new_user.name, user->name);

    user_save(&new_user);
    return 0;
    printf("User registered successfully with ID: %d\n", new_id);
}


int owner_register(user_t *owner) {
    // Check if the "user.db" file exists and is readable
    if (access("user.db", R_OK) == 0) {
        // Delete the "user.db" file
        if (remove("user.db") != 0) {
            printf("Error deleting the file.\n");
            return 0;  // Return 0 to indicate failure
        }
    }

    // Set the ID of the owner
    owner->id = 1;

    // Open the "user.db" file in write binary mode
    FILE* file = fopen("user.db", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;  // Return 0 to indicate failure
    }

    // Write the owner to the file
    fwrite(owner, sizeof(user_t), 1, file);

    // Close the file
    fclose(file);

    return 1;  // Return 1 to indicate success
}

int librarian_register(user_t *u){
    u->id = get_max_id() + 1;
    u->role = librarian;
    u->nextpayment_duedate = (date_t){0,0,0};

    if(user_save(u) == 1){
        return 1;
    }
    else{
        return 0;
    }
 }

 int update_password(int id, char new_passwd[PASSWD_SIZE]){
    int flag_update = 0;
    user_t u_temp;

    if(user_find_by_id(id, &u_temp) == 1){
        
        strcpy(u_temp.password, new_passwd);
        
        if(user_update(&u_temp) == 1){
            flag_update = 1;
        }
        else{
            flag_update = 0;
        }
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int update_profile(int id, char new_email[EMAIL_SIZE], char new_phone[PHONE_SIZE]){
    int flag_update = 0;
    user_t u_temp;

    if(user_find_by_id(id, &u_temp) == 1){

        strcpy(u_temp.email, new_email);
        strcpy(u_temp.phone, new_phone);
        
        if(user_update(&u_temp) == 1){
            flag_update = 1;
        }
        else{
            flag_update = 0;
        }
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int ispaid_user(int member_id){
    int flag_paid;
    user_t u_buff;
    date_t currdate;
    current_date(&currdate);

    if(user_find_by_id(member_id, &u_buff)){
        
        int diff = datecmp(currdate, u_buff.nextpayment_duedate);
        

        if(diff == 0){
            flag_paid = 1;
        }
        else{
            flag_paid = 0;
        }
    }
    
    if(!flag_paid){
        return 0;
    }
    else{
        return 1;
    }   
}

int update_due_date(int id, date_t nextpayment_duedate){
    int flag_update = 0;
    user_t u_temp;

    if(user_find_by_id(id, &u_temp) == 1){

        u_temp.nextpayment_duedate = nextpayment_duedate;        
        
        if(user_update(&u_temp) == 1){
            flag_update = 1;
        }
        else{
            flag_update = 0;
        }
    }

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

