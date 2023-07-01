
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = n2->next;
    while (n2) {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3 != NULL) {
            n3 = n3->next;
        }
    }
    return n1;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* dum = cur;
    cur->next = head;
    int count = 0;
    while (count < left - 1) {
        cur = cur->next;
        count++;
    }
    struct ListNode* prev = cur;
    struct ListNode* leftNode = prev->next;
    while (count < right) {
        cur = cur->next;
        count++;
    }
    struct ListNode* rightNode = cur;
    struct ListNode* next = rightNode->next;
    rightNode->next = NULL;
    prev->next = NULL;
    struct ListNode* n1 = reverseList(leftNode);
    prev->next = n1;
    struct ListNode* n2 = n1;
    while (n1->next) {
        n1 = n1->next;
    }
    n2 = n1;
    n2->next = next;
 
    return dum->next;
}