
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    *returnSize = k;
    struct ListNode** res = (struct ListNode**)calloc(k, sizeof(struct ListNode*));
    int len = 0;
    struct ListNode* cur = head;
    while (cur) {
        cur = cur->next;
        len++;
    }
    int split = len / k;
    int remain = len % k;
    cur = head;
    struct ListNode* next = NULL;
    int i = 0;
    if (split == 0) {
        while (i < len) {
            res[i++] = cur;
            next = cur->next;
            cur->next = NULL;
            cur = next;
        }
    }
    else {
        while (k--) {
            res[i++] = cur;
            for (int j = 0; j < split + (remain > 0 ? 0 : -1); j++) {
                cur = cur->next;
            }
            remain--;
            next = cur->next;
            cur->next = NULL;
            cur = next;
        }
    }
    return res;
}