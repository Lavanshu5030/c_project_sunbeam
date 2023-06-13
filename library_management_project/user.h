#ifndef USER_H
#define USER_H

typedef struct user{
    int id;                 // User ID
    char name[50];          // User name
    char email[50];         // User email
    char password[50];      // User password
    char phone[20];         // User phone number
    char role[20];          // User role
}__attribute__((packed)) user_t;


#endif // USER_H