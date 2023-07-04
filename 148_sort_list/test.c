#include <stdio.h>
#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode* dum = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = dum;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        }
        else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) {
        cur->next = l1;
    }
    if (l2) {
        cur->next = l2;
    }

    return dum->next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    return merge(sortList(head), sortList(fast));
}

int main() {

    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 4;
    n2->val = 2;
    n3->val = 1;
    n4->val = 3;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    struct ListNode* ret = sortList(n1);
    return 0;
}