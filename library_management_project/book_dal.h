#ifndef BOOK_DAL_
#define BOOK_DAL_

#include "book.h"
#include "copy.h"
#include "hashtable.h"
#include "book_list.h"


int book_save(book_t *book);
int book_find_by_isbn(char *isbn,book_t *bk);
int book_find_by_title(char *title, book_t *bl);
int book_update(char *isbn, char *author, char *title);
int copy_get_max_id();
int copy_save(copy_t *u);
// copy_t check_status(copy_t *isbn);
int book_copy_get_count(char isbn[ISBN_LENGTH], int *total_count, int *avail_count); 
int generate_category_list(hashtable_category_t *hc);


#endif
