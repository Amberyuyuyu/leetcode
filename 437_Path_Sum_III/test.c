/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int _pathSum(struct TreeNode* root, long sum) {
    if (root == NULL) {
        return 0;
    }
    return (root->val == sum ? 1 : 0) + \
        _pathSum(root->left, (long)sum - root->val) + \
        _pathSum(root->right, (long)sum - root->val);
}
int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return 0;
    }
    return _pathSum(root, targetSum) + pathSum(root->left, targetSum) + \
        pathSum(root->right, targetSum);
}