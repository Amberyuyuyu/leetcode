
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
 };
 


int getDecimalValue(struct ListNode* head) {
    struct ListNode* cur = head;
    int ret = 0;
    while (cur) {
        ret = ret * 2 + cur->val;
        cur = cur->next;
    }
    return ret;
}