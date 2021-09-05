//typedef struct ListNode iLL;
typedef struct ListNode ListNode;
typedef struct intDoublyListNode iDLL;
typedef struct intDoublyListNode intDoublyListNode;

struct ListNode {
    int value;
    ListNode* next;
};

struct intDoublyListNode {
    int value;
    ListNode* prev;
    ListNode* next;
};

/*======== LINKED LIST =========*/
ListNode* create_node(int value);
ListNode* insert_node(ListNode* node, int value);
ListNode* insert_node_new(ListNode* node_to_insert_after, ListNode* new_node);

ListNode* find_node(ListNode* head, int value); //returns pointer to node with specified value
ListNode* get_node_by_index(ListNode* head, int index); //return pointer to node by it's index 
ListNode* get_tail(ListNode* head); //return list's tail pointer
int get_index(ListNode* head, ListNode* node); //gets index when provided head and node pointer
int list_size(ListNode* head);

void push_front(ListNode** head_ref, int value);
void push_back(ListNode** tail_ref, int value);

void delete_node(ListNode** head_ref, int index);
void delete_list(ListNode** head_ref);

/*==== DOUBLY LINKED LIST =====*/
