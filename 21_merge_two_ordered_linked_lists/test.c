#include <stdio.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 
struct ListNode* mergeTwoLists_1(struct ListNode* list1, struct ListNode* list2) {
     struct ListNode* head=NULL;
     struct ListNode* tail=NULL;
     struct ListNode* cur1 = list1;
     struct ListNode* cur2 = list2;
     if(list1 == NULL){
         return list2;
     }
     if(list2 == NULL){
         return list1;
     }
     if(cur1->val < cur2->val){
         head = cur1;
         tail = cur1;
         cur1 = cur1->next;
     }else{
         head = cur2;
         tail = cur2;
         cur2 = cur2->next;
     }
     while(cur1 && cur2){
         if(cur1->val < cur2->val){
             tail->next = cur1;
             tail = tail->next;
             cur1 = cur1->next;

         }else{
             tail->next = cur2;
             tail = tail->next;
             cur2 = cur2->next;
         }

     }
     if(cur1){
         tail->next = cur1;
     }
     if(cur2){
         tail->next = cur2;
     }
     return head;
    
}

struct ListNode* mergeTwoLists_2(struct ListNode* list1, struct ListNode* list2) {
 
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }
    if (list1) {
        tail->next = list1;
    }
    if (list2) {
        tail->next = list2;
    }
    struct ListNode* list = head->next;
    free(head);
    return list;
}
