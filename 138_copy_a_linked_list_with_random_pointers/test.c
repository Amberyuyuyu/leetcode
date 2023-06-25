

 // Definition for a Node.
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
 };
 

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    while (cur) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;
        if (cur->random == NULL) {
            copy->random = NULL;
        }
        else {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    struct Node* copyHead = NULL;
    struct Node* copyTail = NULL;
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (copyTail == NULL) {
            copyHead = copyTail = copy;
        }
        else {
            copyTail->next = copy;
            copyTail = copy;
        }
        cur->next = next;
        cur = next;
    }
    return copyHead;

}