#include <stdio.h>
#include <string.h>
#include "book.h"
#include "book_dal.h"


void book_accept(book_t *b) {
    printf("Enter isbn: ");
    scanf("%s", b->isbn);

  
    printf("Enter your title:\n");
    getchar();  // Consume the newline character left in the input buffer
    fgets(b->title, sizeof(b->title), stdin);
    b->title[strcspn(b->title, "\n")] = '\0';  // Remove the trailing newline

    printf("Enter book author: \n");
    fgets(b->author, sizeof(b->author), stdin);
    b->author[strcspn(b->author, "\n")] = '\0';  // Remove the trailing newline


    printf("Enter your category:\n");
    fgets(b->category, sizeof(b->category), stdin);
    b->category[strcspn(b->category, "\n")] = '\0';  // Remove the trailing newline
   

    printf("Enter your price:\n");
    scanf("%2f", &b->price);

    printf("------------------------------\n");
    // return b;
}

void book_print(book_t *b) {

    if(b == NULL){
        printf("Book not found");
    }
    printf("Isbn: %s\n", b->isbn);
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Category: %s\n", b->category);
    printf("Price:%f\n",b->price);
}

void book_add(book_t *b) {
    book_accept(b);
    book_save(b);
    printf("Added new book Sucessfully \n");
}

