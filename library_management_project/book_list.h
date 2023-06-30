#ifndef __BOOK_LIST_H
#define __BOOK_LIST_H

#include "book.h"

typedef struct book_node{
    book_t data;
    struct book_node *next;
}book_node_t;

typedef struct book_list
{
    book_node_t *head;
}book_list_t;

void init_book_list(book_list_t *bl);
book_node_t *create_book_node(book_t b);
void add_first_book_node(book_t b, book_list_t *bl);
void display_book_list(book_list_t *bl);
void free_book_list(book_list_t *bl);


#endif