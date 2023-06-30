#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "mainmenu.h"

int main(int argc, char *argv[]) {
    
    if(argc == 2 && strcmp(argv[1], "--init") == 0) {
        user_t owner;
        user_accept(&owner);

        if(owner_register(&owner) == 1){
            printf("Intialization is successful.\n");
        }
        
        exit(0);
    }
    int user_id;
    enum rol user_role;
    loginpage_switch(&user_id, &user_role);
    
    return 0;
}
