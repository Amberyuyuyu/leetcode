
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 



typedef struct {
    int list[10000];
    int idx;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution* sol = (Solution*)malloc(sizeof(Solution));
    sol->idx = 0;
    while (head) {
        sol->list[sol->idx++] = head->val;
        head = head->next;
    }
    return sol;
}

int solutionGetRandom(Solution* obj) {
    return obj->list[rand() % (obj->idx)];
}

void solutionFree(Solution* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/