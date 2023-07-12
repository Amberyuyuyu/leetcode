// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int len = 0;

    struct ListNode* cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    int* ret = (int*)malloc(sizeof(int) * len);
    cur = head;
    int i = 0;
    while (cur) {
        struct ListNode* next = cur->next;
        while (next && cur->val >= next->val) {
            next = next->next;
        }
        if (next) {
            ret[i] = next->val;
        }
        else {
            ret[i] = 0;
        }
        cur = cur->next;
        i++;
    }
    *returnSize = i;
    return ret;
}