// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 


struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL && head->val == 0) {
        return NULL;
    }
    struct ListNode* dum = (struct ListNode*)malloc(sizeof(struct ListNode));
    dum->next = head;
    struct ListNode* cur = dum;
    struct ListNode* next = dum->next;
    int sum = 0;
    while (cur) {
        next = cur->next;
        sum = 0;
        while (next) {
            sum -= next->val;
            if (sum == 0) {
                cur->next = next->next;

            }
            next = next->next;
        }
        cur = cur->next;
    }

    return dum->next;
}