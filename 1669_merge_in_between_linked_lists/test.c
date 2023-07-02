// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode* cur = list1;
    int count = 0;
    while (count + 1 < a) {
        cur = cur->next;
        count++;
    }
    struct ListNode* prev = cur;
    while (count < b) {
        cur = cur->next;
        count++;
    }
    struct ListNode* next = cur->next;

    prev->next = list2;
    struct ListNode* cur2 = list2;
    while (cur2->next) {
        cur2 = cur2->next;
    }
    cur2->next = next;

    return list1;
}