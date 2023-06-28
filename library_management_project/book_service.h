#ifndef BOOK_SERVICE
#define BOOK_SERVICE

int book_add(book_t *book);
int book_edit(book_t *book);  
int copy_add(char isbn[ISBN_LENGTH], int rack);
int book_copy_change_status(int book_copy_id, int status, copy_t *bc);
int copy_change_rack(int book_copy_id, int rack, copy_t *bc);
int book_search_by_isbn(char isbn[ISBN_LENGTH], book_t *book);
int copy_available(char isbn[ISBN_LENGTH]);



#endif