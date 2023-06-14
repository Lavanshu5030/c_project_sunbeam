#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "book.h"
#include "book_dal.h"

#define MAX_LINE_LENGTH 250

int book_save(book_t *book) {
    FILE *file = fopen("book.db", "ab");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 0;  // Indicate failure
    }

    if(fwrite(book, sizeof(book_t), 1, file) != 1) {
        printf("Error writing data to the file.\n");
        fclose(file);
        return 0;  // Indicate failure
    }

    printf("Data saved successfully!\n");

    fclose(file);
    return 1;  // Indicate success
}

// book_t* book_find_by_isbn(char *isbn) {
//     FILE *file = fopen("book.db", "rb");
//     if (file == NULL) {
//         printf("Error opening file.\n");
//         return NULL;
//     }

//     book_t *book = (book_t* )malloc(sizeof(book_t));
//     if (book == NULL) {
//         printf("Error allocating memory.\n");
//         fclose(file);
//         return NULL;
//     }

//     while (fread(book, sizeof(book_t), 1, file) == 1) {
//         if (book->isbn == isbn) {
//             fclose(file);
//             return book;
//         }
//     }
  

//     fclose(file);
//     free(book);
//     printf("Record Not Found"); // Do not print in this file
//     return NULL;
// }

book_t* book_find_by_isbn(char *isbn) {
    FILE* file = fopen("book.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    book_t temp_book;
    while (fread(&temp_book, sizeof(book_t), 1, file) > 0) {
        if (strcmp(temp_book.isbn, isbn) == 0) {
            fclose(file);
           book_t* book = (book_t*) malloc(sizeof(book_t));
            if (book == NULL) {
                printf("Error allocating memory.\n");
                return NULL;
            }
            *book = temp_book; // Copy the data to the allocated memory
            return book;
        }
    }

    fclose(file);
    printf("Record not found.\n");// Do not print in this file
    return NULL;
}

book_t* book_find_by_title(char *title) {
    FILE* file = fopen("book.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    book_t temp_book;
    while (fread(&temp_book, sizeof(book_t), 1, file) > 0) {
        if (strstr(temp_book.title, title) == 0) {
            fclose(file);
           book_t* book = (book_t*) malloc(sizeof(book_t));
            if (book == NULL) {
                printf("Error allocating memory.\n");
                return NULL;
            }
            *book = temp_book; // Copy the data to the allocated memory
            return book;
        }\
    }

    fclose(file);
    printf("Record not found.\n");// Do not print in this file
    return NULL;
}

