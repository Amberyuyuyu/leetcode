// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 


struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* next = slow->next;
    slow = NULL;
    fast = NULL;
    prev->next = next;
    return head;
}