#ifndef USER_DAL
#define USER_DAL

#include "user.h"

int user_save(user_t *u);
user_t * find_user_by_id(int *id);
user_t* find_user_by_email(char* email);
int user_get_max_id();


// void user_update(user_t *u);

#endif // USER_DAL