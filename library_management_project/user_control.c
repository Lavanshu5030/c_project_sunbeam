#include <stdio.h>  // Tier-3
#include "user_dal.h"
#include "user_service.h"
#include "user_control.h"
#include"user.h"


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

    printf("Enter your role: ");
    getchar();
    scanf("%s", u->role);

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
    printf("Role:%s\n", u->role);
}



