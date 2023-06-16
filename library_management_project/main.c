#include <stdio.h>
#include <stdlib.h>
#include "user_dal.h"
#include "user_service.h"
#include "user_control.h"
#include "user.h"
#include "book.h"
#include "book_control.h"
#include "book_dal.h"
#include "copy.h"



int main()
{
    // user_t my_user;
    // user_accept(&my_user);//Tier-3
    // user_print(&my_user);//Tier-3
    // user_save(&my_user);//Tier-1
    // Tier-1
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
    // printf("Enter password:\n");
    // scanf("%s", password);

    // user_update(by_id, email, password);
    // int authenticate = user_authenticate(email,password); //Tier-2
    // printf("%d\n",authenticate);
    // user_register(&my_user);
    // int result = owner_register(&my_user);
    // if (result == 1) {
    //     printf("Owner registered successfully\n");// Owner registration was successful
    // } else {
    //     printf("Owner registration failed\n");// Owner registration failed
    // }

    // BOOK
    // book_t my_book;
    // book_accept(&my_book);
    // int saveResult = book_save(&my_book);
    // if (saveResult) {
    //    printf("Success !!!\n");  // Success
    // } else {
    //    printf("Failure\n"); // Failure
    // }
    // book_print(&my_book);
    // book_add(&my_book);//tier-3

    // char *isbn_to_find = "8ddid";
    // book_print(book_find_by_isbn(isbn_to_find));
    //  char title[20];
    // printf("Enter title:\n");
    // scanf("%s", title);
    // book_find_by_title(title);
    // book_print(book_find_by_title(title));// Able to find only one record (list should get printed)
    // char author[20];
    // char *isbn = "74mf";
    // printf("Enter author:\n");
    // scanf("%s", author);
    // printf("Enter title:\n");
    // scanf("%s", title);
    // int i = book_update(isbn, author, title);
    // printf("%d", i);
    // copy_t my_copy;
    // copy_accept(&my_copy);
    // copy_print(&my_copy);
    // copy_add();
    // copy_get_status();
    int total_count=0;
    char isbn[ISBN_LENGTH];
    int avail_count=0;
    printf("Enter isbn:");
    scanf("%s\n", isbn);
    book_copy_get_count(isbn,&total_count,&avail_count);
    printf("Total count :%d\n", total_count);
    printf("avail count: %d\n", avail_count);


    return 0;
}
