
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };



 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* reversePrint(struct ListNode* head, int* returnSize) {
    struct ListNode* cur = head;
    int count = 0;
    while (cur) {
        count++;
        cur = cur->next;
    }
    *returnSize = count;
    int* arr = (int*)malloc(sizeof(struct ListNode) * count);
    cur = head;
    while (cur) {
        arr[--count] = cur->val;
        cur = cur->next;
    }
    return arr;
}