

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            struct ListNode* meet = slow;
            struct ListNode* cur = head;
            while (cur != meet) {
                cur = cur->next;
                meet = meet->next;
            }
            return meet;
        }
    }
    return NULL;
}