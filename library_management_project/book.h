#ifndef BOOK_H
#define BOOK_H

typedef struct book
{
    char isbn[50];
    char title[50];
    char author[50]; 
    char category[50];
    float price;
}book_t;

#endif // BOOK_H


