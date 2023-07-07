

int numComponents(struct ListNode* head, int* nums, int numsSize) {
	int a[10000] = { 0 };
	for (int i = 0; i < numsSize; i++)a[nums[i]] = 1;
	int c = 0;
	while (head) {
		if (a[head->val]) {
			while (head && a[head->val])head = head->next;
			c++;
		}
		else head = head->next;
	}
	return c;
}