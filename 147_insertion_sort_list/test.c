
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 


struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* cur = head;
    while (cur) {
        struct ListNode* next = cur->next;
        while (next) {
            if (cur->val > next->val) {
                int tmp = cur->val;
                cur->val = next->val;
                next->val = tmp;
            }
            next = next->next;
        }
        cur = cur->next;
    }
    return head;
}