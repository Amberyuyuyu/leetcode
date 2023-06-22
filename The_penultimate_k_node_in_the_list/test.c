

 // Definition for singly-linked list.
#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };



struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (k--) {
        if (fast == NULL) {
            // k大于链表长度
            return NULL;
        }
        fast = fast->next;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;

}