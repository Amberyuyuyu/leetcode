#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 
struct ListNode* swapNodes(struct ListNode* head, int k) {

    struct ListNode* cur = head;
    int len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
    if (len < k) {
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    k = k - 1;
    while (k--) {
        fast = fast->next;
    }
    struct ListNode* prev_k = fast;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    struct ListNode* next_k = slow;
    int tmp = next_k->val;
    next_k->val = prev_k->val;
    prev_k->val = tmp;

    return head;
}


int main() {
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    struct ListNode* ret = swapNodes(n1, 2);
    return 0;
}