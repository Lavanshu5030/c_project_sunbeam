#ifndef BOOK_H
#define BOOK_H

struct book
{
    int isbn;
    char title[50];
    char author[50]; 
    char category[50];
    float price;
};

#endif // BOOK_H


