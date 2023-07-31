/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head) {
    struct ListNode* arr[50000];
    struct ListNode* cur = head;
    int i = 0;
    while (cur) {
        arr[i++] = cur;
        cur = cur->next;
    }
    cur = head;
    for (int j = 1; j <= i / 2; j++) {
        cur->next = arr[i - j];
        cur = cur->next;
        cur->next = arr[j];
        cur = cur->next;
    }
    cur->next = NULL;
}