#include <stdio.h>
#include <string.h>
#include "book.h"
#include "book_dal.h"
#include "copy.h"


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
    scanf("%f", &b->price);

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
    printf("Price:%2f\n",b->price);
}

void book_add(book_t *b) {
    book_accept(b);
    book_save(b);
    printf("Added new book Sucessfully \n");
}

void book_edit_control(){
    book_t b;
    printf("Enter new details of the book except ISBN :");
    book_accept(&b);
    if(book_edit(&b) == 1){
        printf("\nBook updated successfully..!!");
    }
    else{
        printf("Failed to edit book..!!");
    }
}

void book_find_by_title_control(){
    book_t b;
    char title[100];
    printf("Enter the title of the book : ");
    scanf("%[^\n]",title);
    if(book_find_by_title(title,&b) == 1){
        printf("\nBook Found..!!\n");
        book_print(&b);
    }
    else{
        printf("\nBook Not Found..!!");
    }
}

void copy_accept(copy_t *copy) {
    // printf("Enter Copy ID: ");
    // scanf("%d", &(copy->copy_id));

    copy->copy_id = 1+copy_get_max_id();
    printf("Copy id = %d\n", copy->copy_id);



    printf("Enter ISBN: ");
    scanf("%s", copy->isbn);
    printf("Enter Rack No: ");
    scanf("%d", &(copy->rack));
    printf("Enter Status (1 for available, 0 for not available): ");
    scanf("%d", &(copy->status));
}

void copy_add(){
    copy_t new_copy;
    copy_accept(&new_copy);
    copy_save(&new_copy);
    printf("Saved Successfully");
}

void copy_tocheck_status_accept_isbn(char *isbn){
    printf("Enter the ISBN: ");
    scanf("%s", isbn);
    printf("ISBN entered successfully");
}

void copy_print(copy_t *c) {

    if(c == NULL){
        printf("Book not found");
    }
    printf("id: %d\n", c->copy_id);
    printf("status: %d\n", c->status);
    printf("rack: %d\n", c->rack);

}

void change_rack(){
    copy_t bc;
    int book_copy_id;
    int rack;
    
    printf("\nEnter the ID of Book copy : ");
    scanf("%d", &book_copy_id);
    printf("\nEnter the new rack number : ");
    scanf("%d", &rack);
    
    if(copy_change_rack(book_copy_id, rack,  &bc) == 1){
        printf("Rack of book copy with ID %d changed successfully..!!", book_copy_id);
    }
    else{
        printf("Failed to change rack..!!");
    }
}

void check_book_availability(){
    char isbn[ISBN_LENGTH] = {0};
    printf("\nEnter the ISBN of the book : ");
    scanf("%s", isbn);
    if(copy_available(isbn) == 1){
        printf("\nBook is available !!");
    }
    else{
        printf("\nBook is not available !!");
    }
}

void book_categories_report(){
    hashtable_category_t hc;
    int hashtable_category_size = 11;
    
    init_hashtable_category(hashtable_category_size, &hc);

   if(get_category_list(&hc) == 1){
    printf("\nBook Report (Categorywise) :\n");
    
    for(int i = 0; i < hashtable_category_size; i++){
            
            if(hc.table[i].head == NULL){
                continue;
            }

            node_category_t *trav = hc.table[i].head;
            while (trav != NULL)
            {
                book_category_count_print(&trav->data);
                trav = trav->next;
            }
             
        }
    }
    else{
        printf("\nError while generating report..!!");
    }
}









