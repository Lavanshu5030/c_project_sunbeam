#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "book.h"
#include "book_dal.h"
#include "copy.h"

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

int book_update(char *isbn, char *author, char *title){
    FILE* file = fopen("book.db", "r+b");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1; // Return -1 to indicate an error
    }
    book_t buffer;
    while (fread(&buffer, sizeof(book_t), 1, file) > 0)
    {

        if (strcmp(buffer.isbn, isbn) == 0) {
            // Update the record with new values
            
            strncpy(buffer.author, author, sizeof(buffer.author));
            strncpy(buffer.title, title, sizeof(buffer.title));

            // Move the file pointer back to the beginning of the record
            fseek(file, -sizeof(book_t), SEEK_CUR);

            // Write the updated record back to the file
            fwrite(&buffer, sizeof(book_t), 1, file);

            printf("Record updated successfully.\n"); // Do not use print in this file
            fclose(file);
            return 1;
            
        }
        
    }
    fclose(file);
    return 0;
    
}

int copy_save(copy_t *u) {
    u->status =1;
    FILE *file = fopen("copy.db", "ab");  // Open the file in binary write mode

    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    fwrite(u, sizeof(copy_t), 1, file);  // Write the user structure to the file

    fclose(file);  // Close the file

    return 1;
}

int copy_get_max_id() {
    FILE* file = fopen("copy.db", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1; // Return -1 to indicate an error
    }

    int max_id = -1; // Initialize with a value that is lower than any possible ID

    copy_t temp_copy;
    fseek(file, -sizeof(copy_t), SEEK_END);
    size_t recordread = fread(&temp_copy, sizeof(copy_t),1,file);

    fclose(file);

    if(recordread == 1){
        return temp_copy.copy_id;
    }
    else{
        printf("No records found.\n");
    }

    return max_id;
}

// copy_t check_status(copy_t *c) {
    
//     FILE *file = fopen("copy.db", "r");
//     if (file == NULL) {
//         printf("Error opening file 'copy.db'.\n");
//         copy_t empty_copy = {"", ""};
//         return empty_copy;
//     }

//     copy_t copy;
//     int found = 0;

//     // Read the file line by line
//     while (fread(&copy, sizeof(copy_t), 1, file) == 1) {
//         // Compare the ISBN with the input
//         if (strcmp(copy.isbn, c) == 0) {
//             found = 1;
//             break;
//         }
//     }

//     fclose(file);

//     if (!found) {
//         printf("No copies found for ISBN '%s'.\n", c);
//         copy_t empty_copy = {"", ""};
//         return empty_copy;
//     }

//     return copy;
// }

int book_copy_get_count(char isbn[ISBN_LENGTH], int *total_count, int *avail_count){ 
     copy_t book_copy_buff; 
     FILE *fbc; 
  
     fbc = fopen("copy.db", "rb"); 
     if(fbc == NULL){ 
         return 0;      //error while opening file. 
     } 
  
     while(fread(&book_copy_buff, sizeof(copy_t), 1, fbc) > 0){ 
         printf("%s", book_copy_buff.isbn); 
         if(strcmp(isbn, book_copy_buff.isbn) == 0){ 
             (*total_count)++; 
             if(book_copy_buff.status == 1){ 
                 (*avail_count)++; 
             } 
         } 
     } 
  
     fclose(fbc); 
  
     return 1; 
 }


