#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list_category(list_category_t *cl){
    cl->head = NULL;
}

int is_empty_list_category(list_category_t *cl){
    return cl->head == NULL;
}

node_category_t *create_node_category(entry_category_t data){
    node_category_t *newnode = (node_category_t *)malloc(sizeof(node_category_t));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void add_first_category(entry_category_t data, list_category_t *cl){
    
    node_category_t *newnode = create_node_category(data);
    if(is_empty_list_category(cl)){
        cl->head = newnode;
        newnode->data.value.count = 1;
    }
    else{
        newnode->next = cl->head;
        cl->head = newnode;
        newnode->data.value.count = 1;

    }
}

node_category_t *search_node_category(int asc_key, list_category_t *cl){
    node_category_t *trav = cl->head;

    while (trav != NULL)
    {
        if(asc_key == trav->data.asc_key){
            return trav;
        }
        trav = trav->next;
    }
    
    return NULL;
}

void free_category_list(list_category_t *cl){
    node_category_t *trav = cl->head;

    while (trav != NULL)
    {
        node_category_t *temp = trav;
        trav = trav->next;
        free(temp);
    }
    cl->head = NULL;
    
}