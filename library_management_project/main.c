#include <stdio.h>
#include "user_dal.h"
#include "user_service.h"
#include "user_control.h"
#include"user.h"

int main()
{
    user_t my_user; 
    // user_accept(&my_user);//Tier-3
    // user_print(&my_user);//Tier-3
    // user_save(&my_user);//Tier-1
    //Tier-1
    // user_update(&my_user);//Tier-1
    

// int main(int argc, char *argv[]) {
//     if(argc == 2 && strcmp(argv[1], "--init") == 0) {
//         // user_t owner;
//         // user_accept(&ownername,&email,&password,&phone,&roler);
//         // owner_register(&owner);
//         exit(0);
//     }

//     // menu-driven program
   
// }
    

    // int by_id;
    // char email[20];
    // char password[20];

    // printf("Enter Id:\n");
    // scanf("%d",&by_id);

    // user_print(find_user_by_id(&by_id));//If present print using user_print();
    // find_user_by_id(&by_id); // if record is not present in user.db

    // printf("Enter email id:\n");
    // scanf("%s",email);

    // find_user_by_email(email);
    // user_print(find_user_by_email(email));

    // int max = user_get_max_id();
    // printf("%d\n",max);
    // printf("Enter email id:\n");
    // scanf("%s", email);
    // printf("%s", "Enter password:\n");
    // scanf("%s", &password);

    // user_update(by_id, email, name);
    // int authenticate = user_authenticate(email,password); //Tier-2
    // printf("%d\n",authenticate);
    // user_register(&my_user);
    int result = owner_register(&my_user);
    if (result == 1) {
        printf("Owner registered successfully\n");// Owner registration was successful
    } else {
        printf("Owner registration failed\n");// Owner registration failed
    }
    
    
    
    

    return 0;
}

