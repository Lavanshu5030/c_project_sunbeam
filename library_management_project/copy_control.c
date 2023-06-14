#include <stdio.h>
#include <string.h>
#include "copy.h"

void copy_accept(copy_t *c) {
    printf("Enter copy id: ");
    scanf("%d",&c->copy_id);

    printf("Enter rack: ");
    scanf("%d",&c->rack);

    printf("Enter your isbn:\n");
    getchar();  // Consume the newline character left in the input buffer
    fgets(c->isbn, sizeof(c->isbn), stdin);
    c->isbn[strcspn(c->isbn, "\n")] = '\0';  // Remove the trailing newline

    printf("Enter book status: \n");
    fgets(c->status, sizeof(c->status), stdin);
    c->status[strcspn(c->status, "\n")] = '\0';  // Remove the trailing newline
     

    printf("------------------------------\n");
    // return b;
}
void copy_print(copy_t *c) {

    if(c == NULL){
        printf("User not found");
    }
    printf("copy id: %d\n", c->copy_id);
    printf("isbn: %s\n", c->isbn);
    printf("rack: %d\n", c->rack);
    printf("status: %s\n", c->status);
}
