#ifndef USER_SERVICE
#define USER_SERVICE

#include "user.h"

int user_authenticate(char* email, char* password);
int user_register(user_t* user);


#endif //USER_SERVICE
