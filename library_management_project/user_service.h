#ifndef USER_SERVICE
#define USER_SERVICE

#include "user.h"

int user_authenticate(char* email, char* password, user_t *u);
int member_register(user_t* user);
int owner_register(user_t *owner);
int librarian_register(user_t *u);
int update_password(int id, char new_passwd[PASSWD_SIZE]);
int update_profile(int id, char new_email[EMAIL_SIZE], char new_phone[PHONE_SIZE]);
int ispaid_user(int member_id);
int update_due_date(int id, date_t nextpayment_duedate);


#endif //USER_SERVICE
