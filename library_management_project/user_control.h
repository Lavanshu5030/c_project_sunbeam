#ifndef USER_CONTROL
#define USER_CONTROL

#include "user.h"

int user_accept(user_t *u);
void user_print(user_t *u);
void signin(int *user_id);
void signup();
void change_password(int id);
void edit_profile(int id);
void appoint_librarian();
void sign_in_menu();
void signed_in_librarian_menu();


#endif // USER_CONTROL