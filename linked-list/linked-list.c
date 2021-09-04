#include <stdio.h>
#include <stdlib.h>
#include "list.h"

ListNode* create_node(int value) {
    ListNode* node;
    node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    return node; //somehow this fucking works even if i don't return the value
}


ListNode* insert_node(ListNode* node, int value) {
    if(node == NULL)
        return NULL;

    ListNode* newNode;
    ListNode* temp; 

    newNode = malloc(sizeof(ListNode));

    newNode->value = value; //assign the value to the new node

    temp = node->next; //cache the next element of 'node'
    node->next = newNode; //connect the new node after 'node' argument
    newNode->next = temp; //connect the next node to the new one
    
    return newNode;
}



ListNode* insert_node_new(ListNode* node_to_insert_after, ListNode* new_node) {
    ListNode* next = node_to_insert_after->next;
    ListNode* new_node_next = new_node->next;

    new_node->next = next; // point new_node's 'next' to the previous next node
    node_to_insert_after->next = new_node; //points the first node's 'next' value to the inserted node

    return new_node_next; /*returns the 'next' of inserted node in case it was not NULL so
                            that the pointer is not lost in case of inserting a head of
                            a different list */
}

ListNode* find_node(ListNode* head, int value) {
    if(head == NULL) //return if NULL is passed as argument
        return NULL;

    ListNode* current = head;
    while(current != NULL) {
        if(current->value == value) //return the pointer to the correct node
            return current;
        current = current->next;
    }
    return NULL;
}
ListNode* delete_list(ListNode* head) {
    ListNode* current = head;
    ListNode* next = current->next;
    while(current != NULL) {
        printf("Freed node at addres %p of value %d\n", current, current->value);
        free(current);
        current = next;
        if(current != NULL) //prevents segfault :)
            next = current->next;
    }
    return NULL;
}

void delete_node(ListNode** head_ptr, int index) {
    ListNode* temp = *head_ptr;

    if(temp == NULL) //stop if list is empty
        return;

    if(index == 0) { //delete and move head
        *head_ptr = temp->next; //move head to the second node
        free(temp); //free the old head
        return;
    }

    for(int i = 0; i < index - 1; i++) //temp is one element before the one to be deleted
        temp = temp->next;

    ListNode* deleted = temp->next;
    temp->next = deleted->next;
    printf("freed node indexed %d of value %d, at address %p\n", index, deleted->value, deleted);
    free(deleted);
}

ListNode* get_node_by_index(ListNode* head, int index) {
    ListNode* temp = head;

    if(temp == NULL) //stop if list is empty
        return NULL;

    for(int i = 0; i < index; i++)
        temp = temp->next;

    return temp;
}