#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/list.h"


list *init_list(void){
    printf("Enter 'i' to insert to list, 's' to search list, 'd to delete from list \n");
    return(NULL);
}

list *search_list(list *l, item_type x){
    if(l == NULL) return (NULL); 

    if (l->item == x) /*if item in l is equal to x, found item*/
        return(l);
    else
        return(search_list(l->next,x)); /*pass next node and search*/
}

void insert_list(list **l, item_type x){

    list *p;  /*temp pointer*/

    p = malloc(sizeof(list)); /*allocate mem to size of list*/
    p->item = x;
    p->next = *l;
    *l = p;
}

list *item_ahead(list *l, list *x){
    /*if list or next is empty*/
    if((l == NULL) || (l->next == NULL)){
        return(NULL);
    }

    /*if the next item in list has element return */
    if((l->next == x)){
        return(l);
    }
    /*recursively pass next list*/
    else{
        return(item_ahead(l->next,x));
    }
}

void delete_list(list **l, list **x){
    list *p; /*item pointer*/
    list *pred; /* predecessor pointer*/

    p = *l;
    pred = item_ahead(*l, *x);

    if(pred == NULL){
        *l = p->next;
    }
    else{
        pred->next = (*x)->next;
    }
    free(*x);
}

void print_list(list *l){
    while(l != NULL){
        printf("%d ",l->item);
        l = l->next;
    }
    printf("\n");
}

int main(){

    char c;
    item_type d;
    list *l;
    list *tmp;

    l = init_list();

    while(scanf("%c", &c) != EOF){
        if(tolower(c) == 'p'){
            print_list(l);
        }

        if(tolower(c) == 'i'){
            printf("Insert Value: ");
            scanf("%d", &d);
            printf("new item: %d\n", d);
            insert_list(&l, d);
        }

        if (tolower(c) == 's') {
            scanf("%d", &d);
            tmp = search_list(l, d);
            if (tmp == NULL) { 
				printf("item %d not found\n", d);
            } else {
                printf("item %d found\n", d);
            }
        }

        if (tolower(c) == 'd') {
            scanf("%d", &d);
            tmp = search_list(l, d);
            if (tmp == NULL) {
                printf("item to delete %d not found\n", d);
            } else {
                delete_list(&l, &tmp);
                printf("item %d deleted\n", d);
            }
        }
    }
    return 0;
}
        
    

