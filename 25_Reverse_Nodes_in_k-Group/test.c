/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int n = 0;
    struct ListNode* cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* p0 = dummy;
    cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    while (n >= k) {
        n -= k;
        int tmp = k;
        while (tmp--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        next = p0->next;
        p0->next->next = cur;
        p0->next = prev;
        p0 = next;

    }
    return dummy->next;
}