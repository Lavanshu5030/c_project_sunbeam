#ifndef BOOK_CONTROL_H
#define BOOK_CONTROL_H

#include "book.h"
#include "copy.h"

void book_accept(book_t *b);
void book_print(book_t *b);
void book_add(book_t *b);
void copy_accept(copy_t *copy);
void copy_add();
void book_find_by_title_control();
void copy_print(copy_t *c);
void change_rack();
void check_book_availability();
void book_categories_report();

#endif // BOOK_H
