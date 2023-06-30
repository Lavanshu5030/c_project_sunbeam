#include <stdio.h>  // Tier-3
#include "user_dal.h"
#include "user_service.h"
#include "user_control.h"
#include"user.h"
#include"book.h"


int user_accept(user_t *u) {
    // printf("Enter your ID: ");
    // scanf("%d", &u->id);
    u->id = 1+user_get_max_id();
    printf("User id = %d\n", u->id);

  
    printf("Enter your name: ");
    getchar();
    scanf("%s", u->name);
  

    printf("Enter your email: ");
    getchar();
    
    scanf("%s", u->email);

    printf("Enter your password: ");
    getchar();

    scanf("%s", u->password);

    printf("Enter your phone: ");
    getchar();
    scanf("%s", u->phone);


    printf("------------------------------\n");
     return 1;
}

void user_print(user_t *u) {

    if(u == NULL){
        printf("User not found");
    }
    printf("ID: %d\n", u->id);
    printf("Name: %s\n", u->name);
    printf("Email: %s\n", u->email);
    printf("Password: %s\n", u->password);
    printf("Phone:%s\n",u->phone);
    // printf("Role:%s\n", u->role);
}

void signin(int *user_id){
    user_t u;
    
    char email[EMAIL_SIZE];
    char password[PASSWD_SIZE];

LOGIN_PROMPT:

    printf("Enter login credentials.\n");
    printf("Email\t: ");
    scanf("%[^\n]", email);
    printf("Password\t:");
    scanf("%*c%[^\n]", password);
    scanf("%*c");   //this removes \n from input buffer for re taking login credentials after failed user authentication.  
    
    if(user_authenticate(email, password, &u) == 1){
        *user_id = u.id;
        printf("User logged in successfully....!!\n");
        sign_in_menu();
    }
    else{
        printf("Incorrect email or password.\n");
        goto LOGIN_PROMPT;
    }
}

void signup(){
    user_t new_member;

    printf("Please enter the details.\n");
    user_accept(&new_member);
    
    int flag = member_register(&new_member);
    if(flag == 1){
        printf("New member successfully registered..!!\n");
    }
    else if(flag == 2){
        printf("Email is already registered with different account. Please use different email address.\n");
    }
    else{
        printf("Failed to register new user..!!\n");
    }
}

void change_password(int id){

    char new_passwd[PASSWD_SIZE];
    printf("Please enter new password : ");
    scanf("%[^\n]", new_passwd);
    if(update_password(id, new_passwd) == 1){
        printf("Password changed successfully..!!\n");
    }
    else{
        printf("Error while changing password.\n");
    }
}

void edit_profile(int id){
    char new_email[EMAIL_SIZE];
    char new_phone[PHONE_SIZE];

    printf("Enter new details.\n");
    printf("New email address : ");
    scanf("%[^\n]", new_email);
    printf("Enter new phone number : ");
    scanf("%*c%[^\n]",new_phone);

    if(update_profile(id, new_email, new_phone) == 1){
        printf("Profile updated successfully..!!\n");
    }
    else{
        printf("Error while updating profile.\n");
    }
}
void appoint_librarian(){
    user_t new_librarian;

    printf("\nPlease enter the details.\n");
    user_accept(&new_librarian);
    
    int flag = librarian_register(&new_librarian);
    if(flag == 1){
        printf("New Librarian added...!!\n");
        signed_in_librarian_menu();
    }
    else if(flag == 2){
        printf("Email is already registered with different account. Please use different email address.\n");
    }
    else{
        printf("Failed to register new librarian..!!\n");
    }
}





