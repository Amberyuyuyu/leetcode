// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;

    while (cur) {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    struct ListNode* head1 = reverseList(l1);
    struct ListNode* head2 = reverseList(l2);

    struct ListNode* cur1 = head1;
    struct ListNode* cur2 = head2;
    int len1 = 0;
    int len2 = 0;
    while (cur1) {
        len1++;
        cur1 = cur1->next;
    }
    while (cur2) {
        len2++;
        cur2 = cur2->next;
    }
    cur2 = head2;
    cur1 = head1;
    struct ListNode* longList = cur1;
    struct ListNode* shortList = cur2;
    if (len2 > len1) {
        longList = cur2;
        shortList = cur1;
    }
    struct ListNode* newhead = longList;
    struct ListNode* head = longList;
    int flag = 0;
    struct ListNode* prev = longList;
    while (shortList) {
        if (flag == 1) {
            longList->val += 1;
            flag = 0;
        }
        longList->val = longList->val + shortList->val;
        if (longList->val >= 10) {
            longList->val = longList->val % 10;
            flag = 1;
        }
        prev = longList;
        longList = longList->next;
        shortList = shortList->next;
    }
    if (longList == NULL && flag) {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = 1;
        newnode->next = NULL;
        prev->next = newnode;
        head = reverseList(newhead);
        return head;
    }
    while (longList) {
        if (flag) {
            longList->val += 1;
            flag = 0;
        }
        if (longList->val >= 10) {
            longList->val %= 10;
            flag = 1;
        }
        prev = longList;
        longList = longList->next;
    }
    if (flag) {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = 1;
        newnode->next = NULL;
        prev->next = newnode;

    }
    head = reverseList(newhead);
    return head;
}