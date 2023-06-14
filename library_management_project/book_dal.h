#ifndef BOOK_DAL_
#define BOOK_DAL_

#include "book.h"

int book_save(book_t *book);
book_t* book_find_by_isbn(char *isbn);


#endif
