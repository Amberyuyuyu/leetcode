/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag = 0;
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    while (cur1 || cur2) {
        int num1 = cur1 ? cur1->val : 0;
        int num2 = cur2 ? cur2->val : 0;
        int val = num1 + num2 + flag;
        if (!head) {
            head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail->val = val % 10;
            tail->next = NULL;
        }
        else {
            tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail->next->val = val % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        flag = val / 10;
        if (cur1) {
            cur1 = cur1->next;
        }
        if (cur2) {
            cur2 = cur2->next;
        }
    }
    if (flag) {
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail->next->val = flag;
        tail->next->next = NULL;
    }
    return head;
}