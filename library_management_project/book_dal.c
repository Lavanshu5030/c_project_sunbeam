#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "book.h"
#include "book_dal.h"
#include "copy.h"
#include "book_list.h"

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



int book_find_by_isbn(char *isbn, book_t *bk) {
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

int book_find_by_title(char *title, book_t *bl) {
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
        }
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
int copy_find_by_id(int id, copy_t *bc){
    int flag_found = 0;  //flag
    FILE *fbc;
    
    fbc = fopen("copy.db" , "rb");
    if(fbc == NULL){
        return 0;
    }

    while ( fread(bc, sizeof(copy_t), 1, fbc) > 0){
        if(bc->copy_id == id){            
            flag_found = 1;
            break;
        }
    }

    fclose(fbc);

    if(!flag_found){
        return 0;
    }
    else{
        return 1;
    }
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

int copy_update(copy_t *bc){
    
    copy_t book_copy_buff;
    
    int flag_update = 0;    //flag

    FILE *fbc;
    fbc = fopen("copy.db", "rb+");
    if(fbc == NULL){
        return 0;
    }

    while( fread(&book_copy_buff, sizeof(copy_t) , 1, fbc) > 0 ) {
        
        // if isbn is matching or not
        if(bc->copy_id == book_copy_buff.copy_id){
            
            //copies data to the respective fields.
            book_copy_buff.rack = bc->rack;            
            book_copy_buff.status = bc->status;

            fseek(fbc, -sizeof(copy_t), SEEK_CUR);  // move file fpos to one record back
            fwrite(&book_copy_buff, sizeof(copy_t), 1, fbc);    // update changes into the file
            
            flag_update = 1;
            break;
        }
    }
    fclose(fbc);

    if(!flag_update){
        return 0;
    }
    else{
        return 1;
    }
}

int copy_get_count(char isbn[ISBN_LENGTH], int *total_count, int *avail_count){ 
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
 int copy_avail_id(char isbn[ISBN_LENGTH], copy_t *bc){
    int flag_avail = 0;

    FILE *fbc;
    fbc = fopen("copy.db", "rb");
    if(fbc == NULL){
        return -1;      //error opening file.
    }

    while(fread(bc, sizeof(copy_t), 1, fbc) > 0){
        if(strcmp(isbn, bc->isbn) == 0){            
            if(bc->status == 1){
                flag_avail = 1;
                break;
            }
        }
    }

    fclose(fbc);

    if(!flag_avail){
        return 0;   //book copy isn't available.
    }
    else{
        return 1;   //book copy is available.
    }
}

int generate_category_list(hashtable_category_t *hc){
    book_t b_buff;
    FILE *fb;

    fb = fopen(BOOK_FILE, "rb");
    if(fb == NULL){
        return -1;
    }

    while( fread(&b_buff, RECSIZE_BOOK, 1, fb) > 0){
        int asc_key = generate_asc_key(b_buff.category);
        entry_category_t ec; 
        
        ec.asc_key = asc_key;
        strcpy(ec.value.book_category, b_buff.category);
        
        
        hc_insert(ec, hc);
    }

    fclose(fb);

    return 1;
}









 
