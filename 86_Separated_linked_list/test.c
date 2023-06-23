#include <stdio.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 


struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* smallHead, * smallTail;
    smallHead = smallTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* bigHead, * bigTail;
    bigHead = bigTail = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;
    while (cur) {
        if (cur->val < x) {
            smallTail->next = cur;
            smallTail = cur;
        }
        else {
            bigTail->next = cur;
            bigTail = cur;
        }
        cur = cur->next;
    }
    bigTail->next = NULL;
    smallTail->next = bigHead->next;
    struct ListNode* newHead = smallHead->next;
    free(smallHead);
    free(bigHead);
    return newHead;

}