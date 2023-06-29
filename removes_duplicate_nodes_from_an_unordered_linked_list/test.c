
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 


struct ListNode* removeDuplicateNodes(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* n1 = head;

    while (n1) {
        struct ListNode* n2 = n1;
        while (n2->next) {
            if (n2->next->val == n1->val) {
                n2->next = n2->next->next;
            }
            else {
                n2 = n2->next;
            }
        }
        n1 = n1->next;
    }
    return head;
}