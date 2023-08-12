/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct listNode* mergeTwoList(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head;
    struct ListNode* tail;
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));


    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;

    return head->next;
}
struct ListNode* TwoList(struct ListNode** lists, int l, int r) {
    if (l > r) {
        return NULL;
    }
    if (l == r) {
        return lists[l];
    }
    int mid = l + (r - l) / 2;
    struct ListNode* l1 = TwoList(lists, l, mid);
    struct ListNode* l2 = TwoList(lists, mid + 1, r);
    return mergeTwoList(l1, l2);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }
    return TwoList(lists, 0, listsSize - 1);
}