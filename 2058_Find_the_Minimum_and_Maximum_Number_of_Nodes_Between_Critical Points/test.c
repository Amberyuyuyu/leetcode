// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int cmp(void* p1, void* p2) {
    return *(int*)p1 - *(int*)p2;
}
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {

    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    struct ListNode* cur = head;
    int len = 0;
    while (cur) {
        cur = cur->next;
        len++;
    }
    cur = head;
    int arr[len];
    int i = 0;
    while (cur) {
        arr[i++] = cur->val;
        cur = cur->next;
    }
    if (i <= 3) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    int count = 0;
    int ans[i];
    for (int j = 1; j < i - 1; j++) {
        if (arr[j] > arr[j - 1] && arr[j] > arr[j + 1]) {
            ans[count++] = j;
            continue;
        }
        if (arr[j] < arr[j - 1] && arr[j] < arr[j + 1]) {
            ans[count++] = j;
        }
    }
    if (count < 2) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }

    qsort(ans, count, sizeof(int), cmp);
    int maxDistance = ans[count - 1] - ans[0];
    int minDistance = len;
    for (int i = 0; i < count - 1; i++) {
        minDistance = fmin(abs(ans[i] - ans[i + 1]), minDistance);
    }
    ret[0] = minDistance;
    ret[1] = maxDistance;
    return ret;
}