/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* _sortedArrayToBST(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int mid = (right + left) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = _sortedArrayToBST(nums, left, mid - 1);
    root->right = _sortedArrayToBST(nums, mid + 1, right);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return _sortedArrayToBST(nums, 0, numsSize - 1);
}