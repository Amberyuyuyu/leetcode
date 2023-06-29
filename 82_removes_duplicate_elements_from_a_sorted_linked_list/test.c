
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };


struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* dum = (struct ListNode*)malloc(sizeof(struct ListNode));
    dum->next = head;
    struct ListNode* cur = dum;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            int x = cur->next->val;
            while (cur->next && cur->next->val == x) {
                cur->next = cur->next->next;
            }
        }
        else {
            cur = cur->next;
        }
    }
    return dum->next;
}