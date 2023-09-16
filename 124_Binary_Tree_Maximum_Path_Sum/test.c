/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max;
int dfs(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int left = dfs(root->left);
    int right = dfs(root->right);
    int l = fmax(root->val, left + root->val);
    int r = fmax(root->val, right + root->val);
    max = fmax(max, fmax(l + r - root->val, fmax(l, r)));
    return fmax(l, r);
}
int maxPathSum(struct TreeNode* root) {
    max = INT_MIN;
    dfs(root);
    return max;
}