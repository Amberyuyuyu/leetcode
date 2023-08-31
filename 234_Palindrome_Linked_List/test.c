/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse_list(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur) {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
struct ListNode* getMid(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(struct ListNode* head) {
    struct ListNode* mid = getMid(head);
    struct ListNode* rev = reverse_list(mid);
    while (head && rev) {
        if (head->val == rev->val) {
            head = head->next;
            rev = rev->next;
        }
        else {
            return false;
        }
    }
    return true;
}