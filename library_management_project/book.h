#ifndef BOOK_H
#define BOOK_H

#define BOOK_FILE "book.db"
#define RECSIZE_BOOK sizeof(book_t)
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define ISBN_LENGTH 16
#define BOOK_CATEGORY_SIZE 40
typedef struct book
{
    
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char isbn[ISBN_LENGTH];
    char category[BOOK_CATEGORY_SIZE];
    float price;
}book_t;

typedef struct BookNode {
    char title[100];
    struct BookNode* next;
}Booknode_t;


#endif // BOOK_H


