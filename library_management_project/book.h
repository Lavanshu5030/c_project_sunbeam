#ifndef BOOK_H
#define BOOK_H

#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define ISBN_LENGTH 16

typedef struct book
{
    
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char isbn[ISBN_LENGTH];
    char category[50];
    float price;
}book_t;

#endif // BOOK_H


