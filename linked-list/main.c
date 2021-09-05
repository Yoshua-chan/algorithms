#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void printList(ListNode* head) {
    ListNode* cur = head;
    if(cur == NULL)
        printf("empty list");
    while(cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* temp;

    head = create_node(2);
    temp = insert_node(head, 3);
    temp = insert_node(temp, 7);
    temp = insert_node(temp, 69);
    temp = insert_node(temp, 420);

    insert_node_new(temp, create_node(2137));
    printList(head);
    insert_node(head, 1);
    printList(head);
    push_front(&head, 777);
    printList(head);

    delete_node(&head, get_index(head, find_node(head, 420)));
    printList(head);

    tail = get_tail(head);
    printf("tail: %d\n", tail->value);
    push_back(&tail, 1337);
    push_back(&tail, 80);
    printf("tail: %d\n", tail->value);
    printList(head);
    printf("size: %d\n", list_size(head));

    return 0;
}