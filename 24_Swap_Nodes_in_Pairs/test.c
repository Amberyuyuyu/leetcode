/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* tmp;
    tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->next = head;
    struct ListNode* prev = tmp;
    struct ListNode* cur = head;
    struct ListNode* next = head->next;
    while (cur && cur->next) {
        prev->next = next;
        cur->next = next->next;
        next->next = cur;
        prev = cur;
        cur = cur->next;
        if (cur != NULL) {
            next = cur->next;
        }

    }
    return tmp->next;
}