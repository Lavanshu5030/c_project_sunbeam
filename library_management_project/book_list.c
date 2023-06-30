#include <stdio.h>
#include <stdlib.h>
#include "book_list.h"
#include "book.h"

void init_book_list(book_list_t *bl)
{
    bl->head = NULL;
}
int is_empty(book_list_t *bl)
{
    return bl->head == NULL;
}

book_node_t *create_book_node(book_t b){
    book_node_t *newnode = (book_node_t *)malloc(sizeof(book_node_t));
    newnode->data = b;
    newnode->next = NULL;
    return newnode;
}

void add_first_book_node(book_t data, book_list_t *bl)
{
    //1. create node
    book_node_t *newnode = create_book_node(data); 
    //2. if list is empty
    if(is_empty(bl))
	    //a. add newnode into head
        bl->head  = newnode;
    //3. if list is not empty
    else
    {
	    //a. add address of first node into next of newnode
        newnode->next = bl->head;
	    //b. add newnode into head
        bl->head = newnode;
    }
}

void free_book_list(book_list_t *bl){
     //1. create one trav pointer and start from head
    book_node_t *trav = bl->head;
    while(trav != NULL)
    {
        //2. take backup of current
        book_node_t *temp = trav;
        //3. go on next node
        trav = trav->next;
        //4. free the memory of backuped node
        free(temp); 
    }//5. repeat step 2 and 3 till last node (trav != NULL)
    //6. make head and tail eqaul to NULL
    bl->head = NULL;
}