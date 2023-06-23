

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;
    while (n2) {
        n2->next = n1;

        n1 = n2;
        n2 = n3;
        if (n3 != NULL) {
            n3 = n3->next;
        }
    }
    return n1;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* middlenode = middleNode(head);
    struct ListNode* reversenode = reverseList(middlenode);
    struct ListNode* cur = head;
    struct ListNode* curmid = reversenode;
    while (cur && curmid) {
        if (cur->val != curmid->val) {
            return false;
        }
        else {
            cur = cur->next;
            curmid = curmid->next;
        }
    }
    return true;
}