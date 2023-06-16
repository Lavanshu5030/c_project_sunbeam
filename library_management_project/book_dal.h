#ifndef BOOK_DAL_
#define BOOK_DAL_

#include "book.h"

int book_save(book_t *book);
book_t* book_find_by_isbn(char *isbn);
book_t* book_find_by_title(char *title);
int book_update(char *isbn, char *author, char *title);
int copy_get_max_id();
int copy_save(copy_t *u);

#endif
