
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 


struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* cur = head;
    int len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
    if (len <= 1) {
        return head;
    }
    k = k % len;
    if (k == 0) {
        return head;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (k--) {
        fast = fast->next;
    }
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    struct ListNode* next = slow->next;
    slow->next = NULL;
    fast->next = head;
    return next;
}