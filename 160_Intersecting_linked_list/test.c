

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA, * tailB;
    tailA = headA;
    tailB = headB;
    int lenA = 1;
    int lenB = 1;
    while (tailA->next) {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next) {
        tailB = tailB->next;
        lenB++;
    }
    if (tailA->val != tailB->val) {
        return NULL;
    }
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    if (lenA < lenB) {
        longList = headB;
        shortList = headA;
    }
    int gap = abs(lenA - lenB);
    while (gap--) {
        longList = longList->next;
    }
    while (longList != shortList) {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;

    
}