#include <string.h>
#include <malloc.h>
#include "stdio.h"

#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node * next;
};
struct Node *head = NULL;

void delete_node(int x){
    struct Node *current = (struct Node *) malloc(sizeof(struct Node));
    struct Node *prev = (struct Node *) malloc(sizeof(struct Node));
    bool found = false;
    prev = head;
    current = head->next;
    if(head->val == x){
        found = true;
        head = head->next;
    }
    while(current != NULL){
        if(current->val == x)
        {
            prev->next = current->next;
            found = true;
            break;

        }
        prev = current;
        current = current-> next;
    }
    if(!found) printf("This Element is not in the list");
}

void insert_node(int x){
    struct Node *newN, *current;
    newN = (struct Node *) malloc(sizeof(struct Node));
   newN ->val = x;
    newN -> next = NULL;
    if(head == NULL) {
       head = newN;
        return;
    }
    current = head;
    while(current ->next != NULL)
    {
   current = current->next;
      }
     current ->next = newN;
}
void print_list(){
   struct Node *current = head;
    while(current != NULL){
        printf("%d ", current->val);
        current = current ->next;
    }
    printf("\n");

}
int main (){
    int x;
    int size;
    printf("Please enter the Size of your list\n");
    scanf("%d", &size);
    printf("Now enter your elements\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &x);
        insert_node(x);
    }
    printf("Here is your list:\n");
    print_list();
    printf("Enter Number you want to delete\n");
    scanf("%d", &x);
    delete_node(x);
    print_list();
}