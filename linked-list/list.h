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

ListNode* create_node(int value);
ListNode* insert_node(ListNode* node, int value);
ListNode* getnode(ListNode* head, int index);
ListNode* find_node(ListNode* head, int value);
ListNode* insert_node_new(ListNode* node_to_insert_after, ListNode* new_node);
ListNode* delete_list(ListNode* head);
void delete_node(ListNode** head_ptr, int index);
ListNode* get_node_by_index(ListNode* head, int index);
iDLL* create_iDLL(int value);