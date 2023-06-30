#ifndef USER_H
#define USER_H
#include "date.h"


#define USER_FILE "user.db"
#define USER_NAME_SIZE 41
#define EMAIL_SIZE 60
#define PASSWD_SIZE 40
#define PHONE_SIZE 11
#define RECSIZE_USER sizeof(user_t)


enum rol {owner, librarian, member};

typedef struct user{
    int id;                 // User ID
    char name[USER_NAME_SIZE];          // User name
    char email[EMAIL_SIZE];         // User email
    char password[PASSWD_SIZE];      // User password
    char phone[PHONE_SIZE];         // User phone number
    enum rol role;  
    date_t nextpayment_duedate;
}__attribute__((packed)) user_t;


#endif // USER_H