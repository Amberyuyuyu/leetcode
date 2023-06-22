#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList_1(struct ListNode* head) {
     if(head == NULL){
         return head;
     }
     struct ListNode* n1 = NULL;
     struct ListNode* n2 = head;
     struct ListNode* n3 = head->next;
     while(n2){
         // ·­×ª
         n2->next = n1;
         // µü´ú
         n1 = n2;
         n2 = n3;
         if(n3 != NULL){
             n3 = n3->next;
         }
     }
     return n1;
}


struct ListNode* reverseList_2(struct ListNode* head) {
    
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;

    while (cur) {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
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
    struct ListNode* ret = reverseList(n1);

    return 0;

} 