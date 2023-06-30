#ifndef __ENTRY_H
#define __ENTRY_H

#include "book.h"

typedef struct category_data
{
    char book_category[BOOK_CATEGORY_SIZE];
    int count;
}category_data_t;


typedef struct entry_category
{
    int asc_key;
    category_data_t value;
}entry_category_t;


#endif

