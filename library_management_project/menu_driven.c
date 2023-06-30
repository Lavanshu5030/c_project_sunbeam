#include <stdio.h>
#include "book.h"

int main(){
    int choice;

    while (1) {
        printf("Menu\n");
        printf("1. Sign In\n");
        printf("2. Sign Up\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sign_in();
                break;
            case 2:
                sign_up();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    

    return 0;
}

void sign_in_menu(){
    int choice;
    int user_id;

    while (1) {
        printf("\n");
        printf("Menu\n");
        printf("0. Sign out\n");
        printf("1. Edit Profile\n");
        printf("2. Change Password\n");
        printf("3. Subject Wise Report\n");
        printf("4. Bookwise copies report");
        printf("Fee/Fine report");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Signed Out\n");
                return;

            case 1:
                printf("1. Enter User Id:\n");
                scanf("%d", &user_id);
                edit_profile(user_id);
                // Implement view profile logic
                break;
            case 2:
                printf("Changing password...\n");
                printf("1. Enter User Id:\n");
                scanf("%d", &user_id);
                change_password(user_id);
                // Implement change password logic
                break;
            case 3:
                printf("3. Subject Wise Report\n");
                break;
            case 4:
                printf("4. Bookwise copies report\n");
                break;
            case 5:
                printf("Fee/fine report");
                break;        
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void signed_in_librarian_menu(){
    int choice;
    int user_id;
    char title[TITLE_LENGTH];

    while (1) {
        printf("\n");
        printf("Menu\n");
        printf("0. Sign out\n");
        printf("1. Edit Profile\n");
        printf("2. Change Password\n");
        printf("3. Subject Wise Report\n");
        printf("4. Bookwise copies report");
        printf("Fee/Fine report");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Signed Out\n");
                return;

            case 1:
                printf("1. Enter User Id:\n");
                scanf("%d", &user_id);
                edit_profile(user_id);
                // Implement view profile logic
                break;
            case 2:
                printf("Changing password...\n");
                printf("1. Enter User Id:\n");
                scanf("%d", &user_id);
                change_password(user_id);
                // Implement change password logic
                break;
            case 3:
                printf("3. Find book by name\n");
                printf("1. Enter book name:\n");
                scanf("%s",title);
                find_book_by_title();
                break;
            case 4:
                printf("4. Check book availability\n");
                check_copy();
                break;
            case 5:
                printf("Add new book\n");
                book_add();
                break;

            case 6:
                printf("Add new copy\n");
                copy_add();
                break;    
            
            case 7:
                printf("Issue book copy\n");
                issue_copy();
                break;
    
            case 8:
                printf("Return book copy\n"); 
                return_copy();   
                break;
            
            case 9:
                printf("List of issued book");
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}