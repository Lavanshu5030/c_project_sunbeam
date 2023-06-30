#ifndef TABLE_H
#define TABLE_H

#include "entry.h"
#include "list.h"

typedef struct hashtable_category
{
    int size_category_table;
    list_category_t *table;
}hashtable_category_t;

int generate_asc_key(char *str);
int hashfunction(int k, int SIZE);

void init_hashtable_category(int size_category_table, hashtable_category_t *hc);
void hc_insert(entry_category_t ec, hashtable_category_t *hc);
// int hc_search(int asc_key, hashtable_category_t *hc);
void free_hashtable_category(hashtable_category_t *hc);



#endif